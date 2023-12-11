#include "Attribute.hpp"

Attribute::Attribute(std::string token, std::string description)
    : token(token), description(description) {}

const std::string &Attribute::get_token() const { return this->token; }
const std::string &Attribute::get_description() const {
  return this->description;
}