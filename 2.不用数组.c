/*************************************************************************
	> File Name: b.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2020年05月05日 星期二 18时47分47秒
 ************************************************************************/

#include<stdio.h>
#define SUP 4000000

int main() {
	int a = 1, b = 2;
	int sum = 2;
	while (a + b <=SUP) {
		a = a + b;
		b = a + b;
		!(a & 1) && (sum += a);
		!(b & 1) && (sum += b);
	}
	printf("%d\n", sum);

	return 0;
}
