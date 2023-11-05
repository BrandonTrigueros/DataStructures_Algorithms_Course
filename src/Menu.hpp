#ifndef MENU_HPP
#define MENU_HPP

// #include "ArbolArreglo.hpp"
// #include "ArbolListaDeListas.hpp"
#include "ArbolHMIHD.hpp"
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
  "║         Operadores Básicos Árbol             ║\n"\
  "║══════════════════════════════════════════════║\n"\
  "║ 1. Iniciar            2. Destruir            ║\n"                                                                                             \
  "║ 3. Vaciar             4. Vacío               ║\n"                                                                                            \
  "║ 5. AgregarHijo        6. BorrarHoja          ║\n"                                                                                             \
  "║ 7. PonerRaíz          8. HijoMasIzq          ║\n"                                                                                            \
  "║ 9. HermanoDer         10. ModificarEtiqueta  ║\n"                                                                                             \
  "║ 11. Raíz              12. Padre              ║\n"                                                                                            \
  "║ 13. Etiqueta          14. NumHijos           ║\n"                                                                                             \
  "║ 15. EsHoja            16. NumNodos           ║\n"\
  "║══════════════════════════════════════════════║\n"\
  "║                Algoritmos                    ║\n"\
  "║══════════════════════════════════════════════║\n"\
  "║ 17. HermanoIzq        18. EtiquetasRepetidas ║\n"\
  "║ 19. AlturaNodo        20. ProfundidadNodo    ║\n"\
  "║ 21. CantNivPreOrden   22. CantNivNiveles     ║\n"\
  "║ 23. EtiquetasNivel    24. PreOrden           ║\n"\
  "║ 25. Niveles           26. BuscarEtiqueta     ║\n"\
  "║ 27. BorrarSubArbol    28. HijosNodo          ║\n"\
  "║ 29. Volver                                   ║\n"                                                                                             \
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

  void crearArbolAuto(int64_t levelsToCreate);

// Algoritmos

// Parámetros: Árbol “a”, Etiqueta "etiqueta"
// Efecto: Busca un nodo en el arbol "a" con la etiqueta "etiqueta". Retorna un nodo si encuentra la etiqueta si no retorna nulo
// Requiere: Árbol “a” inicializado
// Modifica: N/A
  NODO* BuscarNodo(ARBOL* a, int64_t etiqueta);

// Parámetros: Árbol “a”, Nodo “n” 
// Efecto: Encuentra el hermano izquierdo de “n” en el Árbol “a” y lo retorna. Si no tiene hermano izquierdo retorna nulo
// Requiere: Árbol “a” inicializado, “n” válido en el Árbol “a”
// Modifica: N/A
  NODO* HermanoIzquierdo(ARBOL* a, NODO* n); 

// Parámetros: Árbol “a”
// Efecto: Busca si en el árbol “a” se encuentran etiquetas repetidas, retorna verdadero si se encuentra, retorna falso si no
// Requiere: Árbol “a” inicializado
// Modifica: N/A
  bool EtiquetasRepetidas(ARBOL* a);

// Parámetros: Árbol “a”, Nodo “n”
// Efecto: Obtiene la altura de un nodo “n”, retorna un entero que seria la altura de “n”
// Requiere: Árbol “a: inicializado, Nodo “n” que pertenezca a “a”
// Modifica:N/A
  int64_t AlturaNodo(ARBOL* a, NODO* n);

// Parámetros: Árbol “a”, Nodo “n”
// Efecto: Obtiene la profundidad de un nodo “n”, retorna un entero que seria la profundidad del nodo
// Requiere: Árbol “a” inicializado, Nodo “n” que pertenezca a “a”
// Modifica: N/A
  int64_t ProfundidadNodo(ARBOL* a, NODO* n);

// Parámetros: Árbol “a”
// Efecto: Obtiene la cantidad de niveles de “a” haciendo un recorrido en pre-orden, retorna un entero que seria el numero de niveles del árbol “a”
// Requiere: Árbol “a” inicializado
// Modifica: N/A
  int64_t NivelesArbolPreOrden(ARBOL* a);

// Parámetros: Árbol “a”
// Efecto: Obtiene la cantidad de niveles de “a” haciendo un recorrido por niveles
// Requiere: Árbol “a” inicializado
// Modifica: N/A
  int64_t NivelesArbolNiveles(ARBOL* a);

// Parámetros: Árbol “a”, Entero “i”
// Efecto: Imprime las etiquetas del nivel de “i”
// Requiere: “a” inicializado, “i” sea un nivel válido dentro del árbol “a”
// Modifica: N/A
  void ListarEtiquetasNivel_I(ARBOL* a, int64_t i);

// Parámetros: Árbol “a”
// Efecto: Imprime el árbol “a” utilizando un recorrido en pre-orden
// Requiere: “a” inicializado
// Modifica: N/A
  void ListarArbolPreOrden(ARBOL* a); 

// Parámetros: Árbol “a”
// Efecto: Imprime el árbol “a” utilizando un recorrido por niveles
// Requiere: “a” inicializado
// Modifica: N/A
  void ListarArbolNiveles(ARBOL* a); 

// Parámetros: Árbol “a”, int “etiqueta”
// Efecto: Buscar la etiqueta, retorna verdadero si la etiqueta se encuentra en árbol “a”, retorna falso si la etiqueta no se encuentra en “a”
// Requiere: “a” inicializado
// Modifica: N/A
  bool BuscarEtiqueta(ARBOL* a, int64_t etiqueta); 

// Parámetros: Árbol “a”, Nodo “n”
// Efecto: Elimina el sub-árbol utilizando “n” como raíz
// Requiere: “a” inicializado, “n” pertenezca al árbol “a”
// Modifica: Árbol “a”
  void BorrarSubArbol(ARBOL* a, NODO* n); 

// Parámetros: Árbol “a”, Nodo “n”
// Efecto: Imprime una lista con los hijos del nodo “n”
// Requiere: “a” inicializado, “n” pertenezca a árbol “a”
// Modifica: N/A
  void ListarHijosNodos(ARBOL* a, NODO* n); 
};

#endif  // MENU_HPP
