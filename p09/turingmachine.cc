// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con cadenas
// Autor: Alberto Lago Fernández
// Correo: alu0101562247@ull.edu.es
// Fecha: 23/09/2023
// Archivo turingmachine.cc: Archivo con la definicion de los metodos de la clase turingmachine
// Referencias:
// Enlaces de interés
// Historial de revisiones
// 13/11/2023 - Creación del código

#include "turingmachine.h"

/// @brief constructor de la clase turingmachine
/// @param my_file 
TuringMachine::TuringMachine(std::ifstream &my_file) {
  int numOfState, numOfTransitions;
  State acceptState;
  std::string line;
  getline(my_file, line);
  numOfState = std::stoi(line);
  for(int i = 0; i <= numOfState - 1 ; i++) {
    State state(i);
    states_.insert(state);
  }
  getline(my_file, line);
  initialState_ = std::stoi(line);

  getline(my_file, line);
  line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end());
  for(long unsigned int i = 0; i < line.size(); i++) {
    acceptState = line[i] - '0';
    acceptStates_.insert(acceptState);
  }

  getline(my_file, line);
  numOfTransitions = std::stoi(line);
  State actualState, nextState;
  Symbol readSymbol, writeSymbol;
  char move;
  for(int i = 0; i < numOfTransitions; i++) {
    getline(my_file, line);
    line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end());
    actualState = line[0] - '0';
    isAState(actualState, numOfState);
    readSymbol = line[1];
    writeSymbol = line[2];
    move = line[3];
    isAMovement(move);
    nextState = line[4] - '0';
    isAState(nextState, numOfState);

    transitions_.emplace(actualState, std::pair<std::pair<Symbol, Symbol>, std::pair<char, State>>(std::pair<Symbol, Symbol>(readSymbol, writeSymbol), std::pair<char, State>(move, nextState)));
  }
}

/// @brief funcion que comprueba si un parametro leido en el constructor es un movimiento
/// @param move 
void TuringMachine::isAMovement(char &move) {
  bool result = false;
  if( move == 'R' || move == 'L' || move == 'S') result = true;
  if(result == false) {
    std::cerr << move << " no es un movimiento\n";
    exit(EXIT_FAILURE);
  }
}

void TuringMachine::isAState(State &state, int& numStates) {
  if(state.getId() < 0 || state.getId() >= numStates) {
    std::cerr << state << " no es un estado\n";
    exit(EXIT_FAILURE);
  }
}

/// @brief funcion que simula una cinta con la maquina 
/// @param my_file 
void TuringMachine::simulateTuringMachine(std::ifstream &my_file) {
  std::string line;
  Symbol symbol;
  Symbol white{'$'};
  getline(my_file, line);
  tape_.push_back(white);
  for(long unsigned int i = 0; i < line.size(); i++) {
    symbol = line[i];
    tape_.push_back(symbol);
  }
  tape_.push_back(white);
  long unsigned int pointer{1};
  State actualState{initialState_};
  while(true) {
    for(long unsigned int i = 0; i < tape_.size(); i++) {
      if(pointer == i) std::cout << ' ' << actualState << ' ';
      std::cout << tape_[i];
    }
    std::cout << std::endl;
    if(!areMoreTransitions(actualState, pointer)) break;
    move(actualState, pointer);
  }
  if(isAccepted(actualState)) std::cout << "cadena ACEPTADA" << std::endl;
  else std::cout << "cadena RECHAZADA" << std::endl;
}

/// @brief funcion que realiza un moviento
/// @param actualState 
/// @param pointer 
void TuringMachine::move(State& actualState, long unsigned int& pointer) {
  Symbol white{'$'};
  auto itlow = transitions_.lower_bound(actualState);
  auto itup = transitions_.upper_bound(actualState);
  for(auto it = itlow; it != itup ; it++) {
    if( (*it).second.first.first == tape_[pointer] ) {
      std::cout << "\a";
      tape_[pointer] = (*it).second.first.second;
      if((*it).second.second.first == 'R') pointer++;
      if((*it).second.second.first == 'L') pointer--;
      if(pointer <= 0) {
        tape_.insert(tape_.begin(), white);
        pointer++;
      }
      if(pointer >= tape_.size()) {
        tape_.push_back(white);
        pointer--;
      }
      actualState = (*it).second.second.second; 
      break;
    }
  }

}

bool TuringMachine::areMoreTransitions(State &actualState, long unsigned int &pointer) {
  bool result = false;
  for(auto itr = transitions_.lower_bound(actualState); itr != transitions_.upper_bound(actualState); ++itr) {
    if( (*itr).second.first.first == tape_[pointer] ) result = true;
  }
  return result;
}

bool TuringMachine::isAccepted(State &state) {
  bool result = false;
  if(acceptStates_.count(state) != 0) result = true;
  return result;
}

/*
  for(auto itr = states_.begin(); itr != states_.end(); itr++) {
    std::cout << (*itr);
  }
  std::cout << std::endl;
*/