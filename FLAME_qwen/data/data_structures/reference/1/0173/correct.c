#include<stdio.h>
int cmp(int s[], int x);
void print(int s[], int x);
void op(int s[], int n, int x);
int main()
{
	int a[10];
	int n, flag;
	scanf("%d", &n);
	op(a, n, 1);
	return 0;
}

void op(int s[], int n, int x)
{
	for(s[x-1]=1; s[x-1]<=n; s[x-1]++)
	{
		if(cmp(s, x-1)==1) continue;
		if(n==x)
		{
			print(s, n);
			continue;
		}
		if(x+1<=n) op(s, n, x+1);
	}
}

int cmp(int s[], int x)
{
	int i;
	for(i=0; i<x; i++)
	{
		if(s[i]==s[x]) return 1;
	}
	return 0;
}

void print(int s[], int x)
{
	int i;
	for(i=0; i<x; i++) printf("%d ", s[i]);
	printf("\n");
}

