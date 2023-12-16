#pragma once

#include <string>
#include <vector>

#include "nlohmann/json.hpp"

class Category;
class Annotation;

using json = nlohmann::json;

class Instance {
  friend class NuScenes;

 private:
  std::string token;
  std::string category_token;
  size_t nbr_annotations;
  std::string first_annotation_token;
  std::string last_annotation_token;

  Category *category = nullptr;
  Annotation *first_annotation = nullptr;
  Annotation *last_annotation = nullptr;

  std::vector<Annotation *> annotations;

 public:
  const std::string &get_token() const;
  const std::string &get_category_token() const;
  const size_t &get_nbr_annotations() const;
  const std::string &get_first_annotation_token() const;
  const std::string &get_last_annotation_token() const;

  Instance &operator=(const Instance &) = default;
  Instance &operator=(Instance &&) = default;

  Instance() = delete;
  Instance(const Instance &) = default;
  Instance(Instance &&) = default;
  Instance(const json &);
  Instance(const std::string &, const std::string &, size_t,
           const std::string &, const std::string &);
  ~Instance() = default;
};
