#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

int parent[1000010];
int range[1000010];

int n;
void init() {
    for(int i=0;  i< n; i++) {
        parent[i] = i;
        range[i] = 0;
    }
}

int find(int x) {
    if(x == parent[x]) {
        return x;
    }
    else {
        parent[x] = find(parent[x]);
        
        return parent[x];
    }
}

void unionRank(int x,int y) { 
    int xRaiz = find(x);
    int yRaiz = find(y);
    if(range[xRaiz] > range[yRaiz]) {
        parent[yRaiz] = xRaiz;
    } else {
        parent[xRaiz] = yRaiz;
        if(range[xRaiz] == range[yRaiz]) {
            range[yRaiz]++;
        }
    }
}

int main() {
    input;
    int q;
    scanf("%d %d",&n,&q);

    init();
    for (int i = 0; i < q; i++)
    {
        char o;
        int a,b;
        scanf(" %c %d %d",&o,&a,&b);
        int p1=find(a);
        int p2=find(b);
        if (o=='=')
            unionRank(a,b);
        else if (find(a)==find(b))
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
