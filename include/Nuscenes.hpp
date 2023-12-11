#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Attribute.hpp"
#include "Category.hpp"
#include "EgoPosition.hpp"
#include "Log.hpp"
#include "nlohmann/json.hpp"

using json = nlohmann::json;
namespace fs = std::filesystem;

class Nuscenes {
 private:
  fs::path path;
  std::string version;
  bool verbose;
  std::vector<Attribute> attributes;
  std::vector<Category> categories;
  std::vector<EgoPosition> ego_positions;
  std::vector<Log> logs;

  const json load_json(const fs::path &) const;
  void load_attributes();
  void load_categories();
  void load_ego_positions();
  void load_logs();

 public:
  const fs::path &get_path() const;
  const std::string &get_version() const;
  const bool &get_verbose() const;
  const std::vector<Attribute> &get_attributes() const;
  const std::vector<Category> &get_categories() const;
  const std::vector<EgoPosition> &get_ego_positions() const;
  const std::vector<Log> &get_logs() const;
  Nuscenes() = delete;
  Nuscenes(std::string, std::string = "v1.0-mini", bool = false);
  ~Nuscenes() = default;
};
