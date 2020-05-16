/*************************************************************************
	> File Name: 46.cpp
	> Author: 北海望谷堆
	> Mail: dayuyuhai@outlook.com 
	> Created Time: Sat 16 May 2020 10:52:47 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#define max_n 10000

int num[max_n + 5];

void init() {
	for (int i = 2; i < max_n; i++) {
		if (num[i]) continue;
		for (int j = i * i; j < max_n; j += i) {
			num[j] = 1;
		}
		num[++num[0]] = i;
	}
}

int find(int x) {
	for (int i = 1; num[i] != 1 && num[i] != 0; i++) {
		if (num[i] == x) return 1;
	}
	return 0;
}

int main() {
	init();
	for (int i = 3; i < max_n; i += 2) {
		if (find(i)) continue;
		int j = 1, flag = 1;
		while ((i - 2 * j * j) > 1) {
			if (find(i - 2 * j * j)) {
				flag = 0;
				break;
			}
			j++;
		}
		if (flag) {
			cout << i << endl;
			break;
		}
	}
	return 0;
}
