#include "alphabet.h"

Alphabet::Alphabet(std::set<Symbol> alphabet) {
  alphabet_ = alphabet;
}

Alphabet::Alphabet(Alphabet &alphabet) {
  alphabet_ = alphabet.getAlphabet();
}

void Alphabet::insert(Symbol &symbol) {
  alphabet_.insert(symbol);
}

void Alphabet::print() const
{
}

long unsigned int Alphabet::size() const
{
  return alphabet_.size();
}

std::set<Symbol> Alphabet::getAlphabet() const
{
  return alphabet_;
}
