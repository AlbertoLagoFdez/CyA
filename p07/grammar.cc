#include "grammar.h"

/// @brief Constructor
/// @param my_file 
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

/// @brief Funcion que imprime una gramatica
/// @param os 
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

/// @brief Encuentra un symbol en la gramatica
/// @param symbol 
/// @return iterator
std::multimap<Symbol, std::vector<Symbol>>::const_iterator Grammar::find(const Symbol &symbol) const {
  std::multimap<Symbol, std::vector<Symbol>>::const_iterator found = production_.find(symbol);
  return found;
}

/// @brief genera un nuevo no terminal
/// @return Symbol
Symbol Grammar::generateNewNonTerminal() {
  int ascii = 84;
  Symbol nonTerminal = static_cast<char>(ascii);
  //std::cout << nonTerminal;
  //std::cout << ascii;
  while(non_terminals_.isOnAlphabet(nonTerminal) == true) {
    ascii++;
    nonTerminal = static_cast<char>(ascii);
  }
  non_terminals_.insert(nonTerminal);
  return nonTerminal;
}

/// @brief comprueba que no haya producciones unitarias o vacias
void Grammar::checkSingleProductions() {
  for(auto itr = production_.begin(); itr != production_.end(); itr++) {
    if(production_.count((*itr).first) == 1 && (*itr).second.size() && non_terminals_.isOnAlphabet((*itr).second[0])) {
      std::cerr << "No se puede transformar a la forma normal de Chomsky ya que posee producciones unitarias o vacias.";
      exit(EXIT_FAILURE);
    }
  }
}



/// @brief algoritmo que transforma una gramtica con CNF
void Grammar::Grammar2CNF() {
  checkSingleProductions();
  //PRIMERA PARTE DEL ALGORITMO QUE CREA NUEVAS PRODUCCION DE SIMBOLOS TERMINALES CUANDO LA PRODUCCION GENERA CADENAS DE MAS DE 2 DE SIZE.
  //for para recorrer los simbolos no terminales.
  for(std::set<Symbol>::iterator itr = non_terminals_.begin(); itr != non_terminals_.end(); itr++) {
    //Buscar cada simbolo no terminal para recorrer 
    //std::multimap<Symbol, std::vector<Symbol>>::const_iterator itrmap = production_.find(*itr);
    std::multimap<Symbol, std::vector<Symbol>>::iterator it, itlow, itup;
    itlow = production_.lower_bound(*itr);
    itup = production_.upper_bound(*itr);
    //Recorrer todos los vectores de la misma produccion
    for(it = itlow ; it != itup ; ++it) {
      if((*it).second.size() >= 2) {
        for(long unsigned int i = 0; i < (*it).second.size() ; i++) {
          if(terminals_.isOnAlphabet((*it).second[i])) {
            Symbol nuevaProduccion = toupper((*it).second[i].getChar()); //Buscar otra forma de llamar a la producción.
            std::vector<Symbol> nuevoVector;
            nuevoVector.emplace_back((*it).second[i]);
            if(production_.count(nuevaProduccion) == 0) {
              production_.emplace(nuevaProduccion, nuevoVector);
              non_terminals_.insert(nuevaProduccion);
            }
            (*it).second[i] = nuevaProduccion;
          }
        }
      }
    }
  }
  //SEGUNDA PARTE DEL ALGORITMO. 
  for(std::set<Symbol>::iterator itr = non_terminals_.begin(); itr != non_terminals_.end(); itr++) { 
    std::multimap<Symbol, std::vector<Symbol>>::iterator it, itlow, itup;
    itlow = production_.lower_bound(*itr);
    itup = production_.upper_bound(*itr);
    //Recorrer todos los vectores de la misma produccion
    for(it = itlow ; it != itup ; ++it) {
      if((*it).second.size() >= 3) {
        //non_terminals_.insert(nuevoSymbol);
        //std::cout << "Genero un nuevo symbol\n";
        Symbol nuevoSymbol = generateNewNonTerminal();  //Problema
        //std::cout << nuevoSymbol;
        std::vector<Symbol> nuevoVector;
        for(long unsigned int i = (*it).second.size(); i > 1 ; i--) {
          nuevoVector.emplace(nuevoVector.begin(), (*it).second.back());
          (*it).second.pop_back();
        }
        (*it).second.emplace_back(nuevoSymbol);
        production_.emplace(nuevoSymbol, nuevoVector);
      }
    }
    //std::cout << "Iterador de no terminales.\n";
  }
}

/// @brief Sobrecarga del oprador de salida
/// @param os 
/// @param a 
/// @return os
std::ostream &operator<<(std::ostream &os, Grammar& a) {
  a.print(os);
  return os;
}
