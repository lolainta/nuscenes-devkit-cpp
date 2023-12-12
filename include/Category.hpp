#pragma once
#include <string>

#include "nlohmann/json.hpp"
using json = nlohmann::json;

class Category {
 private:
  std::string token;
  std::string name;
  std::string description;

 public:
  const std::string &get_token() const;
  const std::string &get_name() const;
  const std::string &get_description() const;

  Category &operator=(const Category &) = default;

  Category() = delete;
  Category(const json &);
  Category(std::string, std::string, std::string);
  ~Category() = default;
};
