#ifndef SIMBOL_H
#define SIMBOL_H
#include <iostream>

class Simbol {
  public:
    Simbol() {};
    Simbol(char simbol);
    void print();

    friend std::ostream &operator<<(std::ostream &os, Simbol p);
    bool operator<(Simbol const &e) const;

  private:
    char simbol_; 
};

#endif