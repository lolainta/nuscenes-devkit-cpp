#include "Nuscenes.hpp"

#include <filesystem>
#include <fstream>

using std::cout, std::endl;
namespace fs = std::filesystem;

Nuscenes::Nuscenes(std::string dataroot, std::string version, bool verbose)
    : dataroot(dataroot), version(version), verbose(verbose) {
  this->path = fs::path(dataroot) / fs::path(version);
  if (this->verbose) {
    cout << "Loading Nuscenes dataset from " << path << endl;
  }
  this->load_annotations();
  this->load_attributes();
  this->load_categories();
  this->load_ego_positions();
  this->load_instances();
  this->load_logs();
  this->load_maps();
  this->load_samples();
  this->load_sample_datas();
  this->load_scenes();
}

const json Nuscenes::load_json(const fs::path &path) const {
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

void Nuscenes::load_annotations() {
  fs::path ann_path = this->path / "sample_annotation.json";
  json ann_json = this->load_json(ann_path);
  for (auto &ann : ann_json) {
    this->annotations.emplace_back(ann);
  }
  if (this->verbose) {
    cout << "Loaded " << this->annotations.size() << " annotations." << endl;
  }
}

void Nuscenes::load_attributes() {
  fs::path attr_path = this->path / "attribute.json";
  json attr_json = this->load_json(attr_path);
  for (auto &attr : attr_json) {
    this->attributes.emplace_back(attr);
  }
  if (this->verbose) {
    cout << "Loaded " << this->attributes.size() << " attributes." << endl;
  }
}

void Nuscenes::load_categories() {
  fs::path cat_path = this->path / "category.json";
  json cat_json = this->load_json(cat_path);
  for (auto &cat : cat_json) {
    this->categories.emplace_back(cat);
  }
  if (this->verbose) {
    cout << "Loaded " << this->categories.size() << " categories." << endl;
  }
}

void Nuscenes::load_ego_positions() {
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

void Nuscenes::load_instances() {
  fs::path inst_path = this->path / "instance.json";
  json inst_json = this->load_json(inst_path);
  for (auto &inst : inst_json) {
    this->instances.emplace_back(inst);
  }
  if (this->verbose) {
    cout << "Loaded " << this->instances.size() << " instances." << endl;
  }
}

void Nuscenes::load_logs() {
  fs::path log_path = this->path / "log.json";
  json log_json = this->load_json(log_path);
  for (auto &log : log_json) {
    this->logs.emplace_back(log);
  }
  if (this->verbose) {
    cout << "Loaded " << this->logs.size() << " logs." << endl;
  }
}

void Nuscenes::load_maps() {
  fs::path map_path = this->path / "map.json";
  json map_json = this->load_json(map_path);
  for (auto &map : map_json) {
    this->maps.emplace_back(map);
  }
  if (this->verbose) {
    cout << "Loaded " << this->maps.size() << " maps." << endl;
  }
}

void Nuscenes::load_samples() {
  fs::path sample_path = this->path / "sample.json";
  json sample_json = this->load_json(sample_path);
  for (auto &sample : sample_json) {
    this->samples.emplace_back(sample);
  }
  if (this->verbose) {
    cout << "Loaded " << this->samples.size() << " samples." << endl;
  }
}

void Nuscenes::load_sample_datas() {
  fs::path data_path = this->path / "sample_data.json";
  json data_json = this->load_json(data_path);
  for (auto &data : data_json) {
    this->datas.emplace_back(data);
  }
  if (this->verbose) {
    cout << "Loaded " << this->datas.size() << " sample datas." << endl;
  }
}

void Nuscenes::load_scenes() {
  fs::path scene_path = this->path / "scene.json";
  json scene_json = this->load_json(scene_path);
  for (auto &scene : scene_json) {
    this->scenes.emplace_back(scene);
  }
  if (this->verbose) {
    cout << "Loaded " << this->scenes.size() << " scenes." << endl;
  }
}

const fs::path &Nuscenes::get_path() const { return this->path; }

const fs::path &Nuscenes::get_dataroot() const { return this->dataroot; }

const std::string &Nuscenes::get_version() const { return this->version; }

const bool &Nuscenes::get_verbose() const { return this->verbose; }

const std::vector<Annotation> &Nuscenes::get_annotations() const {
  return this->annotations;
}

const std::vector<Attribute> &Nuscenes::get_attributes() const {
  return this->attributes;
}

const std::vector<Category> &Nuscenes::get_categories() const {
  return this->categories;
}

const std::vector<EgoPosition> &Nuscenes::get_ego_positions() const {
  return this->ego_positions;
}

const std::vector<Instance> &Nuscenes::get_instances() const {
  return this->instances;
}

const std::vector<Log> &Nuscenes::get_logs() const { return this->logs; }

const std::vector<Map> &Nuscenes::get_maps() const { return this->maps; }

const std::vector<Sample> &Nuscenes::get_samples() const {
  return this->samples;
}

const std::vector<SampleData> &Nuscenes::get_sample_datas() const {
  return this->datas;
}

const std::vector<Scene> &Nuscenes::get_scenes() const { return this->scenes; }
