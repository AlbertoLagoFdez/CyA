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
#include "Automata.h"
#include <iostream>
#include <algorithm>
#include <iterator>
/*
void Automata::Insertar_transicion(std::string nombre, char a) {
  multimap_transiciones_.insert(std::pair<std::string, char>(nombre, a));
}
*/
std::ostream &operator<<(std::ostream &os, Automata p) {
  os << "El numero de estados es: " << p.Get_num_estados() << std::endl;
  os << "El estado de arranque es: q" << p.Get_arranque() << std::endl;
  for(auto itr = p.multimap_.begin(); itr != p.multimap_.end(); ++itr) {
    os << "estado: " << itr->first << " transicion: " << itr->second << "\n";
  }
  return os;
}

bool Automata::Search_multimap(Estado estado, char a) {
  for(auto itr = multimap_.begin(); itr != multimap_.end(); itr++) {
      if(itr->first == estado && itr->second.Get_simbolo() == a) {
        return true;
      }
  }
  return false;
}
Estado Automata::Get_estado_destino(Estado estado, char a) {
  for(auto itr = multimap_.begin(); itr != multimap_.end(); ++itr) {
      if(itr->first == estado && itr->second.Get_simbolo() == a) {
        return itr->second.Get_estado();
      }
  }
  return Estado();
}

void Automata::Estados_de_muerte() {
  for(auto itr = multimap_.begin(); itr != multimap_.end(); itr++) {
    if(itr->second.Get_estado() == (itr++)->second.Get_estado()) {
      std::cout << "estado: " << itr->first << " transicion: " << itr->second << "\n";
      std::cout << "estado: " << itr++->first << " transicion: " << itr++->second << "\n";
      std::cout << "Estado de muerte." << std::endl;
    }
  }
}