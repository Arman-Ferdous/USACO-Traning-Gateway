/*
ID: akash331
TASK: maze1
LANG: C++11
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 205;
int n, m;
string g[N];

int d[N][N];
int wx[] = {-1, 0, 1, 0};
int wy[] = {0, 1, 0, -1};
int dx[] = {-2, 0, 2, 0};
int dy[] = {0, 2, 0, -2};

int main() {
	freopen("maze1.in", "r", stdin);
	freopen("maze1.out", "w", stdout);

	cin >> m >> n; cin.ignore();
	n = 2 * n + 1, m = 2 * m + 1;
	for(int i = 0; i < n; i++) {
		getline(cin,g[i]);
	}
	vector< pair<int,int> > s;
	for(int i = 1; i < n; i+=2)
		for(int j = 1; j < m; j+=2)
			for(int k = 0; k < 4; k++) {
				int tx = i + wx[k], ty = j + wy[k];
				if(tx == 0 || tx == n-1 || ty == 0 || ty == m-1)
					if(g[tx][ty] == ' ') s.push_back({i,j});
			}

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			d[i][j] = (int)2e9;
	queue< pair<int,int> > q;
	for(auto x : s) {
		d[x.first][x.second] = 0;
		q.push({x.first,x.second});
	}

	pair<int,int> tmp; int sx, sy, tx, ty;
	while(!q.empty()) {
		tmp = q.front(); q.pop();
		sx = tmp.first, sy = tmp.second;
		for(int i = 0; i < 4; i++) {

			tx = sx + dx[i], ty = sy + dy[i];
			if(min(tx,ty) < 0 || tx >= n || ty >= m) continue;
			if(g[sx + wx[i]][sy + wy[i]] != ' ') continue;
			if(d[tx][ty] <= d[sx][sy] + 1) continue;
			d[tx][ty] = d[sx][sy] + 1;
			q.push({tx,ty});
		}
	}
	int ans = 0;
	for(int i = 1; i < n; i += 2)
		for(int j = 1; j < m; j += 2)
			ans = max(ans, d[i][j]);
	printf("%d\n", ans + 1);
	return 0;
}