#include "Scene.hpp"

Scene::Scene(const std::string &token, const std::string &log_token,
             const size_t &nbr_samples, const std::string &first_sample_token,
             const std::string &last_sample_token, const std::string &name,
             const std::string &description)
    : token(token),
      log_token(log_token),
      nbr_samples(nbr_samples),
      first_sample_token(first_sample_token),
      last_sample_token(last_sample_token),
      name(name),
      description(description) {}

Scene::Scene(const json &j)
    : token(j.at("token").get<std::string>()),
      log_token(j.at("log_token").get<std::string>()),
      nbr_samples(j.at("nbr_samples").get<uint64_t>()),
      first_sample_token(j.at("first_sample_token").get<std::string>()),
      last_sample_token(j.at("last_sample_token").get<std::string>()),
      name(j.at("name").get<std::string>()),
      description(j.at("description").get<std::string>()) {}

const std::string &Scene::get_token() const { return this->token; }

const std::string &Scene::get_log_token() const { return this->log_token; }

const uint64_t &Scene::get_nbr_samples() const { return this->nbr_samples; }

const std::string &Scene::get_first_sample_token() const {
  return this->first_sample_token;
}

const std::string &Scene::get_last_sample_token() const {
  return this->last_sample_token;
}

const std::string &Scene::get_name() const { return this->name; }

const std::string &Scene::get_description() const { return this->description; }

const Log &Scene::get_log() const { return *this->log; }

const std::vector<Sample *> &Scene::get_samples() const {
  return this->samples;
}
