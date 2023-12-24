#include "RecordDumper.hpp"

#include <iostream>

#include "Annotation.hpp"
#include "Attribute.hpp"
#include "CalibratedSensor.hpp"
#include "Category.hpp"
#include "EgoPosition.hpp"
#include "Instance.hpp"
#include "Log.hpp"
#include "Map.hpp"
#include "Rotation.hpp"
#include "Sample.hpp"
#include "SampleData.hpp"
#include "Scene.hpp"
#include "Sensor.hpp"
#include "Translation.hpp"
#include "Visibility.hpp"

RecordDumper::RecordDumper(uint32_t indent, uint32_t level)
    : indent(indent), level(level) {}

inline std::string RecordDumper::indent_string() const {
  std::string indent_string = std::string(this->indent * this->level, ' ');
  return indent_string;
}

void RecordDumper::print(const std::string &s) const {
  this->ss += this->indent_string() + s;
}

std::string RecordDumper::obj2string(const Record *r) const {
  RecordDumper dumper(this->indent, this->level);
  r->accept(dumper);
  return dumper.get_string();
}

void RecordDumper::visit(const Annotation &a) const {
  this->print("Annotation {\n");
  this->level++;
  this->print("token: " + a.get_token() + "\n");
  this->print("sample_token: " + a.get_sample_token() + "\n");
  this->print("instance_token: " + a.get_instance_token() + "\n");
  this->print("visibility_token: " + a.get_visibility_token() + "\n");
  this->print("attribute_tokens: [");
  for (const auto &attribute_token : a.get_attribute_tokens()) {
    this->print(attribute_token + ", ");
  }
  this->print("]\n");
  this->print("translation: " + obj2string(&a.get_translation()));
  this->print("rotation: " + obj2string(&a.get_rotation()));
  this->print("size: [");
  for (const auto &size : a.get_size()) {
    this->ss += (std::to_string(size) + ", ");
  }
  this->print("]\n");
  this->print("prev_token: " + a.get_prev_token() + "\n");
  this->print("next_token: " + a.get_next_token() + "\n");
  this->level--;
  this->print("}\n");
}

void RecordDumper::visit(const Attribute &a) const {
  this->print("Attribute {\n");
  this->level++;
  this->print("token: " + a.get_token() + "\n");
  this->print("name: " + a.get_name() + "\n");
  this->print("description: " + a.get_description() + "\n");
  this->level--;
  this->print("}\n");
}

void RecordDumper::visit(const CalibratedSensor &a) const {
  this->print("CalibratedSensor {\n");
  this->level++;
  this->print("token: " + a.get_token() + "\n");
  this->print("sensor_token: " + a.get_sensor_token() + "\n");
  this->level--;
  this->print("}\n");
}

void RecordDumper::visit(const Category &a) const {
  this->print("Category {\n");
  this->level++;
  this->print("token: " + a.get_token() + "\n");
  this->print("name: " + a.get_name() + "\n");
  this->print("description: " + a.get_description() + "\n");
  this->level--;
  this->print("}\n");
}

void RecordDumper::visit(const EgoPosition &a) const {
  this->print("EgoPosition {\n");
  this->level++;
  this->print("token: " + a.get_token() + "\n");
  this->print("timestamp: " + std::to_string(a.get_timestamp()) + "\n");
  this->print("translation: " + obj2string(&a.get_translation()));
  this->print("rotation: " + obj2string(&a.get_rotation()));
  this->level--;
  this->print("}\n");
}

void RecordDumper::visit(const Instance &a) const {
  this->print("Instance {\n");
  this->level++;
  this->print("token: " + a.get_token() + "\n");
  this->print("category_token: " + a.get_category_token() + "\n");
  this->print("nbr_annotations: " + std::to_string(a.get_nbr_annotations()) +
              "\n");
  this->level--;
  this->print("}\n");
}

void RecordDumper::visit(const Log &a) const {
  this->print("Log {\n");
  this->level++;
  this->print("token: " + a.get_token() + "\n");
  this->print("logfile: " + a.get_logfile().generic_string() + "\n");
  this->print("vehicle: " + a.get_vehicle() + "\n");
  this->print("date_captured: " + a.get_date_captured() + "\n");
  this->level--;
  this->print("}\n");
}

void RecordDumper::visit(const Map &a) const {
  this->print("Map {\n");
  this->level++;
  this->print("token: " + a.get_token() + "\n");
  this->print("filename: " + a.get_filename().generic_string() + "\n");
  this->level--;
  this->print("}\n");
}

void RecordDumper::visit(const Rotation &a) const {
  this->print("Rotation {\n");
  this->level++;
  this->print("[");
  this->ss += std::to_string(a.get_x()) + ", ";
  this->ss += std::to_string(a.get_y()) + ", ";
  this->ss += std::to_string(a.get_z()) + ", ";
  this->ss += std::to_string(a.get_w()) + ", ";
  this->print("]\n");
  this->level--;
  this->print("}\n");
}

void RecordDumper::visit(const Sample &a) const {
  this->print("Sample {\n");
  this->level++;
  this->print("token: " + a.get_token() + "\n");
  this->print("timestamp: " + std::to_string(a.get_timestamp()) + "\n");
  this->print("scene_token: " + a.get_scene_token() + "\n");
  this->level--;
  this->print("}\n");
}

void RecordDumper::visit(const SampleData &a) const {
  this->print("SampleData {\n");
  this->level++;
  this->print("token: " + a.get_token() + "\n");
  this->print("sample_token: " + a.get_sample_token() + "\n");
  this->print("filename: " + a.get_filename().generic_string() + "\n");
  this->print("ego_pose_token: " + a.get_ego_pose_token() + "\n");
  this->print("calibrated_sensor_token: " + a.get_calibrated_sensor_token() +
              "\n");
  this->level--;
  this->print("}\n");
}

void RecordDumper::visit(const Scene &a) const {
  this->print("Scene {\n");
  this->level++;
  this->print("token: " + a.get_token() + "\n");
  this->print("nbr_samples: " + std::to_string(a.get_nbr_samples()) + "\n");
  this->print("first_sample_token: " + a.get_first_sample_token() + "\n");
  this->print("last_sample_token: " + a.get_last_sample_token() + "\n");
  this->print("name: " + a.get_name() + "\n");
  this->level--;
  this->print("}\n");
}

void RecordDumper::visit(const Sensor &a) const {
  this->print("Sensor {\n");
  this->level++;
  this->print("token: " + a.get_token() + "\n");
  this->print("channel: " + a.get_channel() + "\n");
  this->print("modality: " + a.get_modality() + "\n");
  this->print("channel: " + a.get_channel() + "\n");
  this->print("channel: " + a.get_channel() + "\n");
  this->level--;
  this->print("}\n");
}

void RecordDumper::visit(const Translation &a) const {
  this->print("Translation {\n");
  this->level++;
  this->print("[");
  this->ss += std::to_string(a.get_x()) + ", ";
  this->ss += std::to_string(a.get_y()) + ", ";
  this->ss += std::to_string(a.get_z()) + ", ";
  this->print("]\n");
  this->level--;
  this->print("}\n");
}

void RecordDumper::visit(const Visibility &a) const {
  this->print("Visibility {\n");
  this->level++;
  this->print("token: " + a.get_token() + "\n");
  this->print("name: " + a.get_level() + "\n");
  this->print("description: " + a.get_description() + "\n");
  this->level--;
  this->print("}\n");
}

std::string RecordDumper::get_string() const {
  std::string ret = this->ss;
  this->ss.clear();
  return ret;
}
