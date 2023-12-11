#include "Translation.hpp"

Translation::Translation(long double x, long double y, long double z)
    : x(x), y(y), z(z) {}

const long double &Translation::get_x() const { return this->x; }

const long double &Translation::get_y() const { return this->y; }

const long double &Translation::get_z() const { return this->z; }
