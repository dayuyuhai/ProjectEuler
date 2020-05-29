/*************************************************************************
	> File Name: 34.cpp
	> Author: 北海望谷堆
	> Mail: dayuyuhai@outlook.com 
	> Created Time: Thu 28 May 2020 08:20:34 PM CST
 ************************************************************************/

#include<iostream>
#include<math.h>
#define max_n 2540160
using namespace std;

long long f(int x) {
	int p = 1;
	for (int i = 2; i <= x; i++) {
		p *= i;
	}
	return p;
}

int main() {
	long long t, ans = 0;
	for (int i = 3; i <= max_n; i++) {
		long long sum = 0;
		t = i;
		while (t) {
			sum += f(t % 10);
			t /= 10;
		}
		if (i == sum) ans += i;
	}
	cout << ans << endl;
	return 0;
}
