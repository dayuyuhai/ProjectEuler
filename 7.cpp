/*************************************************************************
	> File Name: 7.cpp
	> Author: 北海望谷堆
	> Mail: dayuyuhai@outlook.com 
	> Created Time: Sun 10 May 2020 02:16:09 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int num[200000] = {0};

void init() {
	for (int i = 2; i * i < 150000; i++) {
		if (num[i]) continue;
		for (int j = i * i; j < 150000; j += i) {
			num[j] = 1;
		}
	}
}

int main() {
	init();
	int i, cnt = 0;
	for (i = 2; cnt < 10001; i++) {
		(num[i] == 0) && cnt++;
	}
	cout << i - 1 << endl;
	return 0;
}
