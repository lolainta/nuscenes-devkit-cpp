#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Attribute.hpp"
#include "nlohmann/json.hpp"
using json = nlohmann::json;
namespace fs = std::filesystem;

class Nuscenes {
 private:
  fs::path path;
  std::string version;
  bool verbose;
  std::vector<Attribute> attributes;

 public:
  const fs::path &get_path() const;
  const std::string &get_version() const;
  const bool &get_verbose() const;
  const std::vector<Attribute> &get_attributes() const;
  Nuscenes() = delete;
  Nuscenes(std::string, std::string = "v1.0-mini", bool = false);
  ~Nuscenes() = default;
};
