/*
ID: akash331
TASK: lamps
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

int n, c;
vector<int> on, off;
set<string> soln;

void apply1(string &v, int sz) {
	for(int i = 0; i < sz; i++) v[i] = (v[i] == '0' ? '1' : '0');
} void apply2(string &v, int sz) {
	for(int i = 0; i < sz; i+=2) v[i] = (v[i] == '0' ? '1' : '0');
} void apply3(string &v, int sz) {
	for(int i = 1; i < sz; i+=2) v[i] = (v[i] == '0' ? '1' : '0');
} void apply4(string &v, int sz) {
	for(int i = 0; i < sz; i+=3) v[i] = (v[i] == '0' ? '1' : '0');
} bool ok(string v) {
	int sz = on.size();
	for(int i = 0; i < sz; i++) if(v[on[i]-1] != '1') return false;
	sz = off.size();
	for(int i = 0; i < sz; i++) if(v[off[i]-1] != '0') return false;
	return true;
}

void bt(int move, int pos, vector<int> take) {
	if(pos == 5 || move == c) {
		if(take.size() != c-1) {
			string got(n,'1');
			for(int i = 0; i < take.size(); i++) {
				if(take[i] == 1) apply1(got,n);
				else if(take[i] == 2) apply2(got,n);
				else if(take[i] == 3) apply3(got,n);
				else apply4(got,n);
			}
			if(ok(got)) soln.insert(got);
		}
		return;
	} 
	bt(move,pos+1,take);
	take.push_back(pos);
	bt(move+1,pos+1,take);
}

int main() {
	freopen("lamps.in", "r", stdin);
	freopen("lamps.out", "w", stdout);
	scanf("%d %d", &n, &c);

	int x; while(scanf("%d", &x)) {
		if(x == -1) break;
		on.push_back(x);
	} while(scanf("%d", &x)) {
		if(x == -1) break;
		off.push_back(x);
	} vector<int> dummy;
	bt(0,1,dummy);
	if(soln.size() == 0) puts("IMPOSSIBLE");
	else for(set<string>::iterator it = soln.begin(); it != soln.end(); it++)
		cout << *it << endl;
	return 0;
}