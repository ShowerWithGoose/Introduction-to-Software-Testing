#include <stdio.h>//从1开始的全排列的递归算法-实现小数在前-用qsort函数
#include <string.h>
#include <stdlib.h>
void swap(int num[], int start, int i) { //交换函数
	int tmp = num[start];
	num[start] = num[i];
	num[i] = tmp;
}
int cmp(const void*a, const void*b) {
	if (*(int*)a < * (int*)b)
		return -1;
	else
		return 1;
}
void fullarr(int num[], int start, int end, int n) {
	int i;
	if (start == end) {
		for (i = 1; i <= n; i++)
			printf("%d ", num[i]);
		printf("\n");
	} else {
		for (i = start; i <= end; i++) {
			swap(num, start, i);
			qsort(&num[start + 1], n - start, sizeof(int), cmp); //把固定位置之后的数都按自然序排列，之后只剩一个数就不动
			fullarr(num, start + 1, end, n);
			qsort(&num[start], n - start + 1, sizeof(int), cmp); //把固定位置和之后的数都按自然序排列，实现小数在前
		}
	}
}
int main() {
	int num[11];
	int n, i;
	scanf("%d", &n);
	for (i = 0; i <= n; i++) //数组初始化
		num[i] = i;
	fullarr(num, 1, n, n);
	return 0;
}



