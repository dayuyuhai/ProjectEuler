/*************************************************************************
	> File Name: 排列组合.c
	> Author: 北海望谷堆
	> Mail: dayuyuhai@outlook.com 
	> Created Time: Tue 05 May 2020 08:51:49 PM CST
 ************************************************************************/

#include<stdio.h>

int main() {
	long long sum = 1;
	for (int i = 1; i < 21; i++) {
		sum = sum * (i + 20) / i;
	}
	printf("%lld\n", sum);
	return 0;
}
