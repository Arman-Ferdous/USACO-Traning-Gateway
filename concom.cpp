/*
ID: akash331
TASK: concom
LANG: C++11
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int n;
int c[N], g[N][N];

int vis[N];
int dfs(int u) {
	vis[u] = 1;
	for(int i = 1; i < N; i++) c[i] += g[u][i];
	for(int i = 1; i < N; i++) if(!vis[i] && c[i] > 50) dfs(i);
}

int main() {
	freopen("concom.in", "r", stdin);
	freopen("concom.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		g[u][v] = w;
	}
	for(int i = 1; i < N; i++) {
		memset(c,0,sizeof c);
		memset(vis,0,sizeof vis);
		dfs(i);
		for(int j = 1; j < N; j++) if(c[j] > 50 && i != j)
			printf("%d %d\n", i, j);
	}
	return 0;
}