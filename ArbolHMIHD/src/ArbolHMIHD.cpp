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

}

void ArbolHMIHD::borrarHoja(int etiqueta) {
 
}

void ArbolHMIHD::modificarEtiqueta(int etiqueta, int nuevaEtiqueta) {
 
}

int ArbolHMIHD::raiz() {
  return this->raizArbol->etiqueta;
}

int ArbolHMIHD::padre(int etiqueta) {
 
}

int ArbolHMIHD::hijoMasIzquierdo(int etiqueta) {
 
}

int ArbolHMIHD::hermanoDerecho(int etiqueta) {
 
}

int ArbolHMIHD::etiqueta(nodoArbol* nodo) {
  return nodo->etiqueta;
}

int ArbolHMIHD::numNodos() {
  return this->contadorNodos;
}

int ArbolHMIHD::numHijos(int etiqueta) {
 
}

ArbolHMIHD::ArbolHMIHD() {
  
}

ArbolHMIHD::~ArbolHMIHD() {
  destruir();
}

