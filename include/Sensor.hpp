#pragma once

#include <string>

#include "Record.hpp"
#include "RecordVisitor.hpp"
#include "nlohmann/json.hpp"

using json = nlohmann::json;

class Sensor : public Record {
  friend class NuScenes;

 private:
  std::string token;
  std::string modality;
  std::string channel;

 public:
  const std::string &get_token() const;
  const std::string &get_modality() const;
  const std::string &get_channel() const;

  void accept(const RecordVisitor &visitor) const override;

  Sensor &operator=(const Sensor &) = default;
  Sensor &operator=(Sensor &&) = default;

  Sensor() = delete;
  Sensor(const Sensor &) = default;
  Sensor(Sensor &&) = default;
  Sensor(const json &);
  Sensor(const std::string &, const std::string &, const std::string &);
  ~Sensor() = default;
};
