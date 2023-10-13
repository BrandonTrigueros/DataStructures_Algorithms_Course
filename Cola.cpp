#include "Cola.hpp"

void Cola::iniciar() {
  Cola* cola = new Cola();
  *this = *cola;
}

void Cola::destruir(){
  if (this->vacia()) {
    delete this;
  }
  queueNode* it = this->frenteCola;
  while (it->next != nullptr) {
    queueNode* toDelete = it;
    it = it->next;
    delete toDelete;
  }
  delete this;
}

void Cola::vaciar(){
  queueNode* it = this->frenteCola;
  while (it->next != nullptr) {
    queueNode* toDelete = it;
    it = it->next;
    delete toDelete;
  }
  this->frenteCola = this->finalCola = nullptr;
}

bool Cola::vacia(){
  if (this->frenteCola == nullptr) {
    return true;
  }
  return false;
}

void Cola::encolar(int e){
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

int Cola::desencolar(){
  queueNode* toDelete = this->frenteCola;
  int toReturn = toDelete->val;

  if (this->finalCola == this->frenteCola) {
    this->finalCola = nullptr;
    this->frenteCola = nullptr;
  } else {
    this->frenteCola = toDelete->next;
  }
  delete toDelete;

  return toReturn;
}

int Cola::frente(){
  return this->frenteCola->val;
}

int Cola::ultimo(){
  return this->finalCola->val;
}

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

