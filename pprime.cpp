/*
ID: akash331
TASK: pprime
LANG: C++11
*/

// different from the official analysis
// got AC due to bad tests, the limit of N was 10^7 instead of 10^8, if it was 10^8 it would get MLE
// official solution generates all palindromes and then checks if they are prime or not

#include <bits/stdc++.h>
using namespace std;

#define off(x,i) (((~x)>>i)&1)
#define put(x,i) (x|(1<<i))

const int SIZE = 1e7+10;
int mark[(SIZE>>5) + 10];
vector<int> prime;

void sieve(int n) {
	mark[0] = 3;
	prime.push_back(2);
	for(int i = 4; i <= n; i+=2) 
		mark[i>>5] = put(mark[i>>5],(i&31));
	int root = sqrt(n) + 1;
	for(int i = 3; i <= n; i+=2) 
		if(off(mark[i>>5],(i&31))) {
			prime.push_back(i);
			if(i <= root)
				for(int j = i*i; j <= n; j+=(i<<1))
					mark[j>>5] = put(mark[j>>5],(j&31));
		}
}

bool pal(int x) {
	int rev = 0, org = x;
	while(x) {
		rev = rev * 10 + x % 10;
		x /= 10;
	} return rev == org;
}

int main() {
	freopen("pprime.in", "r", stdin);
	freopen("pprime.out", "w", stdout);
	sieve(SIZE-5);
	int a, b;
	cin >> a >> b;

	int sz = prime.size();
	for(int i = 0; i < sz; i++) {
		if(prime[i] < a) continue;
		if(prime[i] > b) break;
		if(pal(prime[i])) cout << prime[i] << endl;
	} return 0;
}