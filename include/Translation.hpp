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
  Translation &operator=(Translation &&) = default;

  Translation() = delete;
  Translation(const Translation &) = default;
  Translation(Translation &&) = default;
  Translation(const json &);
  Translation(const long double &, const long double &, const long double &);
  ~Translation() = default;
};
