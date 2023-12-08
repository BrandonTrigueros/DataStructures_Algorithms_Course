#ifndef MATRIZ_DE_ADYACENCIA_HPP
#define MATRIZ_DE_ADYACENCIA_HPP

#define MAX_VERTICES 100

#include <cstdint>
#include <iostream>
#include <vector>

struct Arista {
  double peso;

  Arista(double pesoAux = -1) {
    this->peso = pesoAux;
  }

  void setPeso(double pesoAux) {
    this->peso = pesoAux;
  }
};

struct Vertice {
  std::string etiqueta;
  Vertice(std::string etiq = "") {
    this->etiqueta = etiq;
  }
};

class MatrizDeAdyacencia
{
  private:
    int64_t maxVertices;
    int64_t cantVertices;
    Vertice* vertices;
    Arista*** matriz;

  public:
    MatrizDeAdyacencia();
    ~MatrizDeAdyacencia();

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

#define GRAFO MatrizDeAdyacencia

#endif // MATRIZ_DE_ADYACENCIA_HPP