#include <iostream>
#include "Cola.hpp"

int main () {
  Cola newCola;
  std::cout << "ALo" << std::endl;
  newCola.iniciar();
  newCola.encolar(4);
  newCola.encolar(5);
  newCola.encolar(6);
  newCola.encolar(7);
  newCola.encolar(9);
  newCola.encolar(9);
  newCola.encolar(9);
  newCola.encolar(9);
  newCola.encolar(9);
  newCola.encolar(9);
  newCola.encolar(9);
  int saveEle = newCola.numElem();
  std::cout << "Cola: "<<  newCola.numElem() << std::endl;
  newCola.desencolar();
  
  
  return 0;
}
