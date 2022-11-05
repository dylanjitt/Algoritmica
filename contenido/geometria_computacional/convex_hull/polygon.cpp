#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

const double EPS = 1e-9;

double DEG_to_RAD(double d) { return d*M_PI / 180.0; }

double RAD_to_DEG(double r) { return r*180.0 / M_PI; }

struct point { double x, y;   
  point() { x = y = 0.0; }                      
  point(double _x, double _y) : x(_x), y(_y) {}   
  bool operator == (point other) const {
   return (fabs(x-other.x) < EPS && (fabs(y-other.y) < EPS)); } 
  bool operator <(const point &p) const {
   return x < p.x || (abs(x-p.x) < EPS && y < p.y); } };

struct vec { double x, y;  
  vec(double _x, double _y) : x(_x), y(_y) {} };

// convierte 2 puntos en 1 vector
vec toVec(point a, point b) {       
  return vec(b.x-a.x, b.y-a.y); }

double dist(point p1, point p2) {                
  return hypot(p1.x-p2.x, p1.y-p2.y); }               

// retorna el perimetro
double perimeter(const vector<point> &P) {       
  double ans = 0.0;
  for (int i = 0; i < (int)P.size()-1; ++i)      
    ans += dist(P[i], P[i+1]);                   
  return ans;
}

// retorna el area del poligono
double area(const vector<point> &P) {
  double ans = 0.0;
  for (int i = 0; i < (int)P.size()-1; ++i)      
    ans += (P[i].x*P[i+1].y - P[i+1].x*P[i].y);
  return fabs(ans)/2.0;                         
}

double dot(vec a, vec b) { return (a.x*b.x + a.y*b.y); }

double norm_sq(vec v) { return v.x*v.x + v.y*v.y; }

//retorna angulo a o b en radian
double angle(point a, point o, point b) {  
  vec oa = toVec(o, a), ob = toVec(o, b);
  return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob))); }

double cross(vec a, vec b) { return a.x*b.y - a.y*b.x; }

// retorna el area del poligono p
double area_alternative(const vector<point> &P) {
  double ans = 0.0; point O(0.0, 0.0);           
  for (int i = 0; i < (int)P.size()-1; ++i)      
    ans += cross(toVec(O, P[i]), toVec(O, P[i+1]));
  return fabs(ans)/2.0;
}

// retorna true si el punto r esta a la izquierda de pq
bool ccw(point p, point q, point r) {
  return cross(toVec(p, q), toVec(p, r)) > 0;
}

// retorna true si el punto r esta en la misma linea que pq
bool collinear(point p, point q, point r) {
  return fabs(cross(toVec(p, q), toVec(p, r))) < EPS;
}


// retorna true si siempre giramos en la misma direccion
bool isConvex(const vector<point> &P) {
  int n = (int)P.size();
  
  if (n <= 3) return false;
  bool firstTurn = ccw(P[0], P[1], P[2]);        
  for (int i = 1; i < n-1; ++i)                 
    if (ccw(P[i], P[i+1], P[(i+2) == n ? 1 : i+2]) != firstTurn)
      return false;                             
  return true;                                   
}


int insidePolygon(point pt, const vector<point> &P) {
  int n = (int)P.size();
  if (n <= 3) return -1;                         
  bool on_polygon = false;
  for (int i = 0; i < n-1; ++i)                  
    if (fabs(dist(P[i], pt) + dist(pt, P[i+1]) - dist(P[i], P[i+1])) < EPS)
      on_polygon = true;
  if (on_polygon) return 0;                      
  double sum = 0.0;                              
  for (int i = 0; i < n-1; ++i) {
    if (ccw(pt, P[i], P[i+1]))
      sum += angle(P[i], pt, P[i+1]);            
    else
      sum -= angle(P[i], pt, P[i+1]);            
  }
  return fabs(sum) > M_PI ? 1 : -1;              
}

// calcula el punto de interseccion entre p-q y a-b
point lineIntersectSeg(point p, point q, point A, point B) {
  double a = B.y-A.y, b = A.x-B.x, c = B.x*A.y - A.x*B.y;
  double u = fabs(a*p.x + b*p.y + c);
  double v = fabs(a*q.x + b*q.y + c);
  return point((p.x*v + q.x*u) / (u+v), (p.y*v + q.y*u) / (u+v));
}

//intersecta el poligono Q entre la linea formada por A y B
vector<point> cutPolygon(point A, point B, const vector<point> &Q) {
  vector<point> P;
  for (int i = 0; i < (int)Q.size(); ++i) {
    double left1 = cross(toVec(A, B), toVec(A, Q[i])), left2 = 0;
    if (i != (int)Q.size()-1) left2 = cross(toVec(A, B), toVec(A, Q[i+1]));
    if (left1 > -EPS) P.push_back(Q[i]);         
    if (left1*left2 < -EPS)                      
      P.push_back(lineIntersectSeg(Q[i], Q[i+1], A, B));
  }
  if (!P.empty() && !(P.back() == P.front()))
    P.push_back(P.front());                      
  return P;
}


vector<point> CH_Andrew(vector<point> &Pts) {    
  int n = Pts.size(), k = 0;
  vector<point> H(2*n);
  sort(Pts.begin(), Pts.end());                  
  for (int i = 0; i < n; ++i) {                 
    while ((k >= 2) && !ccw(H[k-2], H[k-1], Pts[i])) --k;
    H[k++] = Pts[i];
  }
  for (int i = n-2, t = k+1; i >= 0; --i) {       
    while ((k >= t) && !ccw(H[k-2], H[k-1], Pts[i])) --k;
    H[k++] = Pts[i];
  }
  H.resize(k);
  return H;
}

int main()
{
    input;
    output;
    int n;

    while (cin >> n && n)
    {
        vector<point> poligono;
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            poligono.push_back(point(x, y));
        }
        int a,b;
        cin>>a>>b;
        int inside = insidePolygon(point(a,b), poligono);
        if ( inside == -1)
        {
            cout << "F" << endl;
        }
        else
        {
            cout << "T" << endl;
        }
    }

    return 0;
}
