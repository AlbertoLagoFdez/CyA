// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con cadenas
// Autor: Alberto Lago Fernández
// Correo: alu0101562247@ull.edu.es
// Fecha: 23/09/2023
// Archivo tools.cc: Archivo con la definicion de los metodos utilizados en TMsimulator.cc
// Referencias:
// Enlaces de interés
// Historial de revisiones
// 13/11/2023 - Creación del código

#include <iostream>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

//Funcion Usage que muestra el modo de empleo del programa.
void Usage() {
  std::cerr << "Modo de empleo: ./TMsimulator input.tm output.tape\n"
               "Pruebe ./TMsimulator --help para mas informacion\n";
}

/// @brief funcion que muestra la ayuda de programa
void Help() {
  std::cout << "El programa recive un fichero de entrada como primer parametro, este fichero tendrá la definición del automata\n"
               "Este primer fichero sigue la siguiente estructura:\n"
               "Línea 1: Símbolos del alfabeto separados por espacios.\n"
               "Línea 2: Número total de estados del automata\n"
               "Línea 3: Estado de arranque del automata\n"
               "A continuación figurará una línea para cada uno de los estados. Cada línea contendrá los siguientes números, separados entre sí por espacios en blanco:\n"
               "Número identificador del estado. Los estados del autómata se representarán mediante números naturales.\n" << "La numeración de los estados corresponderá a los primeros números comenzando en 0.\n"
               "Un 1 si se trata de un estado de aceptación y un 0 en caso contrario.\n"
               "Número de transiciones que posee el estado\n"
               "A continuación, para cada una de las transiciones, y utilizando espacios en blanco como separadores \n" << "se detallará la información siguiente:\n"
               "Símbolo de entrada necesario para que se produzca la transición. \n" << "Para representar la cadena vacía (el no consumir símbolo de la entrada) se utilizará el carácter &\n"
               "Estado destino de la transición.\n"
               "El programa transformara el NFA dado en un DFA y colocará su descripción en el archivo de texto output.dfa\n";
}

/// @brief funcion que comprueba los parametros pasados por terminal
/// @param argc 
/// @param argv 
void CheckParameters(int& argc, char* argv[]) {
  //Si hay mas de 4 parametros, es incorrecto.
  if (argc > 3) {
    Usage();
    exit(EXIT_FAILURE);
  }
  //Si hay 2 parametros y coincide con --help, mostramos la ayuda.
  if (argc < 3 && argc == 2) {
    std::string key_word{argv[1]};
    if (key_word == "--help") {
        Help();
        exit(EXIT_FAILURE);
    }
  }
  //Si hay menos de 3 parametros y no hay 2, uso incorrecto.
  if (argc < 3) {
    Usage();
    exit(EXIT_FAILURE);
  }
}



void CheckInputFileOpening(std::ifstream& file, std::string file_name) {
  //bool right_opening {true};
  //Abrimos el fichero en nuestro stream.
  file.open(file_name);
  //Si no abre, apertura incorrecta.
  if (!file) {
    std::cerr << "Error al abrir el fichero de entrada" << std::endl;
    //right_opening = false;
    exit(EXIT_FAILURE);
  }
}