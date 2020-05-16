/*************************************************************************
	> File Name: 42.cpp
	> Author: 北海望谷堆
	> Mail: dayuyuhai@outlook.com 
	> Created Time: Sat 16 May 2020 12:12:33 PM CST
 ************************************************************************/

#include<iostream>
#include<string.h>
using namespace std;
#define max_n 40

int a[max_n + 5];

void init() {
	for (int i = 1; i < max_n; i++) {
		a[i] = i * (i + 1) / 2;
	}
}

int find(int x) {
	for (int i = 1; i < max_n; i++) {
		if (a[i] == x) return 1;
	}
	return 0;
}

int main() {
	init();
	int cnt = 0;
	int sum = 0;
	string s;
	while (getline(cin, s, ',')) {
		sum = 0;
		for (int i = 0; s[i]; i++) {
			sum = sum + (int)s[i] - 64;
		}
		if (find(sum + 60)) cnt++;
	}
	cout << cnt << endl;
	return 0;
}
