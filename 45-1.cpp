/*************************************************************************
	> File Name: 45-1.cpp
	> Author: 北海望谷堆
	> Mail: dayuyuhai@outlook.com 
	> Created Time: Sun 31 May 2020 03:48:43 PM CST
 ************************************************************************/

#include<iostream>
#include<inttypes.h>
using namespace std;

int64_t t(int64_t n) {
	return n * (n + 1) / 2;
}

int64_t p(int64_t n) {
	return n * (3 * n - 1) / 2;
}

int64_t h(int64_t n) {
	return n * (2 * n - 1);
}

int64_t binary(int64_t (*func)(int), int64_t x) {
	int l = 0, r = x, mid;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (func[mid] == x) return mid;
		if (func[mid] > x) mid = l - 1;
		else mid = r + 1;
	}
	return 0;
}

int main() {
	for (int i = 144; ; i++) {
		if (binary(t, h(i)) == 0) continue;
		if (binary(p, h(i)) == 0) continue;
		cout << h(i) << endl;
		break;
	}
	return 0;
}
