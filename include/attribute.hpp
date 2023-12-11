#pragma once

#include <filesystem>
#include <iostream>
#include <string>

#include "attribute.hpp"
#include "nlohmann/json.hpp"

namespace fs = std::filesystem;
using json = nlohmann::json;

class Attribute {
 private:
  json raw;

 public:
  Attribute() = delete;
  Attribute(fs::path path);

  ~Attribute() = default;
};