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
#ifndef AUTOMATA_H
#define AUTOMATA_H
#include <map>
#include <string>
#include "Estado.h"
#include "Transicion.h"

class Automata {
  public:
    Automata(int numero_estados, int arranque) {numero_estados_ = numero_estados; arranque_ = arranque;}
    Automata(){}
    void Insertar_num_estados(int numero) {numero_estados_ = numero;}
    void Definir_arranque(Estado arranque) {arranque_ = arranque;}
    Estado Get_arranque(){return arranque_;}
    int Get_num_estados(){return numero_estados_;}
    //std::map<char, Estado> Get_estados_del_automata(){return Estados_de_automata_;}
    std::multimap<Estado, Transicion> Get_multimap(){return multimap_;}
    void Insert(Estado estado, Transicion transicion){multimap_.insert(std::pair<Estado, Transicion>(estado, transicion));}
    friend std::ostream &operator<<(std::ostream &os, Automata p);
    bool Search_multimap(Estado, char);
    Estado Get_estado_destino(Estado, char);
    void Estados_de_muerte();
  private:
    //std::map<char, Estado> Estados_de_automata_;
    std::multimap<Estado, Transicion> multimap_;
    int numero_estados_;
    Estado arranque_;
};

    //void Insertar_transicion(std::string, char);
    //void Imprimir_multimap();
    //std::multimap<std::string, char> Get_multimap_transiciones() {return multimap_transiciones_;}
    //std::map<char, Estado> automata_;
    //std::multimap<std::string, char> multimap_transiciones_;
#endif //AUTOMATA_HPP_