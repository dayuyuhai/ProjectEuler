/*************************************************************************
	> File Name: 31-2.cpp
	> Author: 北海望谷堆
	> Mail: dayuyuhai@outlook.com 
	> Created Time: Sat 30 May 2020 02:53:53 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#define max_n 8
#define max_m 200

int f[max_m + 5];
int w[max_n + 5] = {1, 2, 5, 10, 20, 50, 100, 200};

int main() {
	f[0] = 1;
	for (int k = 0; k < max_n; k++) {
		for (int j = w[k]; j <= max_m; j++) {
			f[j] += f[j - w[k]];
		}
	}
	cout << f[max_m] << endl;
	return 0;
}

