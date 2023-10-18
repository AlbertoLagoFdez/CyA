#ifndef TOOLS_CC
#define TOOLS_CC
#include <iostream>

void Usage(int argc, char* argv[]){
  if(argc < 4){
    if(argc == 2) {
      std::string parameter = argv[1];
        if(parameter == "--help"){
        std::cout << "El programa realiza una serie de operaciones.\nPara usarlo tienes que pasar por linea de comandos el nombre del fichero de entrada, el nombre del de salida y además la operación que deseamos realizar."
        << "\nSiendo los opcodes:"
        << "\n 1. Escribir el alfabeto asiciado a la cadena."
        << "\n 2. Escribir la longitud de la cadena."
        << "\n 3. Escribir la cadena inversa."
        << "\n 4. Escribir todos los prefijos de cada cadena."
        << "\n 5. Escribir todos los sufijos de cada cadena.\n";
        exit(EXIT_SUCCESS);
      }
    }
    else {
      std::cout<< "Modo de empleo: 1 ./ p02_strings filein.txt fileout.txt opcode \nPruebe ’./p02_strings --help’ para más informacion." << std::endl;
      exit(EXIT_SUCCESS);
    }
  }

};


#endif