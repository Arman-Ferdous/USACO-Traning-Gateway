/*
ID: akash331
TASK: fracdec
LANG: C++11
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
int arr[N], seen[N], cnt;

int main() {
	freopen("fracdec.in", "r", stdin);
	freopen("fracdec.out", "w", stdout);
	int n, d;
	scanf("%d %d", &n, &d);

	if(n % d == 0) {
		printf("%d.0\n", n/d);
		return 0;
	}

	printf("%d.", n/d); 
	if(n/d != 0) cnt = log10(n/d) + 2;
	else cnt = 2;

	int ptr = 0, idx;
	memset(seen, -1, sizeof seen);
	for(;;) {
		n %= d;
		n *= 10;
		if(seen[n] + 1) {
			idx = seen[n];
			break;
		}
		arr[ptr++] = n/d;
		seen[n] = ptr-1;
	}
	for(int i = 0; i < idx; i++) {
		if(cnt == 76) { printf("\n"); cnt = 0; }
		printf("%d", arr[i]); cnt++;
	}

	if(arr[idx] == 0 && idx + 1 == ptr) {
		printf("\n");
		return 0;
	}

	if(cnt == 76) { printf("\n"); cnt = 0; }
	printf("("); cnt++;

	for(int i = idx; i < ptr; i++) {
		if(cnt == 76) { printf("\n"); cnt = 0; }
		printf("%d", arr[i]); cnt++;
	}
	printf(")\n");

	return 0;
}