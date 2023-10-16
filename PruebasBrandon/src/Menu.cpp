#include "Menu.hpp"

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

void Menu::run() {
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

void Menu::runCola() {
  int opcion;
  do {
    opcion = mostrarOperadoresCola();
    int e = 0;
    switch (opcion) {
    case 1:
      this->cola = new Cola();
      this->cola->iniciar();
      break;
    case 2:
      if (this->cola == nullptr) {
        std::cout << "No hay una cola actualmente." << std::endl;
        break;
      }
      this->cola->destruir();
      break;
    case 3:
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
      std::cout << "Ingrese el número a encolar: ";
      std::cin >> e;
      this->cola->encolar(e);
      break;
    case 6:
      e = this->cola->desencolar()->val;
      std::cout << "Elemento desencolado: " << e << std::endl;
      break;
    case 7:
      if (this->cola->frente() == nullptr) {
        std::cout << "La cola está vacía." << std::endl;
      } else {
        std::cout << "Frente: " << this->cola->frente()->val << std::endl;
      }
      break;
    case 8:
      if (this->cola->ultimo() == nullptr) {
        std::cout << "La cola está vacía." << std::endl;
      } else {
        std::cout << "Último: " << this->cola->ultimo()->val << std::endl;
      }
      break;
    case 9:
      std::cout << "Número de elementos: " << this->cola->numElem()
                << std::endl;
      break;
    case 10:
      this->mostrarColaActual();
      break;
    case 11:
      std::cout << "Saliendo..." << std::endl;
      break;
    default:
      std::cout << "Opción inválida." << std::endl;
      break;
    }
  } while (opcion != 11);
}

void Menu::runArbol() {
  int opcion;
  do {
    opcion = mostrarOperadoresArbol();
    int n, p, e;
    switch (opcion) {
    case 1:
      this->arbol->Iniciar();
      break;
    case 2:
      this->arbol->Destruir();
      break;
    case 3:
      this->arbol->Vaciar();
      break;
    case 4:
      if (this->arbol->Vacio()) {
        std::cout << "El árbol está vacío." << std::endl;
      } else {
        std::cout << "El árbol no está vacío." << std::endl;
      }
      break;
    case 5:
      std::cout << "Ingrese el número a agregar: " << std::endl;
      std::cin >> e;
      std::cout << "Ingrese el nodo al que agregar el hijo: " << std::endl;
      std::cin >> n;
      std::cout << "Ingrese la posición del hijo: " << std::endl;
      std::cin >> p;
      this->arbol->AgregarHijo(this->arbol->BuscarEtiqueta(n), p, e);
      std::cout << "Hijo agregado." << std::endl;
      break;
    case 6:
      std::cout << "Ingrese el número de la hoja a borrar: \n";
      this->arbol->BorrarHoja(this->arbol->BuscarEtiqueta(e));
      std::cout << "Hoja borrada." << std::endl;
      break;
    case 7:
      std::cout << "Ingrese el número a poner como raíz: ";
      std::cin >> e;
      this->arbol->PonerRaiz(e);
      std::cout << "Raíz puesta." << std::endl;
      break;
    case 8:
      std::cout
          << "Ingrese el nodo del cuál desea obtener el hijo más izquierdo:";
      std::cin >> e;
      if (this->arbol->HijoMasIzq(this->arbol->BuscarEtiqueta(e)) != nullptr) {
        std::cout
            << "Hijo más izquierdo: "
            << this->arbol->HijoMasIzq(this->arbol->BuscarEtiqueta(e))->etiqueta
            << std::endl;
      } else {
        std::cout << "El nodo ingresado no tiene hijos." << std::endl;
      }
      break;
    case 9:
      std::cout << "Ingrese el nodo del cuál desea obtener el hermano derecho:";
      std::cin >> e;
      if (this->arbol->HermanoDer(this->arbol->BuscarEtiqueta(e)) != nullptr) {
        std::cout
            << "Hermano derecho: "
            << this->arbol->HermanoDer(this->arbol->BuscarEtiqueta(e))->etiqueta
            << std::endl;
      } else {
        std::cout << "El nodo ingresado no tiene hermano derecho." << std::endl;
      }
      break;
    case 10:
      std::cout << "Ingrese el nodo a modificar: ";
      std::cin >> n;
      std::cout << "Ingrese el nuevo valor: ";
      std::cin >> e;
      this->arbol->ModificarEtiqueta(this->arbol->BuscarEtiqueta(n), e);
      break;
    case 11:
      if (this->arbol->Raiz() == nullptr) {
        std::cout << "El árbol está vacío." << std::endl;
      } else {
        std::cout << "Raíz: " << this->arbol->Raiz()->etiqueta << std::endl;
      }
      break;
    case 12:
      std::cout << "Ingrese el nodo del cuál desea obtener el padre: ";
      std::cin >> n;
      if (n == this->arbol->Raiz()->etiqueta) {
        std::cout << "El nodo ingresado es la raíz. No tiene padre"
                  << std::endl;
      } else {
        std::cout
            << "Padre: "
            << this->arbol->Padre(this->arbol->BuscarEtiqueta(n))->etiqueta
            << std::endl;
      }
      break;
    case 13:
      std::cout << "Ingrese el nodo del cuál desea obtener la etiqueta: ";
      std::cin >> e;
      std::cout << "Etiqueta: "
                << this->arbol->Etiqueta(this->arbol->BuscarEtiqueta(e))
                << std::endl;
      break;
    case 14:
      std::cout
          << "Ingrese el nodo del cuál desea obtener el número de hijos: ";
      std::cin >> p;
      std::cout << "Número de hijos: "
                << this->arbol->NumHijos(this->arbol->BuscarEtiqueta(p))
                << std::endl;
      break;
    case 15:
      std::cout << "Ingrese el nodo del cuál desea saber si es hoja: ";
      std::cin >> n;
      if (this->arbol->EsHoja(this->arbol->BuscarEtiqueta(n))) {
        std::cout << "El nodo es una hoja." << std::endl;
      } else {
        std::cout << "El nodo no es una hoja." << std::endl;
      }
      break;
    case 16:
      std::cout << "Número de nodos: " << this->arbol->NumNodos() << std::endl;
      break;
    case 17:
      this->mostrarArbolActual();
      break;
    case 18:
      std::cout << "Saliendo..." << std::endl;
      break;
    default:
      std::cout << "Opción inválida." << std::endl;
      break;
    }
  } while (opcion != 18);
}

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
  if (this->arbol == nullptr) {
    std::cout << "No hay un árbol actualmente." << std::endl;
    return;
  }
  this->arbol->Imprimir();
}
