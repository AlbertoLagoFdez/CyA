#ifndef TRANSITION_H
#define TRANSITION_H
#include "Simbol.h"
#include "Estado.h"

class Transition {
public:
  Transition() {};
  Transition(Simbol simbolo, Estado estado);
  friend std::ostream &operator<<(std::ostream &os, Transition p);
private:
  Simbol simbolo_;
  Estado estado_;
};


#endif