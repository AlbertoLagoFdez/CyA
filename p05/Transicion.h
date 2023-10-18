// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Pr´actica 5: Implementacios de un simulador de automatas finitos
// Autor: Adrián Manuel Acuña Perdomo
// Correo: alu0101592084@ull.edu.es
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
#ifndef TRANSICION_HPP_
#define TRANSICION_HPP_
#include "Estado.h"

class Transicion {
public:
  Transicion(){}
  Transicion(char simbolo, Estado estado) {simbolo_= simbolo; estado_ = estado;}
  void Set_simbolo(char a) {simbolo_ = a;}
  void Set_estado(Estado a) {estado_ = a;}
  char Get_simbolo() {return simbolo_;}
  Estado Get_estado() {return estado_;}
  void imprimir();
  friend std::ostream &operator<<(std::ostream &os, Transicion t);
private:
  char simbolo_;
  Estado estado_;
};

#endif //TRANSICION_HPP_