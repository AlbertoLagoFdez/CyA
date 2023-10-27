#include "alphabet.h"
#include "symbol.h"
#include "grammar.h"
#include "tools.cc"

int main(int argc, char* argv[]) {
  if (CheckParameters(argc,argv)) {
    std::ifstream grammar_inputfile;
    std::ofstream output;
    std::string file_name{argv[1]};
    std::string outputname{argv[2]};
    if(CheckInputFileOpening(grammar_inputfile, file_name)) {
      Grammar gramatica(grammar_inputfile);
      gramatica.Grammar2CNF();
      output.open(outputname);
      output << gramatica;
      output.close();
    }
  }
  return 0;
}