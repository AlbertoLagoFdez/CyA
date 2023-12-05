#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "point_types.hpp"
#include "sub_tree.hpp"
#include "point_set.hpp"

void CheckInputFileOpening(std::ifstream& file, std::string& file_name) {
  file.open(file_name);
  if (!file) {
    std::cerr << "Error al abrir el archivo" << std::endl;
    exit(EXIT_FAILURE);
  }
}

int main(int argc, char* argv[]) {
  std::ifstream inputfile;
  std::string file_name{argv[1]};
  CheckInputFileOpening(inputfile, file_name);
  //empezamos a leer y a crear objetos necesarios
  std::string line;
  getline(inputfile, line);
  int numOfPoints = std::stoi(line);
  CyA::point_vector puntosDelVector;
  for(int i = 0; i < numOfPoints; i++) 
  {
    getline(inputfile, line);
    std::istringstream iss(line);
    double num;
    std::vector<double> numerosDelPunto;
    while (iss >> num) 
    {
      numerosDelPunto.push_back(num);
    }
    CyA::point punto{numerosDelPunto[0],numerosDelPunto[1]};
    puntosDelVector.push_back(punto);
  }
  std::cout << puntosDelVector;
  return 0;
}