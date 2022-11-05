# Longest Increasing Secuence (LIS)
En ciencias de computación, la subsecuencia creciente mas larga (Longest Increasing Subsecuence, LIS) es un problema algorítmico en el que tenemos que encontrar una subsecuencia dentro de una secuencia dada en la que los elementos de la subsecuencia estén ordenados, de menor a mayor, y en la que la subsecuencia sea lo mas larga posible. Esta subsecuencia no tiene que ser necesariamente contigua o única.

Por ejemplo, tenemos una secuencia:
- ### [0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15]

En este caso, su subsecuencia creciente más larga seria: 
- ### [0, 2, 6, 9, 11, 15]

La idea seria utilizar recursividad para este problema, y también contamos con 2 posibilidades:

1. Incluir el elemento actual en LIS si es mayo que el elemento anterior en LIS y repetir para los elementos restantes

2. Excluir el elemento actual de LIS y repetir para los elementos restantes.

Este algoritmo es de tipo bottom-up, ya que trabajamos con un conjunto de varios elementos, y al final, tenemos que devolver una sola única respuesta: el tamaño final de la secuencia deseada.

![Longest-Increasing-Subsequence](https://user-images.githubusercontent.com/101950765/197430159-fb80f067-6a7f-42f6-ab7b-7176ee572d31.png)

## Codigo
- [LIS.cpp](https://github.com/dylanjitt/Algoritmica/blob/main/contenido/programacion_dinamica/Longest_Increasing_secuence/LIS.cpp)

En esta ocasión utilizaremos una variante del algoritmo con una complejidad O(n^2), ya que utiliza un doble for, y analiza 2 arrays: el principal en 2 iteraciones a la vez, y otro en el que se acumulan los datos para el resultado final.
## Referencias
- [Subsecuencia creciente mas larga](https://www.techiedelight.com/es/longest-increasing-subsequence-using-dynamic-programming/)
- [Longest Increasing secuence](https://www.geeksforgeeks.org/longest-increasing-subsequence-dp-3/)
