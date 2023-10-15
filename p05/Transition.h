#ifndef TRANSITION_H
#define TRANSITION_H
#include "Simbol.h"
#include "Estado.h"

class Transition {
private:
  Transition() {};
  Transition(Simbol simbolo, Estado estado);
public:
  std::pair<Simbol,Estado> transition_;
};


#endif