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

int f[max_n + 5][max_m + 5];
int w[max_n + 5] = {1, 2, 5, 10, 20, 50, 100, 200};

int main() {
	for (int k = 0; k < max_n; k++) {
		int i = k % 2;
		f[i][0] = 1;
		for (int j = 1; j <= max_m; j++) {
			f[i][j] = f[i ^ 1][j];
			if (j >= w[k]) f[i][j] += f[i][j - w[k]];
		}
	}
	cout << f[(max_n - 1) % 2][max_m] << endl;
	return 0;
}

