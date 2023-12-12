#pragma once

#include <filesystem>
#include <string>

#include "enums.hpp"
#include "nlohmann/json.hpp"

namespace fs = std::filesystem;
using json = nlohmann::json;

class Log {
  friend class NuScenes;

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

  Log &operator=(const Log &) = default;

  Log() = delete;
  Log(const std::string &, const fs::path &, const std::string &,
      const std::string &, const Location &);
  Log(const json &);
  ~Log() = default;
};
