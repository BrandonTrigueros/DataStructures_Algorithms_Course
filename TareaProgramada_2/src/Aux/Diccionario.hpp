// Modelo diccionario implementado por lista doblemente enlazada

#pragma once

template <typename T> struct Elemento {
  T valor;
  Elemento* siguiente;
  Elemento* previo;
};

template <typename T> class Diccionario {
 private:
  Elemento* primero;
  Elemento* ultimo;
  int64_t tamanno;

 public:
  void Iniciar() {
    this->primero = nullptr;
    this->tamanno = 0;
  }

  void Destruir() { this->Vaciar(); }

  void Vaciar() {
    Elemento* aux = this->primero;
    while (aux != nullptr) {
      Elemento* borrar = aux;
      aux = aux->siguiente;
      delete borrar;
    }
    dicc->tamanno = 0;
    this->primero = nullptr;
    this->ultimo = nullptr;
  }

  bool Vacio() { return this->tamanno == 0; }

  void Agregar(T valor) {
    Elemento* nuevo = new Elemento();
    nuevo->valor = valor;
    nuevo->siguiente = nullptr;
    nuevo->previo = nullptr;

    if (this->primero == nullptr) {
      this->primero = nuevo;
      this->ultimo = nuevo;
    } else {
      nuevo->previo = this->ultimo;
      this->ultimo->siguiente = nuevo;
      this->ultimo = nuevo;
    }
    this->tamanno++;
  }

  T Borrar(T valor) {
    Elemento* aux = this->primero;
    while (aux != nullptr && aux->valor != valor) {
      aux = aux->siguiente;
    }
    if (aux == nullptr) {
      return nullptr;
    }
    if (aux == this->primero) {
      this->primero = aux->siguiente;
      this->primero->previo = nullptr;
    } else if (aux == this->ultimo) {
      this->ultimo = aux->previo;
      this->ultimo->siguiente = nullptr;
    } else {
      aux->previo->siguiente = aux->siguiente;
      aux->siguiente->previo = aux->previo;
    }
    T valor = aux->valor;
    delete aux;
    this->tamanno--;
    return valor;
  }

  bool Pertenece(T valor) {
    Elemento* aux = this->primero;
    while (aux != nullptr && aux->valor != valor) {
      aux = aux->siguiente;
    }
    if (aux == nullptr) {
      return false;
    }
    return true;
  }

  int64_t NumElem() { return this->tamanno; }
};
