/*************************************************************************
	> File Name: 9.cpp
	> Author: 北海望谷堆
	> Mail: dayuyuhai@outlook.com 
	> Created Time: Sun 31 May 2020 03:18:24 PM CST
 ************************************************************************/

#include<iostream>
#include<math.h>
using namespace std;

int gcd(int a, int b) {
	return (b ? gcd(b, a % b) : a);
}

int main() {
	int ans = 0;
	for (int n = 1; n <= 33; n++) {
		for (int m = n + 1; m * m + n * n < 1000; m++) {
			if (gcd(n, m) - 1) continue;
			int a = 2 * n * m;
			int b = m * m - n * n;
			int c = m * m + n * n;
			if (1000 % (a + b + c) == 0) {
				int k = 1000 / (a + b + c);
				ans = a * b * c * pow(k, 3);
			}
			if (ans) break;
		}
		if (ans) break;
	}
	cout << ans << endl;
	return 0;
}
