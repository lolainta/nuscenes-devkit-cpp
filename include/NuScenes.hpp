#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "Annotation.hpp"
#include "Attribute.hpp"
#include "CalibratedSensor.hpp"
#include "Category.hpp"
#include "EgoPosition.hpp"
#include "Instance.hpp"
#include "Log.hpp"
#include "Map.hpp"
#include "Sample.hpp"
#include "SampleData.hpp"
#include "Scene.hpp"
#include "Sensor.hpp"
#include "Visibility.hpp"
#include "nlohmann/json.hpp"

using json = nlohmann::json;
namespace fs = std::filesystem;

class NuScenes {
 private:
  fs::path path;
  fs::path dataroot;
  std::string version;
  bool verbose;
  std::vector<Annotation> annotations;
  std::vector<Attribute> attributes;
  std::vector<CalibratedSensor> calibrated_sensors;
  std::vector<Category> categories;
  std::vector<EgoPosition> ego_positions;
  std::vector<Instance> instances;
  std::vector<Log> logs;
  std::vector<Map> maps;
  std::vector<Sample> samples;
  std::vector<SampleData> datas;
  std::vector<Scene> scenes;
  std::vector<Sensor> sensors;
  std::vector<Visibility> visibilities;

  std::unordered_map<std::string, Annotation *> annotations_token2ptr;
  std::unordered_map<std::string, Attribute *> attributes_token2ptr;
  std::unordered_map<std::string, CalibratedSensor *>
      calibrated_sensors_token2ptr;
  std::unordered_map<std::string, Category *> categories_token2ptr;
  std::unordered_map<std::string, EgoPosition *> ego_positions_token2ptr;
  std::unordered_map<std::string, Instance *> instances_token2ptr;
  std::unordered_map<std::string, Log *> logs_token2ptr;
  std::unordered_map<std::string, Map *> maps_token2ptr;
  std::unordered_map<std::string, Sample *> samples_token2ptr;
  std::unordered_map<std::string, SampleData *> datas_token2ptr;
  std::unordered_map<std::string, Scene *> scenes_token2ptr;
  std::unordered_map<std::string, Sensor *> sensors_token2ptr;
  std::unordered_map<std::string, Visibility *> visibilities_token2ptr;

  void load_data();
  const json load_json(const fs::path &) const;
  void load_annotations();
  void load_attributes();
  void load_calibrated_sensors();
  void load_categories();
  void load_ego_positions();
  void load_instances();
  void load_logs();
  void load_maps();
  void load_samples();
  void load_sample_datas();
  void load_scenes();
  void load_sensors();
  void load_visibilities();

  void build_token2idx();
  void reverse_index();
  void index_annotations();
  void index_calibrated_sensors();
  void index_instances();
  void index_maps();
  void index_samples();
  void index_sample_datas();
  void index_scenes();

 public:
  const fs::path &get_path() const;
  const fs::path &get_dataroot() const;
  const std::string &get_version() const;
  const bool &get_verbose() const;

  const std::vector<Annotation> &get_annotations() const;
  const std::vector<Attribute> &get_attributes() const;
  const std::vector<CalibratedSensor> &get_calibrated_sensors() const;
  const std::vector<Category> &get_categories() const;
  const std::vector<EgoPosition> &get_ego_positions() const;
  const std::vector<Instance> &get_instances() const;
  const std::vector<Log> &get_logs() const;
  const std::vector<Map> &get_maps() const;
  const std::vector<Sample> &get_samples() const;
  const std::vector<SampleData> &get_sample_datas() const;
  const std::vector<Scene> &get_scenes() const;
  const std::vector<Sensor> &get_sensors() const;
  const std::vector<Visibility> &get_visibilities() const;

  const Annotation &get_annotation(const std::string &) const;
  const Attribute &get_attribute(const std::string &) const;
  const CalibratedSensor &get_calibrated_sensor(const std::string &) const;
  const Category &get_category(const std::string &) const;
  const EgoPosition &get_ego_position(const std::string &) const;
  const Instance &get_instance(const std::string &) const;
  const Log &get_log(const std::string &) const;
  const Map &get_map(const std::string &) const;
  const Sample &get_sample(const std::string &) const;
  const SampleData &get_sample_data(const std::string &) const;
  const Scene &get_scene(const std::string &) const;
  const Sensor &get_sensor(const std::string &) const;
  const Visibility &get_visibility(const std::string &) const;

  NuScenes &operator=(const NuScenes &) = default;
  NuScenes &operator=(NuScenes &&) = default;

  NuScenes() = delete;
  NuScenes(const NuScenes &) = default;
  NuScenes(NuScenes &&) = default;
  NuScenes(const std::string &, const std::string & = "v1.0-mini",
           bool = false);
  ~NuScenes() = default;
};
