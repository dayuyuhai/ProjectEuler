/*************************************************************************
	> File Name: 43.cpp
	> Author: 北海望谷堆
	> Mail: dayuyuhai@outlook.com 
	> Created Time: Sun 31 May 2020 04:20:32 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
#define max_n 10
#define max_m 3628800

int prime[10] = {2, 3, 5, 7, 11, 13, 17};

long long change(int *a) {
	long long x = 0;
	for (int i = 0; i < max_n; i++) {
		x += a[i];
		if (i == max_n - 1) continue;
		x *= 10;
	}
	return x;
}

int is_val(long long x) {
	int i = 1;
	for (int i = 6; i >= 0; i--) {
		int tmp = x % 1000;
		if (tmp % prime[i]) return 0;
		x /= 10;
	}
	return 1;
}
int main() {
	long long sum = 0;
	int a[max_n + 5] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	for (int i = 1; i < max_m; i++) {
		long long num = change(a);
		if (is_val(num)) sum += num;	
		next_permutation(a, a + max_n);
	}
	cout << sum << endl;
	return 0;
}
