/*
ID: akash331
TASK: castle
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
const int N = 110;
int n, m, arr[N][N];
int dx[] = {0, -1, 0, +1};
int dy[] = {-1, 0, +1, 0};
#define valid(x,y) (0<=min(x,y) && x<n && y<m)

bool vis[N][N];
int dfs(int sx, int sy) {
	int here = 1;
	vis[sx][sy] = true;
	for(int i = 0; i < 4; i++) {
		int tx = sx+dx[i], ty = sy+dy[i];
		if((arr[sx][sy] & (1<<i)) == 0 && valid(tx,ty) && !vis[tx][ty])
			here += dfs(tx,ty);
	} return here;
}


int main() {
	freopen("castle.in", "r", stdin);
	freopen("castle.out", "w", stdout);
	scanf("%d %d", &m, &n);
	for(int i = 0; i < n; i++) 
		for(int j = 0; j < m; j++)
			scanf("%d", &arr[i][j]);
	memset(vis,false,sizeof vis);
	int room = 0, maxsize = 0, ans = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(!vis[i][j]) room++, maxsize = max(maxsize, dfs(i,j));
	int px, py, d;
	for(int j = 0; j < m; j++) {
		for(int i = n-1; i >= 0; i--) {
			if(arr[i][j] & 2) {
				arr[i][j] -= 2;
				memset(vis,false,sizeof vis);
				int sz = dfs(i,j);
				arr[i][j] += 2;
				if(sz > ans) px = i, py = j, d = 1, ans = sz;
			}
			if(arr[i][j] & 4) {
				arr[i][j] -= 4;
				memset(vis,false,sizeof vis);
				int sz = dfs(i,j);
				arr[i][j] += 4;
				if(sz > ans) px = i, py = j, d = 2, ans = sz;
			}
		}
	}
	printf("%d\n%d\n%d\n%d %d %c\n", room, maxsize, ans, px+1, py+1, (d == 1 ? 'N' : 'E'));
	return 0;
}