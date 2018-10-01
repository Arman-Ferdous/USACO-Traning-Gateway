/*
ID: akash331
TASK: frac1
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

struct data{
	int a, b;
	data() {}
	data(int x, int y) : a(x), b(y) {}
	bool operator<(data x) const {
		return a * x.b < x.a * b;
	}
};
vector<data> v;
int main() {
	freopen("frac1.in", "r", stdin);
	freopen("frac1.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for(int i = 0; i <= n; i++) 
		for(int j = i + (i==0); j <= n; j++)
			if(__gcd(i,j) == 1) v.push_back({i,j});
	sort(v.begin(),v.end());
	int sz = v.size();
	for(int i = 0; i < sz; i++)
		printf("%d/%d\n", v[i].a, v[i].b);
	return 0;
}