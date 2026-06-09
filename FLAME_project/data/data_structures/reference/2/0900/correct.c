#include<stdio.h>
#include<string.h>
char a[100], cal[100];
int num[100];
int main()
{	
	int i, j, k = 0, l = 0, everynum = 0;
	gets(a);
	for(i = 0, j = 0; i <= strlen(a) - 1; i++)
	{
		if(a[i] != ' ')
		{
			a[j] = a[i];
			j++;
		}
		else if(a[i] == ' ')
		{
			;
		}
	}
//	for(i = 0; i <= j-1; i++)printf("%c", a[i]);//j-1为删除空格后地长度 
//	printf("\n");
	for( i = 0; i<= j-1; i++)
	{
		
		if(a[i] >= '0' && a[i] <= '9')
		{
			everynum = 10 * everynum + (a[i] - 48);//注意这里不是自加 
			num[l] = everynum;
		}
		else if(a[i] == '+'||a[i] == '-'||a[i] == '*'||a[i] == '/'||a[i] == '=')
		{
			cal[k] = a[i];
			k++;
			everynum = 0;
			l++;
		}
	}
	//for(int i = 0; i <= k-1; i++)printf("%c ", cal[i]);
	//for(int i = 0; i <= l-1; i++)printf("%d ", num[i]);
	int m, n, p = 0, q = 0, nummark[100] = {0}, calmark[100] = {0}, result = 0;
	int resultnum[100];
	for(m = 0; m <= k - 1; m++)
	{
		if(cal[m] == '+' || cal[m] == '-' || cal[m] == '=')
		{	
			resultnum[p] = num[m];
			p++;
		}
		else if(cal[m] == '*')
		{
			nummark[m] = 1;
			num[m+1] = num[m] * num[m+1];
		}
		else if(cal[m] == '/')
		{
			nummark[m] = 1;
			num[m+1] = num[m] / num[m+1];
		}
		else if(cal[m] == '=')
		{
			break;
		}
		
	}
//	for(int i = 0; i <= k-1; i++)printf("%d ", num[i]);//确认乘法和除法计算后地有效性 
//for(int i = 0; i <= p-1; i++)printf("%d", resultnum[i]);//确认去除乘除符号地运算结果 
//printf("\n");
for(i = 0; i <= k-1; i++)                              //去除加减法 
{
	if(cal[i] == '*' || cal[i] == '/')
	{
		continue;
	}
	else if(cal[i] == '+' || cal[i] == '-' || cal[i] == '=')
	{
		cal[q] = cal[i];
		q++;
	}
}
//printf("%d\n", q);
for(i = 0; i <= q-1; i++)
{	
	if(i == 0)result += resultnum[i];
	 if(cal[i] == '+')
	{
		result+=resultnum[i+1];
	}
	 if(cal[i] == '-')
	{
		result-=resultnum[i+1];
	}
}
printf("%d", result);

	return 0;
}

