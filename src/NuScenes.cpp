#include "NuScenes.hpp"

#include <filesystem>
#include <fstream>

using std::cout, std::endl;
namespace fs = std::filesystem;

NuScenes::NuScenes(std::string dataroot, std::string version, bool verbose)
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
  this->load_annotations();
  this->load_attributes();
  this->load_calibrated_sensors();
  this->load_categories();
  this->load_ego_positions();
  this->load_instances();
  this->load_logs();
  this->load_maps();
  this->load_samples();
  this->load_sample_datas();
  this->load_scenes();
  this->load_sensors();
  this->load_visibilities();
}

const json NuScenes::load_json(const fs::path &path) const {
  json ret;
  try {
    if (!fs::exists(path)) {
      throw std::runtime_error("File " + path.string() + " does not exist.");
    }
    std::ifstream file(path);
    file >> ret;
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    exit(1);
  }
  return ret;
}

void NuScenes::load_annotations() {
  fs::path ann_path = this->path / "sample_annotation.json";
  json ann_json = this->load_json(ann_path);
  for (auto &ann : ann_json) {
    this->annotations.emplace_back(ann);
  }
  if (this->verbose) {
    cout << "Loaded " << this->annotations.size() << " annotations." << endl;
  }
}

void NuScenes::load_attributes() {
  fs::path attr_path = this->path / "attribute.json";
  json attr_json = this->load_json(attr_path);
  for (auto &attr : attr_json) {
    this->attributes.emplace_back(attr);
  }
  if (this->verbose) {
    cout << "Loaded " << this->attributes.size() << " attributes." << endl;
  }
}

void NuScenes::load_calibrated_sensors() {
  fs::path cs_path = this->path / "calibrated_sensor.json";
  json cs_json = this->load_json(cs_path);
  for (auto &cs : cs_json) {
    this->calibrated_sensors.emplace_back(cs);
  }
  if (this->verbose) {
    cout << "Loaded " << this->calibrated_sensors.size()
         << " calibrated sensors." << endl;
  }
}

void NuScenes::load_categories() {
  fs::path cat_path = this->path / "category.json";
  json cat_json = this->load_json(cat_path);
  for (auto &cat : cat_json) {
    this->categories.emplace_back(cat);
  }
  if (this->verbose) {
    cout << "Loaded " << this->categories.size() << " categories." << endl;
  }
}

void NuScenes::load_ego_positions() {
  fs::path ego_path = this->path / "ego_pose.json";
  json ego_json = this->load_json(ego_path);
  for (auto &ego : ego_json) {
    this->ego_positions.emplace_back(ego);
  }
  if (this->verbose) {
    cout << "Loaded " << this->ego_positions.size() << " ego positions."
         << endl;
  }
}

void NuScenes::load_instances() {
  fs::path inst_path = this->path / "instance.json";
  json inst_json = this->load_json(inst_path);
  for (auto &inst : inst_json) {
    this->instances.emplace_back(inst);
  }
  if (this->verbose) {
    cout << "Loaded " << this->instances.size() << " instances." << endl;
  }
}

void NuScenes::load_logs() {
  fs::path log_path = this->path / "log.json";
  json log_json = this->load_json(log_path);
  for (auto &log : log_json) {
    this->logs.emplace_back(log);
  }
  if (this->verbose) {
    cout << "Loaded " << this->logs.size() << " logs." << endl;
  }
}

void NuScenes::load_maps() {
  fs::path map_path = this->path / "map.json";
  json map_json = this->load_json(map_path);
  for (auto &map : map_json) {
    this->maps.emplace_back(map);
  }
  if (this->verbose) {
    cout << "Loaded " << this->maps.size() << " maps." << endl;
  }
}

void NuScenes::load_samples() {
  fs::path sample_path = this->path / "sample.json";
  json sample_json = this->load_json(sample_path);
  for (auto &sample : sample_json) {
    this->samples.emplace_back(sample);
  }
  if (this->verbose) {
    cout << "Loaded " << this->samples.size() << " samples." << endl;
  }
}

void NuScenes::load_sample_datas() {
  fs::path data_path = this->path / "sample_data.json";
  json data_json = this->load_json(data_path);
  for (auto &data : data_json) {
    this->datas.emplace_back(data);
  }
  if (this->verbose) {
    cout << "Loaded " << this->datas.size() << " sample datas." << endl;
  }
}

void NuScenes::load_scenes() {
  fs::path scene_path = this->path / "scene.json";
  json scene_json = this->load_json(scene_path);
  for (auto &scene : scene_json) {
    this->scenes.emplace_back(scene);
  }
  if (this->verbose) {
    cout << "Loaded " << this->scenes.size() << " scenes." << endl;
  }
}

void NuScenes::load_sensors() {
  fs::path sensor_path = this->path / "sensor.json";
  json sensor_json = this->load_json(sensor_path);
  for (auto &sensor : sensor_json) {
    this->sensors.emplace_back(sensor);
  }
  if (this->verbose) {
    cout << "Loaded " << this->sensors.size() << " sensors." << endl;
  }
}

void NuScenes::load_visibilities() {
  fs::path vis_path = this->path / "visibility.json";
  json vis_json = this->load_json(vis_path);
  for (auto &vis : vis_json) {
    this->visibilities.emplace_back(vis);
  }
  if (this->verbose) {
    cout << "Loaded " << this->visibilities.size() << " visibilities." << endl;
  }
}

void NuScenes::reverse_index() { this->build_token2idx(); }

void NuScenes::build_token2idx() {
  for (int i = 0; i < this->annotations.size(); i++) {
    this->annotation_token2idx[this->annotations[i].get_token()] = i;
  }
  for (int i = 0; i < this->attributes.size(); i++) {
    this->attribute_token2idx[this->attributes[i].get_token()] = i;
  }
  for (int i = 0; i < this->calibrated_sensors.size(); i++) {
    this->calibrated_sensor_token2idx[this->calibrated_sensors[i].get_token()] =
        i;
  }
  for (int i = 0; i < this->categories.size(); i++) {
    this->category_token2idx[this->categories[i].get_token()] = i;
  }
  for (int i = 0; i < this->ego_positions.size(); i++) {
    this->ego_position_token2idx[this->ego_positions[i].get_token()] = i;
  }
  for (int i = 0; i < this->instances.size(); i++) {
    this->instance_token2idx[this->instances[i].get_token()] = i;
  }
  for (int i = 0; i < this->logs.size(); i++) {
    this->log_token2idx[this->logs[i].get_token()] = i;
  }
  for (int i = 0; i < this->maps.size(); i++) {
    this->map_token2idx[this->maps[i].get_token()] = i;
  }
  for (int i = 0; i < this->samples.size(); i++) {
    this->sample_token2idx[this->samples[i].get_token()] = i;
  }
  for (int i = 0; i < this->datas.size(); i++) {
    this->sample_data_token2idx[this->datas[i].get_token()] = i;
  }
  for (int i = 0; i < this->scenes.size(); i++) {
    this->scene_token2idx[this->scenes[i].get_token()] = i;
  }
  for (int i = 0; i < this->sensors.size(); i++) {
    this->sensor_token2idx[this->sensors[i].get_token()] = i;
  }
  for (int i = 0; i < this->visibilities.size(); i++) {
    this->visibility_token2idx[this->visibilities[i].get_token()] = i;
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
