/*************************************************************************
	> File Name: 42.c的字符读入法.cpp
	> Author: 北海望谷堆
	> Mail: dayuyuhai@outlook.com 
	> Created Time: Sun 17 May 2020 04:31:27 PM CST
 ************************************************************************/

#include<iostream>
#include"word.for42"

using namespace std;

inline int triangle(int n) {
	return n * (n + 1) / 2;
}

int binary_search(int (*func)(int), int l, int r, int x) {
	int head = l, tail = r, mid;
	while (head <= tail) {
		mid = (head + tail) >> 1;
		if (func(mid) == x) return 1;
		if (func(mid) < x) head = mid + 1;
		else tail = mid - 1;
	}
	return 0;
}

int is_val(const char *str) {
	int sum = 0;
	for (int i = 0; str[i]; i++) {
		sum += (str[i] - 'A' + 1);
	}
	return binary_search(triangle, 1, sum, sum);
}

int main() {
	int cnt = 0;
	int n = sizeof(str) / 100;
	for (int i = 0; i < n; i++) {
		cnt += (is_val(str[i]));
	}
	printf("%d\n", cnt);
	return 0;
}
