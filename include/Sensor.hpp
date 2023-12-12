#pragma once

#include <string>

#include "nlohmann/json.hpp"

using json = nlohmann::json;

class Sensor {
  friend class NuScenes;

 private:
  std::string token;
  std::string modality;
  std::string channel;

 public:
  const std::string &get_token() const;
  const std::string &get_modality() const;
  const std::string &get_channel() const;

  Sensor &operator=(const Sensor &) = default;

  Sensor() = delete;
  Sensor(const json &);
  Sensor(std::string, std::string, std::string);
  ~Sensor() = default;
};
