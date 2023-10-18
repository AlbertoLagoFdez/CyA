#include "Chain.h"

Chain::Chain(std::string chain) {
  chain_ = chain;
}

void Chain::push_back(const char x) {
  chain_.push_back(x);
}

int Chain::length() const{
  return chain_.length();
}

std::string Chain::inverse(std::string text, std::string output_text) const {
  for(int i = chain_.length() - 1; i >= 0; i--) {
    text += chain_[i];
  }
  return text;
}

std::string Chain::prefijo(std::string text, std::string output_text) const {
  std::string prefijo;
  int longitud = chain_.length();
  text += "{&, ";
  for(int i = 0 ; i < longitud ; i++) {
    prefijo += chain_[i];
    text += prefijo;
    if(i != longitud - 1 ) {
      text += ", ";
    }
  }
  text += "}";
  return text;
}

std::string Chain::sufijo(std::string text, std::string output_text) const{
  Chain sufijo;
  std::string inverse;
  int longitud = chain_.length();
  text += "{&, ";
  for(int i = longitud - 1 ; i >= 0 ; i--) {
    sufijo.push_back(chain_[i]);
    text += sufijo.inverse(inverse, output_text);
    if (i != 0) {
      text += ", ";
    }
  }
  text += "}";
  return text;
}

bool Chain::operator<(Chain const &e) const
{
  return chain_.length() < e.chain_.length() || chain_.length() == e.chain_.length() ;
}
