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
#include "Transicion.h"
#include<iostream>

void Transicion::imprimir() {
  std::cout << simbolo_ << estado_;
}

std::ostream &operator<<(std::ostream &os, Transicion t) {
  t.imprimir();
  return os;
}
