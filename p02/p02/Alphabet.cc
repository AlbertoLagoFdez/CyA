#include "Alphabet.h"

Alphabet::Alphabet(std::set<char> alphabet) {
  alphabet_ = alphabet;
}

void Alphabet::insert(char &x) {
  alphabet_.insert(x);
}

std::string Alphabet::print(std::string text, std::string output_text) {
  text += "{";
  for(std::set<char>::iterator i = alphabet_.begin() ; i != alphabet_.end(); i++) {
    text += (*i);
    if ( i != --alphabet_.end()) {
    text += ", ";    
    }
  }
  text += "}";
  return text;
}
