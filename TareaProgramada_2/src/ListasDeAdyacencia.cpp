#include "ListasDeAdyacencia.hpp"

#include <iterator>

void ListasDeAdyacencia::Iniciar() {
  this->listaVert = nullptr;
  this->cantVert = 0;
}

void ListasDeAdyacencia::Destruir() {
  if (!this->Vacio()) {
    Vaciar();
  }
}

void ListasDeAdyacencia::Vaciar() {
  Vertice* aux = this->listaVert;
  while (aux != nullptr) {
    Arista* aristaAux = aux->listaAristas;
    while (aristaAux != nullptr) {
      Arista* aristaBorrar = aristaAux;
      aristaAux = aristaAux->sigArista;
      this->EliminarArista(aux, aristaBorrar->verticeApuntado);
    }
    Vertice* borrar = aux;
    aux = aux->siguienteVert;
    this->EliminarVert(borrar);
  }
}

bool ListasDeAdyacencia::Vacio() {
  if (this->listaVert != nullptr) {
    return false;
  }
  return true;
}

Vertice* ListasDeAdyacencia::AgregarVert(std::string etiq) {
  Vertice* toAdd = new Vertice();
  toAdd->etiqueta = etiq;

  if (this->listaVert == nullptr) {
    this->listaVert = toAdd;
  } else {
    toAdd->siguienteVert = this->listaVert;
    this->listaVert = toAdd;
  }
  ++this->cantVert;
  return toAdd;
}

void ListasDeAdyacencia::EliminarVert(Vertice* vert) {
  Vertice* iterador = this->listaVert;
  if (vert == iterador) {
    this->listaVert = iterador->siguienteVert;
    delete iterador;
    this->cantVert--;
    return;
  }

  while (iterador != nullptr && iterador->siguienteVert != vert) {
    iterador = iterador->siguienteVert;
  }

  iterador->siguienteVert = vert->siguienteVert;
  this->cantVert--;
  delete vert;
}

void ListasDeAdyacencia::ModificarEtiqueta(Vertice* vert, std::string etiq) {
  vert->etiqueta = etiq;
}

std::string ListasDeAdyacencia::Etiqueta(Vertice* vert) {
  return vert->etiqueta;
}

void ListasDeAdyacencia::AgregarArista(
    Vertice* salida, Vertice* llegada, double peso) {
  Arista* aristaAgregar = new Arista();
  Arista* aristaAgregarInv = new Arista();

  aristaAgregar->peso = peso;
  aristaAgregar->verticeApuntado = llegada;
  aristaAgregar->sigArista = salida->listaAristas;

  aristaAgregarInv->peso = peso;
  aristaAgregarInv->verticeApuntado = salida;
  aristaAgregarInv->sigArista = llegada->listaAristas;

  salida->listaAristas = aristaAgregar;
  llegada->listaAristas = aristaAgregarInv;
}

void ListasDeAdyacencia::EliminarArista(Vertice* salida, Vertice* llegada) {
  bool salirS = false;
  bool salirL = false;
  Arista* aristaABorrar = salida->listaAristas;
  Arista* aristaABorrarLlegada = llegada->listaAristas;
  
  if (aristaABorrar->verticeApuntado == llegada) {
    salida->listaAristas = aristaABorrar->sigArista;
    delete aristaABorrar;
    salirS = true;
  }

  if (aristaABorrarLlegada->verticeApuntado == salida) {
    llegada->listaAristas = aristaABorrarLlegada->sigArista;
    delete aristaABorrarLlegada;
    salirL = true;
  }

  if (!salirS) {
    while (aristaABorrar->sigArista->verticeApuntado != llegada) {
      aristaABorrar = aristaABorrar->sigArista;
    }
    aristaABorrar->sigArista = aristaABorrar->sigArista->sigArista;
    delete aristaABorrar->sigArista;
  }

  if (!salirL) {
    while (aristaABorrarLlegada->sigArista->verticeApuntado != salida) {
      aristaABorrarLlegada = aristaABorrarLlegada->sigArista;
    }
    aristaABorrarLlegada->sigArista = aristaABorrarLlegada->sigArista->sigArista;
    delete aristaABorrarLlegada->sigArista;
  }
}

void ListasDeAdyacencia::ModificarPeso(
    Vertice* salida, Vertice* llegada, double peso) {
  Arista* pesoAModificar = salida->listaAristas;
  while (pesoAModificar->verticeApuntado != llegada) {
    pesoAModificar = pesoAModificar->sigArista;
  }
  pesoAModificar->peso = peso;
}

double ListasDeAdyacencia::Peso(Vertice* salida, Vertice* llegada) {
  Arista* pesoARetornar = salida->listaAristas;
  while (pesoARetornar->verticeApuntado != llegada) {
    pesoARetornar = pesoARetornar->sigArista;
  }
  return pesoARetornar->peso;
}

Vertice* ListasDeAdyacencia::PrimerVertice() { return this->listaVert; }

Vertice* ListasDeAdyacencia::SiguienteVertice(Vertice* vert) {
  return vert->siguienteVert;
}

Vertice* ListasDeAdyacencia::PrimerVerticeAdyacente(Vertice* primer) {
  if (primer->listaAristas != nullptr) {
    return primer->listaAristas->verticeApuntado;
  }
  return nullptr;
}

Vertice* ListasDeAdyacencia::SiguienteVerticeAdyacente(
    Vertice* vert, Vertice* sig) {
  Arista* aristaAux = vert->listaAristas;
  while (aristaAux->verticeApuntado != sig) {
    aristaAux = aristaAux->sigArista;
  }
  if (aristaAux->sigArista != nullptr) {
    return aristaAux->sigArista->verticeApuntado; 
  }
  return nullptr;
}

int64_t ListasDeAdyacencia::NumVertices() { return this->cantVert; }
