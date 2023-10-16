#include "ArbolHMIHDPADRE.hpp"

void ArbolHMIHDPADRE::Iniciar() {
  this->raizArbol = nullptr;
  this->contadorNodos = 0;
}

void ArbolHMIHDPADRE::Destruir() {
  if (!this->Vacio()) {
    nodoArbol* nodo = this->raizArbol;
    DestruirPostOrden(nodo);
  }
  // delete this->raizArbol;
  this->raizArbol = nullptr;
}

void ArbolHMIHDPADRE::DestruirPostOrden(nodoArbol* nodo) {
  nodoArbol* nodoHijo = nodo->hijoMasIzq;
  nodoArbol* nodoHermanoDerecho = nullptr;
  while (nodoHijo != nullptr && nodoHijo->ultimoHIjo == false) {
    nodoHermanoDerecho = nodoHijo->hermanoDer;
    DestruirPostOrden(nodoHijo);
    nodoHijo = nodoHermanoDerecho;
  }
  if (nodoHijo != nullptr) {
    DestruirPostOrden(nodoHijo);
  }
  delete nodo;
}

void ArbolHMIHDPADRE::Vaciar() {
  Destruir();
  Iniciar();
}

bool ArbolHMIHDPADRE::Vacio() {
  if (this->raizArbol == nullptr) {
    return true;
  }
  return false;
}

void ArbolHMIHDPADRE::PonerRaiz(int64_t etiqueta) {
  nodoArbol* nodo = new nodoArbol();
  nodo->etiqueta = etiqueta;
  nodo->hijoMasIzq = nullptr;
  nodo->hermanoDer = nullptr;
  nodo->ultimoHIjo = true;
  this->raizArbol = nodo;
  this->contadorNodos++;
}

nodoArbol* ArbolHMIHDPADRE::AgregarHijo(
    nodoArbol* nodo, int64_t numHijo, int64_t etiqueta) {
  nodoArbol* nuevoNodohijo = crearNodo(etiqueta);
  nodoArbol* nodoHijo = nodo->hijoMasIzq;
  if (nodoHijo == nullptr && numHijo == 1) {
    nodo->hijoMasIzq = nuevoNodohijo;
    nuevoNodohijo->ultimoHIjo = true;
    nuevoNodohijo->hermanoDer = nodo;
  } else if (numHijo == 1) {
    nodoArbol* nodoHijoAux = nodoHijo;
    nodo->hijoMasIzq = nuevoNodohijo;
    nodo->hijoMasIzq->hermanoDer = nodoHijoAux;
  } else {
    for (int64_t iteradorNodos = 2; iteradorNodos < numHijo; iteradorNodos++) {
      nodoHijo = nodoHijo->hermanoDer;
    }
    if (nodoHijo->ultimoHIjo == true) {
      nodoArbol* nodoHermanoDerechoAux = nodoHijo->hermanoDer;
      nodoHijo->hermanoDer = nuevoNodohijo;
      nuevoNodohijo->hermanoDer = nodoHermanoDerechoAux;
      nodoHijo->ultimoHIjo = false;
      nuevoNodohijo->ultimoHIjo = true;
    } else {
      nodoArbol* nodoHijoAux = nodoHijo->hermanoDer;
      nodoHijo->hermanoDer = nuevoNodohijo;
      nuevoNodohijo->hermanoDer = nodoHijoAux;
    }
  }
  this->contadorNodos++;
  return nuevoNodohijo;
}

void ArbolHMIHDPADRE::BorrarHoja(nodoArbol* nodo) {

  if (nodo == Raiz()) {
    raizArbol = nullptr;
    this->contadorNodos--;
    return;
  }

  nodoArbol* nodoPadre = Padre(nodo);
  nodoArbol* nodoHijo = nodoPadre->hijoMasIzq;
  if (nodoHijo == nodo) {
    if (nodoHijo->ultimoHIjo == true) {
      nodoPadre->hijoMasIzq = nullptr;
    } else {
      nodoPadre->hijoMasIzq = nodoHijo->hermanoDer;
    }
  } else {
    while (nodoHijo != nullptr && nodoHijo->hermanoDer != nodo) {
      nodoHijo = nodoHijo->hermanoDer;
    }
    if (nodoHijo != nullptr) {
      if (nodo->ultimoHIjo == true) {
        nodoHijo->hermanoDer = nodo->hermanoDer;
        nodoHijo->ultimoHIjo = true;
      } else {
        nodoHijo->hermanoDer = nodo->hermanoDer;
      }
    }
  }

  delete nodo;
  this->contadorNodos--;
}

void ArbolHMIHDPADRE::ModificarEtiqueta(nodoArbol* nodo, int64_t etiqueta) {
  nodo->etiqueta = etiqueta;
}

nodoArbol* ArbolHMIHDPADRE::Raiz() { return this->raizArbol; }

nodoArbol* ArbolHMIHDPADRE::Padre(nodoArbol* nodo) {
  while (nodo->ultimoHIjo != true) {
    nodo = nodo->hermanoDer;
  }
  return nodo->hermanoDer;
}

nodoArbol* ArbolHMIHDPADRE::HijoMasIzq(nodoArbol* nodo) {
  return nodo->hijoMasIzq;
}

nodoArbol* ArbolHMIHDPADRE::HermanoDer(nodoArbol* nodo) {
  return nodo->hermanoDer;
}

int64_t ArbolHMIHDPADRE::Etiqueta(nodoArbol* nodo) { return nodo->etiqueta; }

int64_t ArbolHMIHDPADRE::NumHijos(nodoArbol* nodo) {
  int64_t numeroHijos = 0;
  nodoArbol* nodoHijo = nodo->hijoMasIzq;
  while (nodoHijo != nullptr && nodoHijo->ultimoHIjo == false) {
    numeroHijos++;
    nodoHijo = nodoHijo->hermanoDer;
  }
  if (nodoHijo != nullptr) {
    numeroHijos++;
  }
  return numeroHijos;
}

bool ArbolHMIHDPADRE::EsHoja(nodoArbol* nodo) {
  if (nodo->hijoMasIzq == nullptr) {
    return true;
  }
  return false;
}

int64_t ArbolHMIHDPADRE::NumNodos() { return this->contadorNodos; }

nodoArbol* ArbolHMIHDPADRE::BuscarEtiqueta(int64_t etiqueta) {
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
    while (nodoHijo != nullptr && !nodoEncontrado
        && nodoHijo->ultimoHIjo == false) {
      cola.push(nodoHijo);
      nodoHijo = nodoHijo->hermanoDer;
    }
    if (nodoHijo != nullptr && !nodoEncontrado) {
      cola.push(nodoHijo);
    }
  }
  return nullptr;
}

nodoArbol* ArbolHMIHDPADRE::crearNodo(int64_t etiqueta) {
  nodoArbol* nodo = new nodoArbol();
  nodo->etiqueta = etiqueta;
  nodo->hijoMasIzq = nullptr;
  nodo->hermanoDer = nullptr;
  nodo->ultimoHIjo = false;
  return nodo;
}

ArbolHMIHDPADRE::ArbolHMIHDPADRE() { }

ArbolHMIHDPADRE::~ArbolHMIHDPADRE() { }

void ArbolHMIHDPADRE::Imprimir() {
  if (this->Vacio()) {
    std::cout << "El árbol está vacío." << std::endl;
    return;
  }
  std::queue<nodoArbol*> cola;
  cola.push(Raiz());
  while (!cola.empty()) {
    nodoArbol* nodoActual = cola.front();
    std::cout << nodoActual->etiqueta << " ";
    cola.pop();
    nodoArbol* nodoHijo = nodoActual->hijoMasIzq;
    while (nodoHijo != nullptr && nodoHijo->ultimoHIjo == false) {
      cola.push(nodoHijo);
      nodoHijo = nodoHijo->hermanoDer;
    }
    if (nodoHijo != nullptr) {
      cola.push(nodoHijo);
    }
  }
  std::cout << std::endl;
}
