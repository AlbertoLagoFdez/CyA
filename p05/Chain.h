#ifndef CHAIN_H
#define CHAIN_H
#include "Simbol.h"
#include <iostream>
#include <vector>

class Chain {
  public:
    Chain() { };
    Chain(std::vector<Simbol> chain);
  private:
    std::vector<Simbol> chain_;
};

#endif