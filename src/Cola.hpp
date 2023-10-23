#include <iostream>

template<typename DataType>
class Cola {
 public:
  struct queueNode {
    DataType val;
    queueNode* next;
  };

 private:
  queueNode* frenteCola;
  queueNode* finalCola;

 public:
  Cola(queueNode* frenteCola = nullptr, queueNode* finalCola = nullptr)
      : frenteCola(frenteCola)
      , finalCola(finalCola) {};

  ~Cola() {};

  inline void iniciar() { this->frenteCola = this->finalCola = nullptr; }

  void destruir() {
    if (this->vacia()) {
      this->frenteCola = this->finalCola = nullptr;
      return;
    }
    this->vaciar();
  }

  void vaciar() {
    queueNode* it = this->frenteCola;
    while (it != nullptr) {
      queueNode* toDelete = it;
      it = it->next;
      delete toDelete;
    }
    this->frenteCola = this->finalCola = nullptr;
  }

  bool vacia() {
    if (this->frenteCola == nullptr) {
      return true;
    }
    return false;
  }

  void encolar(DataType e) {
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

  DataType desencolar() {
    queueNode* toDelete = this->frenteCola;
    DataType toReturn = toDelete->val;

    if (this->finalCola == this->frenteCola) {
      this->finalCola = nullptr;
      this->frenteCola = nullptr;
    } else {
      this->frenteCola = toDelete->next;
    }
    delete toDelete;

    return toReturn;
  }

  inline queueNode* frente() { return this->frenteCola; }

  inline queueNode* ultimo() { return this->finalCola; }

  int64_t numElem() {
    int64_t numElem = 0;
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

  void imprimir() {
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

};
