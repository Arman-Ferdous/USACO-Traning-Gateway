/*
ID: akash331
TASK: dualpal
LANG: C++11
*/

#include <bits/stdc++.h>
using namespace std;

bool check(int n, int b) {
	int p = 1, ret = 0, rev = 0;
	while(n) {
		ret += p * (n % b);
		rev = rev * 10 + (n % b);
		p *= 10, n /= b;
	} return ret == rev;
}

int main() {
	freopen("dualpal.in", "r", stdin);
	freopen("dualpal.out", "w", stdout);
	int n, s;
	scanf("%d %d", &n, &s); s++;
	while(n) {
		int palindrome = 0;
		for(int i = 2; i <= 10; i++)
			if(check(s,i)) palindrome++;
		if(palindrome > 1) { printf("%d\n", s); n--; }
		s++;
	} return 0;
}