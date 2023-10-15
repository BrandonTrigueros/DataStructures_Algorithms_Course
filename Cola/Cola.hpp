#include <iostream>

class Cola {
 private:
  struct queueNode {
    int val;
    queueNode* next;
  };

  queueNode* frenteCola;
  queueNode* finalCola;

 public:
  Cola(queueNode* frenteCola = nullptr, queueNode* finalCola = nullptr)
      : frenteCola(frenteCola)
      , finalCola(finalCola) {};
  ~Cola() {};

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
