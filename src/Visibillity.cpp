#include "Visibility.hpp"

Visibility::Visibility(std::string token, std::string level,
                       std::string description)
    : token(token), level(level), description(description) {}

Visibility::Visibility(const json &j)
    : token(j.at("token").get<std::string>()),
      level(j.at("level").get<std::string>()),
      description(j.at("description").get<std::string>()) {}

const std::string &Visibility::get_token() const { return this->token; }

const std::string &Visibility::get_level() const { return this->level; }

const std::string &Visibility::get_description() const {
  return this->description;
}
