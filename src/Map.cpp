#include "Map.hpp"

Map::Map(std::string token, fs::path filename, std::string category,
         std::vector<std::string> log_tokens)
    : token(token),
      filename(filename),
      category(category),
      log_tokens(log_tokens) {}

Map::Map(const json& j)
    : token(j.at("token").get<std::string>()),
      filename(j.at("filename").get<std::string>()),
      category(j.at("category").get<std::string>()),
      log_tokens(j.at("log_tokens").get<std::vector<std::string>>()) {}

const std::string& Map::get_token() const { return this->token; }

const fs::path& Map::get_filename() const { return this->filename; }

const std::string& Map::get_category() const { return this->category; }

const std::vector<std::string>& Map::get_log_tokens() const {
  return this->log_tokens;
}
