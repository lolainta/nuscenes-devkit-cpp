#pragma once

#include <string>

#include "nlohmann/json.hpp"

using json = nlohmann::json;

class Visibility {
 private:
  std::string token;
  std::string level;
  std::string description;

 public:
  const std::string &get_token() const;
  const std::string &get_level() const;
  const std::string &get_description() const;
  Visibility() = delete;
  Visibility(const json &);
  Visibility(std::string, std::string, std::string);
  ~Visibility() = default;
};
