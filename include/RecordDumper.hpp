#pragma once

#include <cstdint>
#include <sstream>

#include "Record.hpp"
#include "RecordVisitor.hpp"

class RecordDumper : public RecordVisitor {
 private:
  uint32_t indent = 2;
  mutable uint32_t level = 0;
  mutable std::string ss;
  std::string indent_string() const;
  void print(const std::string &) const;
  std::string obj2string(const Record *) const;

 public:
  void visit(const Annotation &) const override;
  void visit(const Attribute &) const override;
  void visit(const CalibratedSensor &) const override;
  void visit(const Category &) const override;
  void visit(const EgoPosition &) const override;
  void visit(const Instance &) const override;
  void visit(const Log &) const override;
  void visit(const Map &) const override;
  void visit(const Rotation &) const override;
  void visit(const Sample &) const override;
  void visit(const SampleData &) const override;
  void visit(const Scene &) const override;
  void visit(const Sensor &) const override;
  void visit(const Translation &) const override;
  void visit(const Visibility &) const override;

  std::string get_string() const;

  RecordDumper() = default;
  RecordDumper(uint32_t, uint32_t);
  ~RecordDumper() = default;
};
