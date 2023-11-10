#ifndef ARBOLARREGLO_HPP
#define ARBOLARREGLO_HPP

#include <inttypes.h>
#include <iostream>
#include <string>

struct nodo {
  int etiqueta;
  int padre;
};

class ArbolArreglo {
 private:
  nodo* arreglo;
  int ultimoLleno;
  int capacidad;

 public:
  ArbolArreglo() { }
  ~ArbolArreglo() { }

  void Iniciar();
  void Destruir();
  void Vaciar();
  bool Vacio();
  nodo* AgregarHijo(nodo* padre, int64_t numHijo, int64_t etiquetaHijo);
  void BorrarHoja(nodo* hoja);
  void PonerRaiz(int64_t etiqueta);
  nodo* HijoMasIzq(nodo* nodo);
  nodo* HermanoDer(nodo* nodo);
  void ModificarEtiqueta(nodo* nodo, int64_t etiqueta);
  nodo* Raiz();
  nodo* Padre(nodo* nodo);
  int64_t Etiqueta(nodo* nodo);
  int64_t NumHijos(nodo* nodo);
  bool EsHoja(nodo* nodo);
  int64_t NumNodos();

  void Imprimir();
};

#define ARBOL ArbolArreglo
#define NODO nodo

#endif  // ARBOLARREGLO_HPP