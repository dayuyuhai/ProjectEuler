/*************************************************************************
	> File Name: 20.cpp
	> Author: 北海望谷堆
	> Mail: dayuyuhai@outlook.com 
	> Created Time: Sat 30 May 2020 02:03:29 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#define max_n 200

int a[max_n + 5] = {1, 1, 0};

int main() {
	int sum = 0;
	for (int i = 2; i <= 100; i++) {
		for (int j = 1; j <= a[0]; j++) {
			a[j] *= i;
		}
		for (int j = 1; j <= a[0]; j++) {
			if (a[j] < 10) continue;
			a[j + 1] += a[j] / 10;
			a[j] %= 10;
			a[0] += (j == a[0]);
		}
	}
	for (int i = 1; i <= a[0]; i++) {
		sum += a[i];
	}
	cout << sum << endl;
	return 0;
}
