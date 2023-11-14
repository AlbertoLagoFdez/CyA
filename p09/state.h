// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con cadenas
// Autor: Alberto Lago Fernández
// Correo: alu0101562247@ull.edu.es
// Fecha: 23/09/2023
// Archivo state.h: Archivo con la declaracion de la clase state.
// Contiene la declaración de la clase state
// Referencias:
// Enlaces de interés
// Historial de revisiones
// 13/11/2023 - Creación del código

#ifndef STATE_H
#define STATE_H

#include <iostream>

class State {
public:
  State() {};
  State(int id);
  State(const State& state);

  int getId() const;
  void print() const;
  
  bool operator<(const State& state) const;
  friend std::ostream &operator<<(std::ostream&os, const State& n);
private:
  int id_;
};

const bool operator==(State& a, State& b);

#endif