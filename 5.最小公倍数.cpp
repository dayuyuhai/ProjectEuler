/*************************************************************************
	> File Name: 5.最小公倍数.cpp
	> Author: 北海望谷堆
	> Mail: dayuyuhai@outlook.com 
	> Created Time: Sun 10 May 2020 02:35:09 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int gcd(int a, int b) {
	return (b ? gcd(b, a % b) : a);
}

int main() {
	int ans = 1;
	for (int i = 1; i <= 20; i++) {
		ans *= i / gcd(ans, i);
	}
	cout << ans << endl;
	return 0;
}

