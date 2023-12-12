#pragma once

#include <filesystem>
#include <string>

#include "nlohmann/json.hpp"

using json = nlohmann::json;
namespace fs = std::filesystem;

class SampleData {
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
  std::string prev;
  std::string next;

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
  const std::string &get_prev() const;
  const std::string &get_next() const;
  SampleData() = delete;
  SampleData(const json &);
  SampleData(std::string, std::string, std::string, std::string, uint64_t,
             std::string, bool, size_t, size_t, fs::path, std::string,
             std::string);
  ~SampleData() = default;
};
