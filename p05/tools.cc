#ifndef TOOLS_CC
#define TOOLS_CC
#include "Alphabet.h"
#include "Estado.h"
#include "Automata.h"
#include <iostream>
#include <fstream>

void Usage(int argc, char* argv[]){
  if(argc < 3){
    if(argc == 2) {
      std::string parameter = argv[1];
        if(parameter == "--help"){
        std::cout << "Introduzca en la primera linea el lenguaje regular.\n"  
                  << "En la siguiente linea el numero de estados.\n"
                  << "En la siguiente linea el estado de arranque.\n"
                  << "Y en las siguientes lineas introduzca:\n"
                  << "El estado, si es de aceptación, el número de transiciones, y las transiciones, con el simbolo que reciben y el estado de destino.\n";
        exit(EXIT_SUCCESS);
      }
    }
    else {
      std::cout<< "Modo de empleo: ./p05_automata_simulator input.fa input.txt \nPruebe ’p05_automata_simulator --help’ para más información." << std::endl;
      exit(EXIT_SUCCESS);
    }
  }
};

void lecturadearchivo(std::ifstream& input_file, Automata& automata) {
  std::string linea;
  Estado b;
  Alphabet alfabeto;
  int numEstados;
  Estado estadoInicial;
  //leer los simbolos
  getline(input_file, linea);
  for(long unsigned int i = 0; i < linea.length(); i++) {
    if(linea[i] != ' ') {
      char a = linea[i];
      alfabeto.insert(a);
    }
  }
  getline(input_file, linea);
  numEstados = std::stoi(linea);
  automata.Insertar_num_estados(numEstados);
  getline(input_file, linea);
  estadoInicial = linea[0];
  automata.Definir_arranque(estadoInicial);
  while(getline(input_file,linea)) {
    Estado q = linea[0];
    q.Set_aceptacion(linea[2]-'0');
    q.Set_numero_transiciones(linea[4]);
    for(long unsigned int i = 6; i <= linea.length(); i+=4) {
      Transicion transicion(linea[i], linea[i+2]);
      automata.Insert(q, transicion);
    }
  }
}

#endif