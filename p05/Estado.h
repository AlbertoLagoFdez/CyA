#ifndef ESTADO_H
#define ESTADO_H
#include <iostream>

class Estado {
public:
  Estado() {};
  Estado(char name);
  void set_acept(bool acept);
  void set_numTransitions(int numTransiotion);
  char get_name() const;

  friend std::ostream &operator<<(std::ostream &os, Estado p);
private:
  char name_;
  bool acept_;
  int numTransitions_;
};

#endif