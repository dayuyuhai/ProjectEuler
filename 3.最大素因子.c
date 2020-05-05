/*************************************************************************
	> File Name: 3.c
	> Author: 北海望谷堆
	> Mail: dayuyuhai@outlook.com 
	> Created Time: Tue 05 May 2020 07:45:53 PM CST
 ************************************************************************/

#include<stdio.h>
#define max 600851475143LL  //定义一个长整形的宏

int main() {
	long long num = max, ans = 0;
	int i = 2;
	while (i * i <= num) {
		if (num % i == 0) ans = i; //ans一定为素因子
		while (num % i == 0) num /= i;
		i++;
	}
	if (num != 1) ans = num; 
	printf("%lld\n", ans);

	return 0;
}
