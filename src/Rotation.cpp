#include "Rotation.hpp"

Rotation::Rotation(long double x, long double y, long double z, long double w)
    : x(x), y(y), z(z), w(w) {}

Rotation::Rotation(const json &j) : Rotation(j[0], j[1], j[2], j[3]) {}

const long double &Rotation::get_x() const { return this->x; }

const long double &Rotation::get_y() const { return this->y; }

const long double &Rotation::get_z() const { return this->z; }

const long double &Rotation::get_w() const { return this->w; }
