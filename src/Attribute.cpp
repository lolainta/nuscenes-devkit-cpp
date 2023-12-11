#include "attribute.hpp"

#include <fstream>

namespace fs = std::filesystem;

Attribute::Attribute(fs::path path) {
  std::ifstream attribute_file(path);
  if (attribute_file.is_open()) {
    attribute_file >> this->raw;
    attribute_file.close();
  } else {
    std::cout << "Unable to open file: " << path << std::endl;
  }
}