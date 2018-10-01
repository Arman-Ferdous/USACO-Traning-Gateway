/*
ID: akash331
TASK: friday
LANG: C++11
*/

#include <bits/stdc++.h>
using namespace std;

bool isleap(int n) {
	return (n%400==0) || (n%4==0 && n%100!=0);
}
int main() {
	freopen("friday.in", "r", stdin);
	freopen("friday.out", "w", stdout);
	int n, ans[7] = {0,0,0,0,0,0,0};
	cin >> n; n += 1899;
	int date = 1, month = 1, year = 1900, day = 2;
	while(year <= n) {
		if(date == 13) ans[day]++;
		day = (day + 1) % 7;
		date++;
		if(month == 2) {
			if(isleap(year) && date > 29)
				date = 1, month++;
			else if(!isleap(year) && date > 28)
				date = 1, month++;
		}
		else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
			if(date > 31) date = 1, month++;
			if(month > 12) month = 1, year++;
		} 
		else if(date > 30) date = 1, month++;
	}  printf("%d", ans[0]);
	for(int i = 1; i < 7; i++)
		printf(" %d", ans[i]); 
	puts("");
	return 0;
}