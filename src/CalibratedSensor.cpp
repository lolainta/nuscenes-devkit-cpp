#include "CalibratedSensor.hpp"

CalibratedSensor::CalibratedSensor(const std::string &token,
                                   const std::string &sensor_token,
                                   const Translation &translation,
                                   const Rotation &rotation)

    : token(token),
      sensor_token(sensor_token),
      translation(translation),
      rotation(rotation) {}

CalibratedSensor::CalibratedSensor(const json &j)
    : token(j.at("token").get<std::string>()),
      sensor_token(j.at("sensor_token").get<std::string>()),
      translation(j.at("translation")),
      rotation(j.at("rotation")) {}

const std::string &CalibratedSensor::get_token() const { return this->token; }

const std::string &CalibratedSensor::get_sensor_token() const {
  return this->sensor_token;
}

const Translation &CalibratedSensor::get_translation() const {
  return this->translation;
}

const Rotation &CalibratedSensor::get_rotation() const {
  return this->rotation;
}

const Sensor &CalibratedSensor::get_sensor() const { return *this->sensor; }

void CalibratedSensor::accept(const RecordVisitor &visitor) const {
  visitor.visit(*this);
}
