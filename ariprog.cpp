/*
ID: akash331
TASK: ariprog
LANG: C++11
*/
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;
bool got[126000];

int main() {
	freopen("ariprog.in", "r", stdin);
	freopen("ariprog.out", "w", stdout);
	int n, m;
	scanf("%d %d", &n, &m);
	for(int p = 0; p <= m; ++p) 
		for(int q = 0; q <= m; ++q)
			got[p*p + q*q] = true;

	int ans_cnt = 0, MAX = ((m*m)<<1);
	for(int b = 1; b <= MAX; ++b)
		for(int a = 0; a <= MAX; ++a) {
			if(a + (n-1) * b > MAX) break;
			bool flag = true;
			for(int i = 0; i < n; i++)
				if(!got[a + i*b]) { flag = false; break; }
			if(flag) { ans_cnt++; printf("%d %d\n", a, b); }
		}
	if(!ans_cnt) puts("NONE");
	return 0;
}