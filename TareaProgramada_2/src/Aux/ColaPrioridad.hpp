#pragma once

#include <iostream>
#include <queue>

template <typename TypeData> class ColaPrioridad {
 private:
  struct QueueNode {
    TypeData data;
    int64_t priority;
    QueueNode(const TypeData& item, int p)
        : data(item)
        , priority(p) { }
    bool operator<(const QueueNode& other) const {
      return priority > other.priority;
    }
  };

  std::priority_queue<QueueNode> pq;

 public:
  void push(const TypeData& item, int priority) {
    // std::cout << "pushing with priority " << priority << std::endl;
    this->pq.push(QueueNode(item, priority));
  }

  TypeData pop() {
    TypeData element = this->top();
    this->pq.pop();
    return element;
  }

  TypeData top() const { return this->pq.top().data; }

  bool empty() const { return this->pq.empty(); }

  size_t size() const { return this->pq.size(); }

  bool existe(TypeData& item) {
    std::priority_queue<QueueNode> copiaPQ
        = pq;  // Realizar una copia de la cola de prioridad

    // Buscar el elemento en la copia de la cola de prioridad
    while (!copiaPQ.empty()) {
      if (copiaPQ.top().data == item) {
        return true;  // Elemento encontrado
      }
      copiaPQ.pop();
    }

    return false;  // Elemento no encontrado
  }
};
