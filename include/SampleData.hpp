#pragma once

#include <filesystem>
#include <string>

#include "nlohmann/json.hpp"

class Sample;
class EgoPosition;
class CalibratedSensor;

using json = nlohmann::json;
namespace fs = std::filesystem;

class SampleData {
  friend class NuScenes;

 private:
  std::string token;
  std::string sample_token;
  std::string ego_pose_token;
  std::string calibrated_sensor_token;
  uint64_t timestamp;
  std::string fileformat;
  bool is_key_frame;
  size_t width;
  size_t height;
  fs::path filename;
  std::string prev_token;
  std::string next_token;

  Sample *sample = nullptr;
  EgoPosition *ego_pose = nullptr;
  CalibratedSensor *calibrated_sensor = nullptr;
  SampleData *prev = nullptr;
  SampleData *next = nullptr;

 public:
  const std::string &get_token() const;
  const std::string &get_sample_token() const;
  const std::string &get_ego_pose_token() const;
  const std::string &get_calibrated_sensor_token() const;
  const uint64_t &get_timestamp() const;
  const std::string &get_fileformat() const;
  const bool &get_is_key_frame() const;
  const size_t &get_width() const;
  const size_t &get_height() const;
  const fs::path &get_filename() const;
  const std::string &get_prev_token() const;
  const std::string &get_next_token() const;

  const Sample &get_sample() const;
  const EgoPosition &get_ego_pose() const;
  const CalibratedSensor &get_calibrated_sensor() const;
  const SampleData &get_prev() const;
  const SampleData &get_next() const;

  SampleData &operator=(const SampleData &) = default;
  SampleData &operator=(SampleData &&) = default;

  SampleData() = delete;
  SampleData(const SampleData &) = default;
  SampleData(SampleData &&) = default;
  SampleData(const json &);
  SampleData(const std::string &, const std::string &, const std::string &,
             const std::string &, uint64_t, const std::string &, bool, size_t,
             size_t, const fs::path &, const std::string &,
             const std::string &);
  ~SampleData() = default;
};
