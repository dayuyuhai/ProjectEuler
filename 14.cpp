/*************************************************************************
	> File Name: 14.cpp
	> Author: 北海望谷堆
	> Mail: dayuyuhai@outlook.com 
	> Created Time: Fri 15 May 2020 08:54:40 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int a;

long long find(long long n) {
	if (n > 32) {
		a = n;
		return -1;
	}
	if ((n - 1) % 3) return find(n * 2) + 1;
	return max(find((n - 1) / 3), find(n * 2)) + 1;
}

int main() {
	cout << find(16) << endl;
	cout << a / 2 << endl;
	return 0;
}
