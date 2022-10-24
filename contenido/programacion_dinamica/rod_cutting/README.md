## Rod Cutting
Dada una varilla de longitud n y una lista de precios de varillas de longitud i, encuentre la forma optima de cortar la varilla en varillas mas pequeñas para maximizar las ganancias.

Para resolver este problema, primero nos dan un array precio [ ], donde la varilla de longitud i tiene un valor precio[i-1]. La idea es simple: uno por uno, divide la barra dada de longitud n en 2 partes: “i” y “n-i”. 

Esto se hace recursivo para la barra n-i pero ya no dividas la vara “i”. Finalmente toma el máximo de todos los valores, para devolver la máxima ganancia posible.

Este algoritmo es de tipo Bottom Up, ya que tiene un montón de elementos (varios precios almacenados en un array), todo para llegar a un precio final.

![07-rodcutting-example](https://user-images.githubusercontent.com/101950765/197425241-f29b0d63-7a0e-4c64-8b83-d99afc9f7a06.jpg)

## Codigo
- [Rod Cutting](https://github.com/dylanjitt/Algoritmica/blob/main/contenido/programacion_dinamica/rod_cutting/rodCutting.cpp)

Hay varios tipos de soluciones, pero en esta ocasión vamos a escoger una versión con una complejidad O(n)=n^2, porque maneja un array de int con todos los precios y un vector basado en ese array, contando también con el tamaño de este.

## Referencias

- [problema de corte de varilla](https://www.techiedelight.com/es/rod-cutting/)
- [cutting a rod](https://www.geeksforgeeks.org/cutting-a-rod-dp-13/)
