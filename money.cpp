/*
ID: akash331
TASK: money
LANG: C++11
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n, k, arr[30];
ll dp[30][10010];

ll DP(int pos, int have) {
	if(have == 0) return 1;
	if(pos >= n) return 0;

	ll &ret = dp[pos][have];
	if(ret != -1) return ret;
	ret = DP(pos+1, have);
	if(have - arr[pos] >= 0) ret += DP(pos, have - arr[pos]);
	return ret;
}

int main() {
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	memset(dp,-1,sizeof dp);
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	printf("%lld\n", DP(0,k));
	return 0;
}