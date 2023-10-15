#ifndef ESTADO_H
#define ESTADO_H
#include <iostream>

class Estado {
public:
  Estado() {};
  Estado(char name);
  void set_acept(bool acept);

  friend std::ostream &operator<<(std::ostream &os, Estado p);
private:
  char name_;
  bool acept_;
};

#endif