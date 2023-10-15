#include "Menu.hpp"

Menu::Menu() { }

Menu::~Menu() { }

void Menu::run() { }

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
  this->arbol->imprimir();
}
