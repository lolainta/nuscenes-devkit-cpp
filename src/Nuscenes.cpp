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
  this->load_attributes();
  if (this->verbose)
    cout << "Loaded " << this->attributes.size() << " attributes." << endl;
  this->load_categories();
  if (this->verbose)
    cout << "Loaded " << this->categories.size() << " categories." << endl;
}

const json Nuscenes::load_json(const fs::path &path) const {
  json ret;
  try {
    if (!fs::exists(path)) {
      throw std::runtime_error("File not found.");
    }
    std::ifstream file(path);
    file >> ret;
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    exit(1);
  }
  return ret;
}

void Nuscenes::load_attributes() {
  fs::path attr_path = this->path / this->version / "attribute.json";
  json attr_json = this->load_json(attr_path);
  for (auto &attr : attr_json) {
    this->attributes.emplace_back(attr["token"], attr["description"]);
  }
}

void Nuscenes::load_categories() {
  fs::path cat_path = this->path / this->version / "category.json";
  json cat_json = this->load_json(cat_path);
  for (auto &cat : cat_json) {
    this->categories.emplace_back(cat["token"], cat["name"],
                                  cat["description"]);
  }
}

const fs::path &Nuscenes::get_path() const { return this->path; }

const std::string &Nuscenes::get_version() const { return this->version; }

const bool &Nuscenes::get_verbose() const { return this->verbose; }

const std::vector<Attribute> &Nuscenes::get_attributes() const {
  return this->attributes;
}

const std::vector<Category> &Nuscenes::get_categories() const {
  return this->categories;
}