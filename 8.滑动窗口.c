/*************************************************************************
	> File Name: 8.滑动窗口.c
	> Author: 北海望谷堆
	> Mail: dayuyuhai@outlook.com 
	> Created Time: Tue 05 May 2020 08:11:42 PM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#define max 1000
char num[max + 5];

int main() {
	int len = 0;
	while (~scanf("%s", num + len)) len += strlen(num + len);
	long long ans = 0, p = 1, zero = 0;
	for (int i = 0; num[i]; i++) {  //字符串末尾是\0
		num[i] -= '0';   //ASCII字符转整形
		if (num[i]) p *= num[i];
		else zero += 1;
		if (i < 13) continue;
		if (num[i - 13]) p /= num[i - 13];
		else zero -= 1;
		if (zero == 0 && p > ans) ans = p;
	}
	printf("%lld\n", ans);

	return 0;
}
