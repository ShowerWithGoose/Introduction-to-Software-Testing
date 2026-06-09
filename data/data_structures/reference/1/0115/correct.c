#include<stdio.h>
void Perm(int a[], int n, int s, int r[], int m)//无返回值
{
	int i, j, k, flag = 0;//循环变量
	int b[11];
	for (i = 0; i < n; i++) {
		flag = 1;
		r[s] = a[i];
		j = 0;
		for (k = 0; k < n; k++)//k是共有几个数参与全排列
			if (i != k) {
				b[j] = a[k];
				j++;
			}
		Perm(b, n - 1, s + 1, r, m);//进行从1到n-2的全排列
		//当n-1也是1时，只有一种情况->直接输出
	}
	if (flag == 0) {
	//	printf("?\n");
		for (k = 0; k < m; k++)//逐一输出一个全排列数的每一位
			printf("%d ", r[k]);//有共m位，储存在r[]里面
		printf("\n");
	}
}
int main()
{
	
	int a[11], r[11];
	int i, n;
	scanf("%d", &n);//n为数字的个数
	for (i = 0; i < n; i++)
		a[i]=i+1;//a[i]里储存所有的数字，从1到n-1的所有数
	Perm(a, n, 0, r, n);//调用全排列函数,a是已输入数组的首地址，r是准备存放数字的数组的首地址
	return 0;
}


