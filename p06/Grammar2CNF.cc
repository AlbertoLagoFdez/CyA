#include "alphabet.h"
#include "symbol.h"
#include "grammar.h"
#include <iostream>
#include <sstream>
#include <fstream>

//Funcion Usage que muestra el modo de empleo del programa.
bool Usage(int argc,char* argv[]) {
    bool correctUse = true;
    if(argc > 3 || (argc < 3 && argc != 2)) {
      std::cout << "Modo de empleo: ./Grammar2CNF input.gra output.gra\n"
                   "Pruebe ./Grammar2CNF --help para mas informacion\n";
      correctUse = false;
    }
    if (argc < 3 && argc == 2) {
      std::cout << "Aqui iría el mensaje de ayuda de --help\n"
                   "Y la explicacion de todo\n"
                   "vamos loko vamos\n";
      correctUse = false;
    }
return correctUse;
}

bool CheckInputFileOpening(std::ifstream& file, std::string file_name) {
  bool right_opening {true};
  //Abrimos el fichero en nuestro stream.
  file.open(file_name);
  //Si no abre, apertura incorrecta.
  if (!file) {
    std::cout << "Error al abrir el fichero de entrada" << std::endl;
    right_opening = false;
  }
  return right_opening;
}

int main(int argc, char* argv[]) {
  if (Usage(argc, argv)) {
    std::ifstream grammar_inputfile;
    std::ofstream output;
    std::string file_name{argv[1]};
    std::string outputname{argv[2]};
    if(CheckInputFileOpening(grammar_inputfile, file_name)) {
      Grammar gramatica(grammar_inputfile);
      output.open(outputname);
      output << gramatica;
      output.close();
    }
  }
  return 0;
}