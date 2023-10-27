#include "grammar.h"

Grammar::Grammar(std::ifstream &my_file) {
  int numOfTerminals, numOfNonTerminales, numOfProductions;
  std::string line;
  getline(my_file, line);
  numOfTerminals = std::stoi(line);
  for(int i = 0; i < numOfTerminals ; i++) {
    getline(my_file, line);
    Symbol simbolo = line[0];
    terminals_.insert(simbolo);
  }
  //std::cout << "Conjunto de terminales: " << terminals_ << std::endl;
  getline(my_file,line);
  numOfNonTerminales = std::stoi(line);
  for(int i = 0; i < numOfNonTerminales ; i++) {
    getline(my_file, line);
    if(i == 0) inicial_ = line[0];
    Symbol simbolo = line[0];
    non_terminals_.insert(simbolo);
  }
  //std::cout << inicial_ << std::endl;
  //std::cout << "Conjunto de no terminales: " << non_terminals_ << std::endl;
  getline(my_file, line);
  numOfProductions = std::stoi(line);
  for(int i = 0 ; i < numOfProductions ; i++) {
    getline(my_file, line);
    Symbol noTerminal, symbolOfvector;
    std::vector<Symbol> vectorOfSymbols;
    noTerminal = line[0];
    for(long unsigned int j = 2; j < line.size(); j++) {
      symbolOfvector = line[j];
      vectorOfSymbols.emplace_back(symbolOfvector);
    }
    //std::pair<Symbol, std::vector<Symbol>> pair(noTerminal, vectorOfSymbols);
    production_.emplace(noTerminal, vectorOfSymbols);
  }
}

void Grammar::print(std::ostream& os) {
  os << terminals_.size() << std::endl;
  os << terminals_;
  os << non_terminals_.size() << std::endl;
  os << non_terminals_;
  os << production_.size() << std::endl;
  for( auto itr = production_.begin(); itr != production_.end() ; itr++) {
    os << itr->first << ' ';
    for(long unsigned int i = 0; i < itr->second.size(); i++) {
      os << itr->second[i];
    }
    os << std::endl;
  }
}

void Grammar::Grammar2CNF() {
  
}

std::ostream &operator<<(std::ostream &os, Grammar a) {
  a.print(os);
  return os;
}
