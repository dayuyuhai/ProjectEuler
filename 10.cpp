/*************************************************************************
	> File Name: 10.cpp
	> Author: 北海望谷堆
	> Mail: dayuyuhai@outlook.com 
	> Created Time: Fri 15 May 2020 08:22:31 PM CST
 ************************************************************************/

#include<iostream>
#define max_n 2000000
using namespace std;
int num[max_n] = {0};

void init() {
	for (int i = 2; i * i < max_n; i++) {
		if (num[i]) continue;
		for (int j = i * i; j < max_n; j += i) {
			num[j] = 1;
		}
	}
}

int main() {
	init();
	int i;
	long long sum = 0;
	for (i = 2; i < max_n; i++) {
		(num[i] == 0) && (sum += i);
//		cout << sum << endl;
	}
	cout << sum << endl;
	return 0;
}

