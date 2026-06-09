#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
////减法函数，len1>=len2
//void minus(char* num1, char* num2, int len1, int len2)
//{
//	char num[100];
//	for (int i = 1; i <=len2; i++)
//	{
//		if (num1[len1-i] >= num2[len2-i])num[len1-i] = num1[len1-i] - num2[len2-i]+'0';
//		else
//		{
//			num[len1-i] = num1[len1-i] - num2[len2-i] + 10 + '0';
//			int k = 1;
//			while (num1[len1-i - k] == 0) { num1[len1-i - k] = '9'; k++; }
//			num1[len1-i - k]--;
//		}
//	}
//	for (int i = 0; i < len1 - len2; i++)
//		num[i] = num1[i];
//	int i = 0;
//	while (num[i++] == '0');
//	i--;
//	for (; i < len1; i++)
//	 printf("%c", num[i]);
//}
//int main()
//{
//	//1.去零化
//	char num1[100];
//	scanf("%c", &num1[0]);
//	int i = 0,flag = 0;
//	while (num1[i] != '\n')
//	{
//		if (num1[i] == '0' && flag == 0)
//		{
//			scanf("%c", &num1[i]);
//			continue;
//		}
//		else {
//			flag = 1;
//			scanf("%c", &num1[++i]);
//		}
//	}
//	num1[i] = '\0';
//	int len = strlen(num1);
////num1
//	char num2[100];
//	scanf("%c", &num2[0]);
//	int i2 = 0, flag2 = 0;
//	while (num2[i2] != '\n')
//	{
//		if (num2[i2] == '0' && flag2 == 0)
//		{
//			scanf("%c", &num2[i2]);
//			continue;
//		}
//		else {
//			flag2 = 1;
//			scanf("%c", &num2[++i2]);
//		}
//	}
//	num2[i2] = '\0';
//	int len2 = strlen(num2);
////num2
//	//2.比大小
//	int size;
//	if (len > len2)size = 1;
//	else if (len < len2)size = -1;
//	else if (len == len2) {
//		int k;
//		for ( k = 0; k < len; k++)
//		{
//			if (num1[k] > num2[k]) 
//			{
//				size = 1; break;
//			}
//			else if (num1[k] < num2[k])
//			{
//				size = -1; break;
//			}
//		}
//		if (k == len)
//		{
//			printf("0");
//			return 0;
//		}
//	}
//	if (size == 1)
//		minus(num1, num2, len, len2);
//	else { printf("-"); minus(num2, num1, len2,len); }
//	return 0;
//}
int memory[20], flag[20] = { 0 };
void dfs(int i, int t, int n)
{
	memory[n - t] = i;//存入i
	flag[i] = 1;
	if (t == 1)
	{
		for (int k = 0; k < n; k++)
			printf("%d ", memory[k]);
		printf("\n");
		return;
	}
	for (int w = 1; w <= n; w++)
	{
		if (flag[w] == 0)
		{
			dfs(w, t - 1, n);
			flag[w] = 0;//
		}
	}
	return;
}
#include<stdio.h>
int main()
{

	int x = 0;
	scanf("%d", &x);
	for (int i = 1; i <= x; i++)
	{
		dfs(i, x, x);
		memset(flag, 0, 20);
	}
	return 0;
}
