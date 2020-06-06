/*************************************************************************
	> File Name: 43-ze.cpp
	> Author: 北海望谷堆
	> Mail: dayuyuhai@outlook.com 
	> Created Time: Sat 06 Jun 2020 04:55:22 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
#define max_n 10

int prime[10] = {7, 2, 3, 5, 7, 11, 13, 17};

long long add_to(int *a) {
	long long x = 0;
	for (int i = 0; i < max_n; i++) {
		x = x * 10 + a[i];
	}
	return x;
}

int is_val(int *num) {
	int flag = 1;
	for (int i = 1; flag && i < 8; i++) {
		int tmp = num[i] * 100 + num[i + 1] * 10 + num[i + 2];
		flag = !(tmp % prime[i]);
	}
	return flag;
}
int main() {
	long long sum = 0;
	int a[max_n + 5] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	do {
		if (is_val(a)) sum += add_to(a);	
	} while (next_permutation(a, a + max_n));
	cout << sum << endl;
	return 0;
}
