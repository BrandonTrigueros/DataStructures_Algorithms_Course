#include <cstdint>

#ifndef ARBOL_DE_LISTAS 
#define ARBOL_DE_LISTAS 

struct ListaPrincipal;

struct ListaPunteros{
  ListaPunteros* sigP;
  ListaPrincipal* hijo;
};

struct ListaPrincipal{
  int64_t etiqueta;
  ListaPrincipal* sigM;
  ListaPunteros* primero;
};

class ArbolListaDeListas {


  ListaPrincipal* raiz;

 public:
  ArbolListaDeListas(){};
  ~ArbolListaDeListas(){};
  
  void Iniciar();
  void Destruir();
  void Vaciar();
  bool Vacio();
  ListaPrincipal* AgregarHijo(ListaPrincipal* nodo, int64_t numHijo,
      int64_t etiqueta);
  void BorrarHoja(ListaPrincipal* nodo);
  void PonerRaiz(int64_t etiqueta);
  ListaPrincipal* HijoMasIzq(ListaPrincipal* nodo);
  ListaPrincipal* HermanoDer(ListaPrincipal* nodo);
  void ModificarEtiqueta(ListaPrincipal* nodo, int64_t etiqueta);
  ListaPrincipal* Raiz();
  ListaPrincipal* Padre(ListaPrincipal* nodo);
  int64_t Etiqueta(ListaPrincipal* nodo);
  int64_t NumHijos(ListaPrincipal* nodo);
  bool EsHoja(ListaPrincipal* nodo);
  int64_t NumNodos();
};

#endif
