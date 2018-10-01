/*
ID: akash331
TASK: milk3
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 21;
int A, B, C;
bool made[N], vis[N][N][N];
void solve(int a, int b, int c) {
	if(vis[a][b][c]) return;
	vis[a][b][c] = true;
	if(a == 0) made[c] = true;
	int k = min(a,B-b);
	solve(a-k,b+k,c);				// a --> c
	k = min(a,C-c);
	solve(a-k,b,c+k);				// a --> b
	k = min(b,A-a);
	solve(a+k,b-k,c);				// b --> a
	k = min(b,C-c);
	solve(a,b-k,c+k);				// b --> c
	k = min(c,A-a);
	solve(a+k,b,c-k);				// c --> a
	k = min(c,B-b);
	solve(a,b+k,c-k);				// c --> b
}

int main() {
	freopen("milk3.in", "r", stdin);
	freopen("milk3.out", "w", stdout);
	scanf("%d %d %d", &A, &B, &C);
	solve(0,0,C);
	bool flag = true;
	for(int i = 0; i < N; i++) {
		if(made[i] && flag) { printf("%d", i); flag = false; }
		else if(made[i]) printf(" %d", i); 
	} puts("");
	return 0;
}