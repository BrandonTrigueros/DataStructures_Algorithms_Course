#include "Cola.hpp"

void Cola::iniciar() {
  this->frenteCola = this->finalCola = nullptr;
}

void Cola::destruir() {
  queueNode* it = this->frenteCola;
  while (it->next != nullptr) {
    queueNode* toDelete = it;
    it = it->next;
    delete toDelete;
  }
  this->frenteCola = this->finalCola = nullptr;
}

void Cola::vaciar() {
  queueNode* it = this->frenteCola;
  while (it->next != nullptr) {
    queueNode* toDelete = it;
    it = it->next;
    delete toDelete;
  }
  this->frenteCola = this->finalCola = nullptr;
}

bool Cola::vacia() {
  if (this->frenteCola == nullptr) {
    return true;
  }
  return false;
}

void Cola::encolar(int e) {
  queueNode* toQueue = new queueNode();
  toQueue->next = nullptr;
  toQueue->val = e;

  if (this->finalCola == nullptr) {
    this->finalCola = toQueue;
    this->frenteCola = toQueue;
  } else {
    this->finalCola->next = toQueue;
    this->finalCola = toQueue;
  }
}

Cola::queueNode* Cola::desencolar() {
  queueNode* toDelete = this->frenteCola;
  Cola::queueNode* toReturn = toDelete;

  if (this->finalCola == this->frenteCola) {
    this->finalCola = nullptr;
    this->frenteCola = nullptr;
  } else {
    this->frenteCola = toDelete->next;
  }
  delete toDelete;

  return toReturn;
}

Cola::queueNode* Cola::frente() { return this->frenteCola; }

Cola::queueNode* Cola::ultimo() { return this->finalCola; }

int Cola::numElem() {
  int numElem = 0;
  if (vacia()) {
    return numElem;
  }

  queueNode* it = this->frenteCola;
  ++numElem;

  while (it->next != nullptr) {
    ++numElem;
    it = it->next;
  }
  return numElem;
}

void Cola::imprimir() {
  if (this->vacia()) {
    std::cout << "La cola está vacía." << std::endl;
    return;
  }

  queueNode* it = this->frenteCola;
  std::cout << "Cola: ";
  while (it->next != nullptr) {
    std::cout << it->val << " - ";
    it = it->next;
  }
  std::cout << it->val << std::endl;
}
