#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define ep 1e-6
#define pi 3.14159265
#define pf printf
#define sf scanf
#define ll long long
#define ull unsigned long long
#define NumberOf(x) (sizeof(x)/sizeof(x[0])
#define max(A,B) ((A)>(B)?(A):(B))

int main()
{
	char s[1000];
	scanf("%s",s);
	int n=strlen(s),i,j,x;
	for(i=0;s[i]!='.'&&i<n;i++);
	if(i==n)
	{
		if(n==1)
		{
			printf("%se0",s);
		}
		else
		{
			printf("%c",s[0]);
			s[0]='.';
			printf("%se%d",s,n-1);
		}
	}
	else
	{
		if(s[0]=='0')
		{
			for(j=i+1;s[j]=='0';j++);
			x=j;
			printf("%c",s[j]);
			if(s[j+1]!='\0')
			{
				putchar('.');
				for(j=j+1;s[j]!='\0';j++)
				{
					printf("%c",s[j]);
				}
			}
			printf("e-%d",x-1);
		}
		else
		{
			printf("%c.",s[0]);
			for(j=1;s[j]!='\0';j++)
			{
				if(s[j]!='.')
				printf("%c",s[j]);
			}
			printf("e%d",i-1);
		}
	}
}

