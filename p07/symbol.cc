// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con cadenas
// Autor: Alberto Lago Fernández
// Correo: alu0101562247@ull.edu.es
// Fecha: 23/09/2023
// Archivo alphabet.cc: Archivo con la deficion de los metodos de la clase symbol.
// Contiene la declaración de la clase symbol
// Referencias:
// Enlaces de interés
// Historial de revisiones
// 23/09/2023 - Creación del código

#include "symbol.h"

/// @brief Constructor de la clase symbol
/// @param symbol 
Symbol::Symbol(char symbol) {
  symbol_ = symbol;
}

/// @brief getter de la clase symbol
/// @return symbol_ 
const char Symbol::getChar() const {
  return symbol_;
}

/// @brief Sobrecargar del operador <
/// @param symbol 
/// @return bool
bool Symbol::operator<(const Symbol &symbol) const {
  return symbol_ < symbol.getChar();
}

/// @brief sobrecarga del operador de igualdad '=='
/// @param a 
/// @param b 
/// @return bool
const bool operator==(Symbol& a, Symbol& b) {
  return a.getChar() == b.getChar();
}

/// @brief Sobrecarga del operador de salida
/// @param os 
/// @param a 
/// @return os
std::ostream &operator<<(std::ostream &os, Symbol a)
{
  os << a.getChar();
  return os;
}
