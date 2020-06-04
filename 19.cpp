/*************************************************************************
	> File Name: 19.cpp
	> Author: 北海望谷堆
	> Mail: dayuyuhai@outlook.com 
	> Created Time: Thu 04 Jun 2020 06:11:14 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int is_val(int m, int y) {
	int w;
	if (m == 1 || m == 2) {
		m += 12, y--;
	}
	w = (1 + y + y / 4 + 2 * m - y / 100 + y / 400 + 3 * (m + 1) / 5) % 7;
	return w == 6;
}	
int main() {
	int cnt = 0;
	for (int y = 1901; y <= 2000; y++) {
		for (int m = 1; m <= 12; m++) {
			cnt += (is_val(m, y));
		}
	}
	cout << cnt << endl;
	return 0;
}
