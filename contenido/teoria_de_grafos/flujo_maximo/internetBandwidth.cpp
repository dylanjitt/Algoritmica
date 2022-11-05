#include <bits/stdc++.h> 
using namespace std;
#define INF 1e9
#define MAX_V 105

int res[MAX_V][MAX_V], mf, f, s, t;
vector<vector<int>> AdjList;
vector<int> p;

int n, c, cnt = 1;

void aumentar(int v, int minEdge) {
	if (v == s) {
		f = minEdge;
		return;
	} else if (p[v] != -1) {
		aumentar(p[v], min(minEdge, res[p[v]][v]));
		res[p[v]][v] -= f;
		res[v][p[v]] += f;
	}
}

void edmondsKarp() {
	mf = 0;
	while (1) {
		f = 0;
		bitset<MAX_V> sited;
		sited.set(s);
		queue<int> q;
		q.push(s);
		p.assign(MAX_V, -1);
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			if (u == t)
				break;
			for (int i = 0; i < (int) AdjList[u].size(); i++) {
				int v = AdjList[u][i];
				if (res[u][v] > 0 && !sited.test(v)) {
					sited.set(v);
					q.push(v);
					p[v] = u;
				}
			}
		}
		aumentar(t, INF);
		if (f == 0)
			break;
		mf += f;
	}
}

int main() {
	while (scanf("%d", &n), n) {
		memset(res, 0, sizeof res);
		AdjList.assign(n, vector<int>());

		scanf("%d %d %d", &s, &t, &c);
		s--;
		t--;

		for (int i = 0; i < c; i++) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			u--;
			v--;
			res[u][v] += w;
			res[v][u] += w;
			AdjList[u].push_back(v);
			AdjList[v].push_back(u);
		}

		edmondsKarp();

		printf("Network %d\nThe bandwidth is %d.\n\n", cnt++, mf);
	}

	return 0;
}
