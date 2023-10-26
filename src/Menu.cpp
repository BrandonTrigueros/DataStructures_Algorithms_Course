#include "Menu.hpp"

#include <cstdint>

Menu::Menu() {
  this->cola = nullptr;
  this->arbol = nullptr;
}

Menu::~Menu() {
  if (this->cola != nullptr) {
    this->cola->destruir();
  }
  if (this->arbol != nullptr) {
    this->arbol->Destruir();
  }
}

// ----------------------------------
// ----------MENU PRINCIPAL----------
// ----------------------------------
void Menu::run() {
  // this->arbol = new ARBOL;
  // this->arbol->Iniciar();
  // this->arbol->PonerRaiz(1);
  // this->arbol->AgregarHijo(this->arbol->Raiz(), 1, 2);
  // this->arbol->AgregarHijo(this->arbol->Raiz(), 2, 3);
  // this->arbol->AgregarHijo(this->BuscarNodo(this->arbol, 2), 1, 4);
  // this->arbol->AgregarHijo(this->BuscarNodo(this->arbol, 2), 2, 5);
  // this->arbol->AgregarHijo(this->BuscarNodo(this->arbol, 3), 1, 6);
  // this->arbol->AgregarHijo(this->BuscarNodo(this->arbol, 6), 1, 7);
  // this->arbol->AgregarHijo(this->BuscarNodo(this->arbol, 7), 1, 8);
  // this->arbol->AgregarHijo(this->BuscarNodo(this->arbol, 2), 2, 9);
  // this->arbol->AgregarHijo(this->BuscarNodo(this->arbol, 9), 1, 10);
  // this->arbol->AgregarHijo(this->BuscarNodo(this->arbol, 9), 2, 11);
  // this->arbol->AgregarHijo(this->BuscarNodo(this->arbol, 11), 1, 12);
  // this->arbol->AgregarHijo(this->BuscarNodo(this->arbol, 12), 1, 13);
  // this->arbol->AgregarHijo(this->BuscarNodo(this->arbol, 6), 2, 14);
  // this->arbol->AgregarHijo(this->BuscarNodo(this->arbol, 6), 1, 15);

  // std::cout << "Niveles: " << this->NivelesArbolPreOrden(this->arbol)
  //           << std::endl;
  // std::cout << "Niveles: " << this->NivelesArbolNiveles(this->arbol)
  //           << std::endl;
  // this->ListarEtiquetasNivel_I(this->arbol, 4);

  int opcion;
  do {
    opcion = mostrarPrincipal();
    switch (opcion) {
    case 1:
      this->runCola();
      break;
    case 2:
      this->runArbol();
      break;
    case 3:
      mostrarCreditos();
      break;
    case 4:
      std::cout << "Saliendo..." << std::endl;
      break;
    default:
      std::cout << "Opción inválida." << std::endl;
      break;
    }
  } while (opcion != 4);
}

// -----------------------------
// ----------MENU COLA----------
// -----------------------------
void Menu::runCola() {
  int opcion;
  do {
    opcion = mostrarOperadoresCola();
    int e = 0;
    switch (opcion) {
    case 1:
      this->cola = new Cola<int64_t>();
      this->cola->iniciar();
      break;
    case 2:
      if (this->cola == nullptr) {
        std::cout << "No hay una cola actualmente." << std::endl;
        break;
      }
      this->cola->destruir();
      delete this->cola;
      this->cola = nullptr;
      break;
    case 3:
      if (this->cola == nullptr) {
        std::cout << "No hay una cola actualmente." << std::endl;
        break;
      }
      if (this->cola->vacia()) {
        std::cout << "La cola está vacía." << std::endl;
        break;
      }
      this->cola->vaciar();
      break;
    case 4:
      if (this->cola->vacia()) {
        std::cout << "La cola está vacía." << std::endl;
      } else {
        std::cout << "La cola no está vacía." << std::endl;
      }
      break;
    case 5:
      if (this->cola == nullptr) {
        std::cout << "No hay una cola actualmente." << std::endl;
        break;
      }
      std::cout << "Ingrese el número a encolar: ";
      std::cin >> e;
      this->cola->encolar(e);
      break;
    case 6:
      if (this->cola == nullptr) {
        std::cout << "No hay una cola actualmente." << std::endl;
        break;
      }
      std::cout << "Elemento desencolado: " << cola->desencolar() << std::endl;
      break;
    case 7:
      if (this->cola == nullptr) {
        std::cout << "No hay una cola actualmente." << std::endl;
        break;
      }
      if (this->cola->frente() == nullptr) {
        std::cout << "La cola está vacía." << std::endl;
      } else {
        std::cout << "Frente: " << this->cola->frente()->val << std::endl;
      }
      break;
    case 8:
      if (this->cola == nullptr) {
        std::cout << "No hay una cola actualmente." << std::endl;
        break;
      }
      if (this->cola->ultimo() == nullptr) {
        std::cout << "La cola está vacía." << std::endl;
      } else {
        std::cout << "Último: " << this->cola->ultimo()->val << std::endl;
      }
      break;
    case 9:
      if (this->cola == nullptr) {
        std::cout << "No hay una cola actualmente." << std::endl;
        break;
      }
      std::cout << "Número de elementos: " << this->cola->numElem()
                << std::endl;
      break;
    case 10:
      this->mostrarColaActual();
      break;
    case 11:
      std::cout << "Saliendo..." << std::endl;
      if (this->cola == nullptr) {
        break;
      }
      this->cola->vaciar();
      delete this->cola;
      this->cola = nullptr;
      break;
    default:
      std::cout << "Opción inválida." << std::endl;
      break;
    }
  } while (opcion != 11);
}

// ------------------------------
// ----------MENU ARBOL----------
// ------------------------------
void Menu::runArbol() {
  int opcion;
  do {
    opcion = mostrarOperadoresArbol();
    int n, p, e;
    switch (opcion) {
    case 1:
      this->arbol = new ARBOL;
      this->arbol->Iniciar();
      break;
    case 2:
      if (this->arbol == nullptr) {
        std::cout << "No hay un árbol actualmente." << std::endl;
      } else {
        this->arbol->Destruir();
        delete this->arbol;
        this->arbol = nullptr;
      }
      break;
    case 3:
      if (this->arbol == nullptr) {
        std::cout << "No hay un árbol actualmente." << std::endl;
      } else {
        this->arbol->Vaciar();
      }
      break;
    case 4:
      if (this->arbol == nullptr || this->arbol->Vacio()) {
        std::cout << "El árbol está vacío." << std::endl;
      } else {
        std::cout << "El árbol no está vacío." << std::endl;
      }
      break;
    case 5:
      if (this->arbol == nullptr) {
        std::cout << "No hay un árbol actualmente." << std::endl;
      } else {
        std::cout << "Ingrese el número a agregar: ";
        std::cin >> e;
        std::cout << "Ingrese el nodo al que agregar el hijo: ";
        std::cin >> n;
        std::cout << "Ingrese la posición del hijo: ";
        std::cin >> p;
        this->arbol->AgregarHijo(this->BuscarNodo(this->arbol, n), p, e);
        std::cout << "Hijo agregado." << std::endl;
      }
      break;
    case 6:
      if (this->arbol == nullptr) {
        std::cout << "No hay un árbol actualmente." << std::endl;
      } else {
        std::cout << "Ingrese el número de la hoja a borrar: ";
        std::cin >> e;
        this->arbol->BorrarHoja(this->BuscarNodo(this->arbol, e));
        std::cout << "Hoja borrada." << std::endl;
      }
      break;
    case 7:
      if (this->arbol == nullptr) {
        std::cout << "No hay un árbol actualmente." << std::endl;
      } else {
        std::cout << "Ingrese el número a poner como raíz: ";
        std::cin >> e;
        this->arbol->PonerRaiz(e);
        std::cout << "Raíz puesta." << std::endl;
      }
      break;
    case 8:
      if (this->arbol == nullptr) {
        std::cout << "No hay un árbol actualmente." << std::endl;
      } else {
        std::cout
            << "Ingrese el nodo del cuál desea obtener el hijo más izquierdo: ";
        std::cin >> e;
        if (this->arbol->HijoMasIzq(this->BuscarNodo(this->arbol, e))
            != nullptr) {
          std::cout << "Hijo más izquierdo: "
                    << this->arbol->HijoMasIzq(this->BuscarNodo(this->arbol, e))
                           ->etiqueta
                    << std::endl;
        } else {
          std::cout << "El nodo ingresado no tiene hijos." << std::endl;
        }
      }
      break;
    case 9:
      if (this->arbol == nullptr) {
        std::cout << "No hay un árbol actualmente." << std::endl;
      } else {
        std::cout
            << "Ingrese el nodo del cuál desea obtener el hermano derecho: ";
        std::cin >> e;
        if (this->arbol->HermanoDer(this->BuscarNodo(this->arbol, e))
            != nullptr) {
          std::cout << "Hermano derecho: "
                    << this->arbol->HermanoDer(this->BuscarNodo(this->arbol, e))
                           ->etiqueta
                    << std::endl;
        } else {
          std::cout << "El nodo ingresado no tiene hermano derecho."
                    << std::endl;
        }
      }
      break;
    case 10:
      if (this->arbol == nullptr) {
        std::cout << "No hay un árbol actualmente." << std::endl;
      } else {
        std::cout << "Ingrese el nodo a modificar: ";
        std::cin >> n;
        std::cout << "Ingrese el nuevo valor: ";
        std::cin >> e;
        this->arbol->ModificarEtiqueta(this->BuscarNodo(this->arbol, n), e);
      }
      break;
    case 11:
      if (this->arbol == nullptr || this->arbol->Raiz() == nullptr) {
        std::cout << "El árbol está vacío." << std::endl;
      } else {
        std::cout << "Raíz: " << this->arbol->Raiz()->etiqueta << std::endl;
      }
      break;
    case 12:
      if (this->arbol == nullptr) {
        std::cout << "No hay un árbol actualmente." << std::endl;
      } else {
        std::cout << "Ingrese el nodo del cuál desea obtener el padre: ";
        std::cin >> n;
        if (n == this->arbol->Raiz()->etiqueta) {
          std::cout << "El nodo ingresado es la raíz. No tiene padre."
                    << std::endl;
        } else {
          std::cout
              << "Padre: "
              << this->arbol->Padre(this->BuscarNodo(this->arbol, n))->etiqueta
              << std::endl;
        }
      }
      break;
    case 13:
      if (this->arbol == nullptr) {
        std::cout << "No hay un árbol actualmente." << std::endl;
      } else {
        std::cout << "Ingrese el nodo del cuál desea obtener la etiqueta: ";
        std::cin >> e;
        std::cout << "Etiqueta: "
                  << this->arbol->Etiqueta(this->BuscarNodo(this->arbol, e))
                  << std::endl;
      }
      break;
    case 14:
      if (this->arbol == nullptr) {
        std::cout << "No hay un árbol actualmente." << std::endl;
      } else {
        std::cout
            << "Ingrese el nodo del cuál desea obtener el número de hijos: ";
        std::cin >> p;
        std::cout << "Número de hijos: "
                  << this->arbol->NumHijos(this->BuscarNodo(this->arbol, p))
                  << std::endl;
      }
      break;
    case 15:
      if (this->arbol == nullptr) {
        std::cout << "No hay un árbol actualmente." << std::endl;
      } else {
        std::cout << "Ingrese el nodo del cuál desea saber si es hoja: ";
        std::cin >> n;
        if (this->arbol->EsHoja(this->BuscarNodo(this->arbol, n))) {
          std::cout << "El nodo es una hoja." << std::endl;
        } else {
          std::cout << "El nodo no es una hoja." << std::endl;
        }
      }
      break;
    case 16:
      if (this->arbol == nullptr) {
        std::cout << "No hay un árbol actualmente." << std::endl;
      } else {
        std::cout << "Número de nodos: " << this->arbol->NumNodos()
                  << std::endl;
      }
      break;
    case 17:
      if (this->arbol == nullptr) {
        std::cout << "No hay un árbol actualmente." << std::endl;
        break;
      }
      this->mostrarArbolActual();
      break;
    case 18:
      std::cout << "Saliendo..." << std::endl;
      if (this->arbol != nullptr) {
        this->arbol->Destruir();
        delete this->arbol;
        this->arbol = nullptr;
      }
      break;
    default:
      std::cout << "Opción inválida." << std::endl;
      break;
    }
  } while (opcion != 18);
}

// --------------------------------------
// ----------MÉTODOS AUXILIARES----------
// --------------------------------------
int Menu::mostrarPrincipal() {
  int opcion;
  std::cout << OPCIONES_PRINCIPAL;
  std::cin >> opcion;
  return opcion;
}

int Menu::mostrarOperadoresArbol() {
  int opcion;
  std::cout << OPERADORES_ARBOL;
  std::cin >> opcion;
  return opcion;
}

int Menu::mostrarOperadoresCola() {
  int opcion;
  std::cout << OPERADORES_COLA;
  std::cin >> opcion;
  return opcion;
}

void Menu::mostrarCreditos() { std::cout << CREDITOS; }

void Menu::mostrarColaActual() {
  if (this->cola == nullptr) {
    std::cout << "No hay una cola actualmente." << std::endl;
    return;
  }
  this->cola->imprimir();
}

void Menu::mostrarArbolActual() {
  if (this->arbol->Vacio()) {
    std::cout << "El árbol está vacío." << std::endl;
    return;
  }
  this->arbol->Imprimir();
}

// -----------------------------
// -----ALGORITMOS ETAPA 3------
// -----------------------------

NODO* Menu::BuscarNodo(ARBOL* a, int64_t etiqueta) {
  bool nodoEncontrado = false;
  NODO* nodoActual = nullptr;
  Cola<NODO*> colaNodo;
  colaNodo.iniciar();
  colaNodo.encolar(a->Raiz());
  while (!colaNodo.vacia() && !nodoEncontrado) {
    nodoActual = colaNodo.desencolar();
    if (nodoActual->etiqueta == etiqueta) {
      nodoEncontrado = true;
      colaNodo.destruir();
      return nodoActual;
    }

    NODO* nodoHijo = a->HijoMasIzq(nodoActual);
    while (nodoHijo != nullptr && !nodoEncontrado) {
      colaNodo.encolar(nodoHijo);
      nodoHijo = a->HermanoDer(nodoHijo);
    }
  }
  colaNodo.destruir();
  return nullptr;
}

NODO* Menu::HermanoIzquierdo(ARBOL* a, NODO* n) {
  if (a->Raiz() == n) {
    return nullptr;
  }
  NODO* nodoActual = nullptr;
  NODO* nodoHermanoIzquierdo = nullptr;
  Cola<NODO*> colaNodo;
  colaNodo.iniciar();
  colaNodo.encolar(a->Raiz());
  while (!colaNodo.vacia()) {
    nodoActual = colaNodo.desencolar();
    NODO* nodoHijo = a->HijoMasIzq(nodoActual);
    if (nodoHijo == n) {
      colaNodo.destruir();
      return nullptr;
    }
    while (nodoHijo != nullptr) {
      colaNodo.encolar(nodoHijo);
      nodoHermanoIzquierdo = nodoHijo;
      nodoHijo = a->HermanoDer(nodoHijo);
      if (nodoHijo == n) {
        colaNodo.destruir();
        return nodoHermanoIzquierdo;
      }
    }
  }
  colaNodo.destruir();
  return nullptr;
}

bool Menu::EtiquetasRepetidas(ARBOL* a) {
  bool etiquetasRepetidas = false;
  if (!a->Vacio()) {
    NODO* nodoActual = nullptr;
    NODO* nodoHijo = nullptr;
    Cola<NODO*> colaNodo;
    colaNodo.iniciar();
    std::map<std::int64_t, bool> diccionario;
    colaNodo.encolar(a->Raiz());
    diccionario[a->Etiqueta(a->Raiz())] = true;
    while (!colaNodo.vacia() && etiquetasRepetidas != true) {
      nodoActual = colaNodo.desencolar();
      nodoHijo = a->HijoMasIzq(nodoActual);
      while (nodoHijo != nullptr) {
        colaNodo.encolar(nodoHijo);
        if (diccionario.find(a->Etiqueta(nodoHijo)) != diccionario.end()) {
          etiquetasRepetidas = true;
        } else {
          diccionario[a->Etiqueta(nodoHijo)] = true;
          nodoHijo = a->HermanoDer(nodoHijo);
        }
      }
    }
    colaNodo.destruir();
  }
  return etiquetasRepetidas;
}

void AlturaNodoAux(ARBOL* a, NODO* n, int64_t* height, int64_t i) { 
  if (i > *height) {
    *height = i;
  }

  NODO* nodoHijo = a->HijoMasIzq(n);
  while (nodoHijo != nullptr) {
    AlturaNodoAux(a, nodoHijo, height, i + 1);
    nodoHijo = a->HermanoDer(nodoHijo);
  }
}

int64_t Menu::AlturaNodo(ARBOL* a, NODO* n) { 
  int64_t height = 0;
  AlturaNodoAux(a, n, &height , 0);
  return height; 
}

int64_t ProfundidadNodoAux(ARBOL* t, NODO* a, NODO* n, int64_t i) {
  NODO* NodoActual = t->HijoMasIzq(a);
  if (a == n) {
    return i;
  } else {
    while (NodoActual != nullptr) {
      ProfundidadNodoAux(t, NodoActual, n, i + 1);
      NodoActual = t->HermanoDer(NodoActual);
    }
  }
  return 0;
}

int64_t Menu::ProfundidadNodo(ARBOL* a, NODO* n) {
  if (a->Raiz() == nullptr) {
    return 0;
  }
  if (a->Raiz() == n) {
    return 1;
  }
  int64_t Profundidad = ProfundidadNodoAux(a, a->Raiz(), n, 1);
  return Profundidad;
}

void NivelesArbolPreOrdenAux(ARBOL* a, NODO* n, int64_t i, int64_t& niveles) {
  if (i > niveles) {
    niveles = i;
  }
  NODO* nodoHijo = a->HijoMasIzq(n);
  if (nodoHijo != nullptr) {
    i++;
  }
  while (nodoHijo != nullptr) {
    NivelesArbolPreOrdenAux(a, nodoHijo, i, niveles);
    nodoHijo = a->HermanoDer(nodoHijo);
  }
}

int64_t Menu::NivelesArbolPreOrden(ARBOL* a) {
  int64_t niveles = 0;
  if (a->Raiz() != nullptr) {
    NivelesArbolPreOrdenAux(a, a->Raiz(), 1, niveles);
  }
  return niveles;
}

int64_t Menu::NivelesArbolNiveles(ARBOL* a) {
  int64_t niveles = 0;
  if (a->Raiz() != nullptr) {
    NODO* nodoActual = nullptr;
    NODO* nodoHijo = nullptr;
    Cola<NODO*> colaNodo;
    colaNodo.iniciar();
    colaNodo.encolar(a->Raiz());
    while (!colaNodo.vacia()) {
      niveles++;
      int64_t cantidadNodosNivelActual = colaNodo.numElem();
      for (int64_t i = 0; i < cantidadNodosNivelActual; i++) {
        nodoActual = colaNodo.desencolar();
        nodoHijo = a->HijoMasIzq(nodoActual);
        while (nodoHijo != nullptr) {
          colaNodo.encolar(nodoHijo);
          nodoHijo = a->HermanoDer(nodoHijo);
        }
      }
    }
    colaNodo.destruir();
  }
  return niveles;
}

void Menu::ListarEtiquetasNivel_I(ARBOL* a, int64_t i) {
  if (a->Raiz() != nullptr) {
    NODO* nodoActual = nullptr;
    NODO* nodoHijo = nullptr;
    Cola<NODO*> colaNodo;
    colaNodo.iniciar();
    colaNodo.encolar(a->Raiz());
    int64_t nivelActual = 1;
    while (!colaNodo.vacia()) {
      int64_t cantidadNodosNivelActual = colaNodo.numElem();
      for (int64_t j = 0; j < cantidadNodosNivelActual; j++) {
        nodoActual = colaNodo.desencolar();
        if (nivelActual == i) {
          std::cout << a->Etiqueta(nodoActual) << " ";
        }
        nodoHijo = a->HijoMasIzq(nodoActual);
        while (nodoHijo != nullptr) {
          colaNodo.encolar(nodoHijo);
          nodoHijo = a->HermanoDer(nodoHijo);
        }
      }
      nivelActual++;
    }
    colaNodo.destruir();
  }
}


void ListarArbolPreOrdenAux(ARBOL* a, NODO* n) {
  NODO* nodoHijo = a->HijoMasIzq(n);
  while (nodoHijo != nullptr) {
    std::cout << n->etiqueta << std::endl;
    ListarArbolPreOrdenAux(a, nodoHijo);
    nodoHijo = a->HermanoDer(nodoHijo);
  }
}

void Menu::ListarArbolPreOrden(ARBOL* a) {
  if (a->Raiz() == nullptr) {
    std::cout << "Arbol Vacio" << std::endl;
  }
  ListarArbolPreOrdenAux(a, a->Raiz());
}

void Menu::ListarArbolNiveles(ARBOL* a) {
  NODO* nodoActual = nullptr;
  NODO* nodoHijo = nullptr;

  Cola<NODO*> colaNodo;    
  colaNodo.iniciar();
  colaNodo.encolar(a->Raiz());

  while (!colaNodo.vacia()) {
    nodoActual = colaNodo.desencolar();
    std::cout << colaNodo.frente()->val << std::endl; 

    nodoHijo = a->HijoMasIzq(nodoActual);
    while (nodoHijo != nullptr) {
      colaNodo.encolar(nodoHijo);
      nodoHijo = a->HermanoDer(nodoHijo);
    }
  }
  colaNodo.destruir();
}

void BorrarSubArbolAux(ARBOL* a, NODO* n) {
  NODO* nodoHijo = a->HijoMasIzq(n);
  while (nodoHijo!= nullptr) {
    BorrarSubArbolAux(a, n);
    nodoHijo = a->HermanoDer(nodoHijo);
  }
  a->BorrarHoja(n);
}

void Menu::BorrarSubArbol(ARBOL* a, NODO* n) {
  if (a->Raiz() == n) {
    a->BorrarHoja(n);
  }

  NODO* nodoBorrar = nullptr;
  nodoBorrar = BuscarNodo(a, n->etiqueta);
  BorrarSubArbolAux(a, nodoBorrar);
}


void Menu::ListarHijosNodos(ARBOL* a, NODO* n) {
  NODO* nodoActual = nullptr;
  NODO* nodoHijo = nullptr;
  bool salir = false;

  Cola<NODO*> colaNodo;    
  colaNodo.iniciar();
  colaNodo.encolar(a->Raiz());

  while (!colaNodo.vacia() && !salir) {
    nodoActual = colaNodo.desencolar();
    nodoHijo = a->HijoMasIzq(nodoActual);
    if (nodoActual == n && !nodoHijo) {
      salir = true;
    }
    while (nodoHijo != nullptr) {
      if (nodoActual == n) {
        std::cout << nodoHijo->etiqueta << " ";
      } 
      colaNodo.encolar(nodoHijo);
      nodoHijo = a->HermanoDer(nodoHijo);
    }
    std::cout << std::endl; 
  }
  colaNodo.destruir();
}
