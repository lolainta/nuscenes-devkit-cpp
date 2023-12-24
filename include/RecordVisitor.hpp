#pragma once

class RecordVisitor {
 public:
  virtual void visit(const class Annotation &a) const {};
  virtual void visit(const class Attribute &a) const {};
  virtual void visit(const class CalibratedSensor &a) const {};
  virtual void visit(const class Category &a) const {};
  virtual void visit(const class EgoPosition &a) const {};
  virtual void visit(const class Instance &a) const {};
  virtual void visit(const class Log &a) const {};
  virtual void visit(const class Map &a) const {};
  virtual void visit(const class Rotation &a) const {};
  virtual void visit(const class Sample &a) const {};
  virtual void visit(const class SampleData &a) const {};
  virtual void visit(const class Scene &a) const {};
  virtual void visit(const class Sensor &a) const {};
  virtual void visit(const class Translation &a) const {};
  virtual void visit(const class Visibility &a) const {};
};
