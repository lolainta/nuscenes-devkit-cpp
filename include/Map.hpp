#pragma once

#include <filesystem>
#include <string>
#include <vector>

#include "enums.hpp"
#include "nlohmann/json.hpp"

class Log;

namespace fs = std::filesystem;
using json = nlohmann::json;

class Map {
  friend class NuScenes;

 private:
  std::string token;
  fs::path filename;
  std::string category;
  std::vector<std::string> log_tokens;

  std::vector<Log *> logs;

 public:
  const std::string &get_token() const;
  const fs::path &get_filename() const;
  const std::string &get_category() const;
  const std::vector<std::string> &get_log_tokens() const;

  Map &operator=(const Map &) = default;

  Map() = delete;
  Map(const std::string &, const fs::path &, const std::string &,
      const std::vector<std::string> &);
  Map(const json &);
  ~Map() = default;
};
