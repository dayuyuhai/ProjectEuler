/*************************************************************************
	> File Name: 36.cpp
	> Author: 北海望谷堆
	> Mail: dayuyuhai@outlook.com 
	> Created Time: Thu 28 May 2020 08:49:44 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int p(int x, int base) {
	int t = 0;
	int temp = x;
	while (x) {
		t += x % base;
		t *= base;
		x /= base;
	}
	if (temp == t / base) return 1;
	return 0;
}

int main() {
	long long sum = 0;
	for (int i = 1; i < 1000000; i++) {
		if (p(i, 10) && p(i, 2)) sum += i;
	}
	cout << sum << endl;
	return 0;
}
