#pragma once
#include <string>

#include "nlohmann/json.hpp"

namespace fs = std::filesystem;
using json = nlohmann::json;

class Category {
 private:
  json raw;
  std::string token;
  std::string name;
  std::string description;

 public:
  const std::string &get_token() const;
  const std::string &get_name() const;
  const std::string &get_description() const;
  Category() = delete;
  Category(std::string, std::string, std::string);
  ~Category() = default;
};