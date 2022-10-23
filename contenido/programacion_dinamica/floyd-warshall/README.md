# Floyd-Warshall
En ciencias de la computación, el algoritmo Floyd-Warshall es un algoritmo para encontrar los caminos mas cortos en grafos direccionados y ponderados con pesos positivos y negativos. Una sola ejecución del algoritmo podrá encontrar las distancias, o los caminos cortos entre pares de vértices, aunque no retorne los detalles de los pares, es posible reconstruir los caminos con simples modificaciones al algoritmo.

En pocas palabras, el problema es encontrar las distancias mas cortas entre cada par de vértices en un grafo direccionado y ponderado.

Para resolver el algoritmo tenemos que:
- Inicializar la matriz solución con un grafo input.
- Luego actualizamos la matriz solución considerando todos los vértices como intermediarios.
- Cada vez tenemos que escoger uno por uno todos los vértices y actualizar el camino mas corto, incluidos los intermediarios.
- Para cada par desde el origen hasta el destino, hay 2 posibles casos:
  1. K no es un vertice intermediario en el camino mas corto de i a j. mantenemos el valor de [i][j] tal como está
  2. K es un vertice intermediario, y actualizamos el valor de dist[i][j] a dist[i][k]+dist[k][j] si la primera es mayor a esta última suma.

![floyd](https://user-images.githubusercontent.com/101950765/197418371-8d1c6799-b135-4a70-88e1-4f6c1867faa2.jpg)

## Codigo
- [Floyd-Warshall](https://github.com/dylanjitt/Algoritmica/blob/main/contenido/programacion_dinamica/floyd-warshall/floyd_warshall.cpp)

En este caso el sistema tiene una complejidad O(n)= n^3, porque para recorrer el sistema entre el vertice inicio, vertice final, y el vertice mas corto (k), utiliza 3 for para compararlos entre si y/o actualizar el mas corto nuevo.
- [Floyd-warshall sin comentarios descriptivos](https://github.com/dylanjitt/Algoritmica/blob/main/contenido/programacion_dinamica/floyd-warshall/fwc.cpp)

## Referencias

- [Floyd-warshall algorithm](https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm)
- [Floyd-warshall](https://www.geeksforgeeks.org/floyd-warshall-algorithm-dp-16/)
- [algoritmo de Floyd-warshall](https://es.wikipedia.org/wiki/Algoritmo_de_Floyd-Warshall#:~:text=En%20inform%C3%A1tica%2C%20el%20algoritmo%20de,v%C3%A9rtices%20en%20una%20%C3%BAnica%20ejecuci%C3%B3n.)
