/*
ID: akash331
TASK: hamming
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> soln;
int main() {
	freopen("hamming.in", "r", stdin);
	freopen("hamming.out", "w", stdout);
	int n, b, d;
	scanf("%d %d %d", &n, &b, &d);

	for(int i = 0; i < (1<<b) && n; i++) {
		int sz = soln.size();
		if(sz == 0) { soln.push_back(i), n--; continue; }
		bool take = true;
		for(int j = 0; j < sz; j++) {
			int ham = __builtin_popcount(soln[j]^i);
			if(ham < d) { take = false; break; }
		} if(take) soln.push_back(i), n--;
	} int sz = soln.size(), lines = ceil(sz/10.);
	for(int i = 0; i < lines; i++) {
		printf("%d", soln[i*10]);
		for(int j = 1; j < 10 && i*10 + j < sz; j++)
			printf(" %d", soln[i*10 + j]);
		puts("");
	} return 0;
}