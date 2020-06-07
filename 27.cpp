/*************************************************************************
	> File Name: 27.cpp
	> Author: 北海望谷堆
	> Mail: dayuyuhai@outlook.com 
	> Created Time: Sun 07 Jun 2020 03:21:07 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#define max_n 10000

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
	return ;
}

int main() {
	init();
	for (int i = 1; prime[i] <= 1000; i++) {
		cout << prime[i] << endl;
	}
	return 0;
}
