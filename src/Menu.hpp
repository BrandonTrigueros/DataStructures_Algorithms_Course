#ifndef MENU_HPP
#define MENU_HPP

#include "ArbolArreglo.hpp"
// #include "ArbolListaDeListas.hpp"
// #include "ArbolHMIHD.hpp"
// #include "ArbolHMIHDPADRE.hpp"
#include "Cola.hpp"

#include <cstdint>
#include <iostream>
#include <map>
#include <string>

#define OPCIONES_PRINCIPAL                                                        \
  "╔═══════════════════════╗\n" \
  "║    Menú Principal     ║\n"                                              \
  "║ 1. Modelo Cola        ║\n"                                               \
  "║ 2. Modelo Árbol       ║\n"                                              \
  "║ 3. Créditos           ║\n"                                              \
  "║ 4. Salir              ║\n"                                               \
  "╚═══════════════════════╝\n" \
  "Seleccione una opción: "

#define OPERADORES_ARBOL                                                                                                                               \
  "╔══════════════════════════════════════════════╗\n" \
  "║         Operadores Básicos Árbol             ║\n"                                                                                           \
  "║ 1. Iniciar            2. Destruir            ║\n"                                                                                             \
  "║ 3. Vaciar             4. Vacío               ║\n"                                                                                            \
  "║ 5. AgregarHijo        6. BorrarHoja          ║\n"                                                                                             \
  "║ 7. PonerRaíz          8. HijoMasIzq          ║\n"                                                                                            \
  "║ 9. HermanoDer         10. ModificarEtiqueta  ║\n"                                                                                             \
  "║ 11. Raíz              12. Padre              ║\n"                                                                                            \
  "║ 13. Etiqueta          14. NumHijos           ║\n"                                                                                             \
  "║ 15. EsHoja            16. NumNodos           ║\n"                                                                                             \
  "║ 18. Volver                                   ║\n"                                                                                             \
  "╚══════════════════════════════════════════════╝\n" \
  "Seleccione una opción: "

#define OPERADORES_COLA                                                                                                              \
  "╔════════════════════════════════════════╗\n" \
  "║        Operadores Básicos Cola         ║\n"                                                                                \
  "║ 1. Iniciar        2. Destruir          ║\n"                                                                                 \
  "║ 3. Vaciar         4. Vacío             ║\n"                                                                                \
  "║ 5. Encolar        6. Desencolar        ║\n"                                                                                 \
  "║ 7. Frente         8. Último            ║\n"                                                                                \
  "║ 9. NumElementos   11. Volver           ║\n"                                                                                 \
  "╚════════════════════════════════════════╝\n" \
  "Seleccione una opción: "

#define CREDITOS                                                                                    \
  "╔═════════════════════════════╗\n" \
  "║          Créditos           ║\n"                                                          \
  "║ Lester Pereira Cerdas       ║\n"                                                           \
  "║ Christopher Acosta Madrigal ║\n"                                                           \
  "║ Brandon Trigueros Lara      ║\n"                                                           \
  "╚═════════════════════════════╝\n"

class Menu {
 private:
  Cola<int64_t>* cola;
  ARBOL* arbol;

 public:
  Menu();
  ~Menu();

  void run();
  void runCola();
  void runArbol();

  int mostrarPrincipal();
  int mostrarOperadoresArbol();
  int mostrarOperadoresCola();
  void mostrarCreditos();
  void mostrarColaActual();
  void mostrarArbolActual();

  // Algoritmos
  NODO* BuscarNodo(ARBOL* a, int64_t etiqueta);

  NODO* HermanoIzquierdo(ARBOL* a, NODO* n);
  bool EtiquetasRepetidas(ARBOL* a);
  int64_t AlturaNodo(ARBOL* a, NODO* n);
  int64_t ProfundidadNodo(ARBOL* a, NODO* n);
  int64_t NivelesArbolPreOrden(ARBOL* a);
  int64_t NivelesArbolNiveles(ARBOL* a);
  void ListarEtiquetasNivel_I(ARBOL* a, int64_t i);

  void ListarArbolPreOrden(ARBOL* a);
  void ListarArbolNiveles(ARBOL* a);
  bool BuscarEtiqueta(ARBOL* a, NODO* n);
  void BorrarSubArbol(ARBOL* a, NODO* n);
  void ListarHijosNodos(ARBOL* a, NODO* n);
};

#endif  // MENU_HPP
