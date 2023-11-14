// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con cadenas
// Autor: Alberto Lago Fernández
// Correo: alu0101562247@ull.edu.es
// Fecha: 23/09/2023
// Archivo alphabet.cc: Archivo con la deficion de los metodos de la clase alphabet.
// Contiene la declaración de la clase alphabet
// Referencias:
// Enlaces de interés
// Historial de revisiones
// 23/09/2023 - Creación del código

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

void Alphabet::print(std::ostream& os) const {
  for(auto itr = alphabet_.begin(); itr != alphabet_.end(); itr++) {
    os << (*itr).getChar() << std::endl;
  }
}

//me va a decir si hay o no un simbolo en el set.
bool Alphabet::isOnAlphabet(Symbol& symbol) const {
  if(alphabet_.count(symbol)==0) {
    return false;
  } else {
    return true;
  }
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
std::set<Symbol>::iterator Alphabet::begin() const {
  std::set<Symbol>::iterator itr = alphabet_.begin();
  return itr;
}

//Getter del iterador con la posicion del final del leguaje.
std::set<Symbol>::iterator Alphabet::end() const {
  std::set<Symbol>::iterator itr = alphabet_.end();
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
  alphabet.print(os);
  return os;
}
