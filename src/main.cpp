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
      .def(py::init<std::string, std::string, bool>(), py::arg("dataroot"),
           py::arg("version") = std::string("v1.0-mini"),
           py::arg("verbose") = false)
      .def_property_readonly("path", &Nuscenes::get_path)
      .def_property_readonly("dataroot", &Nuscenes::get_dataroot)
      .def_property_readonly("version", &Nuscenes::get_version)
      .def_property_readonly("verbose", &Nuscenes::get_verbose)
      .def_property_readonly("annotations", &Nuscenes::get_annotations)
      .def_property_readonly("attributes", &Nuscenes::get_attributes)
      .def_property_readonly("calibrated_sensors",
                             &Nuscenes::get_calibrated_sensors)
      .def_property_readonly("categories", &Nuscenes::get_categories)
      .def_property_readonly("ego_positions", &Nuscenes::get_ego_positions)
      .def_property_readonly("instances", &Nuscenes::get_instances)
      .def_property_readonly("logs", &Nuscenes::get_logs)
      .def_property_readonly("maps", &Nuscenes::get_maps)
      .def_property_readonly("samples", &Nuscenes::get_samples)
      .def_property_readonly("sample_datas", &Nuscenes::get_sample_datas)
      .def_property_readonly("scenes", &Nuscenes::get_scenes)
      .def_property_readonly("sensors", &Nuscenes::get_sensors)
      .def_property_readonly("visibilities", &Nuscenes::get_visibilities);
}

void bind_Annotation(py::module &m) {
  py::class_<Annotation>(m, "Annotation")
      .def_property_readonly("token", &Annotation::get_token)
      .def_property_readonly("sample_token", &Annotation::get_sample_token)
      .def_property_readonly("instance_token", &Annotation::get_instance_token)
      .def_property_readonly("attribute_tokens",
                             &Annotation::get_attribute_tokens)
      .def_property_readonly("visibility_token",
                             &Annotation::get_visibility_token)
      .def_property_readonly("translation", &Annotation::get_translation)
      .def_property_readonly("rotation", &Annotation::get_rotation)
      .def_property_readonly("size", &Annotation::get_size)
      .def_property_readonly("prev", &Annotation::get_prev)
      .def_property_readonly("next", &Annotation::get_next);
}

void bind_Attribute(py::module &m) {
  py::class_<Attribute>(m, "Attribute")
      .def_property_readonly("token", &Attribute::get_token)
      .def_property_readonly("description", &Attribute::get_description);
}

void bind_CalibratedSensor(py::module &m) {
  py::class_<CalibratedSensor>(m, "CalibratedSensor")
      .def_property_readonly("token", &CalibratedSensor::get_token)
      .def_property_readonly("sensor_token",
                             &CalibratedSensor::get_sensor_token)
      .def_property_readonly("translation", &CalibratedSensor::get_translation)
      .def_property_readonly("rotation", &CalibratedSensor::get_rotation);
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

void bind_Map(py::module &m) {
  py::class_<Map>(m, "Map")
      .def_property_readonly("token", &Map::get_token)
      .def_property_readonly("filename", &Map::get_filename)
      .def_property_readonly("category", &Map::get_category)
      .def_property_readonly("log_tokens", &Map::get_log_tokens);
}

void bind_Rotation(py::module &m) {
  py::class_<Rotation>(m, "Rotation")
      .def_property_readonly("x", &Rotation::get_x)
      .def_property_readonly("y", &Rotation::get_y)
      .def_property_readonly("z", &Rotation::get_z)
      .def_property_readonly("w", &Rotation::get_w);
}

void bind_SampleData(py::module &m) {
  py::class_<SampleData>(m, "SampleData")
      .def_property_readonly("token", &SampleData::get_token)
      .def_property_readonly("sample_token", &SampleData::get_sample_token)
      .def_property_readonly("ego_pose_token", &SampleData::get_ego_pose_token)
      .def_property_readonly("calibrated_sensor_token",
                             &SampleData::get_calibrated_sensor_token)
      .def_property_readonly("timestamp", &SampleData::get_timestamp)
      .def_property_readonly("fileformat", &SampleData::get_fileformat)
      .def_property_readonly("is_key_frame", &SampleData::get_is_key_frame)
      .def_property_readonly("height", &SampleData::get_height)
      .def_property_readonly("width", &SampleData::get_width)
      .def_property_readonly("filename", &SampleData::get_filename)
      .def_property_readonly("prev", &SampleData::get_prev)
      .def_property_readonly("next", &SampleData::get_next);
}

void bind_Sample(py::module &m) {
  py::class_<Sample>(m, "Sample")
      .def_property_readonly("token", &Sample::get_token)
      .def_property_readonly("scene_token", &Sample::get_scene_token)
      .def_property_readonly("timestamp", &Sample::get_timestamp)
      .def_property_readonly("next", &Sample::get_next)
      .def_property_readonly("prev", &Sample::get_prev);
}

void bind_Scene(py::module &m) {
  py::class_<Scene>(m, "Scene")
      .def_property_readonly("token", &Scene::get_token)
      .def_property_readonly("log_token", &Scene::get_log_token)
      .def_property_readonly("nbr_samples", &Scene::get_nbr_samples)
      .def_property_readonly("first_sample_token",
                             &Scene::get_first_sample_token)
      .def_property_readonly("last_sample_token", &Scene::get_last_sample_token)
      .def_property_readonly("name", &Scene::get_name)
      .def_property_readonly("description", &Scene::get_description);
}

void bind_Sensor(py::module &m) {
  py::class_<Sensor>(m, "Sensor")
      .def_property_readonly("token", &Sensor::get_token)
      .def_property_readonly("channel", &Sensor::get_channel)
      .def_property_readonly("modality", &Sensor::get_modality)
      .def_property_readonly("channel", &Sensor::get_channel);
}

void bind_Translation(py::module &m) {
  py::class_<Translation>(m, "Translation")
      .def_property_readonly("x", &Translation::get_x)
      .def_property_readonly("y", &Translation::get_y)
      .def_property_readonly("z", &Translation::get_z);
}

void bind_Visibility(py::module &m) {
  py::class_<Visibility>(m, "Visibility")
      .def_property_readonly("token", &Visibility::get_token)
      .def_property_readonly("level", &Visibility::get_level)
      .def_property_readonly("description", &Visibility::get_description);
}

void bind_classes(py::module &m) {
  bind_Nuscenes(m);
  bind_Annotation(m);
  bind_Attribute(m);
  bind_CalibratedSensor(m);
  bind_Category(m);
  bind_EgoPosition(m);
  bind_Instance(m);
  bind_Log(m);
  bind_Map(m);
  bind_Rotation(m);
  bind_Sample(m);
  bind_SampleData(m);
  bind_Scene(m);
  bind_Sensor(m);
  bind_Translation(m);
  bind_Visibility(m);
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
