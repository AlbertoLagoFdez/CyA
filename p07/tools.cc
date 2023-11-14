// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con cadenas
// Autor: Alberto Lago Fernández
// Correo: alu0101562247@ull.edu.es
// Fecha: 23/09/2023
// Archivo tools.cc: declaracion de las funciones que se utilizan en el archivo principal.
// Contiene funciones utilizas en el main.
// Referencias:
// Enlaces de interés
// Historial de revisiones
// 23/09/2023 - Creación del código

#include <iostream>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>


/// @brief funcion que muestra el funcionamiento del programa
void Usage() {
  std::cerr << "Modo de empleo: ./Grammar2CNF input.gra output.gra\n"
               "Pruebe ./Grammar2CNF --help para mas informacion\n";
}

/// @brief funcion que muestra un mensaje de ayuda.
void Help() {
  std::cout << "El programa recive un fichero de entrada como primer parametro, este fichero tendrá la definición de la gramatica: \n"
               "La primera linea debera contener el numero de terminales, seguido de los terminales linea por linea.\n"
               "la siguiente linea debera contener el numero de no terminal, y seguido los no terminales linea por linea.\n"
               "y la linea a continuacion, debera contener el numero de producciones de la gramatica.\n"
               "Y debera escribir la producciones de la siguiente forma.\n"
               "P aXbY\n";
}


/// @brief funcion que comprueba los parametros de entrada
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

/// @brief funcion que comprueba que el archivo de entrada se abre correctamente
/// @param file 
/// @param file_name 
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