/*************************************************************************
	> File Name: 11.cpp
	> Author: 北海望谷堆
	> Mail: dayuyuhai@outlook.com 
	> Created Time: Sun 17 May 2020 02:13:48 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#define max_n 20

int grid[max_n + 5][max_n + 5];

int dir[4][2] = {
	{0, 1}, {1, 1}, 
	{1, 0}, {1, -1}
};

int calc(int i, int j) {
	int ans = 0;
	for (int k = 0; k < 4; k++) {
		int p = 1;
		for (int step = 0; step < 4; step++) {
			int dx = i + dir[k][0] * step;
			int dy = j + dir[k][1] * step;
			if (dx < 0 || dx >= max_n) break;
			if (dy < 0 || dy >= max_n) break;
			p *= grid[dx][dy];
		}
		if (p > ans) ans = p;
	}
	return ans;
}

int main() {
	int ans = 0;
	for (int i = 0; i < max_n; i++) {
		for (int j = 0; j < max_n; j++) {
			scanf("%d", &grid[i][j]);
		}
	}
	for (int i = 0; i < max_n; i++) {
		for (int j = 0; j < max_n; j++) {
			int p = calc(i, j);
			if (p > ans) ans = p;
		}
	}
	printf("%d\n", ans);
	return 0;
}
