#pragma once

#include <filesystem>
#include <string>

#include "enums.hpp"
#include "nlohmann/json.hpp"

namespace fs = std::filesystem;
using json = nlohmann::json;

class Log {
 private:
  std::string token;
  fs::path logfile;
  std::string vehicle;
  std::string date_captured;
  Location location;

 public:
  const std::string &get_token() const;
  const fs::path &get_logfile() const;
  const std::string &get_vehicle() const;
  const std::string &get_date_captured() const;
  const Location &get_location() const;
  Log() = delete;
  Log(std::string, fs::path, std::string, std::string, Location);
  Log(const json &);
  ~Log() = default;
};