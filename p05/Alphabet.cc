#include "Alphabet.h"


Alphabet::Alphabet(std::set<Simbol> alphabet)
{
  alphabet_ = alphabet;
}

void Alphabet::insert(Simbol c) {
  alphabet_.insert(c);
}

void Alphabet::print() {
  std::cout << "{ ";
  std::set<Simbol>::iterator i;
  for(i = alphabet_.begin() ; i != alphabet_.end() ; i++) {
    std::cout << (*i);
    if(i != --alphabet_.end()) {
      std::cout << ", ";
    }
  }
  std::cout << " }";
}

std::ostream &operator<<(std::ostream &os, Alphabet p)
{
  os << "{ ";
  std::set<Simbol>::iterator i;
  for(i = p.alphabet_.begin() ; i != p.alphabet_.end() ; i++) {
    os << (*i);
    if(i != --p.alphabet_.end()) {
      os << ", ";
    }
  }
  os << " }";
  return os;
}
