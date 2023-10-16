#include "tools.cc"
#include "Simbol.h"
#include "Alphabet.h"
#include "Chain.h"
#include "Estado.h"
#include "Transition.h"
#include <iostream>
#include <fstream>


int main(int argc, char* argv[]) {
  Usage(argc, argv);
  std::ifstream input_file(argv[1]);
  Alphabet alfabeto;
  int numEstados;
  Estado estadoArranque;
  lecturadeautomata(input_file, alfabeto, numEstados, estadoArranque);
  std::cout << alfabeto << std::endl;
  std::cout << "El numero de estados es: " << numEstados << std::endl;
  std::cout << "El estado de arranque es: q" << estadoArranque.get_name() << std::endl;
  return 0;
}
