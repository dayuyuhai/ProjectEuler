/*************************************************************************
	> File Name: 21.cpp
	> Author: 北海望谷堆
	> Mail: dayuyuhai@outlook.com 
	> Created Time: Tue 26 May 2020 08:51:39 PM CST
 ************************************************************************/

#include<iostream>
#include<math.h>
using namespace std;
#define max_n 10000

int prime[max_n + 5] = {0};
int f[max_n + 5] = {0};
int cnt[max_n + 5] = {0};

void init() {
	for (int i = 2; i <= max_n; i++) {
		if (!prime[i]) {
			prime[++prime[0]] = i;
			f[i] = i + 1;
			//cnt[i] = 1;
			cnt[i] = i * i;
		}
		for (int j = 1; j <= prime[0]; j++) {
			if (prime[j] * i > max_n) break;
			prime[prime[j] * i] = 1;
			if (i % prime[j] == 0) {
				//cnt[prime[j] * i] = cnt[i] + 1;
				//f[prime[j] * i] = f[i] * (pow(prime[j], cnt[i] + 2) - 1) / (pow(prime[j], cnt[i] + 1) - 1);
				cnt[prime[j] * i] = cnt[i] * prime[j];
				f[prime[j] * i] = f[i] * (cnt[i] * prime[j] - 1) / (cnt[i] - 1);
				break;
			} else {
				//cnt[prime[j] * i] = 1;
				//f[prime[j] * i] = f[prime[j]] * f[i];
				cnt[prime[j] * i] = prime[j] * prime[j];
				f[prime[j] * i] = f[prime[j]] * f[i];
			}
		}
	}
	return ;
}

int main() {
	init();
	for (int i = 2; i < max_n; i++) {
		f[i] -= i;
	}
	long long sum = 0;
	for (int i = 2; i < max_n; i++) {
		if (f[i] < max_n && i == f[f[i]] && i != f[i]) sum += i;
	}
	cout << sum << endl;
	return 0;
}
