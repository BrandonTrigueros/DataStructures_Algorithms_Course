#ifndef LISTAS_DE_ADYACENCIA
#define LISTAS_DE_ADYACENCIA

#include <cstdint>
#include <string>

#include <iostream>

struct Vertice;

struct Aristas {
  double peso = 0;
  Vertice *verticeApuntado = nullptr;
  Aristas* sigArista = nullptr;
};

struct Vertice {
  Aristas *listaAristas = nullptr;
  Vertice *siguienteVert = nullptr;
  std::string etiqueta = "";
};

class ListasDeAdyacencia {
 public:
  Vertice *listaVert;
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
  Vertice* PrimerVerticeAdyacente(Vertice* primer, Vertice* segundo);
  Vertice* SiguienteVerticeAdyacente(Vertice* vert);
  int64_t NumVertices();
};

#endif // LISTAS_DE_ADYACENCIA
