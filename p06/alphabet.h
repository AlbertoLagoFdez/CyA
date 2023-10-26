// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con cadenas
// Autor: Alberto Lago Fernández
// Correo: alu0101562247@ull.edu.es
// Fecha: 23/09/2023
// Archivo alphabet.h: Archivo con la declaracion de la clase alphabet.
// Contiene la declaración de la clase symbol
// Referencias:
// Enlaces de interés
// Historial de revisiones
// 23/09/2023 - Creación del código

#ifndef ALPHABET_H
#define ALPHABET_H

#include "symbol.h"
#include <iostream>
#include <set>

class Alphabet {
  public:
    Alphabet() {};
    Alphabet(std::set<Symbol> alphabet);
    Alphabet(Alphabet& Alphabet);

    void insert(Symbol& symbol);
    void print() const;

    long unsigned int size() const;
    std::set<Symbol> getAlphabet() const;
    const Symbol GetSymbol(std::set<Symbol>::iterator itr);

    auto Begin() const;
    auto End() const;

    friend std::ostream& operator<<(std::ostream& os, Alphabet& alphabet);

    bool IsInAlphabet(Symbol& symbol);
  private:
    std::set<Symbol> alphabet_;
};

#endif