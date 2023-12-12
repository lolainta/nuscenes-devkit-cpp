#pragma once
#include <string>

#include "nlohmann/json.hpp"

using json = nlohmann::json;

class Attribute {
 private:
  std::string token;
  std::string description;

 public:
  const std::string &get_token() const;
  const std::string &get_description() const;

  Attribute &operator=(const Attribute &) = default;

  Attribute() = delete;
  Attribute(const json &);
  Attribute(std::string, std::string);
  ~Attribute() = default;
};
