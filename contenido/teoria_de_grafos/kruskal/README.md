# Kruskal

Kruskal es un algoritmo que utiliza un arbol de minima expansión (Minimum spanning tree), que toma un grafo como input y encuentra un subconjunto de nodos que forman un arbol que incluye cada vertice y tiene una suma de pesos minima a traves de todas las combinaciones de arboles posibles.

Comenzamos desde los bordes con el peso menor y añadimos mas bordes hasta llegar a nuestro objetivo.

Para implementar Kruskal tenemos que seguir los siguientes pasos:
1. ordenar todos los bordes de menor a mayor peso
2. tomar la esquina con el menor peso y añadirla al spanning tree, si al añadirla crea un bucle, es mejor rechazarla.
3. continua añadiendo conexiones hasta que cubran todos los vertices.


![Kruskal-8](https://user-images.githubusercontent.com/101950765/197363912-5a7c7b44-807d-42be-8b2f-fa6d927c55ef.png)

## Codigo
- [kruskal.cpp](https://github.com/dylanjitt/Algoritmica/blob/main/contenido/teoria_de_grafos/kruskal/kruskal.cpp)

## Problemas
- [Freckles](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=975)
- [Re-connecting computer sites](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=849)

## Referencias
- [kruskal's algorithm](https://www.programiz.com/dsa/kruskal-algorithm)
- [kruskal's minimum spanning tree algorithm](https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/)
