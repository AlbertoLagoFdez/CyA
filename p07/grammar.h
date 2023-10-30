// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con cadenas
// Autor: Alberto Lago Fernández
// Correo: alu0101562247@ull.edu.es
// Fecha: 23/09/2023
// Archivo grammar.h: Archivo con la declaracion de la clase grammar.
// Contiene la declaración de la clase symbol
// Referencias:
// Enlaces de interés
// Historial de revisiones
// 23/09/2023 - Creación del código

#ifndef GRAMMAR_H
#define GRAMMAR_H

#include "alphabet.h"
#include "symbol.h"
#include <map>
#include <sstream>
#include <vector>
#include <fstream>

class Grammar {
  public:
  Grammar() {};
  Grammar(std::ifstream& my_file);

  void print(std::ostream& os);

  std::multimap<Symbol, std::vector<Symbol>>::const_iterator find(const Symbol& simbolo) const;
  Symbol generateNewNonTerminal();
  void checkSingleProductions();

  void Grammar2CNF();

  friend std::ostream &operator<<(std::ostream &os, Grammar& a);

  private:
    Alphabet terminals_;
    Alphabet non_terminals_;
    Symbol inicial_;
    std::multimap<Symbol, std::vector<Symbol>> production_;
};


#endif