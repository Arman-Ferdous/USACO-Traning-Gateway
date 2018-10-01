/*
ID: akash331
TASK: ttwo
LANG: C++11
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 10;
char mat[N + 1][N + 1];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
	freopen("ttwo.in", "r", stdin);
	freopen("ttwo.out", "w", stdout);
	for(int i = 0; i < N; i++)
		scanf(" %s", mat[i]);
	int fx, fy, cx, cy;
	for(int i = 0; i < N; i++) 
		for(int j = 0; j < N; j++) {
			if(mat[i][j] == 'F') fx = i, fy = j;
			else if(mat[i][j] == 'C') cx = i, cy = j;
		}

	int d1 = 0, d2 = 0;
	for(int t = 0; t < 2000; t++) {
		if(fx == cx && fy == cy) { printf("%d\n", t); return 0; }

		int tx = fx + dx[d1];
		int ty = fy + dy[d1];
		if(min(tx,ty) < 0 || N <= max(tx,ty) || mat[tx][ty] == '*') d1 = (d1 + 1) % 4;
		else fx = tx, fy = ty;

		tx = cx + dx[d2];
		ty = cy + dy[d2];
		if(min(tx,ty) < 0 || N <= max(tx,ty) || mat[tx][ty] == '*') d2 = (d2 + 1) % 4;
		else cx = tx, cy = ty;
	} puts("0");
	return 0;
}