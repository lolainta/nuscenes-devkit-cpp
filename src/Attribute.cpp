#include "Attribute.hpp"

Attribute::Attribute(const std::string &token, const std::string &name,
                     const std::string &description)
    : token(token), name(name), description(description) {}

Attribute::Attribute(const json &j)
    : token(j.at("token").get<std::string>()),
      name(j.at("name").get<std::string>()),
      description(j.at("description").get<std::string>()) {}

const std::string &Attribute::get_token() const { return this->token; }

const std::string &Attribute::get_name() const { return this->name; }

const std::string &Attribute::get_description() const {
  return this->description;
}

void Attribute::accept(const RecordVisitor &visitor) const {
  visitor.visit(*this);
}
