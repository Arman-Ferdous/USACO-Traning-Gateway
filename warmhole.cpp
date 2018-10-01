/*
ID: akash331
TASK: wormhole
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 14;
int n, x[N], y[N], link[N], to[N];

bool cycle() {
	for(int source = 1; source <= n; source++) {
		int s = source;
		for(int i = 1; i <= n; i++) 
			s = to[link[s]];
		if(s != 0) return true;
	} return false;
}

int solve() {
	int i, ret = 0;
	for(i = 1; i <= n; i++) if(link[i] == 0) break;
	if(i >= n) return cycle();
	for(int j = i+1; j <= n; j++) if(link[j] == 0) {
		link[i] = j;
		link[j] = i;
		ret += solve();
		link[i] = link[j] = 0;
	} return ret;
}

int main() {
	freopen("wormhole.in", "r", stdin);
	freopen("wormhole.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) 
		scanf("%d %d", &x[i], &y[i]);

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(i == j) continue;
			if(y[i] == y[j] && x[i] < x[j]) {
				if(to[i] == 0) to[i] = j;
				else to[i] = (x[j] < x[to[i]] ? j : to[i]);
			}
		}
	}
	printf("%d\n", solve());
	return 0;
}