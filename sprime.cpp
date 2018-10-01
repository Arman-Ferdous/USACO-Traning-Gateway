/*
ID: akash331
TASK: sprime
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll bigmod(ll a, ll b, ll m) {
	ll ret = 1, p = a;
	while(b) {
		if(b & 1) ret = ret*p % m;
		p = p*p % m;
		b >>= 1;
	} return ret % m;
}

bool Miller(ll p) {
	if(p < 2) return false;
	if(p != 2 && ~p&1) return false;
	ll d = p - 1;
	while(~d&1) d >>= 1;
	for(int i = 0; i < 20; i++) {
		ll a = rand()%(p-1)+1, temp = d;
		ll mod = bigmod(a,temp,p);
		while(temp != p-1 && mod != 1 && mod != p-1)
			mod = mod*mod % p, temp <<= 1;
		if(mod != p-1 && ~temp&1) return false;
	} return true;
}


vector<int> soln;
int n;
void bt(int x) {
	if(!Miller(x)) return;

	int len = log10(x) + 1;
	if(len == n) {
		soln.push_back(x);
		return;
	}
	for(int i = 0; i < 10; i++)
		bt(x*10 + i);
}

int main() {
	freopen("sprime.in", "r", stdin);
	freopen("sprime.out", "w", stdout);
	scanf("%d", &n);
	bt(2), bt(3), bt(5), bt(7);

	sort(soln.begin(),soln.end());
	int sz = soln.size();
	for(int i = 0; i < sz; i++)
		printf("%d\n", soln[i]);
	return 0;
}