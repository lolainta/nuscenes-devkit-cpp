#pragma once

#include <string>

#include "nlohmann/json.hpp"

class Log;
class Sample;

using json = nlohmann::json;

class Scene {
  friend class NuScenes;

 private:
  std::string token;
  std::string log_token;
  size_t nbr_samples;
  std::string first_sample_token;
  std::string last_sample_token;
  std::string name;
  std::string description;

  Log *log;
  Sample *first_sample;
  Sample *last_sample;

 public:
  const std::string &get_token() const;
  const std::string &get_log_token() const;
  const size_t &get_nbr_samples() const;
  const std::string &get_first_sample_token() const;
  const std::string &get_last_sample_token() const;
  const std::string &get_name() const;
  const std::string &get_description() const;

  Scene &operator=(const Scene &) = default;
  Scene &operator=(Scene &&) = default;

  Scene() = delete;
  Scene(const Scene &) = default;
  Scene(Scene &&) = default;
  Scene(const json &);
  Scene(const std::string &, const std::string &, const size_t &,
        const std::string &, const std::string &, const std::string &,
        const std::string &);
  ~Scene() = default;
};
