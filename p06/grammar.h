#ifndef GRAMMAR_H
#define GRAMMAR_H

#include "alphabet.h"
#include "symbol.h"
#include <map>
#include <sstream>
#include <vector>
#include <fstream>

class Grammar {
  public:
  Grammar() {};
  Grammar(std::ifstream& my_file);

  void print(std::ostream& os);

  void Grammar2CNF();

  friend std::ostream &operator<<(std::ostream &os, Grammar a);

  private:
    Alphabet terminals_;
    Alphabet non_terminals_;
    Symbol inicial_;
    std::multimap<Symbol, std::vector<Symbol>> production_;
};


#endif