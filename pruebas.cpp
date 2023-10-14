#include <iostream>
#include <iterator>
#include "Cola.hpp"
#include "ArbolListas/ArbolListaDeListas.hpp"

int main () {

  ArbolListaDeListas arbol;
  ListaPrincipal* raiz;
  raiz->etiqueta = 4;
  
  arbol.PonerRaiz(raiz);
  std::cout << arbol.Raiz()->etiqueta << std::endl;
  arbol.AgregarHijo(arbol.Raiz(), 1, 9); 
  std::cout << arbol.Raiz()->primero->hijo->etiqueta << std::endl;
  return 0;
}
