/* 
ID: akash331
TASK: prefix
LANG: C++11
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll base = 419;
const ll mod = 916969619;

struct HashTable{
	map<int,int> mp;
	void insert(char *s) {
		int len = strlen(s); ll h = 0; 
		for(int i = 0; i < len; i++)
			h = (h * base % mod + s[i] - 'A' + 1) % mod;
		mp[h] = 1;
	}
	bool find(int hash) { return mp[hash] == 1; }
}ds;

int dp[200010];
char s[80], S[200010];

int main() {
	freopen("prefix.in", "r", stdin);
	freopen("prefix.out", "w", stdout);

	while(scanf(" %s", s)) {
		if(s[0] == '.') break;
		ds.insert(s);
	} S[0] = '\0';
	while(scanf(" %s", s) != EOF)
		strcat(S,s);

	int n = strlen(S);
	for(int i = n-1; i >= 0; i--) {
		ll h = 0;
		for(int j = i; j < n && j - i + 1 <= 10; j++) {
			h = (h * base + S[j] - 'A' + 1) % mod;
			if(ds.find(h))
				dp[i] = max(dp[i], j - i + 1 + dp[j+1]);
		}
	} printf("%d\n", dp[0]);
	return 0;
}