#if 0
#include <iostream>
#include <map>
#include <queue>
#include <set>

// #include "ListasDeAdyacencia.hpp"
#include "MatrizDeAdyacencia.hpp"
#include "Menu.hpp"

void RecorridoAnchoPrimero(GRAFO* g);

int main() {
  // Pruebas a todos los operadores del grafo
  Menu* menu = new Menu();
  GRAFO grafo;
  grafo.Iniciar();
  Vertice* verticeA = grafo.AgregarVert("A");
  Vertice* verticeB = grafo.AgregarVert("B");
  Vertice* verticeC = grafo.AgregarVert("C");
  Vertice* verticeD = grafo.AgregarVert("D");
  Vertice* verticeE = grafo.AgregarVert("E");
  Vertice* verticeF = grafo.AgregarVert("F");

  grafo.AgregarArista(verticeA, verticeE, 1);
  grafo.AgregarArista(verticeB, verticeA, 2);
  grafo.AgregarArista(verticeC, verticeA, 10);
  grafo.AgregarArista(verticeC, verticeB, 4);
  grafo.AgregarArista(verticeC, verticeF, 20);
  grafo.AgregarArista(verticeE, verticeC, 8);
  grafo.AgregarArista(verticeE, verticeD, 6);
  grafo.AgregarArista(verticeE, verticeF, 12);
  grafo.AgregarArista(verticeD, verticeF, 5);

  ResultadoDijkstra* resultado = menu->Dijkstra(&grafo, verticeC);
  std::cout << "Resultado Dijkstra: " << std::endl;
  for (size_t i = 0; i < resultado->P.size(); i++) {
    std::cout << grafo.Etiqueta(resultado->P[i]) << " ";
  }
  std::cout << std::endl;
  for (size_t i = 0; i < resultado->D.size(); i++) {
    std::cout << resultado->D[i] << " ";
  }
}

#endif

#if 0
#include <iostream>
#include <map>
#include <queue>
#include <set>

#include "ListasDeAdyacencia.hpp"
// #include "MatrizDeAdyacencia.hpp"

void RecorridoAnchoPrimero(GRAFO* g);

int main() {
  // Pruebas a todos los operadores del grafo
  GRAFO grafo;
  grafo.Iniciar();
  Vertice* vertice1 = grafo.AgregarVert("Vertice 1");
  Vertice* vertice2 = grafo.AgregarVert("Vertice 2");
  Vertice* vertice3 = grafo.AgregarVert("Vertice 3");
  Vertice* vertice4 = grafo.AgregarVert("Vertice 4");
  Vertice* vertice5 = grafo.AgregarVert("Vertice 5");
  Vertice* vertice6 = grafo.AgregarVert("Vertice 6");
  Vertice* vertice7 = grafo.AgregarVert("Vertice 7");
  Vertice* vertice8 = grafo.AgregarVert("Vertice 8");
  Vertice* vertice9 = grafo.AgregarVert("Vertice 9");
  Vertice* vertice10 = grafo.AgregarVert("Vertice 10");

  grafo.EliminarVert(vertice4);

  std::cout << "grafo vacio: " << grafo.Vacio() << std::endl;

  grafo.Vaciar();

  std::cout << "grafo vacio despues de vaciar: " << grafo.Vacio() << std::endl;

  vertice1 = grafo.AgregarVert("Vertice 1");
  vertice2 = grafo.AgregarVert("Vertice 2");
  vertice3 = grafo.AgregarVert("Vertice 3");
  vertice4 = grafo.AgregarVert("Vertice 4");
  vertice5 = grafo.AgregarVert("Vertice 5");
  vertice6 = grafo.AgregarVert("Vertice 6");
  vertice7 = grafo.AgregarVert("Vertice 7");
  vertice8 = grafo.AgregarVert("Vertice 8");
  vertice9 = grafo.AgregarVert("Vertice 9");
  vertice10 = grafo.AgregarVert("Vertice 10");

  grafo.AgregarArista(vertice1, vertice4, 5);
  grafo.AgregarArista(vertice4, vertice3, 10);
  grafo.AgregarArista(vertice7, vertice4, 43);
  grafo.AgregarArista(vertice9, vertice5, 54);
  grafo.AgregarArista(vertice2, vertice6, 23);
  grafo.AgregarArista(vertice10, vertice7, 12);
  grafo.AgregarArista(vertice8, vertice9, 34);
  grafo.AgregarArista(vertice3, vertice2, 45);
  grafo.AgregarArista(vertice4, vertice8, 56);

  std::cout << "grafo vacio despues de agregar vertices y aristas: "
            << grafo.Vacio() << std::endl;

  RecorridoAnchoPrimero(&grafo);

  std::cout << "Peso de la arista entre el vertice 3 y el vertice 2: "
            << grafo.Peso(vertice3, vertice2) << std::endl;

  // grafo.EliminarArista(vertice3, vertice2);

  std::cout << "Peso de la arista entre el vertice 3 y el vertice 2 despues de "
               "eliminarla: "
            << grafo.Peso(vertice3, vertice2) << std::endl;

  grafo.ModificarEtiqueta(vertice1, "Vertice 1 modificado");

  std::cout << "Etiqueta del vertice 1: " << grafo.Etiqueta(vertice1)
            << std::endl;
  std::cout << "Etiqueta del vertice 2: " << grafo.Etiqueta(vertice2)
            << std::endl;

  std::cout << "Peso de la arista entre el vertice 1 y el vertice 4: "
            << grafo.Peso(vertice1, vertice4) << std::endl;
  std::cout << "Peso de la arista entre el vertice 4 y el vertice 3: "
            << grafo.Peso(vertice4, vertice3) << std::endl;

  std::cout << "Numero de vertices: " << grafo.NumVertices() << std::endl;

  std::cout << "Primer vertice: " << grafo.Etiqueta(grafo.PrimerVertice())
            << std::endl;

  std::cout << "Primer vertice adyacente al vertice 4: "
            << grafo.Etiqueta(grafo.PrimerVerticeAdyacente(vertice4))
            << std::endl;

  std::cout << "Siguiente vertice adyacente al vertice 4: "
            << grafo.Etiqueta(grafo.SiguienteVerticeAdyacente(
                   vertice4, grafo.PrimerVerticeAdyacente(vertice4)))
            << std::endl;

  std::cout << "Siguiente vertice al vertice 4: "
            << grafo.Etiqueta(grafo.SiguienteVertice(vertice4)) << std::endl;

  std::cout << "Siguiente vertice al vertice 1: "
            << grafo.Etiqueta(grafo.SiguienteVertice(vertice1)) << std::endl;

  grafo.Destruir();
  return 0;
}

  void RecorridoAnchoPrimero(GRAFO * g) {
    if (!g->Vacio()) {
      std::set<Vertice*> diccionario;
      std::queue<Vertice*> cola;
      Vertice* vertice = g->PrimerVertice();
      while (vertice != nullptr) {
        // Si el vertice no ha sido visitado
        if (diccionario.find(vertice) == diccionario.end()) {
          diccionario.insert(vertice);
          cola.push(vertice);
          while (!cola.empty()) {
            Vertice* verticeActual = cola.back();
            cola.pop();
            std::cout << g->Etiqueta(verticeActual) << " " << std::flush;
            Vertice* verticeAdyacente
                = g->PrimerVerticeAdyacente(verticeActual);
            while (verticeAdyacente != nullptr) {
              if (diccionario.find(verticeAdyacente) == diccionario.end()) {
                cola.push(verticeAdyacente);
                diccionario.insert(verticeAdyacente);
              }
              verticeAdyacente = g->SiguienteVerticeAdyacente(
                  verticeActual, verticeAdyacente);
            }
          }
        }
        vertice = g->SiguienteVertice(vertice);
      }
      std::cout << std::endl;
    }
  }
#endif