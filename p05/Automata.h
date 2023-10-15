#ifndef AUTOMATA_H
#define AUTOMATA_H
#include "Simbol.h"
#include <iostream>
#include <map>

class Automata {
public:
// void ComprobarCadena();
private:
  std::multimap<int, Simbol> automata_;
};


#endif