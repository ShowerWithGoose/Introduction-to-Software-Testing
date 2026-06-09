#define  _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int n;
int check[11];
int order[11];
void findseat(int k) {
	if (k > n) {//所有数字都找完后输出
		for (int i = 1; i <= n; printf("%d ", order[i]), i++);
		printf("\n");
	}
	else {
		for (int i = 1; i <= n; i++) {//寻找k数的位置
			if (check[i]==0) {
				order[k] = i;
				check[i] = 1;
				findseat(k + 1);//找到后找下一个数字
				order[k] = 0;//调用完后清空记录
				check[i] = 0;
			} 
		}
	}
}
int main()
{
	scanf("%d", &n);
	findseat(1);
	return 0;
}


