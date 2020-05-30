/*************************************************************************
	> File Name: 33.cpp
	> Author: 北海望谷堆
	> Mail: dayuyuhai@outlook.com 
	> Created Time: Sat 30 May 2020 04:21:21 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

long long gcd(int a, int b) {
	return (b ? gcd(b, a % b) : a);
}

int is_val(int i, int j) {
	if (i % 10 == 0 || j % 10 == 0) return 0;
	int temp1 = i, temp2 = j;
	int flag = 0;
	if (i % 10 == j / 10) {
		flag = 1;
		temp1 = (temp1 - temp1 % 10) / 10;
		temp2 -= temp2 / 10 * 10;
	} else if (i / 10 == j % 10) {
		flag = 1;
		temp1 -= temp1 / 10 * 10;
		temp2 = (temp2 - temp2 % 10) / 10;
	}
	if (temp2 * i == temp1 * j && flag) return 1;
	return 0;
}

int main() {
	long long s = 1, x = 1;
	for (int i = 10; i < 100; i++) {
		for (int j = i + 1; j < 100; j++){
			if (!is_val(i, j)) continue;
			s *= i;
			x *= j;
		}
	}
	x /= gcd(x, s);
	cout << x << endl;
	return 0;
}
