#include "Nuscenes.hpp"

#include <filesystem>
#include <fstream>
namespace fs = std::filesystem;

Nuscenes::Nuscenes(fs::path path, std::string version, bool verbose)
    : attribute(path / version / "attribute.json") {
  this->path = path;
  this->version = version;
  this->verbose = verbose;
}