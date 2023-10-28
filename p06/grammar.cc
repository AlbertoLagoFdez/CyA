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

std::multimap<Symbol, std::vector<Symbol>>::const_iterator Grammar::find(const Symbol &symbol) const {
  std::multimap<Symbol, std::vector<Symbol>>::const_iterator found = production_.find(symbol);
  return found;
}


void printvectordesimbolos(std::vector<Symbol>& s) {
  for(long unsigned int i = 0 ; i < s.size() ; i++) {
    std::cout << s[i];
  }
}

//Algoritmo
/*
for all (A → X1X2 . . . Xn (con n ≥ 2, Xi ∈ (Σ ∪ V )) do
  for all (Xi) do
    if (Xi = a ∈ Σ) then
      Add the production Ca → a;
      Replace Xi with Ca in A → X1X2 . . . Xn;
    end if
  end for
end for
for all (A → B1B2 . . . Bm (con m ≥ 3, Bi ∈ V ) do
  Add m − 2 non-terminal symbols D1D2 . . . Dm−2;
  Replace the production A → B1B2 . . . Bm with productions:
    A → B1D1
    D1 → B2D2
    . . .
    Dm−2 → Bm−1Bm
end for
*/
void Grammar::Grammar2CNF() {
  //for para recorrer los simbolos no terminales.
  for(std::set<Symbol>::iterator itr = non_terminals_.begin(); itr != non_terminals_.end(); itr++) {
    //Buscar cada simbolo no terminal para recorrer 
    std::multimap<Symbol, std::vector<Symbol>>::const_iterator itrmap = production_.find(*itr);
    for( ; ; ) {
      
    }
  }
}

std::ostream &operator<<(std::ostream &os, Grammar a) {
  a.print(os);
  return os;
}
