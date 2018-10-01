/*
ID: akash331
TASK: zerosum
LANG: C++11
*/

#include <bits/stdc++.h>
using namespace std;

int n;
int op[12];
string s;
vector<string> soln;

char get(int x) {
	if(x == 1) return '+';
	if(x == -1) return '-';
	return ' ';
}

bool ok() {
	int sum = 0;
	for(int i = 1; i <= n; ) {
		int num = i, j;
		for(j = i+1; j <= n && op[j] == 0; j++)
			num = num * 10 + j;
		sum += op[i] * num;
		i = j;
	} return sum == 0;
}

void bt(int pos) {
	if(pos > n) {
		if(ok()) { s = "";
			for(int i = 1; i < n; i++)
				s = s + (char)(i + '0') + get(op[i+1]);
			s += (char)(n + '0');
			soln.push_back(s);
		}
		return;
	}
	for(int i = -1; i < 2; i++) {
		op[pos] = i;
		bt(pos+1);
		op[pos] = 0;
	}
}

int main() {
	freopen("zerosum.in", "r", stdin);
	freopen("zerosum.out", "w", stdout);
	cin >> n;
	op[1] = 1;
	bt(2);
	sort(soln.begin(),soln.end());
	for(string s : soln)
		cout << s << "\n";
	return 0;
}