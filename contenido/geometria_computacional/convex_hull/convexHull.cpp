#include <bits/stdc++.h>
using namespace std;
 
struct Point
{
    int x, y;
};

// Para encontrar la orientacion de un trio ordenado (p, q, r) las funciones tienen los siguientes valores:
// 0 -> p, q y r son colineales
// 1 -> sentido horario (a reloj)
// 2 -> contra-reloj
int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
 
    if (val == 0) return 0;  // colineal
    return (val > 0)? 1: 2; // sentido reloj/contrareloj
}
// imprime un convex hull de un conjunto de n puntos 
void convexHull(Point points[], int n)
{
    // Tienen que haber minimo 3 puntos
    if (n < 3) return;
 
    // Inicializa el resultado
    vector<Point> hull;
 
    // hallando el punto mas hacia la izquierda
    int l = 0;
    for (int i = 1; i < n; i++)
        if (points[i].x < points[l].x)
            l = i;
    
    // Iniciamos desde el punto mas hacia la izquierda, nos movemos contra-reloj hasta llegar al inicio
    // Este loop se ejecuta O(h) veces donde h es el numero de puntos en el resultado o el output.
    int p = l, q;
    do
    {
        // añadir el punto actual al resultado
        hull.push_back(points[p]);
        
        // Buscamos por un punto 'q' tal que la orientacion (p, q, x) sea contra-reloj para todos los puntos 'x'
        // La idea es de mantener seguimiento de los puntos mas contrareloj ya visitados en q.
        q = (p+1)%n;
        for (int i = 0; i < n; i++)
        {
           // Si  i es mas contrareloj que q, entonces actualizamos q.
           if (orientation(points[p], points[i], points[q]) == 2)
               q = i;
        }
        
        // ahora q es el punto mas contrareloj respecto a p.
        // asignamos p como q para la siguiente iteración, y q se añade al resultado 'hull'
        p = q;
 
    } while (p != l);  // Mientras no lleguemos a nuestro primer punto
 
    // Imprimir resultado
    for (int i = 0; i < hull.size(); i++)
        cout << "(" << hull[i].x << ", "
              << hull[i].y << ")\n";
}
 
int main()
{
    Point points[] = {{0, 3}, {2, 2}, {1, 1}, {2, 1},
                      {3, 0}, {0, 0}, {3, 3}};
    int n = sizeof(points)/sizeof(points[0]);
    convexHull(points, n);
    return 0;
}
