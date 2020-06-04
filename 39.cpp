/*************************************************************************
	> File Name: 39.cpp
	> Author: 北海望谷堆
	> Mail: dayuyuhai@outlook.com 
	> Created Time: Tue 02 Jun 2020 07:57:20 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int gcd(int a, int b) {
	return (b ? gcd(b, a % b) : a);
}

int get(int x) {
	int a, b, c;
	int cnt = 0;
	for (int n = 1; n * n <= x; n++) {
		for (int m = n + 1; m * m + n * n < x; m++) {
			if (gcd(n, m) - 1) continue;
			a = 2 * n * m;
			b = m * m - n * n;
			c = m * m + n * n;
			if (gcd(a, b) != 1) continue;
			if (x % (a + b + c) == 0) cnt++;
		}

	}
	return cnt;
}

int main() {
	int ans = 0, max = 0;
	for (int p = 1; p <= 1000; p++) {
		int k = get(p);
		if (k > max) {
			max = k;
			ans = p;
		}
	}
	cout << ans << endl;
	return 0;
}
