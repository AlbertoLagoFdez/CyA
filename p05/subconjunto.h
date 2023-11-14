#ifndef SUBCONJUNTO_H
#define SUBCONJUNTO_H

#include "node.h"
#include <set>

class Subconjunto {
  public:
    Subconjunto() {};
    Subconjunto(int name, std::set<Node> subconjunto);
    Subconjunto(Subconjunto& subconjunto);

    void setAceptance();

    int getName() const;
    std::set<Node> getSubconjunto() const;
    bool getAceptance() const;

  private:
    int name_;
    std::set<Node> subconjunto_;
    bool aceptance_;
};


#endif