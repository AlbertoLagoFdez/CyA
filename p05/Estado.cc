#include "Estado.h"

Estado::Estado(char name) {
  name_ = name;
}

void Estado::set_acept(bool acept) {
  acept_ = acept;
}

std::ostream &operator<<(std::ostream &os, Estado p)
{
  os << "q" << p.name_;
  return os;
}
