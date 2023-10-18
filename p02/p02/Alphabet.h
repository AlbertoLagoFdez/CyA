#ifndef ALPHABET_H
#define ALPHABET_H

#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
#include <cstring>
#include <string>

class Alphabet {
public:
 Alphabet() {};
 Alphabet(std::set<char> alphabet);
 void insert(char& x);
 std::string print(std::string text, std::string output_text);
private:
 std::set<char> alphabet_;
};

#endif
