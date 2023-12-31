#pragma once

#include <string>

#include "Record.hpp"
#include "RecordVisitor.hpp"
#include "Rotation.hpp"
#include "Translation.hpp"
#include "nlohmann/json.hpp"

using json = nlohmann::json;

class EgoPosition : public Record {
  friend class NuScenes;

 private:
  std::string token;
  uint64_t timestamp;
  Rotation rotation;
  Translation translation;

 public:
  const std::string &get_token() const;
  const uint64_t &get_timestamp() const;
  const Rotation &get_rotation() const;
  const Translation &get_translation() const;

  void accept(const RecordVisitor &visitor) const override;

  EgoPosition &operator=(const EgoPosition &) = default;
  EgoPosition &operator=(EgoPosition &&) = default;

  EgoPosition() = delete;
  EgoPosition(const EgoPosition &) = default;
  EgoPosition(EgoPosition &&) = default;
  EgoPosition(const json &);
  EgoPosition(const std::string &, uint64_t, const Rotation &,
              const Translation &);
  ~EgoPosition() = default;
};
