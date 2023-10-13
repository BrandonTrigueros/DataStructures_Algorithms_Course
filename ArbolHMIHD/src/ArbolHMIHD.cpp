#include "ArbolHMIHD.hpp"

void ArbolHMIHD::crear() {
  this->raizArbol = nullptr;
}

void ArbolHMIHD::destruir() {
  if (!vacio()) {
    nodoArbol* nodo = this->raizArbol;
    destruirPostOrden(nodo);
  }
}

void ArbolHMIHD::destruirPostOrden(nodoArbol* nodo) {
  nodoArbol* nodoHijo = nodo->hijoMasIzq;
  while (nodoHijo != nullptr) {
    destruirPostOrden(nodoHijo);
    nodoHijo = nodoHijo->hermanoDer;
  }
  delete nodo;
}

void ArbolHMIHD::vaciar() {
  if (!vacio()) {
    nodoArbol* nodo = this->raizArbol;
    nodoArbol* nodoHijo = nodo->hijoMasIzq;
    while (nodoHijo != nullptr) {
      destruirPostOrden(nodoHijo);
      nodoHijo = nodoHijo->hermanoDer;
    }
    this->raizArbol = nullptr;
  }
}

bool ArbolHMIHD::vacio() {
  if (this->raizArbol == nullptr) {
    return true;
  }
  return false;
}

void ArbolHMIHD::ponerRaiz(int etiqueta) {
  if (this->raizArbol == nullptr) {
    nodoArbol* nodo = new nodoArbol();
    nodo->etiqueta = etiqueta;
    nodo->hijoMasIzq = nullptr;
    nodo->hermanoDer = nullptr;
    this->raizArbol = nodo;
  } else {
    this->raizArbol->etiqueta = etiqueta;
  }
}

int ArbolHMIHD::agregarHijo(int etiquetaAgregar, int etiquetaPadre, int posicion) {
  if (this->raizArbol == nullptr) {
    return -1;
  }
  nodoArbol* nodo = this->raizArbol;
  nodoArbol* nodoHijo = nodo->hijoMasIzq;
  while (nodoHijo != nullptr) {
    if (nodoHijo->etiqueta == etiquetaPadre) {
      nodoArbol* nodoNuevo = new nodoArbol();
      nodoNuevo->etiqueta = etiquetaAgregar;
      nodoNuevo->hijoMasIzq = nullptr;
      nodoNuevo->hermanoDer = nullptr;
      if (posicion == 1) {
        nodoNuevo->hermanoDer = nodoHijo->hijoMasIzq;
        nodoHijo->hijoMasIzq = nodoNuevo;
      } else {
        nodoArbol* nodoHermano = nodoHijo->hijoMasIzq;
        while (nodoHermano->hermanoDer != nullptr) {
          nodoHermano = nodoHermano->hermanoDer;
        }
        nodoHermano->hermanoDer = nodoNuevo;
      }
      return 1;
    }
    nodoHijo = nodoHijo->hermanoDer;
  }
  return -1;
}

ArbolHMIHD::ArbolHMIHD() {
  
}

ArbolHMIHD::~ArbolHMIHD() {
  destruir();
}

