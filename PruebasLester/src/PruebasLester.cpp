#include <iostream>
#include "../../ArbolHMIHD/src/ArbolHMIHD.hpp"

int main() {
    ArbolHMIHD arbol;
    arbol.Iniciar();
    arbol.PonerRaiz(1);
    arbol.AgregarHijo(arbol.Raiz(), 1, 2);
    arbol.AgregarHijo(arbol.Raiz(), 2, 3);
    arbol.Imprimir();
    arbol.Destruir();
    return 0;
}