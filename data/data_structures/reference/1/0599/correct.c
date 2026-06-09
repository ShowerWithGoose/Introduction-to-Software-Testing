#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//指针变量相当于一个新的变量，在函数中必须建一个指针变量指向这个指针变量才能改变这个变量的值
 
 
void Print(int*a, int n) {
	for (int i = 1; i <= n; i++) {
		if (i == n)	printf("%d\n", a[i]);
		else printf("%d ", a[i]);
	}
}
void perm(int*a, int*b,int n,int Index) {
	if (Index== n+1) {
		Print(a, n);
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!b[i]) {
			a[Index] = i;
			b[i] = 1;
			perm(a, b, n, Index + 1);
			b[i] = 0;
		}
	}
	return;
}
int main() {
	int n;
	int a[51], b[51] = { 0 };
	//可最大计算出50个数的全排列
	//其中a是输出数列，b是索引数列，它的索引用来锁定和输入a的数值
	scanf("%d", &n);
	//输入n来全排列1~n的数组
	perm(a, b, n, 1);
	return 0;
}



