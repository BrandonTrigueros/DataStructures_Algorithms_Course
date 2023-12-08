#include "Menu.hpp"

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <ctime>
#include <iomanip>
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

bool ExisteArista(GRAFO* g, Vertice* v1, Vertice* v2);

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
  this->crearGrafoManual();
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
    case 21: {
      std::cout << "Ingrese el vertice de origen:";
      std::cin >> etiq;
      vertice = this->BuscarVertice(etiq);
      ResultadoDijkstra* resultado = this->Dijkstra(this->grafo, vertice);

      std::cout << "-------------------------" << std::endl;
      Vertice* v = this->grafo->PrimerVertice();
      while (v != nullptr) {
        // Set width to 3 characters for each output
        std::cout << std::setw(3) << this->grafo->Etiqueta(v);
        v = this->grafo->SiguienteVertice(v);
      }

      std::cout << std::endl;
      std::cout << "-------------------------" << std::endl;

      for (size_t i = 0; i < resultado->P.size(); i++) {
        // Set width to 3 characters for each output
        std::cout << std::setw(3) << this->grafo->Etiqueta(resultado->P[i]);
      }

      std::cout << std::endl;
      std::cout << "-------------------------" << std::endl;

      for (size_t i = 0; i < resultado->D.size(); ++i) {
        if (resultado->D[i] > 100000) {
          // Set width to 3 characters for each output
          std::cout << std::setw(3) << "-";
        } else {
          // Set width to 3 characters for each output
          std::cout << std::setw(3) << resultado->D[i];
        }
      }
      std::cout << std::endl;
      std::cout << "-------------------------" << std::endl;
    }

    break;
    case 22: {
      // ResultadoFloyd* resultado = this->Floyd(this->grafo);
    }

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

int64_t PreImagen(std::map<int64_t, Vertice*> map, Vertice* v) {
  int64_t i = 0;
  for (auto it = map.begin(); it != map.end(); ++it) {
    if (it->second == v) {
      return i;
    }
    ++i;
  }
  return -1;
}

Vertice* Imagen(std::map<int64_t, Vertice*> map, int64_t i) {
  for (auto it = map.begin(); it != map.end(); ++it) {
    if (it->first == i) {
      return it->second;
    }
  }
  return nullptr;
}

pivote encontrarPivoteDijkstra(
    GRAFO* G, Diccionario<Vertice*>* dicc, std::vector<double>& D) {
  int64_t i = 0;
  int64_t pivIndice = 0;
  double min = std::numeric_limits<double>::max();
  Vertice* p = nullptr;
  Vertice* v = G->PrimerVertice();
  while (v != nullptr) {
    if (!dicc->Pertenece(v)) {
      if (D[i] < min) {
        min = D[i];
        p = v;
        pivIndice = i;
      }
    }
    ++i;
    v = G->SiguienteVertice(v);
  }
  pivote piv;
  piv.vertice = p;
  piv.indice = pivIndice;
  return piv;
}

int64_t EncontrarPivotePrim(
    std::vector<double>& costos, Diccionario<int64_t>& dicc) {
  int64_t i = 0;
  int64_t pivIndice = 0;
  double min = std::numeric_limits<double>::max();
  for (auto it = costos.begin(); it != costos.end(); ++it) {
    if (!dicc.Pertenece(i)) {
      if (*it < min) {
        min = *it;
        pivIndice = i;
      }
    }
    ++i;
  }
  return pivIndice;
}

bool ExisteArista(GRAFO* g, Vertice* v1, Vertice* v2) {
  Vertice* v = g->PrimerVertice();
  while (v != nullptr) {
    if (v == v1) {
      Vertice* va = g->PrimerVerticeAdyacente(v);
      while (va != nullptr) {
        if (va == v2) {
          return true;
        }
        va = g->SiguienteVerticeAdyacente(v, va);
      }
    }
    v = g->SiguienteVertice(v);
  }
  return false;
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

ResultadoDijkstra* Menu::Dijkstra(GRAFO* G, Vertice* origen) {
  int64_t n = G->NumVertices();
  Vertice* v = nullptr;

  std::vector<Vertice*> P(n);
  std::vector<double> D(n);

  Diccionario<Vertice*> dicc;
  dicc.Iniciar();
  dicc.Agregar(origen);

  v = G->PrimerVertice();
  int i = 0;
  while (v != nullptr) {
    P[i] = origen;
    if (ExisteArista(G, origen, v)) {
      D[i] = G->Peso(origen, v);
    } else {
      D[i] = std::numeric_limits<double>::max();
    }
    v = G->SiguienteVertice(v);
    ++i;
  }
  for (int64_t i = 0; i < n - 2; ++i) {
    pivote p = encontrarPivoteDijkstra(G, &dicc, D);
    dicc.Agregar(p.vertice);
    v = G->PrimerVertice();
    for (int64_t j = 0; j < n; ++j) {
      if (!dicc.Pertenece(v)) {
        if (ExisteArista(G, p.vertice, v)) {
          if (D[p.indice] + G->Peso(p.vertice, v) < D[j]) {
            D[j] = D[p.indice] + G->Peso(p.vertice, v);
            P[j] = p.vertice;
          }
        }
      }
      v = G->SiguienteVertice(v);
    }
  }
  ResultadoDijkstra* resultado = new ResultadoDijkstra;
  resultado->P = P;
  resultado->D = D;
  return resultado;
}

ResultadoFloyd* Menu::Floyd(GRAFO* g) {
  std::vector<std::vector<double>> A(g->NumVertices());
  std::vector<std::vector<int64_t>> P(g->NumVertices());
  Vertice* vi = g->PrimerVertice();
  Vertice* vj = g->PrimerVertice();
  for (int64_t i = 0; i < g->NumVertices(); ++i) {
    for (int64_t j = 0; j < g->NumVertices(); ++j) {
      if (i == j) {
        A[i][j] = 0;
      } else {
        A[i][j] = g->Peso(vi, vj);
        vj = g->SiguienteVertice(vj);
      }
      P[i][j] = 0;
      vi = g->SiguienteVertice(vi);
    }
  }
  for (int64_t k = 0; k < g->NumVertices(); ++k) {
    for (int64_t i = 0; i < g->NumVertices(); ++i) {
      for (int64_t j = 0; j < g->NumVertices(); ++j) {
        if (A[i][k] + A[k][j] < A[i][j]) {
          A[i][j] = A[i][k] + A[k][j];
          P[i][j] = k;
        }
      }
    }
  }
  ResultadoFloyd* resultado = new ResultadoFloyd;
  resultado->A = A;
  resultado->P = P;
  return resultado;
}

ResultadoPrim* Menu::Prim(GRAFO* g, Vertice* origen) {
  std::map<int64_t, Vertice*> map;
  std::vector<double> costos(g->NumVertices());
  std::vector<int64_t> vertices(g->NumVertices());
  std::vector<Vertice*> verticesR1a1(g->NumVertices());
  map[0] = origen;
  Vertice* sv = g->SiguienteVertice(origen);
  int64_t i = 0;
  while (sv != nullptr) {
    map[i + 1] = sv;
    if (ExisteArista(g, origen, sv)) {
      costos[i] = g->Peso(origen, sv);
    } else {
      costos[i] = std::numeric_limits<double>::max();
    }
    vertices[i] = 0;
    verticesR1a1[i] = origen;
    sv = g->SiguienteVertice(sv);
    ++i;
  }

  Diccionario<int64_t> diccPiv;
  diccPiv.Iniciar();
  for (int64_t i = 0; i < g->NumVertices() - 2; ++i) {
    int64_t piv = EncontrarPivotePrim(costos, diccPiv);
    diccPiv.Agregar(piv);
    Vertice* vertPivote = Imagen(map, piv);
    for (int64_t j = 0; j < g->NumVertices() - 1; ++j) {
      Vertice* vertJ = Imagen(map, j);
      if (!diccPiv.Pertenece(j)) {
        if (ExisteArista(g, vertJ, vertPivote)) {
          if (g->Peso(vertJ, vertPivote) < costos[j]) {
            costos[j] = g->Peso(vertJ, vertPivote);
            vertices[j] = piv;
            verticesR1a1[j] = vertPivote;
          }
        }
      }
    }
  }
  ResultadoPrim* resultado = new ResultadoPrim;
  resultado->costos = costos;
  resultado->vertices = verticesR1a1;
  return resultado;
}

void Menu::crearGrafoManual() {
  this->grafo = new GRAFO;
  this->grafo->Iniciar();
  Vertice* verticeA = this->grafo->AgregarVert("A");
  Vertice* verticeB = this->grafo->AgregarVert("B");
  Vertice* verticeC = this->grafo->AgregarVert("C");
  Vertice* verticeD = this->grafo->AgregarVert("D");
  Vertice* verticeE = this->grafo->AgregarVert("E");
  Vertice* verticeF = this->grafo->AgregarVert("F");

  this->grafo->AgregarArista(verticeA, verticeE, 1);
  this->grafo->AgregarArista(verticeB, verticeA, 2);
  this->grafo->AgregarArista(verticeC, verticeA, 10);
  this->grafo->AgregarArista(verticeC, verticeB, 4);
  this->grafo->AgregarArista(verticeC, verticeF, 20);
  this->grafo->AgregarArista(verticeE, verticeC, 8);
  this->grafo->AgregarArista(verticeE, verticeD, 6);
  this->grafo->AgregarArista(verticeE, verticeF, 12);
  this->grafo->AgregarArista(verticeD, verticeF, 5);
}