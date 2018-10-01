/*
ID: akash331
TASK: combo
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;
int n;
int hamming_distance(vector<int> a, vector<int> b) {
	int ret = 0;
	for(int i = 0; i < 3; i++) {
		int tmp = abs(a[i] - b[i]);
		tmp = min(tmp , n - tmp);
		ret = max(ret, tmp);
	}
	return ret;
}
int main() {
	freopen("combo.in", "r", stdin);
	freopen("combo.out", "w", stdout);
	scanf("%d", &n);
	vector<int> farmer(3), master(3);
	for(int i = 0; i < 3; i++)
		scanf("%d", &farmer[i]);
	for(int i = 0; i < 3; i++)
		scanf("%d", &master[i]);
	int ans = 0;
	vector<int> tmp(3);
	for(tmp[0] = 1; tmp[0] <= n; tmp[0]++)
		for(tmp[1] = 1; tmp[1] <= n; tmp[1]++)
			for(tmp[2] = 1; tmp[2] <= n; tmp[2]++)
				if(min(hamming_distance(farmer,tmp),hamming_distance(master,tmp)) <= 2)
					ans++;
	printf("%d\n", ans);
	return 0;
}