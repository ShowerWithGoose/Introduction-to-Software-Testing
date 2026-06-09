#include<stdio.h>
#include<string.h>
char a[101], b;
int main()
{
	gets(a);
	int n, l=0, k, j;
	n=strlen(a)-1;
	if(a[0]!='0')
	{
		while(a[l]!='.')
		{
			l=l+1;
		}
		k=l-1;
		while(a[n]=='0')
		{
			n=n-1;
		}
		j=n;
		printf("%c.", a[0]);
		l=1;
		while(l<=j)
		{
			if(a[l]!='.')
			{
				printf("%c", a[l]);
			l=l+1;
			}
			else
			{
				l=l+1;
			}
		}
		printf("e%d", k);
	}
	if(a[0]=='0')
	{
		l=2;
		while(a[l]=='0')
		{
			l=l+1;
		}
		k=l-1;
		while(a[n]=='0')
		{
			n=n-1;
		}
		j=n;
		if(l==j)
		{
			printf("%c", a[l]);
		}
		else
		{
			printf("%c.", a[l]);
		l=l+1;
		while(l<=j)
		{
			printf("%c", a[l]);
			l=l+1;
		}
		}
		printf("e-%d", k);
	}
	return 0;
}

