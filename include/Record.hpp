#pragma once

#include <string>

class RecordVisitor;

class Record {
 public:
  virtual void accept(const class RecordVisitor &v) const = 0;
};
