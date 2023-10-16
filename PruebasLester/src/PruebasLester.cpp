#include <iostream>
#include <cstdint>
//#include "ArbolHMIHDPADRE.hpp"
#include "ArbolHMIHD.hpp"       

int main() {
    ARBOL arbol;
    arbol.Iniciar();
    std::cout << "Arbol iniciado" << std::endl;
    arbol.PonerRaiz(1);
    std::cout << "Raiz puesta" << std::endl;
    arbol.AgregarHijo(arbol.Raiz(), 1, 2);
    arbol.AgregarHijo(arbol.Raiz(), 2, 3);
    arbol.AgregarHijo(arbol.Raiz(), 2, 4);
    arbol.AgregarHijo(arbol.Raiz(), 1, 5);

    std::cout << "Agregado de hijos" << std::endl;

    arbol.Imprimir();


    std::cout << "Busqueda de padre del 3: " <<  arbol.Etiqueta(arbol.Padre(arbol.BuscarEtiqueta(3))) << std::endl;
    std::cout << "Busqueda de padre del 4: " <<  arbol.Etiqueta(arbol.Padre(arbol.BuscarEtiqueta(4))) << std::endl;

    arbol.BorrarHoja(arbol.BuscarEtiqueta(3));
    arbol.BorrarHoja(arbol.BuscarEtiqueta(2));
    std::cout << "Borrado de hojas" << std::endl;
    std::cout << "Busqueda de padre del 4: " <<  arbol.Etiqueta(arbol.Padre(arbol.BuscarEtiqueta(4))) << std::endl;

    arbol.AgregarHijo(arbol.Raiz(), 1, 2);
    arbol.BorrarHoja(arbol.BuscarEtiqueta(2));

    arbol.AgregarHijo(arbol.BuscarEtiqueta(5), 1, 10);

    std::cout << "Busqueda de padre del 10: " <<  arbol.Etiqueta(arbol.Padre(arbol.BuscarEtiqueta(10))) << std::endl;


    arbol.Imprimir();
    std::cout << arbol.Etiqueta(arbol.HijoMasIzq(arbol.BuscarEtiqueta(5))) << std::endl;
    std::cout << arbol.Etiqueta(arbol.HermanoDer(arbol.BuscarEtiqueta(5))) << std::endl;
    arbol.ModificarEtiqueta(arbol.HermanoDer(arbol.BuscarEtiqueta(5)), 11);
    std::cout << arbol.Etiqueta(arbol.HermanoDer(arbol.BuscarEtiqueta(5))) << std::endl;

    std::cout << arbol.Etiqueta(arbol.Raiz()) << std::endl;

    std::cout << arbol.Etiqueta(arbol.Padre(arbol.BuscarEtiqueta(10))) << std::endl;

    std::cout << arbol.NumHijos(arbol.BuscarEtiqueta(1)) << std::endl;

    std::cout << "Es hoja el 10:"<< arbol.EsHoja(arbol.BuscarEtiqueta(10)) << std::endl;

    std::cout << "Es hoja el 5:"<< arbol.EsHoja(arbol.BuscarEtiqueta(5)) << std::endl;

    std::cout << arbol.NumNodos() << std::endl;

    std::cout << arbol.Vacio() << std::endl;
    arbol.Vaciar();
    std::cout << arbol.Vacio() << std::endl;

    arbol.Destruir();
    return 0;
}