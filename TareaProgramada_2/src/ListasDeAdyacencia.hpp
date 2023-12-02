#ifndef LISTAS_DE_ADYACENCIA
#define LISTAS_DE_ADYACENCIA

#include <cstdint>
#include <iostream>
#include <string>

struct Vertice;

struct Arista {
  double peso = 0;
  Vertice* verticeApuntado = nullptr;
  Arista* sigArista = nullptr;
};

struct Vertice {
  Arista* listaAristas = nullptr;
  Vertice* siguienteVert = nullptr;
  std::string etiqueta = "";
};

class ListasDeAdyacencia {
 public:
  Vertice* listaVert;
  int64_t cantVert;

 public:
  void Iniciar();
  void Destruir();
  void Vaciar();
  bool Vacio();
  Vertice* AgregarVert(std::string etiq);
  void EliminarVert(Vertice* vert);
  void ModificarEtiqueta(Vertice* vert, std::string etiq);
  std::string Etiqueta(Vertice* vert);
  void AgregarArista(Vertice* salida, Vertice* llegada, double peso);
  void EliminarArista(Vertice* salida, Vertice* llegada);
  void ModificarPeso(Vertice* salida, Vertice* llegada, double peso);
  double Peso(Vertice* salida, Vertice* llegada);
  Vertice* PrimerVertice();
  Vertice* SiguienteVertice(Vertice* vert);
  Vertice* PrimerVerticeAdyacente(Vertice* segundo);
  Vertice* SiguienteVerticeAdyacente(Vertice* vert, Vertice* sig);
  int64_t NumVertices();
};

#define GRAFO ListasDeAdyacencia
#endif  // LISTAS_DE_ADYACENCIA
