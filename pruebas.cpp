#include <iostream>
#include <iterator>
#include <ostream>
#include "Cola/Cola.hpp"
#include "ArbolListas/ArbolListaDeListas.hpp"

int main () {

  ArbolListaDeListas arbol;
  
  arbol.PonerRaiz(4);
  std::cout << "Raiz: " << arbol.Raiz()->etiqueta << std::endl;
  arbol.BorrarHoja(arbol.Raiz());
  std::cout << arbol.Vacio() << std::endl;
  return 0;
}
