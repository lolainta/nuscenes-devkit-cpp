#include "Sample.hpp"

Sample::Sample(const std::string &token, const std::string &scene_token,
               uint64_t timestamp, const std::string &prev_token,
               const std::string &next_token)
    : token(token),
      scene_token(scene_token),
      timestamp(timestamp),
      prev_token(prev_token),
      next_token(next_token) {}

Sample::Sample(const json &j)
    : token(j.at("token").get<std::string>()),
      scene_token(j.at("scene_token").get<std::string>()),
      timestamp(j.at("timestamp").get<uint64_t>()),
      prev_token(j.at("prev").get<std::string>()),
      next_token(j.at("next").get<std::string>()) {}

const std::string &Sample::get_token() const { return this->token; }

const std::string &Sample::get_scene_token() const { return this->scene_token; }

const uint64_t &Sample::get_timestamp() const { return this->timestamp; }

const std::string &Sample::get_prev_token() const { return this->prev_token; }

const std::string &Sample::get_next_token() const { return this->next_token; }

const std::vector<Annotation *> &Sample::get_annotations() const {
  return this->annotations;
}

const std::vector<SampleData *> &Sample::get_datas() const {
  return this->datas;
}
