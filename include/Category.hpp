#pragma once
#include <string>

#include "nlohmann/json.hpp"

class Category {
 private:
  std::string token;
  std::string name;
  std::string description;

 public:
  const std::string &get_token() const;
  const std::string &get_name() const;
  const std::string &get_description() const;
  Category() = delete;
  Category(std::string, std::string, std::string);
  ~Category() = default;
};