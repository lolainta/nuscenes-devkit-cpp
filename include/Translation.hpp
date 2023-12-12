#pragma once

#include "nlohmann/json.hpp"

using json = nlohmann::json;

class Translation {
  friend class NuScenes;

 private:
  long double x;
  long double y;
  long double z;

 public:
  const long double &get_x() const;
  const long double &get_y() const;
  const long double &get_z() const;

  Translation &operator=(const Translation &) = default;

  Translation() = delete;
  Translation(const json &);
  Translation(long double, long double, long double);
  Translation(const Translation &) = default;
  Translation(Translation &&) = default;
  ~Translation() = default;
};
