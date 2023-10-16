#include "Estado.h"

Estado::Estado(char name) {
  name_ = name;
  acept_ = false;
  numTransitions_ = 0;
}

void Estado::set_acept(bool acept) {
  acept_ = acept;
}

void Estado::set_numTransitions(int numTransiotion) {
  numTransitions_ = numTransiotion;
}

char Estado::get_name() const
{
  return name_;
}

std::ostream &operator<<(std::ostream &os, Estado p)
{
  os << "q" << p.name_ << std::endl;
  if (p.acept_ == true) {
    os << "Estado de aceptación." << std::endl;
  } else {
    os << "Estado de rechazo. " << std::endl;
  }
  os << "Número de transiciones: " << p.numTransitions_ << std::endl;
  return os;
}
