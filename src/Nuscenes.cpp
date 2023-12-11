#include "Nuscenes.hpp"

#include <filesystem>
#include <fstream>
namespace fs = std::filesystem;

Nuscenes::Nuscenes(std::string path, std::string version, bool verbose)
    : path(fs::path(path)), version(version), verbose(verbose) {
  fs::path attr_path = this->path / this->version / "attribute.json";
  json attr_json;
  try {
    if (!fs::exists(attr_path)) {
      throw std::runtime_error("Attribute file not found.");
    }
    std::ifstream attr_file(attr_path);
    attr_file >> attr_json;
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    exit(1);
  }
  for (auto &attr : attr_json) {
    this->attributes.emplace_back(attr["token"], attr["description"]);
  }
}

const fs::path &Nuscenes::get_path() const { return this->path; }
const std::string &Nuscenes::get_version() const { return this->version; }
const bool &Nuscenes::get_verbose() const { return this->verbose; }
const std::vector<Attribute> &Nuscenes::get_attributes() const {
  return this->attributes;
}