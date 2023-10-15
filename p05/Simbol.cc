#include "Simbol.h"
#include <iostream>

Simbol::Simbol(char simbol) {
  simbol_ = simbol;
}

void Simbol::print() {
  std::cout << simbol_;
}

bool Simbol::operator<(Simbol const &e) const
{
  return simbol_ < e.simbol_ || simbol_ == e.simbol_;
}
//return chain_.length() < e.chain_.length() || chain_.length() == e.chain_.length() ;

std::ostream &operator<<(std::ostream &os, Simbol p)
{
  os << p.simbol_;
  return os; 
  // TODO: Insertar una instrucción "return" aquí
}
