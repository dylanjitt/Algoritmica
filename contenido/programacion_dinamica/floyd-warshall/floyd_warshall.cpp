#include <bits/stdc++.h>
using namespace std;
 
// Numero de vertices en el grafo
#define V 4
 
//El valor infinito sera utilizado para verices que no esten conectados entre si
#define INF 99999
 
// funcion para impirmir la matriz solución

void printSolution(int dist[][V]);
 
//resuelve el camino mas corto entre los pares
void floydWarshall(int graph[][V])
{
    // dist[][] sera la matriz output que tendra el camino mas corto entre cada par de vertices
    int dist[V][V], i, j, k;
 
    // los valores iniciales de las distancias mas cortas
    //estan basadas en los caminos mas cortos sin considerar vertices intermedios.
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];
    //añadir vertices uno por uno al set de vertices intermedios
    //antes de la iteracion: tenemos las distancias mas cortas entre todos los pares
    //para que la mas corta considere los veritces en el rango 0 - k-1 como veritces intermedios
    //luego de la iteracion, vertice "k" se añade al set de vertices intermedios y este se vuelve
    // 0 - k.
    for (k = 0; k < V; k++) {
        // escoge todos los vertices desde el origen uno por uno
        for (i = 0; i < V; i++) {
            // agarra los vertices como destino final en el rango anterior
            for (j = 0; j < V; j++) {
                // si el vertice k es el camino mas corto de la i - j
                // entonces actualiza dist[i][j]
                if (dist[i][j] > (dist[i][k] + dist[k][j])
                    && (dist[k][j] != INF
                        && dist[i][k] != INF))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
 
    // imprime la matriz solucion
    printSolution(dist);
}
 
//funcion para imprimir solucion
void printSolution(int dist[][V])
{
    cout << "la siguiente matriz nos muestra las distancias mas cortas "
            " entre cada par de vertices \n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF"
                     << "     ";
            else
                cout << dist[i][j] << "     ";
        }
        cout << endl;
    }
}
 
int main()
{
    /* un ejemplo del grafo que queremos crear
          10
    (0)------->(3)
     |         /|\
   5 |          |
     |          | 1
    \|/         |
    (1)------->(2)
            3     */
    int graph[V][V] = { { 0, 5, INF, 10 },
                        { INF, 0, 3, INF },
                        { INF, INF, 0, 1 },
                        { INF, INF, INF, 0 } };
 
    floydWarshall(graph);
    return 0;
}
