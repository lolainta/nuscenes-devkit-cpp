#include "Category.hpp"

Category::Category(const std::string &token, const std::string &name,
                   const std::string &description)
    : token(token), name(name), description(description) {}

Category::Category(const json &j)
    : token(j.at("token").get<std::string>()),
      name(j.at("name").get<std::string>()),
      description(j.at("description").get<std::string>()) {}

const std::string &Category::get_token() const { return this->token; }

const std::string &Category::get_name() const { return this->name; }

const std::string &Category::get_description() const {
  return this->description;
}

void Category::accept(const RecordVisitor &visitor) const {
  visitor.visit(*this);
}
