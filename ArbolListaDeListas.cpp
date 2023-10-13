#include "ArbolListaDeListas.hpp"
#include <cstdint>
#include <iomanip>
struct ListaPrincipal;

void  ArbolListaDeListas::Iniciar() {
  ArbolListaDeListas* arbol = new ArbolListaDeListas();
  *this = *arbol;
}

void ArbolListaDeListas::Destruir() {
  delete this;
}

void ArbolListaDeListas::Vaciar() {

}

bool ArbolListaDeListas::Vacio() {
  if (this->raiz) {
    return false;
  }
  return true;
}

ListaPrincipal* ArbolListaDeListas::AgregarHijo(ListaPrincipal* nodo,
    int64_t numHijo) {
  return nullptr;
}

void ArbolListaDeListas::BorrarNodoHijo() {

}

void ArbolListaDeListas::PonerRaiz(ListaPrincipal* raiz) {
  this->raiz = raiz; 
}

void ArbolListaDeListas::ModificarEtiqueta(ListaPrincipal* nodo,
    int64_t etiqueta) {
  nodo->etiqueta = etiqueta;
}

ListaPrincipal* ArbolListaDeListas::Raiz() {
  return this->raiz;
}

ListaPrincipal* ArbolListaDeListas::Padre(ListaPrincipal* nodo) {
  ListaPrincipal* nodoAux = nodo;
  while (nodoAux != nullptr) {
    ListaPunteros* puntero = nodoAux->primero;
    while (puntero != nullptr) {
      if (puntero->hijo == nodo) {
        return nodoAux;
      }
      puntero = puntero->sigP;
    }
    nodoAux = nodoAux->sigM;
  }
  return nullptr; 
}

int64_t ArbolListaDeListas::Etiqueta(ListaPrincipal* nodo) {
  return nodo->etiqueta; 
}

int64_t ArbolListaDeListas::NumHijos(ListaPrincipal* nodo) {
  int64_t paraRet = 0;
  ListaPunteros* nodoAux = nodo->primero;

  while (nodoAux != nullptr) {
    ++paraRet;
    nodoAux = nodoAux->sigP;
  }
  return paraRet;
}

bool ArbolListaDeListas::EsHoja(ListaPrincipal* nodo) {
  if (nodo->primero) {
    return false;
  }
  return true;
}

int64_t ArbolListaDeListas::NumNodos() {
  if (this->raiz == nullptr) {
    return 0;
  }
  int64_t numNodos = 1;
  ListaPrincipal* nodoAux = this->raiz;
  while (nodoAux->sigM) {
    ++numNodos;
    nodoAux = nodoAux->sigM;
  }
  return numNodos;
}
