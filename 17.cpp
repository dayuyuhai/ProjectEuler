/*************************************************************************
	> File Name: what.cpp
	> Author: 北海望谷堆
	> Mail: dayuyuhai@outlook.com 
	> Created Time: Sun 10 May 2020 02:57:05 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int get_letter(int n) {
	static int arr1[20] = {
		0, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3,
		6, 6, 8, 8, 7, 7, 9, 8, 8
	};
	static int arr2[10] = {
		0, 0, 6, 6, 5, 5, 5, 7, 6, 6
	};
//	当前数组一经定义一次不会被重复初始化
	if (n < 20) return arr1[n];
	if (n < 100) return arr2[n / 10] + arr1[n % 10];
	if (n < 1000) {
		int temp = get_letter(n % 100);
		if (temp) temp += 3;
		return temp + arr1[n / 100] + 7;
	}
	if (n == 1000) return 11;
	return 0;
}
int main() {
	int sum = 0;
	for (int i = 1; i <= 1000; i++) {
		sum += get_letter(i);
	}
	cout << sum << endl;

	return 0;
}
