# Convex Hull
En geometría, convex hull (o casco convexo como sugiere su traducción) es la formación de una figura en la mayor cobertura de area entre un conjunto de puntos en un plano cartesiano. Tambien puede ser definido como como una intersección de todos los conjuntos convexos que contienen un subconjunto dado para todas las combinaciones de figuras posibles de puntos en un subconjunto dado en un plano cartesiano.

En otras palabras, dado un conjunto de puntos en un plano cartesiano, el "convex hull" de este conjunto es el poligono convexo mas pequeño que contenga a todos los puntos en si.

La idea del algoritmo de Jarvis es simple: comenzamos desde el punto mas hacia la la izquierda y continuamos uniendo y buscando puntos en sentido contra-reloj. Ahi la gran pregunta es: dado un punto "p" como el actual, ¿como encontraremos el siguiente punto como output?

la idea seria usar orientación, el siguiente punto seleccionado como el punto que supere a todos los otros puntos en posición contra-reloj, nuestro siguiente punto seria "q" si por cada otro punto "r", tendriamos Orientacion(p, q, r)= contra-reloj.

Pasos para el algoritmo:
1. inicializar "p" como el punto mas hacia la izquierda de todos.
2. repetir estos pasos hasta no llegar de vuelta a "p"
  2.1. el siguiente punto es "q", tal que el trio (p, q, r) sea contra-reloj para cualquier punto "r". para hallarlo, inicializamos q como nuestro siguiente punto, luego exploramos todos los puntos disponibles. para cada punto, si "i" es el punto mas "contra-reloj" entre todos, entonces actualizamos q como i- y nuestro valor final será el mas contra-reloj de todos.
  2.2. next[p]=q (guardamos q como el siguiente punto a p en el output del convex hull).
  2.3 p = q (asignamos p como q para nuestra siguiente iteración).
  
  ![3-s2 0-B9781785482434500050-f05-07-9781785482434](https://user-images.githubusercontent.com/101950765/199849806-14d76332-3e8e-4991-8569-2803b13277f7.jpg)

## Código
- [Convex hull.cpp](https://github.com/dylanjitt/Algoritmica/blob/main/contenido/geometria_computacional/convex_hull/convexHull.cpp)

Su complejidad es de O(m*n) donde n es el numero de puntos y m es el numero de puntos output o "hull points" (m<=n).
## Referencias
- [Convex-Hull](https://en.wikipedia.org/wiki/Convex_hull)
- [Convex Hull, Jarvis's Algorithm or wrapping](https://www.geeksforgeeks.org/convex-hull-set-1-jarviss-algorithm-or-wrapping/)

## Videos/Tuturiales
- [Convex Hull Jarvis March(Gift wrapping algorithm)](https://www.youtube.com/watch?v=Vu84lmMzP2o&t=744s)
