#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/stl/filesystem.h>

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
      .def_property_readonly("attributes", &Nuscenes::get_attributes)
      .def_property_readonly("categories", &Nuscenes::get_categories)
      .def_property_readonly("ego_positions", &Nuscenes::get_ego_positions)
      .def_property_readonly("instances", &Nuscenes::get_instances)
      .def_property_readonly("logs", &Nuscenes::get_logs);
}

void bind_Attribute(py::module &m) {
  py::class_<Attribute>(m, "Attribute")
      .def_property_readonly("token", &Attribute::get_token)
      .def_property_readonly("description", &Attribute::get_description);
}

void bind_Category(py::module &m) {
  py::class_<Category>(m, "Category")
      .def_property_readonly("token", &Category::get_token)
      .def_property_readonly("name", &Category::get_name)
      .def_property_readonly("description", &Category::get_description);
}

void bind_EgoPosition(py::module &m) {
  py::class_<EgoPosition>(m, "EgoPosition")
      .def_property_readonly("token", &EgoPosition::get_token)
      .def_property_readonly("timestamp", &EgoPosition::get_timestamp)
      .def_property_readonly("rotation", &EgoPosition::get_rotation)
      .def_property_readonly("translation", &EgoPosition::get_translation);
}

void bind_Rotation(py::module &m) {
  py::class_<Rotation>(m, "Rotation")
      .def_property_readonly("x", &Rotation::get_x)
      .def_property_readonly("y", &Rotation::get_y)
      .def_property_readonly("z", &Rotation::get_z)
      .def_property_readonly("w", &Rotation::get_w);
}

void bind_Translation(py::module &m) {
  py::class_<Translation>(m, "Translation")
      .def_property_readonly("x", &Translation::get_x)
      .def_property_readonly("y", &Translation::get_y)
      .def_property_readonly("z", &Translation::get_z);
}

void bind_Instance(py::module &m) {
  py::class_<Instance>(m, "Instance")
      .def_property_readonly("token", &Instance::get_token)
      .def_property_readonly("category_token", &Instance::get_category_token)
      .def_property_readonly("nbr_annotations", &Instance::get_nbr_annotations)
      .def_property_readonly("first_annotation_token",
                             &Instance::get_first_annotation_token)
      .def_property_readonly("last_annotation_token",
                             &Instance::get_last_annotation_token);
}

void bind_Log(py::module &m) {
  py::class_<Log>(m, "Log")
      .def_property_readonly("token", &Log::get_token)
      .def_property_readonly("logfile", &Log::get_logfile)
      .def_property_readonly("vehicle", &Log::get_vehicle)
      .def_property_readonly("date_captured", &Log::get_date_captured)
      .def_property_readonly("location", &Log::get_location);
}

void bind_classes(py::module &m) {
  bind_Nuscenes(m);
  bind_Attribute(m);
  bind_Category(m);
  bind_EgoPosition(m);
  bind_Instance(m);
  bind_Log(m);
  bind_Rotation(m);
  bind_Translation(m);
}

void bind_Location(py::module &m) {
  py::enum_<Location>(m, "Location")
      .value("BostonSeaport", Location::BostonSeaport)
      .value("SingaporeOnenorth", Location::SingaporeOnenorth)
      .value("SingaporeHollandvillage", Location::SingaporeHollandvillage)
      .value("SingaporeQueenstown", Location::SingaporeQueenstown);
}

PYBIND11_MODULE(_nuscenes, m) {
  bind_classes(m);
  bind_Location(m);
#ifdef VERSION_INFO
  m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
  m.attr("__version__") = "dev";
#endif
}
