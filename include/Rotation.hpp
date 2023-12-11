#pragma once

#include "nlohmann/json.hpp"

class Rotation {
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
  Rotation() = delete;
  Rotation(long double, long double, long double, long double);
  ~Rotation() = default;
};