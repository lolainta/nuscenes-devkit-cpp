#pragma once

#include "Record.hpp"
#include "RecordVisitor.hpp"
#include "nlohmann/json.hpp"

using json = nlohmann::json;

class Translation : public Record {
  friend class NuScenes;

 private:
  long double x;
  long double y;
  long double z;

 public:
  const long double &get_x() const;
  const long double &get_y() const;
  const long double &get_z() const;

  void accept(const RecordVisitor &visitor) const override;

  Translation &operator=(const Translation &) = default;
  Translation &operator=(Translation &&) = default;

  Translation() = delete;
  Translation(const Translation &) = default;
  Translation(Translation &&) = default;
  Translation(const json &);
  Translation(const long double &, const long double &, const long double &);
  ~Translation() = default;
};
