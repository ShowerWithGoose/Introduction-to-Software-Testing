#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>






int a[50] = {}, mark[20] = {}; //a存全排列，mark存标记：是否已经排好

void fullarray(int step, int n) {
	//收尾条件：所有数都已经排好
	if (step > n) {
		for (int i = 1; i < n + 1; i++)
			printf("%d ", a[i]);
		printf("\n");
		return;
	}

	//递归代码
	for (int i = 1; i <= n; i++) { //从小的数开始排
		if (mark[i] == 0) {
			a[step] = i;
			mark[i] = 1;
			fullarray(step + 1, n);
			mark[i] = 0;
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	fullarray(1, n);

	return 0;
}
//che清零



