/*************************************************************************
	> File Name: 38.cpp
	> Author: 北海望谷堆
	> Mail: dayuyuhai@outlook.com 
	> Created Time: Sat 30 May 2020 03:30:54 PM CST
 ************************************************************************/

#include<iostream>
#include<math.h>
using namespace std;
#define max_n 10000

int digits(long long n) {
	if (n == 0) return 1;
	return floor(log10(n)) + 1;
}

long long calc(int x) {
	long long n = 0, ans = 0;
	while (digits(ans) < 9) {
		n += 1;
		ans = ans * pow(10, digits(n * x));
		ans += n * x;
	}
	if (digits(ans) - 9) return 0;
	int num[10] = {1, 0};
	long long temp = ans;
	//判断每位不重复
	while (temp) {
		if (num[temp % 10]) return 0;
		num[temp % 10] += 1;
		temp /= 10;
	}
	return ans;
}


int main() {
	long long ans = 0;
	for (int i = 1; i < max_n; i++) {
		long long temp = calc(i);
		ans = (temp > ans) ? temp : ans;
	}
	cout << ans << endl;
	return 0;
}
