/*
ID: akash331
TASK: milk2
LANG: C++11
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
int cnt[N];
int main() {
	freopen("milk2.in", "r", stdin);
	freopen("milk2.out", "w", stdout);
	int n, R = 0, L = N;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		int l, r;
		scanf("%d %d", &l, &r);
		cnt[l]++, cnt[r]--;
		R = max(R, r-1);
		L = min(L, l);
	}
	for(int i = L; i <= R; i++)
		cnt[i] += cnt[i-1];
	int one = 0, zero = 0;
	for(int i = L; i <= R; i++) {
		if(cnt[i] > 0) {
			int tmp = 0;
			while(i <= R && cnt[i] > 0) 
				tmp++, i++; i--;
			one = max(one, tmp);
		} else {
			int tmp = 0;
			while(i <= R && cnt[i] == 0)
				tmp++, i++; i--;
			zero = max(zero, tmp);
		}
	} printf("%d %d\n", one, zero);
	return 0;
}