/*
ID: akash331
TASK: holstein
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

int n, m, req[25];
struct data{
	int stat[25];
}arr[15];

vector<int> soln;
void check(vector<int> &v) {
	int sz = v.size();
	int got[25]; memset(got,0,sizeof got);
	for(int i = 0; i < sz; i++) {
		for(int j = 0; j < n; j++) 
			got[j] += arr[v[i]].stat[j];
	}
	for(int i = 0; i < n; i++) 
		if(got[i] < req[i]) return;
	if(soln.size() == 0 || v.size() < soln.size()) 
		soln = v;
	else if(v.size() == soln.size())
		for(int i = 0; i < sz; i++) 
			if(v[i] < soln[i]) return void(soln = v);
}

int main() {
	freopen("holstein.in", "r", stdin);
	freopen("holstein.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &req[i]);
	scanf("%d", &m);
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			scanf("%d", &arr[i].stat[j]);
	for(int mask = 1; mask < (1<<m); mask++) {
		vector<int> take;
		for(int j = 0; j < 15; j++) if(mask>>j&1)
			take.push_back(j);
		check(take);
	}
	int sz = soln.size();
	printf("%d", sz);
	for(int i = 0; i < sz; i++)
		printf(" %d", soln[i] + 1);
	puts("");
	return 0;
}