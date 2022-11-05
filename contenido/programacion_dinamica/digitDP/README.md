# Digit DP
Digit DP, como su nombre sugiere, es una técnica de programación dinámica en la que usamos Digitos de los numeros para encontrar una solución a un problema.

En este caso, podemos convertir un numero en un string, y cada digito seria un char, y esto sirve para identificar digitos especificos para un problema, por ejemplo, hallar numeros de un cierto rango (ej: 20 - 50) que contengan un '3' o '4', por lo que el sistema generaría un arbol con varias posibilidades de combinaciones de digitos hasta llegar al numero deseado, en algunos casos puede llegar a ser tedioso o pesado de procesar, porque, dependiendo de cuantos digitos tenga el sistema podemos sacar distintas ramificaciones.

Un ejemplo mas concreto seria de contar cuantos numeros que terminan en 3 o 4 hay del 1 al 17, en este caso creariamos un arbol que tendria 2 ramas principales, una de digitos que comienzan en 0 y otra de los que comienzan en 1, los digitos que comienzan en 0, van completos en el sistemas para revisar uno por uno (en otras palabras, las ramas derivadas de 0- serian 00, 01, 02, 03... 09), y las derivadas de 1- llegarian solamente hasta 17 (nuestro numero objetivo actual), y de esta manera, podemos convertir cada numero en un distinto string, el caul podemos analizar sus chars para encontrar los digitos que estamos buscando y asi, resolver el problema que necesitamos.

![IMG_0329](https://user-images.githubusercontent.com/101950765/197317278-cb2b974d-950d-4e06-b6ad-92325357a27e.jpg)

## Código
- [DigitDp.cpp](https://github.com/dylanjitt/Algoritmica/blob/main/contenido/programacion_dinamica/digitDP/digitdp.cpp)

## Problemas
- Averiguar si un numero contiene en si un 0 o 5
  - [soulcion](https://github.com/dylanjitt/Algoritmica/blob/main/contenido/programacion_dinamica/digitDP/digitdp0-5.cpp)
- [Prefix Zeros](https://www.codechef.com/problems/PREZ)

## Referencias
- [Digit DP | Data structures](https://www.scaler.com/topics/data-structures/digit-dp/)
- [Digit DP | Introducction](https://www.geeksforgeeks.org/digit-dp-introduction/)
