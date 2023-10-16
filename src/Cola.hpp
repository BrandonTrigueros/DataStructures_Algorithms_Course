#include <iostream>

class Cola {
 public:
  struct queueNode {
    int val;
    queueNode* next;
  };

 private:
  queueNode* frenteCola;
  queueNode* finalCola;

 public:
  Cola(queueNode* frenteCola = nullptr, queueNode* finalCola = nullptr)
      : frenteCola(frenteCola)
      , finalCola(finalCola) {};
  ~Cola() {
    free(this->frenteCola);
    free(this->finalCola);
  };

  void iniciar();
  void destruir();
  void vaciar();
  bool vacia();
  void encolar(int e);
  queueNode* desencolar();
  queueNode* frente();
  queueNode* ultimo();
  int numElem();
  void imprimir();
};
