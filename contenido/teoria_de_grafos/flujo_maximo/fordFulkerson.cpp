#include <iostream>
#include <limits.h>
#include <queue>
#include <string.h>
using namespace std;
 
// numero de vertices en el grafo
#define V 6

// Retorna TRUE si hay un camino desde 's' hasta el destino 't' en el grafo residual
// Tambien se llena parent[] para almacenar el camino.
bool bfs(int rGraph[V][V], int s, int t, int parent[])
{
    // crear un array de visitados y marcar todos los vertices como "no visitados"
    bool visited[V];
    memset(visited, 0, sizeof(visited));
 
    // Crear una cola e insertar el vertice origen, marcarlo como visitado
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
 
    // loop BFS tradicional
    while (!q.empty()) {
        int u = q.front();
        q.pop();
 
        for (int v = 0; v < V; v++) {
            if (visited[v] == false && rGraph[u][v] > 0) {
                // Si encontramos una conexion con el nodo destino, entonces ya no hay punto con el BFS
                // Solo tenemos que encontrar su padre y asi retornar TRUE
                if (v == t) {
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
 
    // Aun no hemos llegado al sink en BFS comenzando desde el origen, entonces retornar FALSE
    return false;
}

// Retorna el maximo flujo desde 's' hacia 't' en el grafo
int fordFulkerson(int graph[V][V], int s, int t)
{
    int u, v;
  
    // Crear un grafo residual y llenarlo con las capacidades dadas en el grafo original
    // como capacidades residuales en el grafo residual.
    int rGraph[V]
              [V]; // el grafo residual, donde rGraph[i][j]
                   // indica la capacidad residual del borde
                   // desde i a j (si hay un borde. SI
                   // rGraph[i][j] es 0, entonces ahi no hay nada.)
    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
            rGraph[u][v] = graph[u][v];
 
    int parent[V]; // Este array es llenado por BFS y es para almacenar los caminos.
 
    int max_flow = 0; // No hay flujo inicialmente
 
    // aumenta el flujo mientras hay un camino desde el origen hacia el destino.
    while (bfs(rGraph, s, t, parent)) {
        // Encuentra la capacidad residual minima de los bordes junto al camino llenado por BFS
        // O podemos encontrar el maximo flujo a traves del camino encontrado
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }
 
        // actualizamos la capacidad residual de los bordes y sus inversos junto al camino
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
      
        // Añadir el camino de flujo al flujo maximo.
        max_flow += path_flow;
    }
 
    // retorna el flujo total.
    return max_flow;
}

int main()
{

    int graph[V][V]
        = { { 0, 16, 13, 0, 0, 0 }, { 0, 0, 10, 12, 0, 0 },
            { 0, 4, 0, 0, 14, 0 },  { 0, 0, 9, 0, 0, 20 },
            { 0, 0, 0, 7, 0, 4 },   { 0, 0, 0, 0, 0, 0 } };
 
    cout << "El maximo flujo posible es: "
         << fordFulkerson(graph, 0, 5);
 
    return 0;
}
