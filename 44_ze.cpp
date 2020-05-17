/*************************************************************************
	> File Name: 44_ze.cpp
	> Author: 北海望谷堆
	> Mail: dayuyuhai@outlook.com 
	> Created Time: Sun 17 May 2020 06:06:46 PM CST
 ************************************************************************/

#include<iostream>
#include<inttypes.h>
using namespace std;

typedef long long ll;

inline ll P(int n) {
	return (3 * n - 1) * n / 2;
}

int binary_search(ll (*P)(int), int l, ll r, ll x) {
	int head = l, tail = r, mid;
	while (head <= tail) {
		mid = (head + tail) >> 1;
		if (P(mid) == x) return 1;
		if (P(mid) < x) head = mid + 1;
		else tail = mid - 1;
	}
	return 0;
}

int main() {
	ll n = 2, D = INT32_MAX;
	while (P(n) - P(n - 1) < D) {
		ll pk = P(n);
		for (int j = n - 1; j >= 1; j--) {
			if (pk - P(j) > D) break;
			int flag = 1;
			flag = flag && (binary_search(P, 1, pk + P(j), pk + P(j)));
			flag = flag && (binary_search(P, 1, pk - P(j), pk - P(j)));
			if (!flag) continue;
			D = pk - P(j);
		}
		n++;
	}
	printf("%lld\n", D);
	return 0;
}
