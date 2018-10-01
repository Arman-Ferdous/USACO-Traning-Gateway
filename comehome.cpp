/*
ID: akash331
TASK: comehome
LANG: C++11
*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
const int N = 60;
const int inf = 2e9;
vector< pair<int,int> > g[N];

int id(char x) { return (islower(x) ? x - 'a' : x - 'A' + 26); }

int d[N];
int main() {
	freopen("comehome.in", "r", stdin);
	freopen("comehome.out", "w", stdout);
	int m; scanf("%d", &m);
	while(m--) {
		char u, v; int w;
		scanf(" %c %c %d", &u, &v, &w);
		g[id(u)].push_back({w,id(v)});
		g[id(v)].push_back({w,id(u)});
	}

	for(int i = 0; i < N; i++) d[i] = inf;
	priority_queue<ii,vector<ii>,greater<ii> > q;
	q.push({0,id('Z')}); d[id('Z')] = 0;

	while(!q.empty()) {
		auto tmp = q.top(); q.pop();
		int cw = tmp.first, u = tmp.second;
		for(auto e : g[u]) if(cw + e.first < d[e.second]) {
			d[e.second] = cw + e.first;
			q.push({d[e.second],e.second});
		}
	}

	int ans = inf; char past;
	for(char x = 'A'; x < 'Z'; x++) if(d[id(x)] < ans)
		ans = d[id(x)], past = x;
	printf("%c %d\n", past, ans);
	return 0;
}