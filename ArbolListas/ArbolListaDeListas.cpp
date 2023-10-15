#include "ArbolListaDeListas.hpp"
#include <algorithm>
#include <clocale>
#include <cstdint>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <ostream>
struct ListaPrincipal;

void  ArbolListaDeListas::Iniciar() {
  this->raiz = nullptr;
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
  ListaPrincipal* nodoPadre = Padre(nodo);
  ListaPunteros* puntHijos = nodoPadre->primero; 
  while (puntHijos != nullptr) {
    if (puntHijos->sigP != nullptr && puntHijos->hijo == nodo) {
      return puntHijos->sigP->hijo;
    }
    puntHijos = puntHijos->sigP;
  }
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
  while (puntAux != nullptr && contador < numHijo) {
    if (puntAux->sigP != nullptr) {
      puntAux = puntAux->sigP;
    }
    ++contador;
  }
  
  ListaPunteros* puntAg = new ListaPunteros();
  if (puntAux == nullptr) {
    nodo->primero = puntAg;
    puntAg->sigP = nullptr;
    puntAg->hijo = agregar;
  } else {
    puntAg->sigP = puntAux->sigP;
    puntAux->sigP = puntAg; 
    puntAg->hijo = agregar;
  }
  return agregar;
}

void ArbolListaDeListas::BorrarHoja(ListaPrincipal* nodo) {
  if (this->raiz == nodo) {
    ListaPrincipal* aux = this->raiz;
    this->raiz = nullptr;
    delete aux;
    return;
  }
  
  ListaPrincipal* nodoPadre = Padre(nodo);
  ListaPunteros* punteroEliminar = nodoPadre->primero;
  ListaPunteros* anterior = punteroEliminar;
  while (punteroEliminar->hijo != nodo) {
    anterior = punteroEliminar; 
    punteroEliminar = punteroEliminar->sigP;
  }
  if (anterior == punteroEliminar) {
    nodoPadre->primero = punteroEliminar->sigP;
    delete punteroEliminar;
  } else {
    anterior->sigP = punteroEliminar->sigP;
    delete punteroEliminar;
  }

  ListaPrincipal* raiz = this->raiz;
  ListaPrincipal* ant = raiz;
  while (raiz != nullptr) {
    if (raiz != ant && raiz == nodo) {
      ant->sigM = raiz->sigM; 
      delete raiz;
      return;
    }
    else if (raiz == ant && raiz == nodo) {
      delete raiz;
    }
    ant = raiz;
    raiz = raiz->sigM;
  }
}

void ArbolListaDeListas::PonerRaiz(int64_t etiqueta) {
  ListaPrincipal* agregar = new ListaPrincipal();
  agregar->etiqueta = etiqueta;
  agregar->primero = nullptr;
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
  ListaPrincipal* nodoAux = this->raiz;
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
