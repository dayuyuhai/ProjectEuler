/*************************************************************************
	> File Name: 47_ze.cpp
	> Author: 北海望谷堆
	> Mail: dayuyuhai@outlook.com 
	> Created Time: Sat 16 May 2020 08:46:41 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#define max_n 1000

int num[max_n + 5];

void init() {
	for (int i = 2; i < max_n; i++) {
		if (num[i]) continue;
		for (int j = i; j < max_n; j += i) {
			num[j]++;
		}
	}
}

int main() {
	init();
	for (int i = 2; ; i++) {
		for (int j = 0; flag && j < 4; j++) {
			flag = flag && num[i + j] == 4;
		}
		if (!flag) continue;
		cout << i << endl;
		break;
	}
	return 0;
}
