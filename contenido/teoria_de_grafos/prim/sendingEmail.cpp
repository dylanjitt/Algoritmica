#include<bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
#define MAX_N 10000000

using namespace std;

struct Arista
{
    int s;
    int t;
    long int weight;
    long int weightPrim;
    Arista() {}
     bool operator<(const Arista &a) const
     {
         if (weightPrim == a.weightPrim)
         {
             return s
         < a.s
        ;
         }
         else
         {
             return weightPrim < a.weightPrim;
         }
     }
     
} arists[MAX_N];

void prim(int N, int m)
{

    vector <pair<int,int> > adjacentList[N];

    int a, b, weight;

    for(int i =0; i<m; i++){
        cin >> a >> b >> weight;
        adjacentList[a].push_back(make_pair(b,weight));
        adjacentList[b].push_back(make_pair(a,weight));
    } 

    int padre[N];
    int key[N];
    bool mstSet[N]; 

    for (int i =0; i<N; i++){
        key[i] = MAX_SIZE, mstSet[i] = false;

        key[0]=0;
        padre[0]=-1;
        int pesoTotal=0;

        for (int cont =0; cont < N-1; cont++){

            int mini = MAX_SIZE, minNode;

            for (int v=0; v<N;v++){
                if (mstSet[v]==false && key[v] < mini){
                    mini = key[v];
                    minNode=v;
                }
            }
            mstSet[minNode]= true;

            for(auto it : adjacentList[minNode] ){
                int v = it.first;
                int peso = it.second;
                if (mstSet[v]==false&& peso< key[v]){
                    padre[v] = minNode;
                    key[v]=peso;
                }
            }
        }

        for (int i =1; i < N; i++){
            cout << padre[i] << "-" << i <<"\n";
        }
    }
}

int main()
{
    input;
    output;
    int N, m, n, i = 1;
    cin>>N>>endl;
    while(N--){
        cin>>m>>n>>endl;
        printf("Case #%d: ",i++);
        if(m){
        prim(n,m);
        }else{
        printf("unreachable\n");
        scanf("%*d %*d");
        }
    }
}
