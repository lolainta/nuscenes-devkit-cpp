#pragma once
#include <string>

#include "Rotation.hpp"
#include "Translation.hpp"
#include "nlohmann/json.hpp"

class Attribute;
class Sample;
class Instance;
class Visibility;

using json = nlohmann::json;

class Annotation {
  friend class NuScenes;

 private:
  std::string token;
  std::string sample_token;
  std::string instance_token;
  std::string visibility_token;
  std::vector<std::string> attribute_tokens;
  Translation translation;
  Rotation rotation;
  std::array<double, 3> size;
  std::string prev_token;
  std::string next_token;

  Sample *sample = nullptr;
  Instance *instance = nullptr;
  Visibility *visibility = nullptr;
  std::vector<Attribute *> attributes;
  Annotation *prev = nullptr;
  Annotation *next = nullptr;

 public:
  const std::string &get_token() const;
  const std::string &get_sample_token() const;
  const std::string &get_instance_token() const;
  const std::string &get_visibility_token() const;
  const std::vector<std::string> &get_attribute_tokens() const;
  const Translation &get_translation() const;
  const Rotation &get_rotation() const;
  const std::array<double, 3> &get_size() const;
  const std::string &get_prev_token() const;
  const std::string &get_next_token() const;

  Annotation &operator=(const Annotation &) = default;
  Annotation &operator=(Annotation &&) = default;

  Annotation() = delete;
  Annotation(const Annotation &) = default;
  Annotation(Annotation &&) = default;
  Annotation(const json &);
  Annotation(const std::string &, const std::string &, const std::string &,
             const std::string &, const std::vector<std::string> &,
             const Translation &, const Rotation &,
             const std::array<double, 3> &, const std::string &,
             const std::string &);
  ~Annotation() = default;
};
