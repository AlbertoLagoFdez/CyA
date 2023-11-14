#include "subconjunto.h"

Subconjunto::Subconjunto(int name, std::set<Node> subconjunto) {
  name_ = name;
  subconjunto_ = subconjunto;
  setAceptance();
}

Subconjunto::Subconjunto(Subconjunto& subconjunto) {
  name_ = subconjunto.getName();
  subconjunto_ = subconjunto.getSubconjunto();
  aceptance_ = subconjunto.getAceptance();
}

void Subconjunto::setAceptance() {
  aceptance_ = false;
  for(auto itr = subconjunto_.begin() ; itr != subconjunto_.end(); ++itr) {
    if((*itr).GetType() == true) {
      aceptance_ = true;
    }
  }
}

int Subconjunto::getName() const {
  return name_;
}

std::set<Node> Subconjunto::getSubconjunto() const
{
  return subconjunto_;
}

bool Subconjunto::getAceptance() const
{
  return aceptance_;
}
