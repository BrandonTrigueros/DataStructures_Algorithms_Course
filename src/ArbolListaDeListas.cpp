#include "ArbolListaDeListas.hpp"
#include <algorithm>
#include <clocale>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <ostream>
#include <type_traits>
struct ListaPrincipal;

void ArbolListaDeListas::Iniciar() { this->raiz = nullptr; }

void ArbolListaDeListas::Destruir() {
  if (!this->Vacio()) {
    this->Vaciar();
    delete this->raiz;
    this->raiz = nullptr;
  } else {
    // delete this->raiz;
    this->raiz = nullptr;
  }
}

void ArbolListaDeListas::Vaciar() {
  ListaPrincipal* principal = this->raiz;
  this->raiz = nullptr;
  while (principal != nullptr) {
    ListaPunteros* hijos = principal->primero;
    while (hijos != nullptr) {
      ListaPunteros* eliminar = hijos;
      hijos = hijos->sigP;
      delete eliminar;
    }
    ListaPrincipal* prinEliminar = principal;
    principal = principal->sigM;
    delete prinEliminar;
  }
}

bool ArbolListaDeListas::Vacio() {
  if (this->raiz) {
    return false;
  }
  return true;
}


ListaPrincipal* ArbolListaDeListas::HijoMasIzq(ListaPrincipal* nodo) {
  if (nodo->primero != nullptr) {
    return nodo->primero->hijo;
  }
  return nullptr;
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

ListaPrincipal* ArbolListaDeListas::AgregarHijo(
    ListaPrincipal* nodo, int64_t numHijo, int64_t etiqueta) {
  ListaPrincipal* agregar = new ListaPrincipal();

  agregar->etiqueta = etiqueta;
  agregar->sigM = this->raiz->sigM;
  this->raiz->sigM = agregar;

  ListaPunteros* puntAux;
  puntAux = nodo->primero;
  int64_t contador = 1;
  while (puntAux != nullptr && contador < numHijo-1) {
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
  } else if (puntAux == nodo->primero && numHijo == 1) {
    puntAg->sigP = nodo->primero;
    nodo->primero = puntAg;
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

  ListaPrincipal* nodoBuscar = this->raiz;
  while (nodoBuscar != nullptr && nodoBuscar->sigM != nodo) {
    nodoBuscar = nodoBuscar->sigM;
  }
  nodoBuscar->sigM = nodo->sigM;
  delete nodo;
}

void ArbolListaDeListas::PonerRaiz(int64_t etiqueta) {
  ListaPrincipal* agregar = new ListaPrincipal();
  agregar->etiqueta = etiqueta;
  agregar->primero = nullptr;
  agregar->sigM = nullptr;
  this->raiz = agregar;
}

void ArbolListaDeListas::ModificarEtiqueta(
    ListaPrincipal* nodo, int64_t etiqueta) {
  nodo->etiqueta = etiqueta;
}

ListaPrincipal* ArbolListaDeListas::Raiz() { return this->raiz; }

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
  while (nodoAux->sigM != nullptr) {
    ++numNodos;
    nodoAux = nodoAux->sigM;
  }
  return numNodos;
}

void ArbolListaDeListas::Imprimir() {
  if (this->Vacio()) {
    std::cout << "El árbol está vacío." << std::endl;
    return;
  }
  ListaPrincipal* nodo = this->raiz;
  while (nodo != nullptr) {
    std::cout << nodo->etiqueta << " -> ";
    if (nodo->primero == nullptr) {
      std::cout << "NULL";
    } else {
      ListaPunteros* hijo = nodo->primero;
      while (hijo != nullptr) {
        std::cout << hijo->hijo->etiqueta << "-";
        hijo = hijo->sigP;
      }
    }
    std::cout << std::endl;
    nodo = nodo->sigM;
  }
}
