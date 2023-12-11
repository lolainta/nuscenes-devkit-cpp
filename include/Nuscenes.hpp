#pragma once

#include <iostream>
#include <string>

#include "attribute.hpp"
#include "nlohmann/json.hpp"

using json = nlohmann::json;
namespace fs = std::filesystem;

class Nuscenes {
 private:
  Attribute attribute;

  std::string path;
  std::string version;
  bool verbose;

 public:
  Nuscenes(fs::path, std::string = "v1.0-mini", bool = false);

  ~Nuscenes() = default;
};
