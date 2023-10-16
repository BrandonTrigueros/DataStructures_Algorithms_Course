#include "ArbolHMIHD.hpp"

void ArbolHMIHD::Iniciar() {
  this->raizArbol = nullptr;
  this->contadorNodos = 0;
}

void ArbolHMIHD::Destruir() {
  if (!Vacio()) {
    nodoArbol* nodo = this->raizArbol;
    DestruirPostOrden(nodo);
  }
  this->raizArbol = nullptr;
}

void ArbolHMIHD::DestruirPostOrden(nodoArbol* nodo) {
  nodoArbol* nodoHijo = nodo->hijoMasIzq;
  while (nodoHijo != nullptr) {
    nodoArbol* nodoHermanoDerecho = nodoHijo->hermanoDer;
    DestruirPostOrden(nodoHijo);
    nodoHijo = nodoHermanoDerecho;
  }
  delete nodo;
}

void ArbolHMIHD::Vaciar() {
  Destruir();
  Iniciar();
}

bool ArbolHMIHD::Vacio() {
  if (this->raizArbol == nullptr) {
    return true;
  }
  return false;
}

void ArbolHMIHD::PonerRaiz(int64_t etiqueta) {
  nodoArbol* nodo = new nodoArbol();
  nodo->etiqueta = etiqueta;
  nodo->hijoMasIzq = nullptr;
  nodo->hermanoDer = nullptr;
  this->raizArbol = nodo;
  this->contadorNodos++;
}

nodoArbol* ArbolHMIHD::AgregarHijo(
    nodoArbol* nodo, int64_t numHijo, int64_t etiqueta) {
  nodoArbol* nuevoNodohijo = crearNodo(etiqueta);
  nodoArbol* nodoHijo = nodo->hijoMasIzq;
  if (nodoHijo == nullptr && numHijo == 1) {
    nodo->hijoMasIzq = nuevoNodohijo;
  } else if (numHijo == 1) {
    nodoArbol* nodoHijoAux = nodoHijo;
    nodo->hijoMasIzq = nuevoNodohijo;
    nodo->hijoMasIzq->hermanoDer = nodoHijoAux;
  } else {
    for (int64_t iteradorNodos = 2; iteradorNodos < numHijo; iteradorNodos++) {
      nodoHijo = nodoHijo->hermanoDer;
    }
    if (nodoHijo->hermanoDer == nullptr) {
      nodoHijo->hermanoDer = nuevoNodohijo;
    } else {
      nodoArbol* nodoHijoAux = nodoHijo->hermanoDer;
      nodoHijo->hermanoDer = nuevoNodohijo;
      nodoHijo->hermanoDer->hermanoDer = nodoHijoAux;
    }
  }
  this->contadorNodos++;
  return nuevoNodohijo;
}

void ArbolHMIHD::BorrarHoja(nodoArbol* nodo) {
  if (nodo == Raiz()) {
    delete nodo;
    raizArbol = nullptr;
    return;
  }
  std::queue<nodoArbol*> cola;
  cola.push(Raiz());
  while (!cola.empty()) {
    nodoArbol* nodoActual = cola.front();
    cola.pop();
    nodoArbol* nodoHijo = nodoActual->hijoMasIzq;
    if (nodoHijo == nodo) {
      nodoActual->hijoMasIzq = nodoHijo->hermanoDer;
      delete nodoHijo;
      this->contadorNodos--;
      return;
    }
    while (nodoHijo != nullptr) {
      cola.push(nodoHijo);
      nodoArbol* nodoAnterior = nodoHijo;
      nodoHijo = nodoHijo->hermanoDer;
      if (nodoHijo == nodo) {
        nodoAnterior->hermanoDer = nodoHijo->hermanoDer;
        delete nodoHijo;
        this->contadorNodos--;
        return;
      }
    }
  }
}

void ArbolHMIHD::ModificarEtiqueta(nodoArbol* nodo, int64_t etiqueta) {
  nodo->etiqueta = etiqueta;
}

nodoArbol* ArbolHMIHD::Raiz() { return this->raizArbol; }

nodoArbol* ArbolHMIHD::Padre(nodoArbol* nodo) {
  std::queue<nodoArbol*> cola;
  cola.push(Raiz());
  while (!cola.empty()) {
    nodoArbol* nodoActual = cola.front();
    cola.pop();
    nodoArbol* nodoHijo = nodoActual->hijoMasIzq;
    while (nodoHijo != nullptr) {
      cola.push(nodoHijo);
      if (nodoHijo == nodo) {
        return nodoActual;
      }
      nodoHijo = nodoHijo->hermanoDer;
    }
  }
  return nullptr;
}

nodoArbol* ArbolHMIHD::HijoMasIzq(nodoArbol* nodo) { return nodo->hijoMasIzq; }

nodoArbol* ArbolHMIHD::HermanoDer(nodoArbol* nodo) { return nodo->hermanoDer; }

int64_t ArbolHMIHD::Etiqueta(nodoArbol* nodo) { return nodo->etiqueta; }

int64_t ArbolHMIHD::NumHijos(nodoArbol* nodo) {
  int64_t numeroHijos = 0;
  nodoArbol* nodoHijo = nodo->hijoMasIzq;
  while (nodoHijo != nullptr) {
    numeroHijos++;
    nodoHijo = nodoHijo->hermanoDer;
  }
  return numeroHijos;
}

bool ArbolHMIHD::EsHoja(nodoArbol* nodo) {
  if (nodo->hijoMasIzq == nullptr) {
    return true;
  }
  return false;
}

int64_t ArbolHMIHD::NumNodos() { return this->contadorNodos; }

nodoArbol* ArbolHMIHD::BuscarEtiqueta(int64_t etiqueta) {
  bool nodoEncontrado = false;
  std::queue<nodoArbol*> cola;
  cola.push(Raiz());
  while (!cola.empty() && !nodoEncontrado) {
    nodoArbol* nodoActual = cola.front();
    cola.pop();
    if (nodoActual->etiqueta == etiqueta) {
      nodoEncontrado = true;
      return nodoActual;
    }

    nodoArbol* nodoHijo = nodoActual->hijoMasIzq;
    while (nodoHijo != nullptr && !nodoEncontrado) {
      cola.push(nodoHijo);
      nodoHijo = nodoHijo->hermanoDer;
    }
  }
  return nullptr;
}

nodoArbol* ArbolHMIHD::crearNodo(int64_t etiqueta) {
  nodoArbol* nodo = new nodoArbol();
  nodo->etiqueta = etiqueta;
  nodo->hijoMasIzq = nullptr;
  nodo->hermanoDer = nullptr;
  return nodo;
}

ArbolHMIHD::ArbolHMIHD() { }

ArbolHMIHD::~ArbolHMIHD() {
  Destruir();
  delete this->raizArbol;
}

void ArbolHMIHD::Imprimir() {
  if (this->Vacio()) {
    std::cout << "El árbol está vacío." << std::endl;
    return;
  }
  std::queue<nodoArbol*> cola;
  cola.push(Raiz());
  int nodosEnNivelActual = 1;
  int nodosEnNivelSiguiente = 0;

  while (!cola.empty()) {
    nodoArbol* nodoActual = cola.front();
    cola.pop();
    std::cout << "(" << nodoActual->etiqueta << ")";
    std::cout << " HMI:";
    if (nodoActual->hijoMasIzq != nullptr) {
      std::cout << nodoActual->hijoMasIzq->etiqueta << ", ";
    } else {
      std::cout << "NULL, ";
    }
    nodoArbol* nodoHijo = nodoActual->hijoMasIzq;
    while (nodoHijo != nullptr) {
      cola.push(nodoHijo);
      nodoHijo = nodoHijo->hermanoDer;
      nodosEnNivelSiguiente++;
    }

    if (--nodosEnNivelActual == 0) {
      std::cout << std::endl;
      nodosEnNivelActual = nodosEnNivelSiguiente;
      nodosEnNivelSiguiente = 0;
    }
  }
}
