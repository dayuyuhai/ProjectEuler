/*************************************************************************
	> File Name: 44.cpp
	> Author: 北海望谷堆
	> Mail: dayuyuhai@outlook.com 
	> Created Time: Fri 15 May 2020 10:13:45 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#define max_n 10000

long long p[max_n + 5];

int find(long long x) {
	for (int i = 1; i < max_n; i++) {
		if (p[i] == x) return 1;
	}
	return 0;
}

int main() {
	for (int i = 1; i < max_n; i++) {
		p[i] = i * (3 * i - 1) / 2;
	}
	int i, j;
	int flag = 0;
	for (i = 1; i < max_n ; i++) {
		for (j = i; j < max_n; j++) {
			if (find(p[i] + p[j]) && find(p[i] + 2 * p[j])) {
				flag = 1;
				break;
			}
		}
		if (flag) {
			cout << p[i] << endl;
			break;
		}
	}

	return 0;
}
