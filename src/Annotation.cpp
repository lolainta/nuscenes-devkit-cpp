#include "Annotation.hpp"

Annotation::Annotation(const std::string &token,
                       const std::string &sample_token,
                       const std::string &instance_token,
                       const std::string &visibility_token,
                       const std::vector<std::string> &attribute_tokens,
                       const Translation &translation, const Rotation &rotation,
                       const std::array<double, 3> &size,
                       const std::string &prev_token,
                       const std::string &next_token)
    : token(token),
      sample_token(sample_token),
      instance_token(instance_token),
      visibility_token(visibility_token),
      attribute_tokens(attribute_tokens),
      translation(translation),
      rotation(rotation),
      size(size),
      prev_token(prev_token),
      next_token(next_token) {}

Annotation::Annotation(const json &j)
    : token(j.at("token").get<std::string>()),
      sample_token(j.at("sample_token").get<std::string>()),
      instance_token(j.at("instance_token").get<std::string>()),
      visibility_token(j.at("visibility_token").get<std::string>()),
      attribute_tokens(
          j.at("attribute_tokens").get<std::vector<std::string>>()),
      translation(j.at("translation")),
      rotation(j.at("rotation")),
      size(j.at("size").get<std::array<double, 3>>()),
      prev_token(j.at("prev").get<std::string>()),
      next_token(j.at("next").get<std::string>()) {}

const std::string &Annotation::get_token() const { return this->token; }

const std::string &Annotation::get_sample_token() const {
  return this->sample_token;
}

const std::string &Annotation::get_instance_token() const {
  return this->instance_token;
}

const std::string &Annotation::get_visibility_token() const {
  return this->visibility_token;
}

const std::vector<std::string> &Annotation::get_attribute_tokens() const {
  return this->attribute_tokens;
}

const Translation &Annotation::get_translation() const {
  return this->translation;
}

const Rotation &Annotation::get_rotation() const { return this->rotation; }

const std::array<double, 3> &Annotation::get_size() const { return this->size; }

const std::string &Annotation::get_prev_token() const {
  return this->prev_token;
}

const std::string &Annotation::get_next_token() const {
  return this->next_token;
}
