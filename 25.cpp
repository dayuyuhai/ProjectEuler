/*************************************************************************
	> File Name: 25.cpp
	> Author: 北海望谷堆
	> Mail: dayuyuhai@outlook.com 
	> Created Time: Sat 23 May 2020 07:04:05 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#define max_n 1000

int a[max_n + 5] = {1, 1};
int b[max_n + 5] = {1, 1};

int main() {
	int n = 2;
	while (a[0] < max_n) {
		n++;
		for (int i = 1; i <= a[0]; i++) {
			b[i] = a[i];
		}
		for (int i = 1; i <= a[0]; i++) {
			a[i] = b[i] + a[i];
		}
		for (int i = 1; i <= a[0]; i++) {
			if (a[i] < 10) continue;
			a[i + 1] += a[i] / 10;
			a[i] %= 10;
			a[0] + (i == a[0]);
		}
	}
	cout << n << endl;

	return 0;
}
