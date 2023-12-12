#include "Translation.hpp"

Translation::Translation(const long double &x, const long double &y,
                         const long double &z)
    : x(x), y(y), z(z) {}

Translation::Translation(const json &j) : Translation(j[0], j[1], j[2]) {}

const long double &Translation::get_x() const { return this->x; }

const long double &Translation::get_y() const { return this->y; }

const long double &Translation::get_z() const { return this->z; }
