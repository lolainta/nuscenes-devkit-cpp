#pragma once

#include <filesystem>
#include <string>
#include <vector>

#include "enums.hpp"
#include "nlohmann/json.hpp"

namespace fs = std::filesystem;
using json = nlohmann::json;

class Map {
 private:
  std::string token;
  fs::path filename;
  std::string category;
  std::vector<std::string> log_tokens;

 public:
  const std::string &get_token() const;
  const fs::path &get_filename() const;
  const std::string &get_category() const;
  const std::vector<std::string> &get_log_tokens() const;
  Map() = delete;
  Map(std::string, fs::path, std::string, std::vector<std::string>);
  Map(const json &);
  ~Map() = default;
};
