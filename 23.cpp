/*************************************************************************
	> File Name: 23.cpp
	> Author: 北海望谷堆
	> Mail: dayuyuhai@outlook.com 
	> Created Time: Sun 31 May 2020 04:27:53 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#define max_n 1000000

int f[max_n + 5] = {1, 1};

void init() {
	for (int i = 2; i <= max_n; i++) {
		f[i] += i;
		for (int j = 2; i * j <= max_n; j++) {
			f[i * j] += i;
		}
	}
	return;
}

int main() {
	long long sum = 0;
	int flag;
	init();
	for (int i = 1; i <= max_n; i++) {
		f[i] -= i;
	}
	for (int i = 1; i <= 28123; i++) {
		flag = 1;
		for (int j = 12; j < i; j++) {
			if (f[j] > j && f[i - j] > (i - j)) {
				cout << i << endl;
				flag = 0;
				break;
			}
		}
		if (flag) sum += i;
	}
	cout << sum << endl;
	return 0;
}
