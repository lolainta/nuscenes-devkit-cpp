#pragma once

#include "Record.hpp"
#include "RecordVisitor.hpp"
#include "nlohmann/json.hpp"

using json = nlohmann::json;

class Rotation : public Record {
  friend class NuScenes;

 private:
  long double x;
  long double y;
  long double z;
  long double w;

 public:
  const long double &get_x() const;
  const long double &get_y() const;
  const long double &get_z() const;
  const long double &get_w() const;

  void accept(const RecordVisitor &visitor) const override;

  Rotation &operator=(const Rotation &) = default;
  Rotation &operator=(Rotation &&) = default;

  Rotation() = delete;
  Rotation(const Rotation &) = default;
  Rotation(Rotation &&) = default;
  Rotation(const json &);
  Rotation(const long double &, const long double &, const long double &,
           const long double &);
  ~Rotation() = default;
};
