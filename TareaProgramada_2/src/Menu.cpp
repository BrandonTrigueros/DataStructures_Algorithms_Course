#include "Menu.hpp"

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <ctime>
#include <iomanip>
#include <limits>
#include <list>
#include <ostream>
#include <sched.h>
#include <string>
#include <system_error>
#include <time.h>
#include <unistd.h>
#include <vector>

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

Vertice* Imagen(std::map<int64_t, Vertice*> map, int64_t i);
int64_t PreImagen(std::map<int64_t, Vertice*> map, Vertice* v);

void CircuitoHamiltonMC_BEP_i(GRAFO* g, int64_t i, int64_t& costoAct,
    int64_t& menorCosto, Vertice** lowestHamiltonianPath,
    std::set<Vertice*>& dicVertVis, Vertice** solucionAct);

// ----------------------------------
// ----------MENU PRINCIPAL----------
// ----------------------------------
void Menu::run() {

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

  this->crearGrafoAuto(40, 780);
  //  this->crearGrafoManual();

  int opcion;
  bool salir = false;
  std::string etiq;
  std::string etiq1;
  Vertice* vertice = nullptr;
  Vertice* vertice1 = nullptr;
  Vertice** result = nullptr;
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
        if (resultado->P[i] != nullptr) {
          std::cout << std::setw(3) << this->grafo->Etiqueta(resultado->P[i]);
        } else {
          std::cout << std::setw(3) << "-";
        }
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
      ResultadoFloyd* resultado = this->Floyd(this->grafo);

      // Relación 1 a 1
      std::map<int64_t, Vertice*> map;
      Vertice* v = this->grafo->PrimerVertice();
      int64_t i = 0;
      while (v != nullptr) {
        map[i + 1] = v;
        v = this->grafo->SiguienteVertice(v);
        ++i;
      }

      // Encabezado
      v = this->grafo->PrimerVertice();
      std::cout << std::setw(3) << "*";
      while (v != nullptr) {
        std::cout << std::setw(3) << "" << this->grafo->Etiqueta(v);
        v = this->grafo->SiguienteVertice(v);
      }
      std::cout << std::endl;
      std::cout << "-------------------------" << std::endl;

      for (size_t i = 0; i < resultado->A.size(); ++i) {
        std::cout << std::setw(3) << this->grafo->Etiqueta(Imagen(map, i + 1))
                  << " |";
        for (size_t j = 0; j < resultado->A[i].size(); ++j) {
          if (i == j) {
            std::cout << std::setw(3) << "0";
          } else {
            if (resultado->A[i][j] > 100000) {
              std::cout << std::setw(3) << "-";
            } else {
              std::cout << std::setw(3) << resultado->A[i][j];
            }
          }
        }
        std::cout << std::endl;
      }
      std::cout << "-------------------------" << std::endl;
    }

    break;
    case 23: {
      ResultadoPrim* resultado = this->Prim(this->grafo);

      std::cout << "-------------------------" << std::endl;
      Vertice* v = this->grafo->PrimerVertice();
      v = this->grafo->SiguienteVertice(v);
      while (v != nullptr) {
        // Set width to 3 characters for each output
        std::cout << std::setw(3) << this->grafo->Etiqueta(v);
        v = this->grafo->SiguienteVertice(v);
      }

      std::cout << std::endl;
      std::cout << "-------------------------" << std::endl;

      for (size_t i = 1; i < resultado->costos.size(); ++i) {
        if (resultado->costos[i] > 100000) {
          // Set width to 3 characters for each output
          std::cout << std::setw(3) << "-";
        } else {
          // Set width to 3 characters for each output
          std::cout << std::setw(3) << resultado->costos[i];
        }
      }

      std::cout << std::endl;
      std::cout << "-------------------------" << std::endl;

      for (size_t i = 1; i < resultado->previo.size(); i++) {
        // Set width to 3 characters for each output
        std::cout << std::setw(3)
                  << this->grafo->Etiqueta(resultado->previo[i]);
      }

      std::cout << std::endl;
      std::cout << "-------------------------" << std::endl;
    }

    break;
    case 24: {
      std::vector<AristaKruskal> resultado = this->Kruskal(this->grafo);

      std::cout << "-------------------------" << std::endl;
      for (size_t i = 0; i < resultado.size(); ++i) {
        std::cout << std::setw(3)
                  << this->grafo->Etiqueta(resultado[i].vertice1) << " - "
                  << std::setw(3)
                  << this->grafo->Etiqueta(resultado[i].vertice2) << " |"
                  << std::setw(3) << resultado[i].peso << std::endl;
      }
      std::cout << "-------------------------" << std::endl;
    }

    break;
    case 25:
      result = this->CircuitoHamiltonMC_BEP(this->grafo);
      std::cout << "El circuito de hamilton es el siguiente: " << std::endl;
      std::cout << "-------------------------" << std::endl;

      for (int64_t i = 0; i <= this->grafo->NumVertices(); i++) {
        std::cout << std::setw(3) << this->grafo->Etiqueta(result[i]);
      }
      std::cout << std::endl;
      std::cout << "-------------------------" << std::endl;

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
      if (*it < min) {  // Aquí está el cambio
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
  for (int64_t i = 0; i < g->NumVertices(); ++i) {
    A[i].resize(g->NumVertices());
    P[i].resize(g->NumVertices());
  }
  Vertice* vi = g->PrimerVertice();
  Vertice* vj = g->PrimerVertice();
  for (int64_t i = 0; i < g->NumVertices(); ++i) {
    vj = g->PrimerVertice();
    for (int64_t j = 0; j < g->NumVertices(); ++j) {
      if (i == j) {
        A[i][j] = 0;
      } else {
        if (ExisteArista(g, vi, vj)) {
          A[i][j] = g->Peso(vi, vj);
        } else {
          A[i][j] = std::numeric_limits<double>::max();
        }
      }
      vj = g->SiguienteVertice(vj);
      P[i][j] = 0;
    }
    vi = g->SiguienteVertice(vi);
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

// Prim(Grago g, Matrices Vertices, Matrices Costos, R1a1) {
//   vRaiz = G.PV()
//   R1a1.AgRel(0,vRaiz)
//   v = G.SV(vRaiz); i = 1
//   while v !- vertNulo {
//     R1a1.AgRel(i,v)
//     if G.ExisteArista(vRaizm v) {
//       Costos[i] = G.Peso(vRaiz, v)
//     } else {
//       Costos[i] = Infinito
//     }
//     Vertices[i] = 0
//     v = G.SV(v)
//   }

//   DiccPiv.Iniciar()

//   for i = 1.. G.NumVert() - 2 {
//     indPivote = BuscarPivote(Costos, DiccPiv)
//     DiccPiv.Ag(indPivote)
//     vertPivote = R1a1.Imag(indPivote)
//     for j = 1.. G.NumVert()-1 {
//       vertJ = R1a1.Imag(j)
//       if !DiccPiv.Pert(j) {
//         if G.ExisteArista(vertJ, vertPivote) {
//           if Peso(vertJ, vertPivote) < Costos[j] {
//             Costos[j] = G.Peso(vertJ, vertPivote)
//             Vertices[j] = indPivote
//           }
//         }
//       }
//     }
//   }
// }

ResultadoPrim* Menu::Prim(GRAFO* grafo) {
  std::unordered_map<Vertice*, int> indice;
  std::vector<Vertice*> vertices;

  int numVertices = 0;
  for (Vertice* v = grafo->PrimerVertice(); v != nullptr;
       v = grafo->SiguienteVertice(v)) {
    vertices.push_back(v);
    indice[v] = numVertices++;
  }

  std::vector<bool> visitado(numVertices, false);
  std::vector<double> minCosto(numVertices, std::numeric_limits<double>::max());
  std::vector<Vertice*> previo(numVertices, nullptr);

  std::priority_queue<std::pair<double, Vertice*>,
      std::vector<std::pair<double, Vertice*>>,
      std::greater<std::pair<double, Vertice*>>>
      cola;

  Vertice* inicio = vertices[0];
  cola.push({ 0.0, inicio });
  minCosto[indice[inicio]] = 0.0;

  while (!cola.empty()) {
    Vertice* vertice = cola.top().second;
    cola.pop();

    if (visitado[indice[vertice]])
      continue;
    visitado[indice[vertice]] = true;

    for (Vertice* adyacente = grafo->PrimerVerticeAdyacente(vertice);
         adyacente != nullptr;
         adyacente = grafo->SiguienteVerticeAdyacente(vertice, adyacente)) {
      double peso = grafo->Peso(vertice, adyacente);
      if (!visitado[indice[adyacente]] && peso < minCosto[indice[adyacente]]) {
        previo[indice[adyacente]] = vertice;
        minCosto[indice[adyacente]] = peso;
        cola.push({ peso, adyacente });
      }
    }
  }

  ResultadoPrim* resultado = new ResultadoPrim;
  resultado->vertices = vertices;
  resultado->costos = minCosto;
  resultado->previo = previo;

  return resultado;
}

std::vector<AristaKruskal> Menu::Kruskal(GRAFO* g) {
  std::vector<AristaKruskal> aristas;
  ColaPrioridad<AristaKruskal> APO;
  std::set<std::set<Vertice*>> CC;
  Vertice* v = g->PrimerVertice();
  while (v != nullptr) {
    std::set<Vertice*> s;
    s.insert(v);
    CC.insert(s);
    Vertice* va = g->PrimerVerticeAdyacente(v);
    while (va != nullptr) {
      AristaKruskal a;
      a.vertice1 = v;
      a.vertice2 = va;
      a.peso = g->Peso(v, va);
      if (!APO.existe(a)) {
        APO.push(a, a.peso);
      }
      va = g->SiguienteVerticeAdyacente(v, va);
    }
    v = g->SiguienteVertice(v);
  }
  int64_t n = g->NumVertices();
  int64_t totalAristasEscogidas = 0;
  while (totalAristasEscogidas < n - 1) {
    AristaKruskal a = APO.top();
    APO.pop();
    std::set<Vertice*> s1;
    std::set<Vertice*> s2;
    for (auto it = CC.begin(); it != CC.end(); ++it) {
      if (it->find(a.vertice1) != it->end()) {
        s1 = *it;
      }
      if (it->find(a.vertice2) != it->end()) {
        s2 = *it;
      }
    }
    if (s1 != s2) {
      std::set<Vertice*> s3;
      for (auto it = s1.begin(); it != s1.end(); ++it) {
        s3.insert(*it);
      }
      for (auto it = s2.begin(); it != s2.end(); ++it) {
        s3.insert(*it);
      }
      CC.erase(s1);
      CC.erase(s2);
      CC.insert(s3);
      totalAristasEscogidas++;
      aristas.push_back(a);
    }
  }
  return aristas;
}

void CircuitoHamiltonMC_BEP_i(GRAFO* g, int64_t i, int64_t& costoAct,
    int64_t& menorCosto, Vertice** lowestHamiltonianPath,
    std::set<Vertice*>& dicVertVis, Vertice** solucionAct) {
  Vertice* va = g->PrimerVerticeAdyacente(solucionAct[i - 2]);
  while (va != nullptr) {
    if (dicVertVis.find(va) == dicVertVis.end()) {
      solucionAct[i - 1] = va;
      dicVertVis.insert(va);
      costoAct += g->Peso(solucionAct[i - 2], va);
      if (i == g->NumVertices()) {
        if (ExisteArista(g, va, solucionAct[0])) {
          if (costoAct + g->Peso(va, solucionAct[0]) < menorCosto) {
            menorCosto = costoAct + g->Peso(va, solucionAct[0]);
          }
          for (int j = 0; j < g->NumVertices(); ++j) {
            lowestHamiltonianPath[j] = solucionAct[j];
          }
        }
      } else {
        CircuitoHamiltonMC_BEP_i(g, i + 1, costoAct, menorCosto,
            lowestHamiltonianPath, dicVertVis, solucionAct);
      }
      dicVertVis.erase(va);
      costoAct -= g->Peso(solucionAct[i - 2], va);
    }
    va = g->SiguienteVerticeAdyacente(solucionAct[i - 2], va);
  }
}

Vertice** Menu::CircuitoHamiltonMC_BEP(GRAFO* g) {
  std::set<Vertice*> dicVertVis;
  std::map<int64_t, Vertice*> rel1a1;
  Vertice** lowestHamiltonianPath = new Vertice*[g->NumVertices() + 1];
  Vertice** solucionAct = new Vertice*[g->NumVertices() + 1];
  int64_t costoActFinal = 0;
  int64_t menorCostoInit = 0;

  solucionAct[0] = g->PrimerVertice();
  dicVertVis.insert(g->PrimerVertice());

  CircuitoHamiltonMC_BEP_i(g, 2, costoActFinal, menorCostoInit,
      lowestHamiltonianPath, dicVertVis, solucionAct);

  lowestHamiltonianPath[g->NumVertices()] = g->PrimerVertice();

  return lowestHamiltonianPath;
}

void Menu::crearGrafoAuto(int64_t vertices, int64_t numAristas) {
  std::vector<std::string> listaEtiquetas;
  listaEtiquetas.resize(vertices);

  std::vector<std::vector<double>> matriz;
  matriz.resize(vertices);
  for (int i = 0; i < vertices; ++i) {
    matriz[i].resize(vertices);
  }

  for (int i = 0; i < vertices; ++i) {
    std::string toAdd = "v" + std::to_string(i);
    listaEtiquetas.at(i) = toAdd;
  }

  for (int i = 0; i < vertices; ++i) {
    std::cout << listaEtiquetas.at(i) << " ";
  }
  std::cout << std::endl;

  for (int i = 0; i < vertices; ++i) {
    for (int j = 0; j < vertices; ++j) {
      if (i == j) {
        matriz[i][j] = std::numeric_limits<double>::max();
      } else {
        matriz[i][j] = 1;
      }
    }
  }

  std::map<Vertice*, int64_t> vertMap;
  std::map<int64_t, Vertice*> vertMap1;

  std::set<Vertice*> dicVertVis;

  this->grafo = new GRAFO;
  this->grafo->Iniciar();
  for (int64_t i = 0; i < (int64_t)listaEtiquetas.size(); ++i) {
    Vertice* v = this->grafo->AgregarVert(listaEtiquetas[i]);
    vertMap[v] = i;
    vertMap1[i] = v;
  }

  int64_t count = numAristas;
  double weight = 1;

  Vertice* v = this->grafo->PrimerVertice();
  while (v != nullptr) {
    Vertice* vs = this->grafo->PrimerVertice();
    while (vs != nullptr) {
      if (v != vs) {
        if (count > 0 && !ExisteArista(this->grafo, v, vs)) {
          this->grafo->AgregarArista(v, vs, weight);
          std::cout << "Arista: " << v->etiqueta << " " << vs->etiqueta
                    << std::endl;
          ++weight;
          --count;
        }
      }
      vs = this->grafo->SiguienteVertice(vs);
    }
    v = this->grafo->SiguienteVertice(v);
  }
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

  this->grafo->AgregarArista(verticeA, verticeB, 2);
  this->grafo->AgregarArista(verticeA, verticeC, 8);
  this->grafo->AgregarArista(verticeA, verticeE, 7);
  this->grafo->AgregarArista(verticeA, verticeD, 6);
  this->grafo->AgregarArista(verticeA, verticeF, 3);
  this->grafo->AgregarArista(verticeB, verticeC, 3);
  this->grafo->AgregarArista(verticeB, verticeD, 9);
  this->grafo->AgregarArista(verticeB, verticeF, 5);
  this->grafo->AgregarArista(verticeC, verticeE, 1);
  this->grafo->AgregarArista(verticeC, verticeF, 6);
  this->grafo->AgregarArista(verticeD, verticeF, 9);
  this->grafo->AgregarArista(verticeE, verticeF, 4);
}
