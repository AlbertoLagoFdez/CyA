// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con cadenas
// Autor: Alberto Lago Fernández
// Correo: alu0101562247@ull.edu.es
// Fecha: 23/09/2023
// Archivo state.cc: Archivo con la definicion de los metodos de la clase state
// Referencias:
// Enlaces de interés
// Historial de revisiones
// 13/11/2023 - Creación del código

#include "state.h"

/// @brief constructor de la clase
/// @param id 
State::State(int id) {
  id_ = id;
}

/// @brief constructor de copia de la clase
/// @param state 
State::State(const State &state) {
  id_ = state.id_;
}

/// @brief getter del atributo id_
/// @return 
int State::getId() const
{
  return id_;
}

/// @brief funcion print
void State::print() const
{
  std::cout << "q" << id_;
}

/// @brief sobrecarga del operador de <
/// @param state 
/// @return 
bool State::operator<(const State &state) const {
  return id_ < state.getId();
}

/// @brief sobrecarga del operador de salida
/// @param os 
/// @param n 
/// @return 
std::ostream &operator<<(std::ostream &os, const State &n)
{
  n.print();
  return os;
}

/// @brief sobrecarga del operador de igualdad
/// @param a 
/// @param b 
/// @return 
const bool operator==(State &a, State &b)
{
  return a.getId() == b.getId();
}
