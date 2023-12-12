#pragma once

#include <string>

#include "nlohmann/json.hpp"

using json = nlohmann::json;

class Visibility {
  friend class NuScenes;

 private:
  std::string token;
  std::string level;
  std::string description;

 public:
  const std::string &get_token() const;
  const std::string &get_level() const;
  const std::string &get_description() const;

  Visibility &operator=(const Visibility &) = default;

  Visibility() = delete;
  Visibility(const json &);
  Visibility(const std::string &, const std::string &, const std::string &);
  ~Visibility() = default;
};
