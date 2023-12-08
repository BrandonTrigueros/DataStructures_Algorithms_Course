// Modelo diccionario implementado por lista doblemente enlazada

#pragma once

template <typename T> struct Elemento {
  T valor;
  Elemento* siguiente;
  Elemento* previo;
};

template <typename T> class Diccionario {
 private:
  Elemento<T>* primero;
  Elemento<T>* ultimo;
  int64_t tamanno;

 public:
  Diccionario() { }

  ~Diccionario() { }

  void Iniciar() {
    this->primero = nullptr;
    this->ultimo = nullptr;
    this->tamanno = 0;
  }

  void Destruir() { this->Vaciar(); }

  void Vaciar() {
    Elemento<T>* aux = this->primero;
    while (aux != nullptr) {
      Elemento<T>* borrar = aux;
      aux = aux->siguiente;
      delete borrar;
    }
    this->tamanno = 0;
    this->primero = nullptr;
    this->ultimo = nullptr;
  }

  bool Vacio() { return this->tamanno == 0; }

  void Agregar(T valor) {
    Elemento<T>* nuevo = new Elemento<T>();
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
    Elemento<T>* aux = this->primero;
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
    T val = aux->valor;
    delete aux;
    this->tamanno--;
    return val;
  }

  bool Pertenece(T valor) {
    Elemento<T>* aux = this->primero;
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
