/*
ID: akash331
TASK: sort3
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

int n, arr[1010], cnt[4], p1[4], p2[4], p3[4];
int main() {
	freopen("sort3.in", "r", stdin);
	freopen("sort3.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		cnt[arr[i]]++;
	}
	for(int i = 0; i < cnt[1]; i++)
		p1[arr[i]]++;
	for(int i = cnt[1]; i < cnt[1] + cnt[2]; i++) 
		p2[arr[i]]++;
	for(int i = cnt[1] + cnt[2]; i < n; i++)
		p3[arr[i]]++;
	int ans = 0;

	int k = min(p1[2],p2[1]);
	ans += k, p1[2] -= k, p2[1] -= k;
	k = min(p2[3],p3[2]);
	ans += k, p2[3] -= k, p3[2] -= k;
	k = min(p1[3],p3[1]);
	ans += k, p1[3] -= k, p3[1] -= k;

	ans += min(p2[1] + p3[1] + p1[2] + p3[2], min(p1[2] + p3[2] + p1[3] + p2[3], p1[3] + p2[3] + p3[2] + p1[2]));
	printf("%d\n", ans);
	return 0;
}