// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con cadenas
// Autor: Alberto Lago Fernández
// Correo: alu0101562247@ull.edu.es
// Fecha: 23/09/2023
// Archivo alphabet.cc: Archivo con la definicion de los metodos de la clase alphabet
// Referencias:
// Enlaces de interés
// Historial de revisiones
// 13/11/2023 - Creación del código

#include "alphabet.h"

/// @brief constructor de la clase
/// @param alphabet 
Alphabet::Alphabet(std::set<Symbol> alphabet) {
  alphabet_ = alphabet;
}

/// @brief constructor de copia de la clase
/// @param alphabet 
Alphabet::Alphabet(Alphabet &alphabet) {
  alphabet_ = alphabet.getAlphabet();
}

/// @brief funcion para insertar elementos
/// @param symbol 
void Alphabet::insert(Symbol &symbol) {
  alphabet_.insert(symbol);
}

/// @brief funcion print
void Alphabet::print() const {
  for(auto itr = alphabet_.begin(); itr != alphabet_.end(); itr++) {
    std::cout << (*itr).getChar() << std::endl;
  }
}

/// @brief funcion que comprueba que un symbolo esta en el alfabeto
/// @param symbol 
/// @return 
bool Alphabet::isOnAlphabet(Symbol& symbol) const {
  if(alphabet_.count(symbol)==0) {
    return false;
  } else {
    return true;
  }
}

/// @brief funcion que devuelve el tamaño del alfabeto
/// @return 
long unsigned int Alphabet::size() const
{
  return alphabet_.size();
}

/// @brief getter del atributo alphabet_
/// @return 
std::set<Symbol> Alphabet::getAlphabet() const
{
  return alphabet_;
}

/// @brief funcion para devolver un simbolo del alfabeto
/// @param itr 
/// @return 
const Symbol Alphabet::GetSymbol(std::set<Symbol>::iterator itr) {
  Symbol symbol(*itr); //*itr para acceder al contenido del iterador
  return symbol;
}

/// @brief Getter del iterador con la posicion de inicio del lenguaje. 
/// @return 
std::set<Symbol>::iterator Alphabet::begin() const {
  std::set<Symbol>::iterator itr = alphabet_.begin();
  return itr;
}

/// @brief Getter del iterador con la posicion del final del lenguaje.
/// @return 
std::set<Symbol>::iterator Alphabet::end() const {
  std::set<Symbol>::iterator itr = alphabet_.end();
  return itr; 
}

/// @brief funcion que comprueba si un simbolo esta en el alfabeto, de otra forma (no tiene sentido pero queria probar maneras)
/// @param symbol 
/// @return 
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

/// @brief sobrecarga del operador de salida
/// @param os 
/// @param alphabet 
/// @return 
std::ostream& operator<<(std::ostream& os, Alphabet& alphabet) {
  alphabet.print();
  return os;
}
