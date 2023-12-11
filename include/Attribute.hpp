#pragma once
#include <string>

#include "nlohmann/json.hpp"

class Attribute {
 private:
  std::string token;
  std::string description;

 public:
  const std::string &get_token() const;
  const std::string &get_description() const;
  Attribute() = delete;
  Attribute(std::string, std::string);
  ~Attribute() = default;
};