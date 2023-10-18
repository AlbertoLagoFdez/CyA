// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Pr´actica 5: Implementacios de un simulador de automatas finitos
// Autor: Alberto Lago Fernández
// Correo: alu562247@ull.edu.es
// Fecha: 16/10/2023
// Archivo cya-P05-automata-simulator
// Contiene la función main del proyecto.
// Para hacer un automata finito
// 17/09/2023 - Creación (primera versión) del código
#include "tools.cc"
#include "Alphabet.h"
#include "Estado.h"
#include "Automata.h"
#include <iostream>
#include <fstream>


int main(int argc, char* argv[]) {
  Usage(argc, argv);
  std::ifstream input_file1(argv[1]);
  
  Automata automata;
 
  lecturadearchivo(input_file1, automata);
  std::ifstream input_file2(argv[2]);
  automata.Estados_de_muerte();
  std::ifstream archivo_cadenas(argv[2]);
  std::string cadena;
  Estado estado_actual;
  std::map<char, Estado> mapa_aceptacion;
  while(getline(archivo_cadenas, cadena)) {
    for(long unsigned int i = 0; i < cadena.length(); i++) {
     if(automata.Search_multimap(estado_actual, cadena[i]) == true) {
      estado_actual = automata.Get_estado_destino(estado_actual, cadena[i]);
      }
    }
  std::cout << cadena;
    estado_actual.Get_Aceptacion() ? std::cout <<" --- Accepted\n" : std::cout << " --- Rejected\n";
    estado_actual = automata.Get_arranque();
  }
  return 0;
}
