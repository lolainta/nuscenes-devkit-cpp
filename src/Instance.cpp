#include "Instance.hpp"

Instance::Instance(const std::string& token, const std::string& category_token,
                   size_t nbr_annotations,
                   const std::string& first_annotation_token,
                   const std::string& last_annotation_token)
    : token(token),
      category_token(category_token),
      nbr_annotations(nbr_annotations),
      first_annotation_token(first_annotation_token),
      last_annotation_token(last_annotation_token) {}

Instance::Instance(const json& j)
    : token(j.at("token").get<std::string>()),
      category_token(j.at("category_token").get<std::string>()),
      nbr_annotations(j.at("nbr_annotations").get<size_t>()),
      first_annotation_token(j.at("first_annotation_token").get<std::string>()),
      last_annotation_token(j.at("last_annotation_token").get<std::string>()) {}

const std::string& Instance::get_token() const { return this->token; }

const std::string& Instance::get_category_token() const {
  return this->category_token;
}

const size_t& Instance::get_nbr_annotations() const {
  return this->nbr_annotations;
}

const std::string& Instance::get_first_annotation_token() const {
  return this->first_annotation_token;
}

const std::string& Instance::get_last_annotation_token() const {
  return this->last_annotation_token;
}

const Category& Instance::get_category() const { return *this->category; }

const std::vector<Annotation*>& Instance::get_annotations() const {
  return this->annotations;
}

void Instance::accept(const RecordVisitor& visitor) const {
  visitor.visit(*this);
}
