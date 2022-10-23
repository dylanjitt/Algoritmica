# Edit Distance
Dados 2 strings (str1 y str2), el “edit distance” entre estos es el mínimo numero de operaciones de edición requeridos para transformar str1 en str2. Comúnmente, las operaciones permitidas para este este algoritmo son insertar, borrar o reemplazar un carácter en un string, las distancias de string suelen ser conocidas como “Levenshtein distance”.

La noción de edit distance puede ser generalizada para permitir diferentes pesos para diferentes tipos de operaciones, por ende un mayor peso puede posicionarse a reemplazar un carácter ‘s’ por una ‘p’, en vez de reemplazarlo por una ‘a’ (siendo mas cercana en un teclado).

La idea es procesar todos los caracteres uno por uno comenzando por la derecha o la izquierda de ambos strings, para hallar cuantos cambios se necesitan hacer para transformar Str1 en -> Str2.
En este caso el algoritmo que vamos a utilizar es Bottom-Up, porque en este caso almacenamos en una matriz 2 x Str1.length, el cual debería reducir la complejidad de almacenamiento. Además, que el código a usar tiene una complejidad O(m*n), ya que su complejidad depende de la longitud y las variaciones de letras entre las 2 palabras que queremos procesar.

![editDistance_0](https://user-images.githubusercontent.com/101950765/197406804-f214eb23-3a19-47cf-bae3-4ee25ee7713f.gif)

## Codigo
- [Edit Distance](https://github.com/dylanjitt/Algoritmica/blob/main/contenido/programacion_dinamica/edit_distance/edit_distance.cpp)
este codigo es una versión descriptiva de como funciona el algoritmo, con detalles de como compara cada caracter y como realiza una de las 3 acciones, aunque tiene una complejidad 3^m debido a su recursividad.
- [Edit Distance Bottom-Up](https://github.com/dylanjitt/Algoritmica/blob/main/contenido/programacion_dinamica/edit_distance/edit_distanceBU.cpp)
en este caso, utilizamos un codigo con una menor complejidad, pero con una implementación un poco mas confusa, pero que gana en el apartado del almacenamiento de datos para su posterior uso, su complejidad es O(m*n) porque toma en cuenta la longitud de las 2 palabaras a procesarse para definir cuantos movimientos o acciones se realiza para transforma la 1ra palabra en la 2da.

## Referencias
- [Edit-Distance](https://www.geeksforgeeks.org/edit-distance-dp-5/)
