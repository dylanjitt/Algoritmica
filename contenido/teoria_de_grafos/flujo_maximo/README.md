# Flujo Maximo
En teoria de grafos, una red de flujo es un grafo dirigido donde existen 2 vertices especiales, uno llamado fuente, al que se le asocia un flujo positivo y otro llamado sumidero que tiene un flujo negativo y a cada arista se le asocia cierta capacidad positiva. 

Dentro de la red de flujo, tenemos el conocido problema de flujo maximo o maximal: ¿cual es la tasa mayor a la cual el material puede ser transportado de la fuente al sumidero sin violar ninguna restricciín de capacidad?. En otras palabras, el problema consiste en determinar la maxima capacidad de flujo que puede ingresar a traves de la fuente y salir por el nodo de destino.

El procedimiento para obtener el flujo maximo de una red consiste en seleccionar repetidas veces cualquier trayectoria de la fuente al destino y asignar el flujo maximo posible en esa trayectoria.

Podemos encontrar el flujo maximo de una red mediante el algoritmo de Ford-Fulkerson, y su implementación en el algorimto de Edmonds-Karp.

![download](https://user-images.githubusercontent.com/101950765/199883630-a83a4f83-7951-4659-bcb0-9f0c578721ff.jpg)

# Ford Fulkerson
El algoritmo de Ford-Fulkerson es un metodo iterativo el cual propone buscar caminos en los que se pueda aumentar el flujo, hasta alcanzar el flujo máximo. la idea es encontrar una ruta de penetración con un flujo positivo neto que una los nodos origen y destino. y la busqueda del camino se realiza con busqueda por profundidad (DFS).

Depende de 3 puntos vitales:

- **Red residual**: camino de la fuente al sumidero, donde cada una de las aristas tiene un flujo residual mayor a 0. siendo el flujo residual, el flujo que se puede obtener en una arista una vez que haya pasado el flujo por ella.
- **Aumento de camino**: se basa en ir aumentando en camino, hasta alcanzar la maxima capacidad residual.
- **Corte en redes de flujo**: consiste simplemente en realizar una participación del conjunto de vertices en 2 subconjuntos.

![download](https://user-images.githubusercontent.com/101950765/199883739-0cc1ab5a-b54b-4942-8567-495ab2d96e9d.png)


# Edmonds-Karp
El algoritmo de Edmonds-karp es una implementacion del metodo de Ford-Fulkerson para calcular el flujo maximo en una red de flujo, es similar al anterior, excepto el orden para ir buscando los caminos de forma gradual. El camino encontrado debe ser el camino mas corto que tiene capacidad disponible. Esto se puede encontrar mediante una busqueda por anchura (BFS), ya que dejamos que los bordes tengan unidad de longitud.

![download](https://user-images.githubusercontent.com/101950765/199883937-cec71e34-e3e8-4bca-92ca-7a82223d0def.png)

## Código
- [Ford Fulkerson](https://github.com/dylanjitt/Algoritmica/blob/main/contenido/teoria_de_grafos/flujo_maximo/fordFulkerson.cpp)
- [Edmonds Karp](https://github.com/dylanjitt/Algoritmica/blob/main/contenido/teoria_de_grafos/flujo_maximo/edmondsKarp.cpp)

Ambos algoritmos tienen una complejidad de O(V*E^3), donde cada camino aumentante puede ser encontrado con O(E), cada vez que al menos uno de los lados E se satura, la distancia desde el lado saturado hasta el origen debera ser mas largo que la ultima vez que estuvo saturado, y ese largo es a lo sumo V.

## Referencias
- [Red de Flujo](https://es.wikipedia.org/wiki/Red_de_flujo)
- [Algoritmo de Ford Fulkerson](https://es.wikipedia.org/wiki/Algoritmo_de_Ford-Fulkerson)
- [Algoritmo de Edmonds karp](https://es.wikipedia.org/wiki/Algoritmo_de_Edmonds-Karp)
- [Ford-fulkerson algorithm for maximum flow problem](https://www.geeksforgeeks.org/ford-fulkerson-algorithm-for-maximum-flow-problem/)

## Videos/tutoriales
- [Ford Fulkerson Algorithm Edmonds Karp Algorithm For Max Flow](https://www.youtube.com/watch?v=GiN3jRdgxU4)



