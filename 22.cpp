/*************************************************************************
	> File Name: 22.cpp
	> Author: 北海望谷堆
	> Mail: dayuyuhai@outlook.com 
	> Created Time: Sun 07 Jun 2020 02:10:27 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
#define max_n 6000

string s[max_n + 5];

long long add_to(string str, int n) {
	int ret = 0;
	for (int i = 0; str[i]; i++) {
		if (str[i] == '\"') continue;
		ret += str[i] - 'A' + 1;
	}
	return ret * n;
}

int main() {
	int cnt = 0;
	while (getline(cin, s[cnt], ',')) {
		cnt++;
	}
	long long sum = 0;
	sort(s, s + cnt);
	for (int i = 0; i < cnt; i++) {
		cout << s[i] << endl;
		sum += add_to(s[i], i + 1);
	}
	cout << sum << endl;

	return 0;
}
