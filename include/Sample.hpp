#pragma once

#include <string>

#include "nlohmann/json.hpp"

class Scene;
class Sample;

using json = nlohmann::json;

class Sample {
  friend class NuScenes;

 private:
  std::string token;
  std::string scene_token;
  uint64_t timestamp;
  std::string prev_token;
  std::string next_token;

  Scene *scene;
  Sample *prev;
  Sample *next;

 public:
  const std::string &get_token() const;
  const std::string &get_scene_token() const;
  const uint64_t &get_timestamp() const;
  const std::string &get_prev_token() const;
  const std::string &get_next_token() const;

  Sample &operator=(const Sample &) = default;

  Sample() = delete;
  Sample(const json &);
  Sample(const std::string &, const std::string &, uint64_t,
         const std::string &, const std::string &);
  ~Sample() = default;
};
