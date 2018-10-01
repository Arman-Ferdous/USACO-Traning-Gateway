/*
ID: akash331
TASK: transform
LANG: C++11
*/

#include <bits/stdc++.h>
using namespace std;

int n;
char mat[15][15], arr[15][15];

void rotate() {	// rotates ccw
	char tmp[15][15];
	for(int i = 0; i < n; i++) 
		for(int j = 0; j < n; j++)
			tmp[n-j-1][i] = mat[i][j];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			mat[i][j] = tmp[i][j];
}

void mirror() {
	char tmp[15][15];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			tmp[i][n-j-1] = mat[i][j];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			mat[i][j] = tmp[i][j];
}

bool match() {
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(mat[i][j] != arr[i][j])
				return false;
	return true;
}
void show(int x) { printf("%d\n", x); exit(0); }

int main() {
	freopen("transform.in", "r", stdin);
	freopen("transform.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf(" %s", arr[i]);
	for(int i = 0; i < n; i++)
		scanf(" %s", mat[i]);

	rotate();
	if(match()) show(1);
	rotate();
	if(match()) show(2);
	rotate();
	if(match()) show(3);
	rotate(); mirror();
	if(match()) show(4);
	rotate();
	if(match()) show(5);
	rotate();
	if(match()) show(5);
	rotate();
	if(match()) show(5);
	rotate();
	if(match()) show(6);
	show(7);
	return 0;
}