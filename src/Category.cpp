#include "Category.hpp"

Category::Category(std::string token, std::string name, std::string description)
    : token(token), name(name), description(description) {}

const std::string &Category::get_token() const { return this->token; }

const std::string &Category::get_name() const { return this->name; }

const std::string &Category::get_description() const {
  return this->description;
}
