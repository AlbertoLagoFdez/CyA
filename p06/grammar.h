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

  private:
    Alphabet terminales_;
    Alphabet no_terminales_;
    Symbol inicial_;
    std::multimap<Symbol, std::vector<Symbol>> produccion_;
};

#endif