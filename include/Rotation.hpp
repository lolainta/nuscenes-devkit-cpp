#pragma once

#include "nlohmann/json.hpp"

using json = nlohmann::json;

class Rotation {
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

  Rotation &operator=(const Rotation &) = default;

  Rotation() = delete;
  Rotation(const json &);
  Rotation(long double, long double, long double, long double);
  Rotation(const Rotation &) = default;
  Rotation(Rotation &&) = default;
  ~Rotation() = default;
};
