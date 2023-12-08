#if 1
#include <iostream>
#include <map>
#include <queue>

//#include "ListasDeAdyacencia.hpp"
#include "MatrizDeAdyacencia.hpp"

void RecorridoAnchoPrimero(GRAFO grafo);

int main () {
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

  RecorridoAnchoPrimero(grafo);

  std::cout << "Peso de la arista entre el vertice 3 y el vertice 2: " << grafo.Peso(vertice3, vertice2) << std::endl;

  grafo.EliminarArista(vertice3, vertice2);

  std::cout << "Peso de la arista entre el vertice 3 y el vertice 2 despues de eliminarla: " << grafo.Peso(vertice3, vertice2) << std::endl;

  grafo.ModificarEtiqueta(vertice1, "Vertice 1 modificado");

  std::cout << "Etiqueta del vertice 1: " << grafo.Etiqueta(vertice1) << std::endl;
  std::cout << "Etiqueta del vertice 2: " << grafo.Etiqueta(vertice2) << std::endl;

  std::cout << "Peso de la arista entre el vertice 1 y el vertice 4: " << grafo.Peso(vertice1, vertice4) << std::endl;
  std::cout << "Peso de la arista entre el vertice 4 y el vertice 3: " << grafo.Peso(vertice4, vertice3) << std::endl;

  std::cout << "Numero de vertices: " << grafo.NumVertices() << std::endl;

  std::cout << "Primer vertice: " << grafo.Etiqueta(grafo.PrimerVertice()) << std::endl;

  std::cout << "Primer vertice adyacente al vertice 4: " << grafo.Etiqueta(grafo.PrimerVerticeAdyacente(vertice4)) << std::endl;

  std::cout << "Siguiente vertice adyacente al vertice 4: " << grafo.Etiqueta(grafo.SiguienteVerticeAdyacente(vertice4, grafo.PrimerVerticeAdyacente(vertice4))) << std::endl;

  std::cout << "Siguiente vertice al vertice 4: " << grafo.Etiqueta(grafo.SiguienteVertice(vertice4)) << std::endl;

  std::cout << "Siguiente vertice al vertice 1: " << grafo.Etiqueta(grafo.SiguienteVertice(vertice1)) << std::endl;
  

  grafo.Destruir();
  return 0;
}
#endif


void RecorridoAnchoPrimero(GRAFO grafo) {
  if(!grafo.Vacio()) {
    std::map<Vertice*, bool> diccionario;
    std::queue<Vertice*> cola;
    Vertice* vertice = grafo.PrimerVertice();
    while(vertice != nullptr) {
      // Si el vertice no ha sido visitado
      if (diccionario.find(vertice) == diccionario.end()) {
        cola.push(vertice);
        diccionario[vertice] = true;
        while(!cola.empty()) {
          Vertice* verticeActual = cola.front();
          cola.pop();
          std::cout << grafo.Etiqueta(verticeActual) << " ";
          Vertice* verticeAdyacente = grafo.PrimerVerticeAdyacente(verticeActual);
          while(verticeAdyacente != nullptr) {
            if (diccionario.find(verticeAdyacente) == diccionario.end()) {
              cola.push(verticeAdyacente);
              diccionario[verticeAdyacente] = true;
            }
            verticeAdyacente = grafo.SiguienteVerticeAdyacente(verticeActual, verticeAdyacente);
          }
        }
      }
      vertice = grafo.SiguienteVertice(vertice);
    }
    diccionario.clear();
  }
}