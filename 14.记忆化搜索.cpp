/*************************************************************************
	> File Name: 14_ze.cpp
	> Author: 北海望谷堆
	> Mail: dayuyuhai@outlook.com 
	> Created Time: Sun 17 May 2020 03:15:30 PM CST
 ************************************************************************/

//搜索是一种算法，记忆化是一种编程技巧

#include<iostream>
#define max_n 1000000
using namespace std;
#define max_m 1000000

int keep[max_m + 5];

typedef long long ll;

ll get_len(ll n) {
	if (n == 1) return 1;
	if (n < max_m && keep[n]) return keep[n];
	ll ret;
	if (n & 1) ret = get_len(3 * n + 1) + 1;
	else ret = get_len(n >> 1) + 1;
	if (n < max_m) keep[n] = ret;
	return ret;
}

int main() {
	int ans = 0, len = 0;
	for (int i = 1; i < max_n; i++) {
		int temp = get_len(i);
		if (temp <= len) continue;
		ans = i;
		len = temp;
	}
	printf("%d = %d\n", ans, len);
	return 0;
}

/*
                           简单版get_len
int get_len(ll n) {
	if (n < 0) printf("error\n");
	if (n == 1) return 1;
	if (n & 1) return get_len(3 * n + 1) + 1;
	//n很大的时候可能超过int表示范围，爆栈
	return get_len(n >> 1) + 1;
}

*/
