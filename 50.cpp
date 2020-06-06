/*************************************************************************
	> File Name: 50.cpp
	> Author: 北海望谷堆
	> Mail: dayuyuhai@outlook.com 
	> Created Time: Sat 06 Jun 2020 02:09:29 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#define max_n 1000000

int prime[max_n + 5];
long long sum[max_n + 5];
int is_prime[max_n + 5];

void init() {
	for (int i = 2; i <= max_n; i++) {
		if (!is_prime[i]) {
			prime[++prime[0]] = i;
		}
		for (int j = 1; j <= prime[0]; j++) {
			if (i * prime[j] > max_n) break;
			is_prime[i * prime[j]] = 1;
			if (i % prime[j] == 0) break;
		}
	}
	for (int i = 1; i <= prime[0]; i++) {
		sum[i] = sum[i - 1] + prime[i];
	}
	return ;
}

int main() {
	init();
	long long ans, len = 0;
	for (int i = 0; i < prime[0]; i++) {
		for (int j = i + 1; j <= prime[0]; j++) {
			long long tmp = sum[j] - sum[i];
			if (tmp < max_n && !is_prime[tmp] && j - i > len) {
				len = j - i;
				ans = tmp;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
