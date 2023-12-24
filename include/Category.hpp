#pragma once
#include <string>

#include "Record.hpp"
#include "RecordVisitor.hpp"
#include "nlohmann/json.hpp"

using json = nlohmann::json;

class Category : public Record {
  friend class NuScenes;

 private:
  std::string token;
  std::string name;
  std::string description;

 public:
  const std::string &get_token() const;
  const std::string &get_name() const;
  const std::string &get_description() const;

  void accept(const RecordVisitor &visitor) const override;

  Category &operator=(const Category &) = default;
  Category &operator=(Category &&) = default;

  Category() = delete;
  Category(const Category &) = default;
  Category(Category &&) = default;
  Category(const json &);
  Category(const std::string &, const std::string &, const std::string &);
  ~Category() = default;
};
