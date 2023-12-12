#include "EgoPosition.hpp"

EgoPosition::EgoPosition(const std::string &token, uint64_t timestamp,
                         const Rotation &rotation,
                         const Translation &translation)
    : token(token),
      timestamp(timestamp),
      rotation(rotation),
      translation(translation) {}

EgoPosition::EgoPosition(const json &j)
    : token(j.at("token").get<std::string>()),
      timestamp(j.at("timestamp").get<uint64_t>()),
      rotation(j.at("rotation")),
      translation(j.at("translation")) {}

const std::string &EgoPosition::get_token() const { return this->token; }

const uint64_t &EgoPosition::get_timestamp() const { return this->timestamp; }

const Rotation &EgoPosition::get_rotation() const { return this->rotation; }

const Translation &EgoPosition::get_translation() const {
  return this->translation;
}
