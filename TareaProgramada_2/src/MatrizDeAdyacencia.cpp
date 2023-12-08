#include "MatrizDeAdyacencia.hpp"

void MatrizDeAdyacencia::Iniciar()
{
  this->maxVertices = MAX_VERTICES;
  this->cantVertices = 0;
  this->vertices = new Vertice[this->maxVertices];
  this->matriz = new Arista**[this->maxVertices];
  for (int64_t i = 0; i < this->maxVertices; ++i) {
    this->matriz[i] = new Arista*[this->maxVertices];
    for (int64_t j = 0; j < this->maxVertices; ++j) {
      this->matriz[i][j] = new Arista();
    }
  }
}

void MatrizDeAdyacencia::Destruir() 
{
  if (!this->Vacio()) {
    Vaciar();
  }
  // Liberar la memoria de los vértices
}

void MatrizDeAdyacencia::Vaciar()
{
  this->cantVertices = 0;
  for (int64_t i = 0; i < this->maxVertices; ++i) {
    for (int64_t j = 0; j < this->maxVertices; ++j) {
      this->matriz[i][j]->peso = -1;
    }
  }
}

bool MatrizDeAdyacencia::Vacio()
{
  if (this->cantVertices == 0) {
    return true;
  }
  return false;
}

Vertice* MatrizDeAdyacencia::AgregarVert(std::string etiq)
{
  Vertice* toAdd = new Vertice(etiq);
  toAdd->etiqueta = etiq;
  this->vertices[this->cantVertices] = *toAdd;
  ++this->cantVertices;
  return toAdd;
}

void MatrizDeAdyacencia::EliminarVert(Vertice* vert)
{
  int64_t pos = 0;
  for (int64_t i = 0; i < this->cantVertices; ++i) {
    if (this->vertices[i].etiqueta == vert->etiqueta) {
      pos = i;
      break;
    }
  }
  for (int64_t i = pos; i < this->cantVertices - 1; ++i) {
    this->vertices[i] = this->vertices[i + 1];
  }
  for (int64_t i = 0; i < this->cantVertices; ++i) {
    for (int64_t j = pos; j < this->cantVertices - 1; ++j) {
      this->matriz[i][j] = this->matriz[i][j + 1];
    }
  }
  for (int64_t i = pos; i < this->cantVertices - 1; ++i) {
    for (int64_t j = 0; j < this->cantVertices; ++j) {
      this->matriz[i][j] = this->matriz[i + 1][j];
    }
  }
  --this->cantVertices;
}

void MatrizDeAdyacencia::ModificarEtiqueta(Vertice* vert, std::string etiq)
{
  vert->etiqueta = etiq;
}

std::string MatrizDeAdyacencia::Etiqueta(Vertice* vert)
{
  return vert->etiqueta;
}

void MatrizDeAdyacencia::AgregarArista(
    Vertice* salida, Vertice* llegada, double peso)
{
  int64_t posSalida = 0;
  int64_t posLlegada = 0;
  for (int64_t i = 0; i < this->cantVertices; ++i) {
    if (this->vertices[i].etiqueta == salida->etiqueta) {
      posSalida = i;
    }
    if (this->vertices[i].etiqueta == llegada->etiqueta) {
      posLlegada = i;
    }
  }
  this->matriz[posSalida][posLlegada]->peso = peso;
}

void MatrizDeAdyacencia::EliminarArista(
    Vertice* salida, Vertice* llegada)
{
  int64_t posSalida = 0;
  int64_t posLlegada = 0;
  for (int64_t i = 0; i < this->cantVertices; ++i) {
    if (this->vertices[i].etiqueta == salida->etiqueta) {
      posSalida = i;
    }
    if (this->vertices[i].etiqueta == llegada->etiqueta) {
      posLlegada = i;
    }
  }
  this->matriz[posSalida][posLlegada]->peso = -1;
}

void MatrizDeAdyacencia::ModificarPeso(
    Vertice* salida, Vertice* llegada, double peso)
{
  int64_t posSalida = 0;
  int64_t posLlegada = 0;
  for (int64_t i = 0; i < this->cantVertices; ++i) {
    if (this->vertices[i].etiqueta == salida->etiqueta) {
      posSalida = i;
    }
    if (this->vertices[i].etiqueta == llegada->etiqueta) {
      posLlegada = i;
    }
  }
  this->matriz[posSalida][posLlegada]->peso = peso;
}

double MatrizDeAdyacencia::Peso(Vertice* salida, Vertice* llegada)
{
  int64_t posSalida = 0;
  int64_t posLlegada = 0;
  for (int64_t i = 0; i < this->cantVertices; ++i) {
    if (this->vertices[i].etiqueta == salida->etiqueta) {
      posSalida = i;
    }
    if (this->vertices[i].etiqueta == llegada->etiqueta) {
      posLlegada = i;
    }
  }
  return this->matriz[posSalida][posLlegada]->peso;
}

Vertice* MatrizDeAdyacencia::PrimerVertice()
{
  if (this->cantVertices == 0) {
    return nullptr;
  } else {
    return &this->vertices[0];
  }
}

Vertice* MatrizDeAdyacencia::SiguienteVertice(Vertice* vert)
{
  int64_t pos = 0;
  for (int64_t i = 0; i < this->cantVertices; ++i) {
    if (this->vertices[i].etiqueta == vert->etiqueta) {
      pos = i;
      break;
    }
  }
  if (pos == this->cantVertices) {
    return nullptr;
  } else {
    return &this->vertices[pos + 1];
  }
}

Vertice* MatrizDeAdyacencia::PrimerVerticeAdyacente(Vertice* segundo)
{
  int64_t pos = 0;
  for (int64_t i = 0; i < this->cantVertices; ++i) {
    if (this->vertices[i].etiqueta == segundo->etiqueta) {
      pos = i;
      break;
    }
  }
  for (int64_t i = 0; i < this->cantVertices; ++i) {
    if (this->matriz[pos][i]->peso != -1) {
      return &this->vertices[i];
    }
  }
  return nullptr;
}

Vertice* MatrizDeAdyacencia::SiguienteVerticeAdyacente(
    Vertice* vert, Vertice* sig)
{
  int64_t pos = 0;
  int64_t posSig = 0;
  for (int64_t i = 0; i < this->cantVertices; ++i) {
    if (this->vertices[i].etiqueta == vert->etiqueta) {
      pos = i;
    }
    if (this->vertices[i].etiqueta == sig->etiqueta) {
      posSig = i;
    }
  }
  for (int64_t i = posSig + 1; i < this->cantVertices; ++i) {
    if (this->matriz[pos][i]->peso != -1) {
      return &this->vertices[i];
    }
  }
  return nullptr;
}

int64_t MatrizDeAdyacencia::NumVertices()
{
  return this->cantVertices;
}

MatrizDeAdyacencia::MatrizDeAdyacencia()
{
}

MatrizDeAdyacencia::~MatrizDeAdyacencia()
{
}
