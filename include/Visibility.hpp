#pragma once

#include <string>

#include "Record.hpp"
#include "RecordVisitor.hpp"
#include "nlohmann/json.hpp"

using json = nlohmann::json;

class Visibility : public Record {
  friend class NuScenes;

 private:
  std::string token;
  std::string level;
  std::string description;

 public:
  const std::string &get_token() const;
  const std::string &get_level() const;
  const std::string &get_description() const;

  void accept(const RecordVisitor &visitor) const override;

  Visibility &operator=(const Visibility &) = default;
  Visibility &operator=(Visibility &&) = default;

  Visibility() = delete;
  Visibility(const Visibility &) = default;
  Visibility(Visibility &&) = default;
  Visibility(const json &);
  Visibility(const std::string &, const std::string &, const std::string &);
  ~Visibility() = default;
};
