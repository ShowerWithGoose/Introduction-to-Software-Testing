#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int N, i, j;
int zhongjianzhi[11];
int jieguo[10];

int matrix()
{
	zhongjianzhi[0] = 1;
	int i;
	for (i = 1; i < 10; i++) {
		zhongjianzhi[i] = i * zhongjianzhi[i - 1];
	}
}

void daying()
{
	int i = 0;
	for (i = 0; i < N - 1; i++)
		printf("%d ", jieguo[i]);
	printf("%d\n", jieguo[i]);
}

void find() {
	for (i = N - 2; i >= 0; i--)
	{
		if (jieguo[i] < jieguo[i + 1])
			break;
	}
	int k1 = i;
	int temp_low = i + 1;
	for (i = k1 + 1; i < N; i++)
	{
		if (jieguo[i] > jieguo[k1] && jieguo[i] < jieguo[temp_low])
			temp_low = i;
	}
	int temp;
	temp = jieguo[k1];
	jieguo[k1] = jieguo[temp_low];
	jieguo[temp_low] = temp;
	for (j = k1 + 1, i = N - 1; i > j; i--, j++)
	{
		temp = jieguo[i];
		jieguo[i] = jieguo[j];
		jieguo[j] = temp;
	}
}

int main()
{
	matrix();
	scanf("%d", &N);
	int i;
	for (i = 0; i < N; i++)
	{
		jieguo[i] = i + 1;
	}
	daying();
	for (i = 1; i < zhongjianzhi[N]; i++)
	{
		find();
		daying();
	}
}



