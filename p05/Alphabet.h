#ifndef ALPHABET_H
#define ALPHABET_H
#include <iostream>
#include <iterator>
#include <set>

class Alphabet {
  public:
    Alphabet() {  };
    Alphabet(std::set<char> alphabet);
    void insert(char c);
    void print();
    friend std::ostream &operator<<(std::ostream &os, Alphabet p);
  private:
    std::set<char> alphabet_;
};



#endif