#include <stdio.h>
#include <math.h>
#define MAX 10
//排列串
char s[MAX + 1];
//标记
int mark[MAX + 1];
int m;
void permutate(char[], int[], int, int);
int main()
{
	scanf("%d", &m);
	permutate(s, mark, m, 1);
	return 0;
}
void permutate(char s[], int mark[], int m, int depth)
{
	int i;
	// case : 终点
	if (depth==m+1)
	{
		for(int i=1;i<=m;i++)
		{
		printf("%c ",s[i]);
			
		}
		printf("\n");
		return ;
	}
	for (i = 1; i <= m; i++)
	{
		if (mark[i] == 0)
		{
			mark[i] = 1;					  //标记该数字,下面中不能含有该数字
			s[depth] = i + '0';					  //将当前数字加到该深度全排列字符串中
			permutate(s, mark, m , depth+1); //加深搜索
			mark[i] = 0;					  //删除标记数字
		}
	}
}



