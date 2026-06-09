#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#define MAXN 100000 
typedef long long LL;
char N[MAXN];
int p1, p2, digit, len; 
int GetDigit(char *N, int len)
{
	int flag = 0;
	for(int i = 0; i < len; i ++)
	{
		if(N[i] != '0' && N[i] != '.' && flag == 0 )
		{
			p1 = i;
			flag = 1;
		} 
		if(N[i] == '.') p2 = i;
	}
	return p2 - p1 - 1;
}
void PutNum(char* N)
{
	int i = 0;
	int flag = 0;
	digit = GetDigit(N, len);
	for(i = 0; i < len; i ++)
		if(N[i] != '0' && N[i] != '.')
		{
			printf("%d", N[i] - '0');
			break;
		}
	if(i != len - 1) 
		printf(".");
	if(N[0] == '0')digit ++;
	for(i ++; i < len; i ++)
		if(N[i] != '.')
			printf("%d", N[i] - '0');
	printf("e%d", digit);
}
int main()
{
	int digit;
	gets(N);
	len = strlen(N);
	PutNum(N);
	return 0;
}
