#include "Menu.hpp"

Menu::Menu() { }

Menu::~Menu() { }

void Menu::run() {
  int opcion;
  do {
    opcion = mostrarPrincipal();
    switch (opcion) {
    case 1:
      this->cola = new Cola();
      this->runCola();
      break;
    case 2:
      this->arbol = new ARBOL();
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
    this->mostrarColaActual();
    opcion = mostrarOperadoresCola();
    switch (opcion) {
    case 1:
      this->cola->iniciar();
      break;
    case 2:
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
    case 5: {
      int e;
      std::cout << "Ingrese el número a encolar: ";
      std::cin >> e;
      this->cola->encolar(e);
      break;
    }
    case 6:
      int e = this->cola->desencolar()->val;
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
      std::cout << "Saliendo..." << std::endl;
      break;
    default:
      std::cout << "Opción inválida." << std::endl;
      break;
    }
  } while (opcion != 10);
}

void Menu::runArbol() { }

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
