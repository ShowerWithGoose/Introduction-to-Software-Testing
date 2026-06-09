#include<stdio.h>
int cmp(int s[], int n);
void print(int s[], int n);
void op(int s[], int x, int n);
int main()
{
	int a[10];
	int x, flag;
	scanf("%d", &x);
	op(a, x, 1);
	return 0;
}

void op(int s[], int x, int n)
{
	for(s[n-1]=1; s[n-1]<=x; s[n-1]++)
	{
		if(cmp(s, n-1)==1) continue;
		if(x==n)
		{
			print(s, x);
			continue;
		}
		if(n+1<=x) op(s, x, n+1);
	}
}

int cmp(int s[], int n)
{
	int i;
	for(i=0; i<n; i++)
	{
		if(s[i]==s[n]) return 1;
	}
	return 0;
}

void print(int s[], int n)
{
	int i;
	for(i=0; i<n; i++) printf("%d ", s[i]);
	printf("\n");
}

