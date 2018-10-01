/*
ID: akash331
TASK: nocows
LANG: C++11
*/

#include <bits/stdc++.h>
using namespace std;

const int MOD = 9901;

int n, k; 
int dp[205][105][2];

int DP(int node, int lev, int tag) {
	if(lev > k) return 0;
	if(lev == k && !tag) return 0;
	if(node == 1) {
		if(tag && lev != k) return 0;
		return 1;
	} 
	int &ret = dp[node][lev][tag];
	if(ret != -1) return ret;
	ret = 0;

	node--;
	if(tag) {
		for(int i = 1; i < node; i++)
			ret = (ret + (DP(i, lev+1, 1) * DP(node-i, lev+1, 0) % MOD) + 
				         (DP(i, lev+1, 0) * DP(node-i, lev+1, 1) % MOD) +
				         (DP(i, lev+1, 1) * DP(node-i, lev+1, 1) % MOD) ) % MOD;
	} else for(int i = 1; i < node; i++)
		ret = (ret + DP(i, lev+1, 0) * DP(node-i, lev+1, 0) % MOD) % MOD;
	return ret;
}

int main() {
	freopen("nocows.in", "r", stdin);
	freopen("nocows.out", "w", stdout);
	memset(dp,-1,sizeof dp);
	scanf("%d %d", &n, &k);
	printf("%d\n", DP(n,1,1));
	return 0;
}