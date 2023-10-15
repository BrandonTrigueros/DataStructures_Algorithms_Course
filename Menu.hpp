#pragma once

#include <iostream>
#include <string>

// #include "ArbolListas/ArbolListaDeListas.hpp"
#include "ArbolHMIHD/src/ArbolHMIHD.hpp"
// #include "ArbolHMIHDPADRE/src/ArbolHMIHDPADRE.hpp"
#include "Cola/Cola.hpp"

#define OPCIONES_PRINCIPAL                                                        \
  "╔═══════════════════════╗\n" \
  "║    Menú Principal     ║\n"                                              \
  "║ 1. Modelo Cola        ║\n"                                               \
  "║ 2. Modelo Árbol       ║\n"                                              \
  "║ 3. Créditos           ║\n"                                              \
  "║ 4. Salir              ║\n"                                               \
  "╚═══════════════════════╝\n" \
  "Seleccione una opción: "

#define OPERADORES_ARBOL                                                                                                                   \
  "╔══════════════════════════════════════════╗\n" \
  "║         Operadores Básicos Árbol         ║\n"                                                                                   \
  "║ 1. Iniciar        2. Destruir            ║\n"                                                                                     \
  "║ 3. Vaciar         4. Vacío               ║\n"                                                                                    \
  "║ 5. AgregarHijo    6. BorrarHoja          ║\n"                                                                                     \
  "║ 7. PonerRaíz      8. HijoMasIzq          ║\n"                                                                                    \
  "║ 9. HermanoDer     10. ModificarEtiqueta  ║\n"                                                                                     \
  "║ 11. Raíz          12. Padre              ║\n"                                                                                    \
  "║ 13. Etiqueta      14. NumHijos           ║\n"                                                                                     \
  "║ 15. EsHoja        16. NumNodos           ║\n"                                                                                     \
  "╚══════════════════════════════════════════╝\n" \
  "Seleccione una opción: "

#define OPERADORES_COLA                                                                                         \
  "╔═════════════════════════════════╗\n" \
  "║    Operadores Básicos Cola      ║\n"                                                                  \
  "║ 1. Iniciar        2. Destruir   ║\n"                                                                   \
  "║ 3. Vaciar         4. Vacío      ║\n"                                                                  \
  "║ 5. Encolar        6. Desencolar ║\n"                                                                   \
  "║ 7. Frente         8. Último     ║\n"                                                                  \
  "║ 9. NumElementos                 ║\n"                                                                   \
  "╚═════════════════════════════════╝\n" \
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
  Cola* cola;
  ARBOL* arbol;

 public:
  Menu();
  ~Menu();

  int mostrarPrincipal();
  int mostrarOperadoresArbol();
  int mostrarOperadoresCola();
  void mostrarCreditos();
  void mostrarColaActual();
  void mostrarArbolActual();

  void run();
};