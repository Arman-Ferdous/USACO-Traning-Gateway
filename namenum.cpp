/*
ID: akash331
TASK: namenum
LANG: C++11
*/

#include <bits/stdc++.h>
using namespace std;

struct data{
	string name, id;
}arr[4617];

string get(string &s) {
	string ret = "";
	int sz = s.size();
	for(int i = 0; i < sz; i++) {
		if(s[i] == 'Q' || s[i] == 'Z') ret += "?";
		else if(s[i] <= 'C') ret += "2";
		else if(s[i] <= 'F') ret += "3";
		else if(s[i] <= 'I') ret += "4";
		else if(s[i] <= 'L') ret += "5";
		else if(s[i] <= 'O') ret += "6";
		else if(s[i] <= 'S') ret += "7";
		else if(s[i] <= 'V') ret += "8";
		else ret += "9";
	} return ret;
}

int main() {
	FILE *fp;
	fp = fopen("dict.txt", "r");

	char s[15];
	for(int i = 0; i < 4617; i++) {
		fscanf(fp, " %s", &s);
		string str = s;
		arr[i].name = s;
		arr[i].id = get(str);
	}

	fclose(fp);
	freopen("namenum.in", "r", stdin);
	freopen("namenum.out", "w", stdout);

	int cnt = 0;
	string seq;
	cin >> seq;
	for(int i = 0; i < 4617; i++)
		if(arr[i].id == seq) { cout << arr[i].name << endl; cnt++; }
	if(cnt == 0) cout << "NONE\n";
	return 0;
}