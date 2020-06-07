/*************************************************************************
	> File Name: 41-ze.cpp
	> Author: 北海望谷堆
	> Mail: dayuyuhai@outlook.com 
	> Created Time: Sat 06 Jun 2020 06:46:22 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
#define max_n 10000000

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

int add_to (int *num, int n) {
	int ret = 0;
	for (int i = 0; i < n; i++) {
		ret = ret * 10 + num[i];
	}
	return ret;
}

int main() {
	init();
	int num[10];
	int n = 7, ans = 0;
	while (n && !ans) {
		for (int i = 0; i < n; i++) num[i] = n - i;
		do {
			int temp = add_to(num, n);
			if (!is_prime[temp]) ans = temp;
		} while (prev_permutation(num, num + n) && !ans);
		n--;
	}
	cout << ans << endl;
	return 0;
}
