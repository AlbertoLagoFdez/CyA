#include "grammar.h"

Grammar::Grammar(std::ifstream &my_file) {
  int numOfTerminals;
  std::string line;
  getline(my_file, line);
  numOfTerminals = std::stoi(line);
  for(int i = 0; i < numOfTerminals ; i++) {
    getline(my_file, line);
    Symbol simbolo = line[0];
    terminales_.insert(simbolo);
  }
  std::cout << terminales_ << std::endl;
}