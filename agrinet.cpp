/*
ID: akash331
TASK: agrinet
LANG: C++11
*/

#include <bits/stdc++.h>
using namespace std;

int n, p[105];
struct edge{
	int u, v, w;
	bool operator<(edge o) const{
		return w < o.w;
	}
}; vector<edge> v;

int find(int u) {
	return p[u] = (p[u] == u ? u : find(p[u]));
}

int main() {
	freopen("agrinet.in", "r", stdin);
	freopen("agrinet.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 0; i < n; i++) 
		for(int j = 0; j < n; j++) {
			int w; scanf("%d", &w);
			v.push_back({i,j,w});
		}
	sort(v.begin(),v.end());
	for(int i = 0; i < n; i++) p[i] = i;
	long long mst = 0;
	for(auto it : v) {
		if(find(it.u) != find(it.v)) {
			mst += it.w;
			p[find(it.u)] = find(it.v);
		}
	} printf("%lld\n", mst);
	return 0;
}