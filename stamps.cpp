/*
ID: akash331
TASK: stamps
LANG: C++11
*/

#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e6+10;
const int INF = 2e9;
int n, k, arr[55], d[MAX];
queue<int> q;
int main() {
	freopen("stamps.in", "r", stdin);
	freopen("stamps.out", "w", stdout);
	scanf("%d %d", &k, &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	for(int i = 0; i < MAX; i++) d[i] = INF;

	q.push(0); d[0] = 0;
	while(!q.empty()) {
		int u = q.front(); q.pop();
		if(u >= MAX || d[u] == k) continue;
		for(int i = 0; i < n; i++) {
			int v = u + arr[i];
			if(v >= MAX || d[v] != INF) continue;
			d[v] = d[u] + 1;
			q.push(v);
		}
	}
	int ans = 0;
	while(d[ans] != INF) ans++;
	printf("%d\n", ans-1);
	return 0;
}