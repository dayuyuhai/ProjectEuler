/*************************************************************************
	> File Name: 37.cpp
	> Author: 北海望谷堆
	> Mail: dayuyuhai@outlook.com 
	> Created Time: Sat 30 May 2020 08:14:31 PM CST
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
	int t1, t2;
	int len = floor(log10(n)); 
	int p = pow(10, len);
	int cnt = 1;
	while (len--) {
		t1 = n % p;
		t2 = n / pow(10, cnt);
		p /= 10;
		cnt++;
		if (!keep[t1]) return 0;
		if (!keep[t2]) return 0;
	}
	return 1;
}

int main() {
	init();
	int cnt = 11; 
	long long sum = 0;
	for (int i = 5; i <= prime[0] && cnt; i++) {
		if (!is_val(prime[i])) continue;
		sum += prime[i];
		cnt--;
	}
	cout << sum << endl;
	return 0;
}

