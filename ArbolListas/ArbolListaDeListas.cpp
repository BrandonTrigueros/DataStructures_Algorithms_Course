#include "ArbolListaDeListas.hpp"
#include <clocale>
#include <cstdint>
#include <iostream>
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

ListaPrincipal* ArbolListaDeListas::HijoMasIzq(ListaPrincipal* nodo) {
  return nodo->primero->hijo ; 
}

ListaPrincipal* ArbolListaDeListas::HermanoDer(ListaPrincipal* nodo) { 
  return nullptr;
}

ListaPrincipal* ArbolListaDeListas::AgregarHijo(ListaPrincipal* nodo,
    int64_t numHijo, int64_t etiqueta) {
  ListaPrincipal* agregar = new ListaPrincipal();
  
  agregar->etiqueta = etiqueta; 
  agregar->sigM = this->raiz->sigM;
  this->raiz->sigM = agregar;
 
  ListaPunteros* puntAux;
  puntAux = nodo->primero;
  int64_t contador = 1;
  while (puntAux != nullptr && contador+1 < numHijo) {
    puntAux = puntAux->sigP;
    ++contador;
  }
  
  ListaPunteros* puntAg = new ListaPunteros();
  if (puntAux == nullptr || puntAux->sigP == nullptr) {
    puntAux = puntAg;
    puntAg->sigP = nullptr;
    puntAg->hijo = agregar;
  } else {
    puntAg->sigP = puntAux->sigP;
    puntAux->sigP = puntAg; 
    puntAg->hijo = agregar;
  }
  return agregar;
}

void ArbolListaDeListas::BorrarNodoHijo(ListaPrincipal* nodo) {
  ListaPrincipal* nodoPadre = Padre(nodo);
  ListaPunteros* punteroEliminar = nodoPadre->primero;
  ListaPunteros* anterior = punteroEliminar;
  while (punteroEliminar->hijo != nodo) {
    anterior = punteroEliminar; 
    punteroEliminar = punteroEliminar->sigP;
  }
  anterior->sigP = punteroEliminar->sigP;
  delete punteroEliminar;
}

void ArbolListaDeListas::PonerRaiz(ListaPrincipal* raiz) {
  ListaPrincipal* agregar = new ListaPrincipal();
  agregar->primero = nullptr;
  agregar->etiqueta = raiz->etiqueta;
  agregar->sigM = nullptr;
  this->raiz = agregar; 
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
