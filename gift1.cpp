/*
ID: akash331
TASK: gift1
LANG: C++11
*/

#include <bits/stdc++.h>
using namespace std;

string s[20];
map<string,int> score;
int main() {
	freopen("gift1.in", "r", stdin);
	freopen("gift1.out", "w", stdout);

	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> s[i];
		score[s[i]] = 0;
	}

	string c;
	while(cin >> c) {
		int amount, person;
		cin >> amount >> person;
		
		if(person != 0) {
			int pp = amount/person;
			score[c] -= pp * person;
			while(person--) {
				cin >> c;
				score[c] += pp;
			}
		}
	}
	for(int i = 0; i < n; i++)
		cout << s[i] << " " << score[s[i]] << endl;
	return 0;
}