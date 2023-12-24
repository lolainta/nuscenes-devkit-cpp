#include "NuScenes.hpp"

#include <filesystem>
#include <fstream>

using std::cout, std::endl;
namespace fs = std::filesystem;

NuScenes::NuScenes(const std::string &dataroot, const std::string &version,
                   bool verbose)
    : dataroot(dataroot), version(version), verbose(verbose) {
  if (this->verbose) cout << "====================" << endl;
  this->path = fs::path(dataroot) / fs::path(version);
  if (this->verbose) {
    cout << "Loading NuScenes dataset for version " << this->version << endl;
  }
  auto start = std::chrono::high_resolution_clock::now();
  this->load_data();
  auto end = std::chrono::high_resolution_clock::now();
  if (this->verbose) {
    cout << "Loaded data in "
         << std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
                .count()
         << " ms" << endl;
  }
  if (this->verbose) cout << "====================" << endl;
  start = std::chrono::high_resolution_clock::now();
  this->reverse_index();
  end = std::chrono::high_resolution_clock::now();
  if (this->verbose) {
    cout << "Built reverse index in "
         << std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
                .count()
         << " ms" << endl;
  }
}

void NuScenes::load_data() {
  this->load_categories();
  this->load_attributes();
  this->load_visibilities();
  this->load_instances();
  this->load_sensors();
  this->load_calibrated_sensors();
  this->load_ego_positions();
  this->load_logs();
  this->load_scenes();
  this->load_samples();
  this->load_sample_datas();
  this->load_annotations();
  this->load_maps();
}

const json NuScenes::load_json(const fs::path &path) const {
  json ret;
  try {
    if (!fs::exists(path)) {
      throw std::runtime_error("File " + path.string() + " does not exist.");
    }
    std::ifstream file(path);
    ret = json::parse(file);
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    exit(1);
  }
  return ret;
}

#define LOAD_DATA(member, name)                                                \
  {                                                                            \
    fs::path member##_path = this->path / #name ".json";                       \
    json member##_json = this->load_json(member##_path);                       \
    this->member.assign(member##_json.begin(), member##_json.end());           \
    if (this->verbose) {                                                       \
      cout << "Loaded " << this->member.size() << " " << #name << "." << endl; \
    }                                                                          \
  }

void NuScenes::load_annotations() { LOAD_DATA(annotations, sample_annotation); }

void NuScenes::load_attributes() { LOAD_DATA(attributes, attribute); }

void NuScenes::load_calibrated_sensors() {
  LOAD_DATA(calibrated_sensors, calibrated_sensor);
}

void NuScenes::load_categories() { LOAD_DATA(categories, category); }

void NuScenes::load_ego_positions() { LOAD_DATA(ego_positions, ego_pose); }

void NuScenes::load_instances() { LOAD_DATA(instances, instance); }

void NuScenes::load_logs() { LOAD_DATA(logs, log); }

void NuScenes::load_maps() { LOAD_DATA(maps, map); }

void NuScenes::load_samples() { LOAD_DATA(samples, sample); }

void NuScenes::load_sample_datas() { LOAD_DATA(datas, sample_data); }

void NuScenes::load_scenes() { LOAD_DATA(scenes, scene); }

void NuScenes::load_sensors() { LOAD_DATA(sensors, sensor); }

void NuScenes::load_visibilities() { LOAD_DATA(visibilities, visibility); }

#undef LOAD_DATA

void NuScenes::reverse_index() {
  this->build_token2idx();

  this->index_annotations();
  this->index_calibrated_sensors();
  this->index_instances();
  this->index_maps();
  this->index_samples();
  this->index_sample_datas();
  this->index_scenes();

  for (auto &annotation : this->annotations) {
    annotation.sample->annotations.push_back(&annotation);
  }

  for (auto &instances : this->instances) {
    Annotation *first_annotation = instances.first_annotation;
    while (first_annotation != nullptr) {
      instances.annotations.push_back(first_annotation);
      first_annotation = first_annotation->next;
      assert(instances.annotations.size() <= instances.nbr_annotations);
    }
    assert(instances.annotations.size() == instances.nbr_annotations);
  }

  for (auto &scene : this->scenes) {
    Sample *cur_sample = scene.first_sample;
    while (cur_sample != nullptr) {
      assert(scene.samples.size() < scene.nbr_samples);
      scene.samples.push_back(cur_sample);
      assert(cur_sample->scene == &scene);
      cur_sample = cur_sample->next;
    }
    assert(scene.samples.size() == scene.nbr_samples);
  }

  for (auto &sample_data : this->datas) {
    if (sample_data.is_key_frame) {
      sample_data.sample->sensor_datas[sample_data.calibrated_sensor->sensor] =
          &sample_data;
      sample_data.sample->datas.push_back(&sample_data);
    }
  }
}

void NuScenes::build_token2idx() {
#define BUILD_TOKEN2IDX(member)                                         \
  for (size_t i = 0; i < this->member.size(); ++i) {                    \
    this->member##_token2ptr[this->member[i].token] = &this->member[i]; \
  }
  BUILD_TOKEN2IDX(annotations);
  BUILD_TOKEN2IDX(attributes);
  BUILD_TOKEN2IDX(calibrated_sensors);
  BUILD_TOKEN2IDX(categories);
  BUILD_TOKEN2IDX(ego_positions);
  BUILD_TOKEN2IDX(instances);
  BUILD_TOKEN2IDX(logs);
  BUILD_TOKEN2IDX(maps);
  BUILD_TOKEN2IDX(samples);
  BUILD_TOKEN2IDX(datas);
  BUILD_TOKEN2IDX(scenes);
  BUILD_TOKEN2IDX(sensors);
  BUILD_TOKEN2IDX(visibilities);
#undef BUILD_TOKEN2IDX
}

void NuScenes::index_annotations() {
  for (auto &annotation : this->annotations) {
    annotation.sample = this->samples_token2ptr[annotation.sample_token];
    annotation.instance = this->instances_token2ptr[annotation.instance_token];
    annotation.visibility =
        this->visibilities_token2ptr[annotation.visibility_token];
    for (auto &attribute_token : annotation.attribute_tokens) {
      annotation.attributes.push_back(
          this->attributes_token2ptr[attribute_token]);
    }
    annotation.prev = this->annotations_token2ptr[annotation.prev_token];
    annotation.next = this->annotations_token2ptr[annotation.next_token];
  }
}

void NuScenes::index_calibrated_sensors() {
  for (auto &calibrated_sensor : this->calibrated_sensors) {
    calibrated_sensor.sensor =
        this->sensors_token2ptr[calibrated_sensor.sensor_token];
  }
}

void NuScenes::index_instances() {
  for (auto &instance : this->instances) {
    instance.category = this->categories_token2ptr[instance.category_token];
    instance.first_annotation =
        this->annotations_token2ptr[instance.first_annotation_token];
    instance.last_annotation =
        this->annotations_token2ptr[instance.last_annotation_token];
  }
}

void NuScenes::index_maps() {
  for (auto &map : this->maps) {
    for (auto &log_token : map.log_tokens) {
      map.logs.emplace_back(this->logs_token2ptr[log_token]);
    }
  }
}

void NuScenes::index_samples() {
  for (auto &sample : this->samples) {
    sample.scene = scenes_token2ptr[sample.scene_token];
    sample.prev = this->samples_token2ptr[sample.prev_token];
    sample.next = this->samples_token2ptr[sample.next_token];
  }
}

void NuScenes::index_sample_datas() {
  for (auto &sample_data : this->datas) {
    sample_data.sample = this->samples_token2ptr[sample_data.sample_token];
    sample_data.ego_pose =
        this->ego_positions_token2ptr[sample_data.ego_pose_token];
    sample_data.calibrated_sensor =
        this->calibrated_sensors_token2ptr[sample_data.calibrated_sensor_token];
    sample_data.prev = this->datas_token2ptr[sample_data.prev_token];
    sample_data.next = this->datas_token2ptr[sample_data.next_token];
  }
}

void NuScenes::index_scenes() {
  for (auto &scene : this->scenes) {
    scene.log = this->logs_token2ptr[scene.log_token];
    scene.first_sample = this->samples_token2ptr[scene.first_sample_token];
    scene.last_sample = this->samples_token2ptr[scene.last_sample_token];
  }
}

const fs::path &NuScenes::get_path() const { return this->path; }

const fs::path &NuScenes::get_dataroot() const { return this->dataroot; }

const std::string &NuScenes::get_version() const { return this->version; }

const bool &NuScenes::get_verbose() const { return this->verbose; }

const std::vector<Annotation> &NuScenes::get_annotations() const {
  return this->annotations;
}

const std::vector<Attribute> &NuScenes::get_attributes() const {
  return this->attributes;
}

const std::vector<CalibratedSensor> &NuScenes::get_calibrated_sensors() const {
  return this->calibrated_sensors;
}

const std::vector<Category> &NuScenes::get_categories() const {
  return this->categories;
}

const std::vector<EgoPosition> &NuScenes::get_ego_positions() const {
  return this->ego_positions;
}

const std::vector<Instance> &NuScenes::get_instances() const {
  return this->instances;
}

const std::vector<Log> &NuScenes::get_logs() const { return this->logs; }

const std::vector<Map> &NuScenes::get_maps() const { return this->maps; }

const std::vector<Sample> &NuScenes::get_samples() const {
  return this->samples;
}

const std::vector<SampleData> &NuScenes::get_sample_datas() const {
  return this->datas;
}

const std::vector<Scene> &NuScenes::get_scenes() const { return this->scenes; }

const std::vector<Sensor> &NuScenes::get_sensors() const {
  return this->sensors;
}

const std::vector<Visibility> &NuScenes::get_visibilities() const {
  return this->visibilities;
}

const Annotation &NuScenes::get_annotation(const std::string &token) const {
  if (this->annotations_token2ptr.find(token) ==
      this->annotations_token2ptr.end()) {
    throw std::runtime_error("Annotation with token " + token +
                             " does not exist.");
  }
  return *this->annotations_token2ptr.at(token);
}

const Attribute &NuScenes::get_attribute(const std::string &token) const {
  if (this->attributes_token2ptr.find(token) ==
      this->attributes_token2ptr.end()) {
    throw std::runtime_error("Attribute with token " + token +
                             " does not exist.");
  }
  return *this->attributes_token2ptr.at(token);
}

const CalibratedSensor &NuScenes::get_calibrated_sensor(
    const std::string &token) const {
  if (this->calibrated_sensors_token2ptr.find(token) ==
      this->calibrated_sensors_token2ptr.end()) {
    throw std::runtime_error("CalibratedSensor with token " + token +
                             " does not exist.");
  }
  return *this->calibrated_sensors_token2ptr.at(token);
}

const Category &NuScenes::get_category(const std::string &token) const {
  if (this->categories_token2ptr.find(token) ==
      this->categories_token2ptr.end()) {
    throw std::runtime_error("Category with token " + token +
                             " does not exist.");
  }
  return *this->categories_token2ptr.at(token);
}

const EgoPosition &NuScenes::get_ego_position(const std::string &token) const {
  if (this->ego_positions_token2ptr.find(token) ==
      this->ego_positions_token2ptr.end()) {
    throw std::runtime_error("EgoPosition with token " + token +
                             " does not exist.");
  }
  return *this->ego_positions_token2ptr.at(token);
}

const Instance &NuScenes::get_instance(const std::string &token) const {
  if (this->instances_token2ptr.find(token) ==
      this->instances_token2ptr.end()) {
    throw std::runtime_error("Instance with token " + token +
                             " does not exist.");
  }
  return *this->instances_token2ptr.at(token);
}

const Log &NuScenes::get_log(const std::string &token) const {
  if (this->logs_token2ptr.find(token) == this->logs_token2ptr.end()) {
    throw std::runtime_error("Log with token " + token + " does not exist.");
  }
  return *this->logs_token2ptr.at(token);
}

const Map &NuScenes::get_map(const std::string &token) const {
  if (this->maps_token2ptr.find(token) == this->maps_token2ptr.end()) {
    throw std::runtime_error("Map with token " + token + " does not exist.");
  }
  return *this->maps_token2ptr.at(token);
}

const Sample &NuScenes::get_sample(const std::string &token) const {
  if (this->samples_token2ptr.find(token) == this->samples_token2ptr.end()) {
    throw std::runtime_error("Sample with token " + token + " does not exist.");
  }
  return *this->samples_token2ptr.at(token);
}

const SampleData &NuScenes::get_sample_data(const std::string &token) const {
  if (this->datas_token2ptr.find(token) == this->datas_token2ptr.end()) {
    throw std::runtime_error("SampleData with token " + token +
                             " does not exist.");
  }
  return *this->datas_token2ptr.at(token);
}

const Scene &NuScenes::get_scene(const std::string &token) const {
  if (this->scenes_token2ptr.find(token) == this->scenes_token2ptr.end()) {
    throw std::runtime_error("Scene with token " + token + " does not exist.");
  }
  return *this->scenes_token2ptr.at(token);
}

const Sensor &NuScenes::get_sensor(const std::string &token) const {
  if (this->sensors_token2ptr.find(token) == this->sensors_token2ptr.end()) {
    throw std::runtime_error("Sensor with token " + token + " does not exist.");
  }
  return *this->sensors_token2ptr.at(token);
}

const Visibility &NuScenes::get_visibility(const std::string &token) const {
  if (this->visibilities_token2ptr.find(token) ==
      this->visibilities_token2ptr.end()) {
    throw std::runtime_error("Visibility with token " + token +
                             " does not exist.");
  }
  return *this->visibilities_token2ptr.at(token);
}
