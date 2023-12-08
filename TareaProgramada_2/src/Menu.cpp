#include "Menu.hpp"

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <ctime>
#include <limits>
#include <ostream>
#include <sched.h>
#include <system_error>
#include <time.h>
#include <unistd.h>

#include "Aux/ColaPrioridad.hpp"
#include "Aux/Diccionario.hpp"

Menu::Menu() { this->grafo = nullptr; }

Menu::~Menu() {
  if (this->grafo != nullptr) {
    this->grafo->Destruir();
  }
}

double log(double base, double x) { return std::log(x) / std::log(base); }

int64_t profPrimR(
    GRAFO* g, Vertice* vertAct, std::set<Vertice*>& dicVertVis, int64_t& count);

// void Menu::crearGrafoAuto() { }

// ----------------------------------
// ----------MENU PRINCIPAL----------
// ----------------------------------
void Menu::run() {
  // crearGrafoAuto(10, 3);

  int opcion;
  do {
    opcion = mostrarPrincipal();
    switch (opcion) {
    case 1:
      this->runGrafo();
      break;
    case 2:
      mostrarCreditos();
      break;
    case 3:
      std::cout << "Saliendo..." << std::endl;
      break;
    default:
      std::cout << "Opción inválida." << std::endl;
      break;
    }
  } while (opcion != 3);
}

// ------------------------------
// ----------MENU GRAFO----------
// ------------------------------
void Menu::runGrafo() {
  int opcion;
  bool salir = false;
  std::string etiq;
  std::string etiq1;
  Vertice* vertice = nullptr;
  Vertice* vertice1 = nullptr;
  double peso;
  do {
    opcion = mostrarOperadoresGrafo();
    switch (opcion) {
    case 1:
      this->grafo = new GRAFO;
      this->grafo->Iniciar();
      break;
    case 2:
      if (this->grafo == nullptr) {
        std::cout << "No hay un grafo actualmente." << std::endl;
      } else {
        this->grafo->Destruir();
        delete this->grafo;
        this->grafo = nullptr;
      }
      break;
    case 3:
      if (this->grafo == nullptr) {
        std::cout << "No hay un grafo actualmente." << std::endl;
      } else {
        this->grafo->Vaciar();
      }
      break;
    case 4:
      if (this->grafo == nullptr || this->grafo->Vacio()) {
        std::cout << "El grafo está vacío." << std::endl;
      } else {
        std::cout << "El grafo no está vacío." << std::endl;
      }
      break;
    case 5:
      if (this->grafo == nullptr) {
        std::cout << "No hay un grafo actualmente." << std::endl;
      } else {
        std::cout << "Ingrese la etiqueta a agregar: ";
        std::cin >> etiq;
        this->grafo->AgregarVert(etiq);
        std::cout << "Vertice agregado." << std::endl;
      }
      break;
    case 6:
      if (this->grafo == nullptr) {
        std::cout << "No hay un grafo actualmente." << std::endl;
      } else {
        std::cout << "Ingrese la etiqueta a eliminar: ";
        std::cin >> etiq;
        vertice = this->BuscarVertice(etiq);
        this->grafo->EliminarVert(vertice);
        std::cout << "Vertice eliminado" << std::endl;
      }
      break;
    case 7:
      if (this->grafo == nullptr) {
        std::cout << "No hay un grafo actualmente." << std::endl;
      } else {
        std::cout << "Ingrese la etiqueta a modificar: ";
        std::cin >> etiq;
        std::cout << "Ingrese la nueva etiqueta: ";
        std::cin >> etiq1;
        vertice = this->BuscarVertice(etiq);
        this->grafo->ModificarEtiqueta(vertice, etiq1);
      }
      break;
    case 8:
      if (this->grafo == nullptr) {
        std::cout << "No hay un grafo actualmente." << std::endl;
      } else {
        std::cout << "Ingrese la etiqueta del vertice: ";
        std::cin >> etiq;
        vertice = this->BuscarVertice(etiq);
        std::cout << "Etiqueta: " << this->grafo->Etiqueta(vertice);
        std::cout << std::endl;
      }
      break;
    case 9:
      if (this->grafo == nullptr) {
        std::cout << "No hay un grafo actualmente." << std::endl;
      } else {
        std::cout << "Ingrese el vertice de salida: ";
        std::cin >> etiq;
        std::cout << "Ingrese el vertice de llegada: ";
        std::cin >> etiq1;
        std::cout << "Ingrese el peso de la arista: ";
        std::cin >> peso;
        vertice = this->BuscarVertice(etiq);
        vertice1 = this->BuscarVertice(etiq1);
        this->grafo->AgregarArista(vertice, vertice1, peso);
      }
      break;
    case 10:
      if (this->grafo == nullptr) {
        std::cout << "No hay un grafo actualmente." << std::endl;
      } else {
        std::cout << "Ingrese el vertice de salida: ";
        std::cin >> etiq;
        std::cout << "Ingrese el vertice de llegada: ";
        std::cin >> etiq1;
        vertice = this->BuscarVertice(etiq);
        vertice1 = this->BuscarVertice(etiq1);
        this->grafo->EliminarArista(vertice, vertice1);
      }
      break;
    case 11:
      if (this->grafo == nullptr) {
        std::cout << "El grafo está vacío." << std::endl;
      } else {
        std::cout << "Ingrese el vertice de salida: ";
        std::cin >> etiq;
        std::cout << "Ingrese el vertice de llegada: ";
        std::cin >> etiq1;
        std::cout << "Ingrese el nuevo peso de la arista: ";
        std::cin >> peso;
        vertice = this->BuscarVertice(etiq);
        vertice1 = this->BuscarVertice(etiq1);
        this->grafo->ModificarPeso(vertice, vertice1, peso);
      }
      break;
    case 12:
      if (this->grafo == nullptr) {
        std::cout << "No hay un grafo actualmente." << std::endl;
      } else {
        std::cout << "Ingrese el vertice de salida: ";
        std::cin >> etiq;
        std::cout << "Ingrese el vertice de llegada: ";
        std::cin >> etiq1;
        std::cout << "Peso: ";
        vertice = this->BuscarVertice(etiq);
        vertice1 = this->BuscarVertice(etiq1);
        std::cout << this->grafo->Peso(vertice, vertice1) << std::endl;
      }
      break;
    case 13:
      if (this->grafo == nullptr) {
        std::cout << "No hay un grafo actualmente." << std::endl;
      } else {
        vertice = this->grafo->PrimerVertice();
        std::cout << "Primer vertice: " << vertice->etiqueta << std::endl;
      }
      break;
    case 14:
      if (this->grafo == nullptr) {
        std::cout << "No hay un grafo actualmente." << std::endl;
      } else {
        std::cout << "Ingrese un vertice: ";
        std::cin >> etiq;
        vertice = this->BuscarVertice(etiq);
        vertice1 = this->grafo->SiguienteVertice(vertice);
        std::cout << "Siguiente vertice: " << vertice1->etiqueta << std::endl;
      }
      break;
    case 15:
      if (this->grafo == nullptr) {
        std::cout << "No hay un grafo actualmente." << std::endl;
      } else {
        std::cin >> etiq;
        vertice = this->BuscarVertice(etiq);
        vertice1 = this->grafo->PrimerVerticeAdyacente(vertice);
        std::cout << "Primer vertice adyacente: " << vertice1->etiqueta
                  << std::endl;
      }
      break;
    case 16:
      if (this->grafo == nullptr) {
        std::cout << "No hay un grafo actualmente." << std::endl;
      } else {
        std::cout << "Ingrese un vertice: ";
        std::cin >> etiq;
        vertice = this->BuscarVertice(etiq);
        std::cout << "Ingrese un vertice adyacente: ";
        std::cin >> etiq1;
        vertice1 = this->BuscarVertice(etiq1);
        vertice = this->grafo->SiguienteVerticeAdyacente(vertice, vertice1);
        if (vertice != nullptr) {
          std::cout << "Siguiente vertice adyacente: " << vertice->etiqueta
                    << std::endl;
        } else {
          std::cout << "Siguiente vertice adyacente es nulo " << std::endl;
        }
      }
      break;
    case 17:
      if (this->grafo == nullptr) {
        std::cout << "No hay un grafo actualmente." << std::endl;

      } else {
        std::cout << "Numero de vertices: " << this->grafo->NumVertices()
                  << std::endl;
      }
      break;
    case 18: {
      int64_t aristas = this->numAristas(this->grafo);
      std::cout << "Numero de aristas es: " << aristas << std::endl;
    }

    break;
    case 19: {
      bool result = this->ConexoProfundidad(this->grafo);
      if (result) {
        std::cout << "El grafo es conexo" << std::endl;
      } else {
        std::cout << "El grafo no es conexo" << std::endl;
      }
    }

    break;
    case 20: {
      bool result = this->ConexoAncho(this->grafo);
      if (result) {
        std::cout << "El grafo es conexo" << std::endl;
      } else {
        std::cout << "El grafo no es conexo" << std::endl;
      }
    }

    break;
    case 21:

      break;
    case 22:

      break;
    case 23:

      break;
    case 24:

      break;
    case 25:

      break;
    case 26:
      salir = true;
      std::cout << "Saliendo" << std::endl;
      this->grafo->Destruir();
      break;

    default:
      std::cout << "Opción inválida. Volviendo" << std::endl;
      break;
    }
  } while ((opcion >= 1 || opcion <= 25) && !salir);
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

int Menu::mostrarOperadoresGrafo() {
  int opcion;
  std::cout << OPERADORES_GRAFO;
  std::cin >> opcion;
  return opcion;
}

void Menu::mostrarCreditos() { std::cout << CREDITOS; }

Vertice* Menu::BuscarVertice(std::string etiq) {
  Vertice* vertice = this->grafo->PrimerVertice();
  while (vertice != nullptr && vertice->etiqueta != etiq) {
    vertice = this->grafo->SiguienteVertice(vertice);
  }
  return vertice;
}

// -----------------------------
// -----ALGORITMOS GRAFOS-------
// -----------------------------

int64_t Menu::numAristas(GRAFO* g) {
  int64_t count = 0;
  std::set<Vertice*> dicVisVertex;
  if (!g->Vacio()) {
    Vertice* v = g->PrimerVertice();
    while (v != nullptr) {
      if (dicVisVertex.find(v) == dicVisVertex.end()) {
        Vertice* va = g->PrimerVerticeAdyacente(v);
        while (va != nullptr) {
          ++count;
          va = g->SiguienteVerticeAdyacente(v, va);
        }
      }
      dicVisVertex.insert(v);
      v = g->SiguienteVertice(v);
    }
  }
  return count / 2;
}

int64_t profPrimR(GRAFO* g, Vertice* vertAct, std::set<Vertice*>& dicVertVis,
    int64_t& count) {
  dicVertVis.insert(vertAct);
  count++;
  Vertice* vertAdy = g->PrimerVerticeAdyacente(vertAct);
  while (vertAdy != NULL) {
    if (dicVertVis.find(vertAdy) == dicVertVis.end()) {
      dicVertVis.insert(vertAdy);
      count = profPrimR(g, vertAdy, dicVertVis, count);
    }
    vertAdy = g->SiguienteVerticeAdyacente(vertAct, vertAdy);
  }
  return count;
}

bool Menu::ConexoProfundidad(GRAFO* g) {
  int64_t count = 0;
  std::set<Vertice*> dicVertVis;
  if (!g->Vacio()) {
    Vertice* vertAct = g->PrimerVertice();
    if (dicVertVis.find(vertAct) == dicVertVis.end()) {
      profPrimR(g, vertAct, dicVertVis, count);
    }
  }

  if (count != g->NumVertices()) {
    return false;
  }
  return true;
}

bool Menu::ConexoAncho(GRAFO* g) {
  int64_t count = 0;
  if (!g->Vacio()) {
    std::queue<Vertice*> colaVert;
    std::set<Vertice*> dicVertVis;
    Vertice* v = g->PrimerVertice();
    if (dicVertVis.find(v) == dicVertVis.end()) {
      colaVert.push(v);
      while (!colaVert.empty()) {
        ++count;
        v = colaVert.back();
        colaVert.pop();
        dicVertVis.insert(v);
        Vertice* va = g->PrimerVerticeAdyacente(v);
        while (va != nullptr) {
          if (dicVertVis.find(va) == dicVertVis.end()) {
            colaVert.push(va);
          }
          va = g->SiguienteVerticeAdyacente(v, va);
        }
      }
    }
  }
  if (count == g->NumVertices()) {
    return true;
  }
  return false;
}
