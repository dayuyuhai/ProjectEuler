/*************************************************************************
	> File Name: 33-ze.cpp
	> Author: 北海望谷堆
	> Mail: dayuyuhai@outlook.com 
	> Created Time: Sat 30 May 2020 06:10:04 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int gcd(int a, int b) {
	return (b ? gcd(b, a % b) : a);
}

int is_val(int x, int y) {
	int x1 = x / 10, x2 = x % 10;
	int y1 = y / 10, y2 = y % 10;
	if (x1 == y2 && x * y1 == y * x2) return 1;
	if (x2 == y1 && x * y2 == y * x1) return 1;
	return 0;
}

int main() {
	int x = 1, y = 1;
	for (int a = 11; a < 100; a++) {
		for (int b = a + 1; b < 100; b++) {
			if (!is_val(a, b)) continue;
			x *= a, y *= b;
			int c = gcd(x, y);
			x /= c, y /= c;
		}
	}
	cout << y << endl;
	return 0;
}
