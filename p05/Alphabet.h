#ifndef ALPHABET_H
#define ALPHABET_H
#include "Simbol.h"
#include <iostream>
#include <iterator>
#include <set>

class Alphabet {
  public:
    Alphabet() {  };
    Alphabet(std::set<Simbol> alphabet);
    void insert(Simbol c);
    void print();
    friend std::ostream &operator<<(std::ostream &os, Alphabet p);
  private:
    std::set<Simbol> alphabet_;
};



#endif