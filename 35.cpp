/*************************************************************************
	> File Name: 35.cpp
	> Author: 北海望谷堆
	> Mail: dayuyuhai@outlook.com 
	> Created Time: Sat 30 May 2020 06:34:59 PM CST
 ************************************************************************/

#include<iostream>
#include<math.h>
using namespace std;
#define max_n 1000000

int prime[max_n + 5];
int keep[max_n + 5];

void init() {
	for (int i = 2; i < max_n; i++) {
		if (!prime[i]) {
			prime[++prime[0]] = i;
			keep[i] = 1;
		}
		for (int j = 1; j <= prime[0]; j++) {
			if (i * prime[j] > max_n) break;
			prime[i * prime[j]] = 1;
			if (i % prime[j] == 0) break;
		}
	}
}


int is_val(int n) {
	int len = floor(log10(n)); 
	if (len == 0) return 1;
	int p = pow(10, len);
	while (len--) {
		n = n % p * 10 + n / p;
		if (!keep[n]) return 0;
	}
	return 1;
}

int main() {
	init();
	int cnt = 0;
	for (int i = 1; i <= prime[0]; i++) {
		cnt += is_val(prime[i]);
	}
	cout << cnt << endl;
	return 0;
}
