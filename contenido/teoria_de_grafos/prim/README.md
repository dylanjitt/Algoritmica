# Prim

El algoritmo Prim es un algoritmo Greedy que pertenece a la teoria de grafos para encontrar un arbol de expansion minimo (minimum spanning tree, MST) en un grafo conexo no dirigido y podnderados, en otras palabras, es capaz de encontrar un subconjunto de las aristas que formen un arbol que incluya todos los vertices del grafo inicial, donde el peso total de las aristas del arbol es el minimo posible.

Si el grafo no es conexo, entonces el algoritmo encontrará el MST para uno de los componentes conexos que forman dicho grafo no conexo.

Este es su funcionamiento:
1. se marca un vertice cualquiera. Será el vertice de partida.
2. se selecciona la arista de menor peso incidente en el vertice seleccionado anteriormente y se selecciona el otro vertice en el que incide dicha arista.
3. Repetir el paso 2 siempre que la arista elegida enlace un vertice seleccionado y otro que no lo esté. Es decir, siempre que la arista elegida no cree ningun ciclo.
4. El MST sera encontrado cuando hayan sido seleccionados todos los vertices del grafo.

![download](https://user-images.githubusercontent.com/101950765/197363058-cf08f1b8-527f-4729-8ff2-56ae229f0883.png)

## Codigo Base
- [prim.cpp](https://github.com/dylanjitt/Algoritmica/blob/main/contenido/teoria_de_grafos/prim/prim.cpp)

## Problemas
- [sending email](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1927)
  - [solucion](https://github.com/dylanjitt/Algoritmica/blob/main/contenido/teoria_de_grafos/prim/sendingEmail.cpp)
  

## Referencias
- [Prim's algorithm](https://en.wikipedia.org/wiki/Prim%27s_algorithm)
- [Prim's minimum spanning tree](https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/)
