#ifndef TOOLS_CC
#define TOOLS_CC
#include "Alphabet.h"
#include "Estado.h"
#include <iostream>
#include <fstream>

void Usage(int argc, char* argv[]){
  if(argc < 3){
    if(argc == 2) {
      std::string parameter = argv[1];
        if(parameter == "--help"){
        std::cout << " ";
        exit(EXIT_SUCCESS);
      }
    }
    else {
      std::cout<< "Modo de empleo: ./p05_automata_simulator input.fa input.txt \nPruebe ’p05_automata_simulator --help’ para más información." << std::endl;
      exit(EXIT_SUCCESS);
    }
  }
};

void lecturadeautomata(std::ifstream& input_file, Alphabet& alfabeto, int& numEstados, Estado& estadoArranque) {
  std::string linea;
  Estado a;
  //leer los simbolos
  getline(input_file, linea);
  for(long unsigned int i = 0; i < linea.length(); i++) {
    if(linea[i] != ' ') {
      Simbol a = linea[i];
      alfabeto.insert(a);
    }
  }
  getline(input_file, linea);
  numEstados = std::stoi(linea);
  getline(input_file, linea);
  estadoArranque = linea[0];
}

#endif