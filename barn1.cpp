/*
ID: akash331
TASK: barn1
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("barn1.in", "r", stdin);
	freopen("barn1.out", "w", stdout);
	int k, s, n, arr[205];
	vector<int> v;
	scanf("%d %d %d", &k, &s, &n);

	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	sort(arr,arr+n);
	for(int i = 1; i < n; i++) 
		v.push_back(arr[i] - arr[i-1] - 1);

	int ans = arr[n-1] - arr[0] + 1;
	sort(v.rbegin(),v.rend());
	int sz = v.size();
	for(int i = 0; i < min(sz,k-1); i++)
		ans -= v[i];
	printf("%d\n", ans);
	return 0;
}