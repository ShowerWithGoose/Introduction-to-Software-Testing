#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>

#define MAXLINE 1024
#define eps 1e-15

int N1, N2;//项的个数 
char c1[MAXLINE], c2[MAXLINE];
char C1_a[1000][1000], C1_b[1000][1000];
char C2_a[1000][1000], C2_b[1000][1000];

struct Num{
	int a;
	int b;
	int x;//最后求和时合并 
}num1[1000], num2[1000], outcome[1000000];

void getnum();

int cmp (const void*x,const void*y)
{
	return (*(struct Num *)x).b < (*(struct Num *)y).b ? 1 : -1;
}

int main(){
	getnum();
	
	int n;
	
	for(int i=0;i<N1;i++)
	for(int j=0;j<N2;j++,n++)
	{
		outcome[n].a = num1[i].a * num2[j].a;
		outcome[n].b = num1[i].b + num2[j].b;	
	}
	
	qsort(outcome, n, sizeof(outcome[0]), cmp);
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(outcome[i].x == 1)
				continue;
				
			if(outcome[i].b == outcome[j].b)
			{
				outcome[j].x = 1;
				outcome[i].a += outcome[j].a;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(outcome[i].x == 1)
			continue;
		printf("%d %d ", outcome[i].a, outcome[i].b); 
	}
	return 0;
}
void getnum()
{
	gets(c1);
	gets(c2);

	int n1 = 0, n2 = 0; 
	for(int i=0,j=0;i<strlen(c1);i++)
	{
		if(c1[i] == ' ')
		{
			if(n1 % 2 != 0)
				N1 ++;
			n1++;
			j = 0;
			continue;
		}
		else
		{
			if(n1 % 2 == 0)
				C1_a[N1][j++] = c1[i];
			else
				C1_b[N1][j++] = c1[i];
		}
	}
	for(int i=0,j=0;i<strlen(c2);i++)
	{
		if(c2[i] == ' ')
		{
			if(n2 % 2 != 0)
				N2 ++;
			n2++;
			j = 0;
			continue;
		}
		else
		{
			if(n2 % 2 == 0)
				C2_a[N2][j++] = c2[i];
			else
				C2_b[N2][j++] = c2[i];
		}
	}
	N1++;N2++;
	for(int i=0;i<N1;i++)
	{
		for(int j=strlen(C1_a[i])-1,k = 1;j >= 0;k *= 10,j--)
			num1[i].a += (k * (C1_a[i][j] - 48) );
		for(int j=strlen(C1_b[i])-1,k = 1;j >= 0;k *= 10,j--)
			num1[i].b += (k * (C1_b[i][j] - 48) );
	}
	for(int i=0;i<N2;i++)
	{
		for(int j=strlen(C2_a[i])-1,k = 1;j >= 0;k *= 10,j--)
			num2[i].a += (k * (C2_a[i][j] - 48) );
		for(int j=strlen(C2_b[i])-1,k = 1;j >= 0;k *= 10,j--)
			num2[i].b += (k * (C2_b[i][j] - 48) );
	}	
}

