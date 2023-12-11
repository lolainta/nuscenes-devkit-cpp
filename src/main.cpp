#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <filesystem>
#include <string>

#include "Attribute.hpp"
#include "Nuscenes.hpp"
#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

namespace fs = std::filesystem;
namespace py = pybind11;

void bind_Nuscenes(py::module &m) {
  py::class_<Nuscenes>(m, "Nuscenes")
      .def(py::init<std::string, std::string, bool>(), py::arg("path"),
           py::arg("version") = std::string("v1.0-mini"),
           py::arg("verbose") = false)
      .def_property_readonly("path", &Nuscenes::get_path)
      .def_property_readonly("version", &Nuscenes::get_version)
      .def_property_readonly("verbose", &Nuscenes::get_verbose)
      .def_property_readonly("attributes", &Nuscenes::get_attributes);
}

void bind_Attribute(py::module &m) {
  py::class_<Attribute>(m, "Attribute")
      .def_property_readonly("token", &Attribute::get_token)
      .def_property_readonly("description", &Attribute::get_description);
}
PYBIND11_MODULE(_nuscenes, m) {
  bind_Attribute(m);
  bind_Nuscenes(m);
#ifdef VERSION_INFO
  m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
  m.attr("__version__") = "dev";
#endif
}
