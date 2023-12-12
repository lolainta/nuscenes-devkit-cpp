#include "Sample.hpp"

Sample::Sample(std::string token, std::string scene_token, uint64_t timestamp,
               std::string prev, std::string next)
    : token(token),
      scene_token(scene_token),
      timestamp(timestamp),
      prev(prev),
      next(next) {}

Sample::Sample(const json &j)
    : token(j.at("token").get<std::string>()),
      scene_token(j.at("scene_token").get<std::string>()),
      timestamp(j.at("timestamp").get<uint64_t>()),
      prev(j.at("prev").get<std::string>()),
      next(j.at("next").get<std::string>()) {}

const std::string &Sample::get_token() const { return this->token; }

const std::string &Sample::get_scene_token() const { return this->scene_token; }

const uint64_t &Sample::get_timestamp() const { return this->timestamp; }

const std::string &Sample::get_prev() const { return this->prev; }

const std::string &Sample::get_next() const { return this->next; }
