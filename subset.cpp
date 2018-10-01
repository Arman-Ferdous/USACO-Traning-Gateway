/*
ID: akash331
TASK: subset
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 40;
int n;
vector<int> a, b;
long long x[820], y[820];

int main() {
	freopen("subset.in", "r", stdin);
	freopen("subset.out", "w", stdout);
	scanf("%d", &n);
	int total = (n*(n+1))>>1;
	if(total&1) { puts("0"); return 0; }
	total >>= 1;	

	for(int i = 1; i <= (n>>1); i++) a.push_back(i);
	for(int i = (n>>1)+1; i <= n; i++) b.push_back(i);

	int s1 = a.size(), s2 = b.size();
	for(int mask = 0; mask < (1<<s1); mask++) {
		int sum = 0;
		for(int i = 0; i < s1; i++) if(mask>>i&1)
			sum += a[i];
		x[sum]++;
	} 
	for(int mask = 0; mask < (1<<s2); mask++) {
		int sum = 0;
		for(int i = 0; i < s2; i++) if(mask>>i&1)
			sum += b[i];
		y[sum]++;
	}
	long long ans = 0;
	for(int i = 0; i <= total; i++)
		ans += x[i] * y[total - i];
	printf("%lld\n", ans/2);
	return 0;
}