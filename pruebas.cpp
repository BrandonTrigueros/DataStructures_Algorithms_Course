#include <cstdint>
#include <iostream>
#include <iterator>
#include <ostream>
#include "Cola/Cola.hpp"
#include "ArbolListas/ArbolListaDeListas.hpp"

int main () {

  ArbolListaDeListas arbol;
  
  arbol.PonerRaiz(4);
  std::cout << "Raiz: " << arbol.Raiz()->etiqueta << std::endl;
  for (int64_t i = 0; i < 5; ++i) {
    arbol.AgregarHijo(arbol.Raiz(),
      i, i+1);
  }
  
  ListaPrincipal* hijo = arbol.HijoMasIzq(arbol.Raiz());
  for (int64_t i = 0; i < 5; ++i) {
    std::cout << "Etiq: " << hijo->etiqueta << " Hijo: "<< i << std::endl;
    hijo = arbol.HermanoDer(hijo);
  }

  arbol.Vaciar();

  std::cout << arbol.Vacio() << std::endl;
  return 0;
}
