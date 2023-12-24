#pragma once
#include <string>

#include "Record.hpp"
#include "RecordVisitor.hpp"
#include "nlohmann/json.hpp"

using json = nlohmann::json;

class Attribute : public Record {
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

  Attribute &operator=(const Attribute &) = default;
  Attribute &operator=(Attribute &&) = default;

  Attribute() = delete;
  Attribute(const Attribute &) = default;
  Attribute(Attribute &&) = default;
  Attribute(const json &);
  Attribute(const std::string &, const std::string &, const std::string &);
  ~Attribute() = default;
};
