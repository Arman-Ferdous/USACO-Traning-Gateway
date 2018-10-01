/*
ID: akash331
TASK: milk
LANG: C++11
*/

#include <bits/stdc++.h>
using namespace std;

struct data{
	int amount, cost;
	bool operator<(data b) const {
		return cost < b.cost;
	}
}arr[5010];

int main() {
	freopen("milk.in", "r", stdin);
	freopen("milk.out", "w", stdout);
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++) 
		scanf("%d %d", &arr[i].cost, &arr[i].amount);
	sort(arr,arr+m);
	long long ans = 0;
	int ptr = 0;
	while(n) {
		int take = min(n,arr[ptr].amount);
		ans += take * arr[ptr].cost;
		n -= take, ptr++;
	} printf("%lld\n", ans);
	return 0;
}