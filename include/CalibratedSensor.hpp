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

  Sensor *sensor = nullptr;

 public:
  const std::string &get_token() const;
  const std::string &get_sensor_token() const;
  const Translation &get_translation() const;
  const Rotation &get_rotation() const;

  const Sensor &get_sensor() const;

  CalibratedSensor &operator=(const CalibratedSensor &) = default;
  CalibratedSensor &operator=(CalibratedSensor &&) = default;

  CalibratedSensor() = delete;
  CalibratedSensor(const CalibratedSensor &) = default;
  CalibratedSensor(CalibratedSensor &&) = default;
  CalibratedSensor(const json &);
  CalibratedSensor(const std::string &, const std::string &,
                   const Translation &, const Rotation &);
  ~CalibratedSensor() = default;
};
