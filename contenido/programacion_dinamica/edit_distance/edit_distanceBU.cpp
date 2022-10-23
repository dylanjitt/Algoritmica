#include <bits/stdc++.h>
using namespace std;
 
void EditDistDP(string str1, string str2)
{
    int len1 = str1.length();
    int len2 = str2.length();
  
    // Crear un array DP para almacenar acceder a previos resultados
    int DP[2][len1 + 1];
 
    // Para llenar el DP array con 0
    memset(DP, 0, sizeof DP);
 
    // Base condition when second string
    // is empty then we remove all characters
    for (int i = 0; i <= len1; i++)
        DP[0][i] = i;
 
    // Comenzar a llenar el array DP, este for se ejecuta para cada caracter en el 2do string
    for (int i = 1; i <= len2; i++) {
        // este for compara el char del segundo string con los caracteres del 1er string
        for (int j = 0; j <= len1; j++) {
            // si el 1er string esta vacio entonces tenemos que añadir un caracter para llegar a igualar el 2do string
            if (j == 0)
                DP[i % 2][j] = i;
            // si el caracter de ambos strings es igual, no tenemos que realizar niguna accion
            // i % 2 es para vincular o asociar el numero de la fila
            else if (str1[j - 1] == str2[i - 1]) {
                DP[i % 2][j] = DP[(i - 1) % 2][j - 1];
            }
          
            // si el caracter de ambos strings es diferente 
            // entonces tomamos el minimo entre las 3 operaciones.
            else {
                DP[i % 2][j] = 1 + min(DP[(i - 1) % 2][j],
                                       min(DP[i % 2][j - 1],
                                           DP[(i - 1) % 2][j - 1]));
            }
        }
    }
 
    // luego de completar el array DP, si len2 es par, terminamos en la casilla 0
    // o si no, terminamos el la 1ra casilla por lo que tomariamos len2 % 2 para tener la casilla.
    cout << DP[len2 % 2][len1] << endl;
}

int main()
{
    string str1 = "food";
    string str2 = "money";
    EditDistDP(str1, str2);
    return 0;
}
