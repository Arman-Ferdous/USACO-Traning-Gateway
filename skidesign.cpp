/*
ID: akash331
TASK: skidesign
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

int n, arr[1010], cnt[105];

int main() {
	freopen("skidesign.in", "r", stdin);
	freopen("skidesign.out", "w", stdout);

	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		cnt[arr[i]]++;
	}
	int ans = 1000000000;
	for(int l = 0; l + 17 <= 100; l++) {
		int r = min(l+17,100), res = 0;
		for(int i = 0; i < l; i++)
			res += (l - i) * (l - i) * cnt[i];
		for(int i = r + 1; i <= 100; i++) 
			res += (i - r) * (i - r) * cnt[i];
		ans = min(ans, res);
	} printf("%d\n", ans);
	return 0;
}
