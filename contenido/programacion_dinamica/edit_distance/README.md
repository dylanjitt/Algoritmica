# Edit Distance
Dados 2 strings (str1 y str2), el “edit distance” entre estos es el mínimo numero de operaciones de edición requeridos para transformar str1 en str2. Comúnmente, las operaciones permitidas para este este algoritmo son insertar, borrar o reemplazar un carácter en un string, las distancias de string suelen ser conocidas como “Levenshtein distance”.

La noción de edit distance puede ser generalizada para permitir diferentes pesos para diferentes tipos de operaciones, por ende un mayor peso puede posicionarse a reemplazar un carácter ‘s’ por una ‘p’, en vez de reemplazarlo por una ‘a’ (siendo mas cercana en un teclado).

La idea es procesar todos los caracteres uno por uno comenzando por la derecha o la izquierda de ambos strings.

