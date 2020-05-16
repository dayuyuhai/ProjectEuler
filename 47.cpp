/*************************************************************************
	> File Name: 47.cpp
	> Author: 北海望谷堆
	> Mail: dayuyuhai@outlook.com 
	> Created Time: Sat 16 May 2020 09:58:25 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#define max_n 1000

int num[max_n + 5];

void init() {
	for (int i = 2; i < max_n; i++) {
		if (num[i]) continue;
		for (int j = i * i; j < max_n; j += i) {
			num[j] = 1;
		}
		num[++num[0]] = i;
	}
}

int is(int t) {
	int cnt = 0;
	for (int j = 1; num[j] != 0 && num[j] != 1; j++) {
		(t % num[j] == 0) && cnt++;
		while (t % num[j] == 0) {
			t /= num[j];
		}
		if (t == 1 && cnt == 4) return 1;
	}
	return 0;
}


int main() {
	int ans;
	init();
	for (int i = 644; i < 1000000; i++) {
		if (is(i) && is(i + 1) && is(i + 2) && is(i + 3)) {
			cout << i << endl;
			break;
		}
	}
	return 0;
}
