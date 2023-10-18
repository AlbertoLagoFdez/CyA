#include "Chain.h"
#include "Alphabet.h"
#include "tools.cc"
#include <map>
#include <unordered_map>

int main(int argc, char* argv[]) {
  Usage(argc, argv);
  std::string linea;
  std::string text;
  std::string output_text;
  std::string salida;
  std::string output_file = argv[2];
  std::ifstream  input_file (argv[1]);
  std::ofstream archivo;
  int opcode = std::stoi(argv[3]);
  std::map<Chain, Alphabet> table;   
  while(getline(input_file, linea)) {
    std::set<char> a;
    std::string c;
    for(long unsigned int i = 0 ; i < linea.length() ; i++) {
      char x = linea[i];
      a.insert(x);
      c.push_back(x);
    }
    Alphabet alfabeto = a;
    Chain cadena = c;
    table[cadena] = alfabeto;
  }
    archivo.open(output_file.c_str(), std::fstream::out);

    switch (opcode) {
    case 1: //print alfabeto
        for(std::map<Chain, Alphabet>::iterator i = table.begin(); i != table.end(); i++) {
          salida += (*i).second.print(text,output_text);
          salida += "\n";
        }
        archivo << salida;
      break;
    
    case 2: //print longitud
        for(std::map<Chain, Alphabet>::iterator i = table.begin(); i != table.end(); i++) {
          salida += std::to_string((*i).first.length());
          salida += "\n";
        }
        archivo << salida;
      break;

    case 3: //print inversa
        for(std::map<Chain, Alphabet>::iterator i = table.begin(); i != table.end(); i++) {
          salida += (*i).first.inverse(text,output_text);
          salida += "\n";
        }
        archivo << salida;
      break;

    case 4: //print prefijos
        for(std::map<Chain, Alphabet>::iterator i = table.begin(); i != table.end(); i++) {
          salida += (*i).first.prefijo(text,output_text);
          salida += "\n";
        }
        archivo << salida;
      
      break;

    case 5: //print sufijo
        for(std::map<Chain, Alphabet>::iterator i = table.begin(); i != table.end(); i++) {
          salida += (*i).first.sufijo(text,output_text);
          salida += "\n";
        }
        archivo << salida;
      
      break;
    
    default: 
      std::cout << "Opcode erróneo. {1-5}" << std::endl;
      exit(EXIT_SUCCESS);
      break;
    };
  return 0;
}