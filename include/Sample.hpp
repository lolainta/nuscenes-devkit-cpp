#pragma once

#include <string>

#include "nlohmann/json.hpp"

using json = nlohmann::json;

class Sample {
 private:
  std::string token;
  std::string scene_token;
  uint64_t timestamp;
  std::string prev;
  std::string next;

 public:
  const std::string &get_token() const;
  const std::string &get_scene_token() const;
  const uint64_t &get_timestamp() const;
  const std::string &get_prev() const;
  const std::string &get_next() const;
  Sample() = delete;
  Sample(const json &);
  Sample(std::string, std::string, uint64_t, std::string, std::string);
  ~Sample() = default;
};
