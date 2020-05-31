/*************************************************************************
	> File Name: 24.cpp
	> Author: 北海望谷堆
	> Mail: dayuyuhai@outlook.com 
	> Created Time: Sun 31 May 2020 06:09:48 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#define max_n 1000000

int a[15] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int f(int n) {
	if (n <= 1) return 1;
	return n * f(n - 1);
}

int main() {
	int n = max_n - 1;
	for (int i = 9; i >= 2; i--) {
		flag = 0;
		while (n - f(i) > 0) {
			flag = 1;
			n -= f(i);
			a[9 - i]++;
		}
		n += f(i);
	}
	for (int i = 0; i < 10; i++) {
		cout << a[i] << endl;
	}
	return 0;
}
