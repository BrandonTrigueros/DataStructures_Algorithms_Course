// Modelo Arbol implementado en la estructura de datos
// Arbol Hijo mas izquierdo hermano derecho
// donde cada nodo tiene dos punteros uno al hijo mas izquierdo y otro al hermano derecho
#ifndef ARBOLHMIHD_HPP

class ArbolHMIHD
{
  private:
    struct nodoArbol {
      int etiqueta;
      nodoArbol* hijoMasIzq;
      nodoArbol* hermanoDer;
    };
    nodoArbol* raiz;
  public:
    ArbolHMIHD();
    ~ArbolHMIHD();

};

#endif // ARBOLHMIHD_HPP