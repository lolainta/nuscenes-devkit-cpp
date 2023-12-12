#pragma once

#include <string>

#include "Rotation.hpp"
#include "Translation.hpp"
#include "nlohmann/json.hpp"

class Sensor;

using json = nlohmann::json;

class CalibratedSensor {
  friend class NuScenes;

 private:
  std::string token;
  std::string sensor_token;
  Translation translation;
  Rotation rotation;

  Sensor *sensor;

 public:
  const std::string &get_token() const;
  const std::string &get_sensor_token() const;
  const Translation &get_translation() const;
  const Rotation &get_rotation() const;

  CalibratedSensor &operator=(const CalibratedSensor &) = default;

  CalibratedSensor() = delete;
  CalibratedSensor(const json &);
  CalibratedSensor(std::string, std::string, Translation, Rotation);
  ~CalibratedSensor() = default;
};
