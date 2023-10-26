#include "alphabet.h"

Alphabet::Alphabet(std::set<Symbol> alphabet) {
  alphabet_ = alphabet;
}

Alphabet::Alphabet(Alphabet &alphabet) {
  alphabet_ = alphabet.getAlphabet();
}

void Alphabet::insert(Symbol &symbol) {
  alphabet_.insert(symbol);
}

void Alphabet::print() const {
  std::cout << "{";
  for(auto itr = alphabet_.begin(); itr != alphabet_.end(); itr++) {
    std::cout << (*itr).getChar() << ',';
  }
  std::cout << "\b}";
}

long unsigned int Alphabet::size() const
{
  return alphabet_.size();
}

std::set<Symbol> Alphabet::getAlphabet() const
{
  return alphabet_;
}

const Symbol Alphabet::GetSymbol(std::set<Symbol>::iterator itr) {
  Symbol symbol(*itr); //*itr para acceder al contenido del iterador
  return symbol;
}

//Getter del iterador con la posicion de inicio del lenguaje.
auto Alphabet::Begin() const {
  auto itr = alphabet_.begin();
  return itr;
}

//Getter del iterador con la posicion del final del leguaje.
auto Alphabet::End() const {
  auto itr = alphabet_.end();
  return itr; 
}

bool Alphabet::IsInAlphabet(Symbol &symbol)
{
  bool in_language = false;
  for(auto i = alphabet_.begin(); i != alphabet_.end(); ++i) {
    Symbol aux_symbol(*i);
    if (symbol == aux_symbol) {
      in_language = true;
    }
  }
  return in_language;
}

std::ostream& operator<<(std::ostream& os, Alphabet& alphabet) {
  alphabet.print();
  return os;
}
