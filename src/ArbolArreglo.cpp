#include "ArbolArreglo.hpp"

void ArbolArreglo::Iniciar() {
  this->capacidad = 200000;
  this->ultimoLleno = -1;
  this->arreglo = new nodo[this->capacidad];
}

void ArbolArreglo::Destruir() {
  if (!this->Vacio()) {
    this->Vaciar();
  }
  delete[] this->arreglo;
}

void ArbolArreglo::Vaciar() { this->ultimoLleno = -1; }

bool ArbolArreglo::Vacio() {
  if (this->ultimoLleno == -1) {
    return true;
  }
  return false;
}

nodo* ArbolArreglo::AgregarHijo(
    nodo* padre, int64_t numHijo, int64_t etiquetaHijo) {
  int64_t indicePadre = 0;
  while (this->arreglo[indicePadre].etiqueta != padre->etiqueta) {
    indicePadre++;
  }
  int64_t posCorrimiento = 0;
  // Si me piden agregarlo como ultimo hijo
  if (numHijo == this->NumHijos(padre) + 1) {
    this->arreglo[this->ultimoLleno + 1].etiqueta = etiquetaHijo;
    this->arreglo[this->ultimoLleno + 1].padre = indicePadre;
    this->ultimoLleno++;
    posCorrimiento = this->ultimoLleno;
  } else {
    posCorrimiento = indicePadre + 1;
    int64_t hijosEncontrados = 0;
    while (hijosEncontrados < numHijo - 1) {
      if (this->arreglo[posCorrimiento].padre == indicePadre) {
        hijosEncontrados++;
      }
      posCorrimiento++;
    }
    for (int64_t i = this->ultimoLleno; i >= posCorrimiento; i--) {
      this->arreglo[i + 1] = this->arreglo[i];
      if (this->arreglo[i].padre >= posCorrimiento) {
        this->arreglo[i + 1].padre++;
      }
    }
    this->arreglo[posCorrimiento].etiqueta = etiquetaHijo;
    this->arreglo[posCorrimiento].padre = indicePadre;
    this->ultimoLleno++;
  }
  return &this->arreglo[posCorrimiento];
}

void ArbolArreglo::BorrarHoja(nodo* hoja) {
  int64_t indiceHoja = 0;
  while (this->arreglo[indiceHoja].etiqueta != hoja->etiqueta) {
    indiceHoja++;
  }
  for (int64_t i = indiceHoja; i < this->ultimoLleno; i++) {
    this->arreglo[i] = this->arreglo[i + 1];
    if (this->arreglo[i].padre > indiceHoja) {
      this->arreglo[i].padre--;
    }
  }
  this->ultimoLleno--;
}

void ArbolArreglo::PonerRaiz(int64_t etiqueta) {
  this->arreglo[0].etiqueta = etiqueta;
  this->arreglo[0].padre = -1;
  this->ultimoLleno = 0;
}

nodo* ArbolArreglo::HijoMasIzq(nodo* nodo) {
  int64_t indicePadre = 0;
  while (this->arreglo[indicePadre].etiqueta != nodo->etiqueta) {
    indicePadre++;
  }
  int64_t indiceHijo = indicePadre + 1;
  while (indiceHijo <= this->ultimoLleno
      && this->arreglo[indiceHijo].padre != indicePadre) {
    indiceHijo++;
  }
  if (indiceHijo <= this->ultimoLleno) {
    return &this->arreglo[indiceHijo];
  }
  return nullptr;
}

nodo* ArbolArreglo::HermanoDer(nodo* nodo) {
  int64_t indiceNodo = 0;
  while (this->arreglo[indiceNodo].etiqueta != nodo->etiqueta) {
    indiceNodo++;
  }
  int64_t indiceHermDer = indiceNodo + 1;
  while (indiceHermDer <= this->ultimoLleno
      && this->arreglo[indiceHermDer].padre != nodo->padre) {
    indiceHermDer++;
  }
  if (indiceHermDer <= this->ultimoLleno) {
    return &this->arreglo[indiceHermDer];
  }
  return nullptr;
}

void ArbolArreglo::ModificarEtiqueta(nodo* nodo, int64_t etiqueta) {
  int64_t indiceNodo = 0;
  while (this->arreglo[indiceNodo].etiqueta != nodo->etiqueta) {
    indiceNodo++;
  }
  this->arreglo[indiceNodo].etiqueta = etiqueta;
}

nodo* ArbolArreglo::Raiz() { return &this->arreglo[0]; }

nodo* ArbolArreglo::Padre(nodo* nodo) { return &this->arreglo[nodo->padre]; }

int64_t ArbolArreglo::Etiqueta(nodo* nodo) {
  int64_t indiceNodo = 0;
  while (this->arreglo[indiceNodo].etiqueta != nodo->etiqueta) {
    indiceNodo++;
  }
  return this->arreglo[indiceNodo].etiqueta;
}

int64_t ArbolArreglo::NumHijos(nodo* nodo) {
  int64_t NumHijos = 0;
  int64_t indicePadre = 0;
  while (this->arreglo[indicePadre].etiqueta != nodo->etiqueta) {
    indicePadre++;
  }
  for (int64_t i = 0; i <= this->ultimoLleno; i++) {
    if (this->arreglo[i].padre == indicePadre) {
      NumHijos++;
    }
  }
  return NumHijos;
}

bool ArbolArreglo::EsHoja(nodo* nodo) {
  int64_t indiceNodo = 0;
  while (this->arreglo[indiceNodo].etiqueta != nodo->etiqueta) {
    indiceNodo++;
  }

  for (int64_t i = indiceNodo; i <= this->ultimoLleno; i++) {
    if (this->arreglo[i].padre == i) {
      return false;
    }
  }
  return true;
}

int64_t ArbolArreglo::NumNodos() { return this->ultimoLleno + 1; }

void ArbolArreglo::Imprimir() {
  for (int64_t i = 0; i <= this->ultimoLleno; i++) {
    if (this->arreglo[i].padre == -1) {
      std::cout << "[" << this->arreglo[i].etiqueta << "|P: NULL] ";
    } else {
      std::cout << "[" << this->arreglo[i].etiqueta
                << "|P: " << this->arreglo[this->arreglo[i].padre].etiqueta
                << "] - ";
    }
  }
  std::cout << std::endl;
}
