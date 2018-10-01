/*
ID: akash331
TASK: crypt1
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

#define len(x) (int)log10(x)+1

int n, arr[12], ans, ok[12];
bool check(int x) {
	while(x) {
		if(!ok[x%10]) 
			return false;
		x /= 10;
	} return true;
}

void bt(vector<int> d) {
	if(d.size() == 5) {

		int n1 = d[0] * 100 + d[1] * 10 + d[2];
		int n2 = d[3] * 10 + d[4];

		int p1 = n1 * d[4];
		int p2 = n1 * d[3];
		int m  = n1 * n2;
		if(check(n1) && check(n2) && check(p1) && check(p2) && check(m) && len(p1) == 3 && len(p2) == 3 && len(m) == 4) {
			ans++;
			//cout << n1 << " * " << n2 << " = " << p1 << " + " << p2 << " * 10 = " << m << endl;
		}
		return;
	}
	for(int i = 0; i < n; i++) {
		vector<int> tmp = d;
		tmp.push_back(arr[i]);
		bt(tmp);
	} 
}
int main() {
	freopen("crypt1.in", "r", stdin);
	freopen("crypt1.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		ok[arr[i]] = 1;
	}
	vector<int> dummy;
	bt(dummy);
	printf("%d\n", ans);
	return 0;
}