#include "Nuscenes.hpp"

#include <filesystem>
#include <fstream>

using std::cout, std::endl;
namespace fs = std::filesystem;

Nuscenes::Nuscenes(std::string path, std::string version, bool verbose)
    : path(fs::path(path)), version(version), verbose(verbose) {
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
  fs::path ann_path = this->path / this->version / "sample_annotation.json";
  json ann_json = this->load_json(ann_path);
  for (auto &ann : ann_json) {
    this->annotations.emplace_back(ann);
  }
  if (this->verbose) {
    cout << "Loaded " << this->annotations.size() << " annotations." << endl;
  }
}

void Nuscenes::load_attributes() {
  fs::path attr_path = this->path / this->version / "attribute.json";
  json attr_json = this->load_json(attr_path);
  for (auto &attr : attr_json) {
    this->attributes.emplace_back(attr);
  }
  if (this->verbose) {
    cout << "Loaded " << this->attributes.size() << " attributes." << endl;
  }
}

void Nuscenes::load_categories() {
  fs::path cat_path = this->path / this->version / "category.json";
  json cat_json = this->load_json(cat_path);
  for (auto &cat : cat_json) {
    this->categories.emplace_back(cat);
  }
  if (this->verbose) {
    cout << "Loaded " << this->categories.size() << " categories." << endl;
  }
}

void Nuscenes::load_ego_positions() {
  fs::path ego_path = this->path / this->version / "ego_pose.json";
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
  fs::path inst_path = this->path / this->version / "instance.json";
  json inst_json = this->load_json(inst_path);
  for (auto &inst : inst_json) {
    this->instances.emplace_back(inst);
  }
  if (this->verbose) {
    cout << "Loaded " << this->instances.size() << " instances." << endl;
  }
}

void Nuscenes::load_logs() {
  fs::path log_path = this->path / this->version / "log.json";
  json log_json = this->load_json(log_path);
  for (auto &log : log_json) {
    this->logs.emplace_back(log);
  }
  if (this->verbose) {
    cout << "Loaded " << this->logs.size() << " logs." << endl;
  }
}

void Nuscenes::load_maps() {
  fs::path map_path = this->path / this->version / "map.json";
  json map_json = this->load_json(map_path);
  for (auto &map : map_json) {
    this->maps.emplace_back(map);
  }
  if (this->verbose) {
    cout << "Loaded " << this->maps.size() << " maps." << endl;
  }
}

const fs::path &Nuscenes::get_path() const { return this->path; }

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