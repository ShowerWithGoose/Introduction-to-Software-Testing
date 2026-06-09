#include <stdio.h>
#include <math.h>
#include <string.h>
char s[50005], s1[50005];
int sign[10005],number[10005],lm=0,ls=0;
void num(char s[])
{
	int len = strlen(s),count=0,i=0;
	while (i < len)
	{
		if (isdigit(s[i]))
		{
			count = 10 * count + s[i] - '0';
		}
		else {
			switch (s[i])
			{
			case '+':sign[ls++] = 1; break;
			case '-':sign[ls++] = 2; break;
			case '*':sign[ls++] = 3; break;
			case '/':sign[ls++] = 4; break;
			case '=':sign[ls++] = -1; break;
			}
			number[lm++] = count;
			count = 0;
		}
		i++;
	}
}
void delete(int s[], int i,int l)
{
	int k;
	for (k = i; k < l; k++)
		s[k] = s[k + 1];
}
int main()
{
	int t = 0,i;
	gets(s);
	for (i = 0; i < strlen(s); i++)
	{
		if (s[i] == ' ')continue;
		s1[t++] = s[i];
	}
	num(s1);
	for (i = 0; i < ls; i++)
	{
		if (sign[i] == 3)
		{
			 
			number[i + 1]= number[i] * number[i + 1];
			delete(sign, i, ls);
			delete(number, i, lm);
			i--;
		}
		else if (sign[i] == 4)
		{
			number[i + 1] = number[i] / number[i + 1];
			delete(sign, i, ls);
			delete(number, i, lm);
			i--;
		}
		
	}
//	for (i = 0; i < ls; i++)
//		printf("%d ", sign[i]);
	int flag=0;
	i=0;
	while (sign[i] != -1)
	{
		if (sign[i] == 1)number[i + 1] = number[i] + number[i + 1];
		else if (sign[i] == 2)number[i + 1] = number[i] - number[i + 1];
		i++;
	}
	for (i = ls - 1; i >= 0; i--)
	{
		if (number[i] != 0) {
			printf("%d", number[i]);
			flag = 1;
			break;
		}
	}
	if (flag == 0)printf("0");
	return 0;
}

