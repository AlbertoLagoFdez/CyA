// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con cadenas
// Autor: Alberto Lago Fernández
// Correo: alu0101562247@ull.edu.es
// Fecha: 13/11/2023
// Archivo turingmachine.h: Archivo con la declaracion de la clase turingmachine.
// Contiene la declaración de la clase turing machine
// Referencias:
// Enlaces de interés
// Historial de revisiones
// 13/11/2023 - Creación del código

#ifndef TURINGMACHINE_H
#define TURINGMACHINE_H

#include "alphabet.h"
#include "symbol.h"
#include "state.h"
#include <set>
#include <map>
#include <sstream>
#include <vector>
#include <fstream>
#include <cctype>
#include <algorithm>

class TuringMachine {
public:
  TuringMachine() {};
  TuringMachine(std::ifstream& my_file);
  
  void isAMovement(char& move);
  void isAState(State& state, int& numStates);

  void simulateTuringMachine(std::ifstream& my_file);
  void move(State& actualState, long unsigned int& pointer);
  bool areMoreTransitions(State& actualState, long unsigned int& pointer);
  bool isAccepted(State& state);

private:
  State initialState_;
  std::set<State> acceptStates_;
  std::set<State> states_;
  Alphabet tapeAlphabet_;
  std::vector<Symbol> tape_;
  std::multimap<State, std::pair<std::pair<Symbol, Symbol>, std::pair<char, State>>> transitions_;
  
};


#endif