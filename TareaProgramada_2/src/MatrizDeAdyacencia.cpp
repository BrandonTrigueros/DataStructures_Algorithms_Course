#include "MatrizDeAdyacencia.hpp"

// implementar por matriz de adyacencia el modelo Grafo No Dirigido, con pesos,
// sin aristas paralelas y sin lazos.

void MatrizDeAdyacencia::Iniciar() {
  this->limiteMatriz = std::numeric_limits<int64_t>::max();
  this->maxVertices = MAX_VERTICES;
  this->cantVertices = 0;
  this->vertices = new Vertice[this->maxVertices];
  this->matriz = new Arista*[this->maxVertices];
  for (int64_t i = 0; i < this->maxVertices; i++) {
    this->matriz[i] = new Arista[this->maxVertices];
  }
}

void MatrizDeAdyacencia::Destruir() {
  this->vertices = nullptr;
  this->cantVertices = 0;
  delete[] this->vertices;
  for (int64_t i = 0; i < this->maxVertices; i++) {
    delete[] this->matriz[i];
  }
  delete[] this->matriz;
}

void MatrizDeAdyacencia::Vaciar() { this->cantVertices = 0; }

bool MatrizDeAdyacencia::Vacio() { return this->cantVertices == 0; }

Vertice* MatrizDeAdyacencia::AgregarVert(std::string etiq) {
  if (this->cantVertices < this->maxVertices) {
    this->vertices[this->cantVertices].setEtiqueta(etiq);
    this->cantVertices++;
    return &this->vertices[this->cantVertices - 1];
  }
  return nullptr;
}

void MatrizDeAdyacencia::EliminarVert(Vertice* vert) {
  int64_t indice = this->limiteMatriz;
  for (int64_t i = 0; i < this->cantVertices; i++) {
    if (&this->vertices[i] == vert) {
      indice = i;
      break;
    }
  }
  if (indice != this->limiteMatriz) {
    for (int64_t i = indice; i < this->cantVertices - 1; i++) {
      this->vertices[i] = this->vertices[i + 1];
    }
    for (int64_t i = 0; i < this->cantVertices; i++) {
      for (int64_t j = indice; j < this->cantVertices - 1; j++) {
        this->matriz[i][j] = this->matriz[i][j + 1];
      }
    }
    for (int64_t i = indice; i < this->cantVertices - 1; i++) {
      for (int64_t j = 0; j < this->cantVertices; j++) {
        this->matriz[i][j] = this->matriz[i + 1][j];
      }
    }
    this->cantVertices--;
  }
}

void MatrizDeAdyacencia::ModificarEtiqueta(Vertice* vert, std::string etiq) {
  for (int64_t i = 0; i < this->cantVertices; i++) {
    if (&this->vertices[i] == vert) {
      this->vertices[i].etiqueta = etiq;
      break;
    }
  }
}

std::string MatrizDeAdyacencia::Etiqueta(Vertice* vert) {
  for (int64_t i = 0; i < this->cantVertices; i++) {
    if (&this->vertices[i] == vert) {
      return this->vertices[i].etiqueta;
    }
  }
  return "";
}

void MatrizDeAdyacencia::AgregarArista(
    Vertice* salida, Vertice* llegada, double peso) {
  int64_t indiceSalida = this->limiteMatriz;
  int64_t indiceLlegada = this->limiteMatriz;
  for (int64_t i = 0; i < this->cantVertices; i++) {
    if (&this->vertices[i] == salida) {
      indiceSalida = i;
    }
    if (&this->vertices[i] == llegada) {
      indiceLlegada = i;
    }
  }
  if (indiceSalida != this->limiteMatriz
      && indiceLlegada != this->limiteMatriz) {
    this->matriz[indiceSalida][indiceLlegada].peso = peso;
    this->matriz[indiceLlegada][indiceSalida].peso = peso;
  }
}

void MatrizDeAdyacencia::EliminarArista(Vertice* salida, Vertice* llegada) {
  int64_t indiceSalida = this->limiteMatriz;
  int64_t indiceLlegada = this->limiteMatriz;
  for (int64_t i = 0; i < this->cantVertices; i++) {
    if (&this->vertices[i] == salida) {
      indiceSalida = i;
    }
    if (&this->vertices[i] == llegada) {
      indiceLlegada = i;
    }
  }
  if (indiceSalida != this->limiteMatriz
      && indiceLlegada != this->limiteMatriz) {
    this->matriz[indiceSalida][indiceLlegada].peso = this->limiteMatriz;
    this->matriz[indiceLlegada][indiceSalida].peso = this->limiteMatriz;
  }
}

void MatrizDeAdyacencia::ModificarPeso(
    Vertice* salida, Vertice* llegada, double peso) {
  int64_t indiceSalida = this->limiteMatriz;
  int64_t indiceLlegada = this->limiteMatriz;
  for (int64_t i = 0; i < this->cantVertices; i++) {
    if (&this->vertices[i] == salida) {
      indiceSalida = i;
    }
    if (&this->vertices[i] == llegada) {
      indiceLlegada = i;
    }
  }
  if (indiceSalida != this->limiteMatriz
      && indiceLlegada != this->limiteMatriz) {
    this->matriz[indiceSalida][indiceLlegada].peso = peso;
    this->matriz[indiceLlegada][indiceSalida].peso = peso;
  }
}

double MatrizDeAdyacencia::Peso(Vertice* salida, Vertice* llegada) {
  int64_t indiceSalida = this->limiteMatriz;
  int64_t indiceLlegada = this->limiteMatriz;
  for (int64_t i = 0; i < this->cantVertices; i++) {
    if (&this->vertices[i] == salida) {
      indiceSalida = i;
    }
    if (&this->vertices[i] == llegada) {
      indiceLlegada = i;
    }
  }
  if (indiceSalida != this->limiteMatriz
      && indiceLlegada != this->limiteMatriz) {
    return this->matriz[indiceSalida][indiceLlegada].peso;
  }
  return this->limiteMatriz;
}

Vertice* MatrizDeAdyacencia::PrimerVertice() {
  if (this->cantVertices > 0) {
    return &this->vertices[0];
  }
  return nullptr;
}

Vertice* MatrizDeAdyacencia::SiguienteVertice(Vertice* vert) {
  for (int64_t i = 0; i < this->cantVertices - 1; i++) {
    if (&this->vertices[i] == vert) {
      return &this->vertices[i + 1];
    }
  }
  return nullptr;
}

Vertice* MatrizDeAdyacencia::PrimerVerticeAdyacente(Vertice* segundo) {
  int64_t indice = this->limiteMatriz;
  for (int64_t i = 0; i < this->cantVertices; i++) {
    if (&this->vertices[i] == segundo) {
      indice = i;
      break;
    }
  }
  if (indice != this->limiteMatriz) {
    for (int64_t i = 0; i < this->cantVertices; i++) {
      if (this->matriz[indice][i].peso != this->limiteMatriz) {
        return &this->vertices[i];
      }
    }
  }
  return nullptr;
}

Vertice* MatrizDeAdyacencia::SiguienteVerticeAdyacente(
    Vertice* vert, Vertice* sig) {
  int64_t indiceVert = this->limiteMatriz;
  int64_t indiceSig = this->limiteMatriz;
  for (int64_t i = 0; i < this->cantVertices; i++) {
    if (&this->vertices[i] == vert) {
      indiceVert = i;
    }
    if (&this->vertices[i] == sig) {
      indiceSig = i;
    }
  }
  if (indiceVert != this->limiteMatriz && indiceSig != this->limiteMatriz) {
    for (int64_t i = indiceSig + 1; i < this->cantVertices; i++) {
      if (this->matriz[indiceVert][i].peso != this->limiteMatriz) {
        return &this->vertices[i];
      }
    }
  }
  return nullptr;
}

int64_t MatrizDeAdyacencia::NumVertices() { return this->cantVertices; }

MatrizDeAdyacencia::MatrizDeAdyacencia() {
  this->vertices = nullptr;
  this->matriz = nullptr;
}

MatrizDeAdyacencia::~MatrizDeAdyacencia() { }
