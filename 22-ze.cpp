/*************************************************************************
	> File Name: 22-ze.cpp
	> Author: 北海望谷堆
	> Mail: dayuyuhai@outlook.com 
	> Created Time: Sun 07 Jun 2020 02:55:58 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<string.h>
#include"input-22-char"
using namespace std;
#define max_n 6000

string s[max_n + 5];

long long add_to(string str, int n) {
	int ret = 0;
	for (int i = 0; str[i]; i++) {
		ret += str[i] - 'A' + 1;
	}
	return ret * n;
}

int main() {
	int cnt = 0;
	for (int i = 0; s[i] != "\0"; i++) cnt++;
	long long sum = 0, ans = 0;
	sort(s, s + cnt);
	for (int i = 0; i < cnt; i++) {
		sum += add_to(s[i], i + 1);
	}
	cout << sum << endl;

	return 0;
}

