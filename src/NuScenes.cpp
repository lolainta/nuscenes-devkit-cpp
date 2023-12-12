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
    auto start = std::chrono::high_resolution_clock::now();
    std::ifstream file(path);
    ret = json::parse(file);
    auto end = std::chrono::high_resolution_clock::now();
    cout << "Loaded " << path.string() << " in "
         << std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
                .count()
         << " ms" << endl;
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

void NuScenes::reverse_index() { this->build_token2idx(); }

void NuScenes::build_token2idx() {
#define BUILD_TOKEN2IDX(member)                                \
  for (size_t i = 0; i < this->member.size(); ++i) {           \
    this->member##_token2idx[this->member[i].get_token()] = i; \
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
