/*************************************************************************
	> File Name: 44_ze.cpp
	> Author: 北海望谷堆
	> Mail: dayuyuhai@outlook.com 
	> Created Time: Sat 16 May 2020 07:57:01 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#define max_n 1000000

int prime[max_n + 5];
int is_prime[max_n + 5];

void init() {
	for (int i = 2; i <= max_n; i++) {
		if (!is_prime[i]) prime[++prime[0]] = i;
		for (int j = 1; j <= prime[0]; j++) {
			if (i * prime[j] > max_n) break;
			is_prime[i * prime[j]] = 1;
			if (i % prime[j] == 0) break;
		}
	}
}

int func(int n) {
	return 2 * n * n;
}

int binary_search(int (*func)(int), int l, int r, int x) {
	if (l > r) return 0;
	int mid = (l + r) >> 1;
	if (func(mid) == x) return mid;
	if (func(mid) < x) l = mid + 1;
	else r = mid - 1;
	return binary_search(func, l, r, x);
}

int is_val(int n) {
	for (int i = 1; prime[i] < n && i <= prime[0]; i++) {
		int x = n - prime[i];
		if (binary_search(func, 1, x, x)) return 1;
	}
	return 0;
}

int main() {
	init();
	for (int i = 9; ; i += 2) {
		if (!is_prime[i]) continue;
		if (is_val(i)) continue;
		printf("%d\n", i);
		break;
	}
	return 0;
}
