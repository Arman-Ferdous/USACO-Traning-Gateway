/*
ID: akash331
TASK: beads
LANG: C++11
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("beads.in", "r", stdin);
	freopen("beads.out", "w", stdout);
	int n, ans = 0;
	string s;
	cin >> n >> s;
	s += s;
	for(int i = 0; i < n; i++) {
		int r = i + n - 1;

		int ptr = i, occ = -1, fcnt = 0, bcnt = 0;
		while(ptr < r) {
			if(s[ptr] == 'w') fcnt++, ptr++;
			else {
				if(occ != -1 && s[occ] != s[ptr]) break;
				else { occ = ptr; ptr++; fcnt++; }
			}
		}
		ptr = i-1, occ = -1;
		while(ptr >= 0) {
			if(s[ptr] == 'w') bcnt++, ptr--;
			else {
				if(occ != -1 && s[occ] != s[ptr]) break;
				else { occ = ptr; ptr--; bcnt++; }
			}
		} 
		ans = max(ans, fcnt + bcnt);
	} printf("%d\n", min(n,ans));
}