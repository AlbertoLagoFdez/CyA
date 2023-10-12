#ifndef TOOLS_CC
#define TOOLS_CC
#include <iostream>

void Usage(int argc, char* argv[]){
  if(argc < 4){
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


#endif