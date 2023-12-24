#include "Sensor.hpp"

Sensor::Sensor(const std::string &token, const std::string &modality,
               const std::string &channel)
    : token(token), modality(modality), channel(channel) {}

Sensor::Sensor(const json &j)
    : token(j.at("token").get<std::string>()),
      modality(j.at("modality").get<std::string>()),
      channel(j.at("channel").get<std::string>()) {}

const std::string &Sensor::get_token() const { return this->token; }

const std::string &Sensor::get_modality() const { return this->modality; }

const std::string &Sensor::get_channel() const { return this->channel; }

void Sensor::accept(const RecordVisitor &visitor) const {
  visitor.visit(*this);
}
