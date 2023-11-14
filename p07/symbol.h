// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con cadenas
// Autor: Alberto Lago Fernández
// Correo: alu0101562247@ull.edu.es
// Fecha: 23/09/2023
// Archivo symbol.h: Archivo con la declaracion de la clase symbol.
// Contiene la declaración de la clase symbol
// Referencias:
// Enlaces de interés
// Historial de revisiones
// 23/09/2023 - Creación del código

#ifndef SYMBOL_H
#define SYMBOL_H

#include <sstream>

/// @brief clase Symbol
class Symbol {
  public:
    Symbol() {};
    Symbol(char symbol);
    const char getChar() const;

    bool operator<(const Symbol& symbol) const;
    friend std::ostream &operator<<(std::ostream &os, Symbol a);
  private:
    char symbol_;
};

const bool operator==(Symbol& a, Symbol& b);






#endif