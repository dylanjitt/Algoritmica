# Binary search

La búsqueda binaria es un algoritmo eficiente para encontrar un elemento en una lista ordenada de elementos. Funciona al dividir repetidamente a la mitad la porción de la lista que podría contener al elemento, hasta reducir las ubicaciones posibles a solo una.

Se conoce como busqueda binaria porque si o si tiene que haber un patron de resultado en el que, en un lado del array, nos tiene que decir verdadero y en el otro falso, nunca tiene que haber datos intercalados. y lo vamos calculando dividiendo un array a mitades, y asu vez las mitades de las mitades hasta encontrar una variacion de nuestro resultado, o un punto clave donde termina un patron (sea V/F) y comienzo el otro (F/V).

Para seguir los pasos, basicamente ignoramos la mitad de los elementos justamente despues de una sola comparación: 
1. comparamos x con el elemento del medio.
2. si x coincide con el elemento del medio, retornamos el indice del medio
3. o, si x es mayor al elemento del medio, entonces x solamente puede estar en la mitad derecha despues del elemento medio. asi que recurrimos por la mitad derecha.
4. sino (si x es mas pequeño) recurrimos por la mitad izquierda.

![1_GvdVNpUC_d6n80ZJNqrG1A](https://user-images.githubusercontent.com/101950765/200099201-f6004c22-5713-4fae-a7f4-22d22dbbf227.png)

## Codigo base
