#include "Attribute.hpp"

Attribute::Attribute(std::string token, std::string description)
    : token(token), description(description) {}

Attribute::Attribute(const json &j)
    : token(j.at("token").get<std::string>()),
      description(j.at("description").get<std::string>()) {}

const std::string &Attribute::get_token() const { return this->token; }

const std::string &Attribute::get_description() const {
  return this->description;
}
