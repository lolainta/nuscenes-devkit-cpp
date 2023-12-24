#pragma once
#include <string>

#include "nlohmann/json.hpp"

using json = nlohmann::json;

class Attribute {
  friend class NuScenes;

 private:
  std::string token;
  std::string name;
  std::string description;

 public:
  const std::string &get_token() const;
  const std::string &get_name() const;
  const std::string &get_description() const;

  Attribute &operator=(const Attribute &) = default;
  Attribute &operator=(Attribute &&) = default;

  Attribute() = delete;
  Attribute(const Attribute &) = default;
  Attribute(Attribute &&) = default;
  Attribute(const json &);
  Attribute(const std::string &, const std::string &, const std::string &);
  ~Attribute() = default;
};
