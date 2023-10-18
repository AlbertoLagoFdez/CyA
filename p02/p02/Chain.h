#ifndef CHAIN_H
#define CHAIN_H

#include <iostream>
#include <string>
#include <fstream>

class Chain {
public:
 Chain() {};
 Chain (std::string chain);
 void push_back(const char x);
 int length() const;
 std::string inverse(std::string text, std::string output_text) const;
 std::string prefijo(std::string text, std::string output_text) const;
 std::string sufijo(std::string text, std::string output_text) const;
 bool operator<(Chain const &e) const;
private:
 std::string chain_;
};

#endif