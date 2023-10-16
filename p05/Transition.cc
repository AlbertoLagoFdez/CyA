#include "Transition.h"

Transition::Transition(Simbol simbolo, Estado estado) {
  simbolo_ = simbolo;
  estado_ = estado; 
}

std::ostream &operator<<(std::ostream &os, Transition p) {
  os << "Simbolo que recibe: " << p.simbolo_ << "\t" << "Estado destino: q" << p.estado_.get_name();
  return os;
  // TODO: Insertar una instrucción "return" aquí
}
