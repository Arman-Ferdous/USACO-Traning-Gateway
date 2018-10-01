/*
ID: akash331
TASK: palsquare
LANG: C++11
*/

#include <bits/stdc++.h>
using namespace std;

string convert(int n, int b) {
	string s = "0123456789ABCDEFGHIJ";
	string ret = "";
	while(n) {
		ret = s[n%b] + ret;
		n /= b;
	} return ret;
}

int main() {
	freopen("palsquare.in", "r", stdin);
	freopen("palsquare.out", "w", stdout);

	int b;
	cin >> b;
	for(int i = 1; i <= 300; i++) {
		string num = convert(i*i,b);
		string rev = num; reverse(rev.begin(),rev.end());
		if(num == rev) cout << convert(i,b) << " " << num << endl;
	}
	return 0;
}