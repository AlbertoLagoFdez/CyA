// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con cadenas
// Autor: Alberto Lago Fernández
// Correo: alu0101562247@ull.edu.es
// Fecha: 13/11/2023
// Archivo TMsimulator.cc: Archivo con la función principal.
// Contiene el funcionamiento de la simulación de un automata
// Referencias:
// Enlaces de interés
// Historial de revisiones
// 13/11/2023 - Creación del código

#include "symbol.h"
#include "state.h"
#include "alphabet.h"
#include "turingmachine.h"
#include "tools.cc"
#include <iostream>

int main(int argc, char* argv[]) {
  CheckParameters(argc,argv);
  std::ifstream TuringMachine_input;
  std::string file_name{argv[1]};
  CheckInputFileOpening(TuringMachine_input, file_name);
  TuringMachine machine(TuringMachine_input);
  std::ifstream Tape_input;
  std::string file_name1{argv[2]};
  CheckInputFileOpening(Tape_input,file_name1);
  machine.simulateTuringMachine(Tape_input);
  return 0;
}