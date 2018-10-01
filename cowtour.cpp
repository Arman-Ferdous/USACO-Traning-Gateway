/*
ID: akash331
TASK: cowtour
LANG: C++11
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 155;
const double INF = 1e18;

int n;
char mat[N][N];
double x[N], y[N], dist[N][N];

double g[N][N], f[N];
int main() {
	freopen("cowtour.in", "r", stdin);
	freopen("cowtour.out", "w", stdout);

	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%lf %lf", &x[i], &y[i]);

	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			g[i][j] = INF,
			dist[i][j] = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));

	for(int i = 0; i < n; ++i)
		scanf(" %s", mat[i]);

	for(int i = 0; i < n; ++i) 
		for(int j = 0; j < n; ++j)
			if(mat[i][j] == '1')
				g[i][j] = g[j][i] = dist[i][j];

	for(int i = 0; i < n; i++)
		g[i][i] = 0;

	for(int k = 0; k < n; k++)
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				g[i][j] = min(g[i][j] , g[i][k] + g[k][j]);

	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) 
		if(g[i][j] != INF) f[i] = max(f[i], g[i][j]);

	/* important part that most forget */
	double dia = -INF;
	for(int i = 0; i < n; i++) 
		dia = max(dia, f[i]);

	double ans = INF;
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++)
		if(g[i][j] == INF) ans = min(ans, dist[i][j] + f[i] + f[j]);
	printf("%.6lf\n", max(ans,dia));
	return 0;
}