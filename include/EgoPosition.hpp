#pragma once

#include <string>

#include "Rotation.hpp"
#include "Translation.hpp"
#include "nlohmann/json.hpp"

using json = nlohmann::json;

class EgoPosition {
 private:
  std::string token;
  uint64_t timestamp;
  Rotation rotation;
  Translation translation;

 public:
  const std::string &get_token() const;
  const uint64_t &get_timestamp() const;
  const Rotation &get_rotation() const;
  const Translation &get_translation() const;
  EgoPosition() = delete;
  EgoPosition(const json &);
  EgoPosition(std::string, uint64_t, Rotation, Translation);
  ~EgoPosition() = default;
};
