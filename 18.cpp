/*************************************************************************
	> File Name: 18.cpp
	> Author: 北海望谷堆
	> Mail: dayuyuhai@outlook.com 
	> Created Time: Tue 26 May 2020 06:48:06 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
#define max_n 15

int arr[max_n + 5][max_n + 5];
int keep[max_n + 5][max_n + 5];

int ret;

int dfs(int i, int j, int n) {
	if (i + 1 == n) return arr[i][j];
	if (keep[i][j]) return keep[i][j];
	int val1 = dfs(i + 1, j, n);
	int val2 = dfs(i + 1, j + 1, n);
	return keep[i][j] = max(val1, val2) + arr[i][j];
}

int main() {
	for (int i = 0; i < max_n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> arr[i][j];
		}
	}
	cout << dfs(0, 0, max_n) << endl;
	return 0;
}
