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
#ifndef ESTADO_H
#define ESTADO_H
#include <vector>
#include <map>
#include <iostream>

class Estado {

public:
  Estado(char nombre, bool aceptacion, int numero_transiciones, std::vector<char> transiciones);
  Estado(char nombre) {nombre_ = nombre;}
  Estado(){}
  void Set_aceptacion(char num) {num == 1? aceptacion_ = true : aceptacion_ = false;}
  void Set_nombre(char nombre) {nombre_ = nombre;}
  void Set_numero_transiciones(int num) {numero_transiciones_ = num;}
  bool Get_Aceptacion(){return aceptacion_;}
  int Get_numero_transiciones(){return numero_transiciones_;}
  //std::vector<char> Get_vector_transiciones(){return transiciones_;}
  //void Set_vector_transicion(std::vector<char> v) {transiciones_ = v;}
  //void Insertar_transicion(char);
  friend std::ostream &operator<<(std::ostream &os, Estado p);
  void Imprimir_vector();
  char Get_nombre(){return nombre_;}
  bool operator<(Estado const &e) const;
  bool operator==(Estado p) const;
private:
char nombre_;
bool aceptacion_;
int numero_transiciones_;
//std::vector<char> transiciones_
};
//std::multimap<Estado, char> Get_multimap_transiciones() {return multimap_transiciones_;}
//std::multimap<Estado, char> multimap_transiciones_;

#endif //ESTADO_H