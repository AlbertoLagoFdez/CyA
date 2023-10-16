#ifndef AUTOMATA_H
#define AUTOMATA_H
#include "Simbol.h"
#include "Estado.h"
#include "Transition.h"
#include <iostream>
#include <map>

class Automata {
public:
Automata() {};
// void ComprobarCadena();
private:
  std::multimap<Estado, Transition> automata_;
  Estado estadoArranque;
};


#endif