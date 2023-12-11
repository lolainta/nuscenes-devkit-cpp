#pragma once

#include "nlohmann/json.hpp"

class Translation {
 private:
  long double x;
  long double y;
  long double z;

 public:
  const long double &get_x() const;
  const long double &get_y() const;
  const long double &get_z() const;
  Translation() = delete;
  Translation(long double, long double, long double);
  ~Translation() = default;
};