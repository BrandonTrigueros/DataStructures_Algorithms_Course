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
    nodoArbol* raizArbol;
    int contadorNodos;
  public:
    ArbolHMIHD();
    ~ArbolHMIHD();
    void crear();
    void destruir();
    void destruirPostOrden(nodoArbol* nodo);
    void vaciar();
    bool vacio();
    void ponerRaiz(int etiqueta);
    int agregarHijo(int etiquetaAgregar, int etiquetaPadre, int posicion);
    void borrarHoja(int etiqueta);
    void modificarEtiqueta(int etiqueta, int nuevaEtiqueta);
    int raiz();
    int padre(int etiqueta);
    int hijoMasIzquierdo(int etiqueta);
    int hermanoDerecho(int etiqueta);
    int etiqueta(nodoArbol* nodo);
    int numNodos();
    int numHijos(int etiqueta);
};

#endif // ARBOLHMIHD_HPP