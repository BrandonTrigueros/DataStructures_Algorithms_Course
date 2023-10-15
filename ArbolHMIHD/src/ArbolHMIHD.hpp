
// Modelo Arbol implementado en la estructura de datos
// Arbol Hijo mas izquierdo hermano derecho
// donde cada nodo tiene dos punteros uno al hijo mas izquierdo y otro al
// hermano derecho
#ifndef ARBOLHMIHD_HPP
#define ARBOLHMIHD_HPP

#include <cstdint>
#include <iostream>
#include <queue>

struct nodoArbol {
  int64_t etiqueta;
  nodoArbol* hijoMasIzq;
  nodoArbol* hermanoDer;
};
class ArbolHMIHD {
 private:
  nodoArbol* raizArbol;
  int contadorNodos;

 public:
  ArbolHMIHD();
  ~ArbolHMIHD();

  void Iniciar();
  void Destruir();
  void DestruirPostOrden(nodoArbol* nodo);
  void Vaciar();
  bool Vacio();
  nodoArbol* AgregarHijo(nodoArbol* nodo, int64_t numHijo, int64_t etiqueta);
  void BorrarHoja(nodoArbol* nodo);
  void PonerRaiz(int64_t etiqueta);
  nodoArbol* HijoMasIzq(nodoArbol* nodo);
  nodoArbol* HermanoDer(nodoArbol* nodo);
  void ModificarEtiqueta(nodoArbol* nodo, int64_t etiqueta);
  nodoArbol* Raiz();
  nodoArbol* Padre(nodoArbol* nodo);
  int64_t Etiqueta(nodoArbol* nodo);
  int64_t NumHijos(nodoArbol* nodo);
  bool EsHoja(nodoArbol* nodo);
  int64_t NumNodos();

  nodoArbol* BuscarEtiqueta(int64_t etiqueta);
  nodoArbol* crearNodo(int64_t etiqueta);

  void imprimir();
};

#define ARBOL ArbolHMIHD

#endif  // ARBOLHMIHD_HPP
