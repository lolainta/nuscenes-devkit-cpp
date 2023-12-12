#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Annotation.hpp"
#include "Attribute.hpp"
#include "Category.hpp"
#include "EgoPosition.hpp"
#include "Instance.hpp"
#include "Log.hpp"
#include "Map.hpp"
#include "Sample.hpp"
#include "SampleData.hpp"
#include "Scene.hpp"
#include "Sensor.hpp"
#include "nlohmann/json.hpp"

using json = nlohmann::json;
namespace fs = std::filesystem;

class Nuscenes {
 private:
  fs::path path;
  fs::path dataroot;
  std::string version;
  bool verbose;
  std::vector<Annotation> annotations;
  std::vector<Attribute> attributes;
  std::vector<Category> categories;
  std::vector<EgoPosition> ego_positions;
  std::vector<Instance> instances;
  std::vector<Log> logs;
  std::vector<Map> maps;
  std::vector<Sample> samples;
  std::vector<SampleData> datas;
  std::vector<Scene> scenes;
  std::vector<Sensor> sensors;

  const json load_json(const fs::path &) const;
  void load_annotations();
  void load_attributes();
  void load_categories();
  void load_ego_positions();
  void load_instances();
  void load_logs();
  void load_maps();
  void load_samples();
  void load_sample_datas();
  void load_scenes();
  void load_sensors();

 public:
  const fs::path &get_path() const;
  const fs::path &get_dataroot() const;
  const std::string &get_version() const;
  const bool &get_verbose() const;
  const std::vector<Annotation> &get_annotations() const;
  const std::vector<Attribute> &get_attributes() const;
  const std::vector<Category> &get_categories() const;
  const std::vector<EgoPosition> &get_ego_positions() const;
  const std::vector<Instance> &get_instances() const;
  const std::vector<Log> &get_logs() const;
  const std::vector<Map> &get_maps() const;
  const std::vector<Sample> &get_samples() const;
  const std::vector<SampleData> &get_sample_datas() const;
  const std::vector<Scene> &get_scenes() const;
  const std::vector<Sensor> &get_sensors() const;
  Nuscenes() = delete;
  Nuscenes(std::string, std::string = "v1.0-mini", bool = false);
  ~Nuscenes() = default;
};
