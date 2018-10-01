/*
ID: akash331
TASK: numtri
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1010, inf = 2e9;
int n, arr[N][N], dp[N][N];

int DP(int r, int c) {
	if(r >= n) return 0;
	if(dp[r][c] != -1) return dp[r][c];
	return dp[r][c] = arr[r][c] + max(DP(r+1,c), DP(r+1,c+1));
}

int main() {
	freopen("numtri.in", "r", stdin);
	freopen("numtri.out", "w", stdout);
	memset(dp,-1,sizeof dp);
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		for(int j = 0; j <= i; j++)
			scanf("%d", &arr[i][j]);
	printf("%d\n", DP(0,0));
	return 0;
}