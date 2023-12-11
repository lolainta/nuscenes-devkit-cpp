#include <pybind11/pybind11.h>

#include <string>

#include "Nuscenes.hpp"

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

namespace py = pybind11;

void bind_Nuscenes(py::module &m) {
  py::class_<Nuscenes>(m, "Nuscenes")
      .def(py::init<std::string, std::string, bool>(),
           py::arg("path") = std::string("../data/sets/nuscenes"),
           py::arg("version") = std::string("v1.0-mini"),
           py::arg("verbose") = false);
}

PYBIND11_MODULE(_nuscenes, m) {
  bind_Nuscenes(m);
#ifdef VERSION_INFO
  m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
  m.attr("__version__") = "dev";
#endif
}
