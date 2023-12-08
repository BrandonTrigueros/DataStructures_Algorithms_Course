#if 0

#include <iostream>

#include "ListasDeAdyacencia.hpp"

int main() {
  ListasDeAdyacencia* grafo = new ListasDeAdyacencia();
  grafo->Iniciar();
  grafo->AgregarVert("A");
  grafo->AgregarVert("B");
  grafo->AgregarVert("C");

  Vertice* nodo = grafo->listaVert;
  Vertice* nodoB = grafo->listaVert->siguienteVert;

  grafo->EliminarVert(nodoB->siguienteVert);
  grafo->AgregarArista(nodo, nodo->siguienteVert, 10);
  std::cout << nodo->listaAristas->peso << std::endl;
  grafo->ModificarPeso(nodo, nodo->siguienteVert, 15);
  std::cout << nodo->listaAristas->peso << std::endl;

  std::cout << nodo->etiqueta << std::endl;
  std::cout << nodo->siguienteVert->etiqueta << std::endl;

  return 0;
}

#endif