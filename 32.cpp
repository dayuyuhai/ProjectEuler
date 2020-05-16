/*************************************************************************
	> File Name: 32.cpp
	> Author: 北海望谷堆
	> Mail: dayuyuhai@outlook.com 
	> Created Time: Sun 10 May 2020 03:41:45 PM CST
 ************************************************************************/

#include<iostream>
#include<math.h>
using namespace std;

int add_to_num(int a, int *num) {
	while (a) {
		if (num[a % 10]) return 0;
		num[a % 10] += 1;
		a /= 10;
	}
	return 1;
}

inline int digit(int n) {
	if (n == 0) return 1;
	return floor(log10(n)) + 1;
}

//内联函数，告诉操作系统当前函数被经常调用，需要进行提前加载

int is_val(int a, int b, int c) {
	if (digit(a) + digit(b) + digit(c) - 9) return 0;
	int num[10] = {0}, flag = 1;
	num[0] = 1;
	flag = flag && add_to_num(a, num);
	flag = flag && add_to_num(b, num);
	flag = flag && add_to_num(c, num);
	return flag;
}

int keep[10000] = {0};

int main() {
	int sum = 0;
	for (int a = 1; a < 100; a++) {
		for (int b = 100; b < 10000; b++) {
			if (!is_val(a, b, a * b)) continue;
			if (keep[a * b]) continue;
			sum += a * b;
			keep[a * b] = 1;
		}
	}
	cout << sum << endl;
	return 0;
}
