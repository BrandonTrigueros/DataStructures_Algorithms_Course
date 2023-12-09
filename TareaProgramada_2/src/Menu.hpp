#pragma once
#ifndef MENU_HPP
#define MENU_HPP

#include <cstdint>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

// #include "ListasDeAdyacencia.hpp"
#include "MatrizDeAdyacencia.hpp"

#define OPCIONES_PRINCIPAL                                                        \
  "╔═══════════════════════╗\n" \
  "║    Menú Principal     ║\n"                                              \
  "║ 1. Modelo Grafo       ║\n"                                               \
  "║ 2. Créditos           ║\n"                                              \
  "║ 3. Salir              ║\n"                                               \
  "╚═══════════════════════╝\n" \
  "Seleccione una opción: "

#define OPERADORES_GRAFO                                                                                                                                                                               \
  "╔══════════════════════════════════════════════════════════════╗\n" \
  "║                   Operadores Básicos Grafo                   ║\n"                                                                                                                            \
  "║══════════════════════════════════════════════════════════════║\n" \
  "║ 1.  Crear                     2. Destruir                    ║\n"                                                                                                                             \
  "║ 3.  Vaciar                    4. Vacío                       ║\n"                                                                                                                            \
  "║ 5.  AgregarVertice            6. EliminarVertice             ║\n"                                                                                                                             \
  "║ 7.  ModificarEtiqueta         8. Etiqueta                    ║\n"                                                                                                                             \
  "║ 9.  AgregarArista             10. EliminarArista             ║\n"                                                                                                                             \
  "║ 11. ModificarPeso             12. Peso                       ║\n"                                                                                                                             \
  "║ 13. PrimerVertice             14. SiguienteVertice           ║\n"                                                                                                                             \
  "║ 15. PrimerVerticeAdyacente    16. SiguienteVerticeAdyacente  ║\n"                                                                                                                             \
  "║ 17. NumVertices                                              ║\n"                                                                                                                             \
  "║══════════════════════════════════════════════════════════════║\n" \
  "║                    Algoritmos de Grafos                      ║\n"                                                                                                                             \
  "║══════════════════════════════════════════════════════════════║\n" \
  "║ 18. NumAristas                19. ConexoProfundidad          ║\n"                                                                                                                             \
  "║ 20. ConexoAncho               21. Dijkstra                   ║\n"                                                                                                                             \
  "║ 22. Floyd                     23. Prim                       ║\n"                                                                                                                             \
  "║ 24. Kruskal                   25. CircuitoHamiltonMC-BEP     ║\n"                                                                                                                             \
  "║ 26. Salir                                                    ║\n"                                                                                                                             \
  "╚══════════════════════════════════════════════════════════════╝\n" \
  "Seleccione una opción: "

#define CREDITOS                                                                                    \
  "╔═════════════════════════════╗\n" \
  "║          Créditos           ║\n"                                                          \
  "║ Lester Pereira Cerdas       ║\n"                                                           \
  "║ Christopher Acosta Madrigal ║\n"                                                           \
  "║ Brandon Trigueros Lara      ║\n"                                                           \
  "╚═════════════════════════════╝\n"

struct pivote {
  Vertice* vertice;  // vertice pivote
  int64_t indice;  // indice del pivote dentro del arreglo D
};

struct ResultadoDijkstra {
  std::vector<Vertice*> P;
  std::vector<double> D;
};

struct ResultadoFloyd {
  std::vector<std::vector<double>> A;
  std::vector<std::vector<int64_t>> P;
};

struct ResultadoPrim {
  std::vector<Vertice*> vertices;
  std::vector<double> costos;
};

struct AristaKruskal {
  Vertice* vertice1;
  Vertice* vertice2;
  double peso;

  inline bool operator==(const AristaKruskal& rhs) const {
    return (this->vertice1 == rhs.vertice1 && this->vertice2 == rhs.vertice2)
        || (this->vertice1 == rhs.vertice2 && this->vertice2 == rhs.vertice1);
  }
};

class Menu {
 private:
  GRAFO* grafo;
  double timeElapsed = 0;

 public:
  Menu();
  ~Menu();

  void run();
  void runGrafo();

  int mostrarPrincipal();
  int mostrarOperadoresGrafo();
  void mostrarCreditos();
  Vertice* BuscarVertice(std::string etiq);
  void crearGrafoAuto(int64_t vertices, int64_t numAristas);
  void crearGrafoManual();



  // ----------ALGORITMOS----------

  // Parámetros:
  // Efecto:
  // Retorna:
  // Requiere:
  // Modifica: N/A
  int64_t numAristas(GRAFO* g);

  // Parámetros:
  // Efecto:
  // Retorna:
  // Requiere:
  // Modifica: N/A
  bool ConexoProfundidad(GRAFO* g);

  // Parámetros:
  // Efecto:
  // Retorna:
  // Requiere:
  // Modifica: N/A
  bool ConexoAncho(GRAFO* g);

  // Parámetros:
  // Efecto:

  // Retorna: Un vector de vertices, cada uno representa el vertice anterior
  // del camino más corto del i-esimo

  // Requiere:
  // Modifica: N/A
  ResultadoDijkstra* Dijkstra(GRAFO* G, Vertice* origen);

  // Parámetros:
  // Efecto:
  // Retorna:
  // Requiere:
  // Modifica: N/A
  ResultadoFloyd* Floyd(GRAFO* g);

  // Parámetros:
  // Efecto:
  // Retorna:
  // Requiere:
  // Modifica: N/A
  ResultadoPrim* Prim(GRAFO* g);

  // Parámetros:
  // Efecto:
  // Retorna:
  // Requiere:
  // Modifica: N/A
  std::vector<AristaKruskal> Kruskal(GRAFO* g);

  // CircuitoHamiltonMC-BEP
  // Parámetros:
  // Efecto:
  // Retorna:
  // Requiere:
  // Modifica: N/A
  Vertice** CircuitoHamiltonMC_BEP(GRAFO* g);
};

#endif  // MENU_HPP
