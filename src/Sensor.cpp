#include "Sensor.hpp"

Sensor::Sensor(std::string token, std::string modality, std::string channel)
    : token(token), modality(modality), channel(channel) {}

Sensor::Sensor(const json &j)
    : token(j.at("token").get<std::string>()),
      modality(j.at("modality").get<std::string>()),
      channel(j.at("channel").get<std::string>()) {}

const std::string &Sensor::get_token() const { return this->token; }

const std::string &Sensor::get_modality() const { return this->modality; }

const std::string &Sensor::get_channel() const { return this->channel; }
