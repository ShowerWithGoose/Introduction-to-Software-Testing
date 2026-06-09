#include<time.h>
#include<math.h>
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#define eps 1e-5
int main()
{
	int i,j,k,l;
	char a[150];
	gets(a);
	l=strlen(a);
	for(i=0;i<l;i++)
	{
		if(a[i]!='-')
			printf("%c",a[i]);
		else 
		{
			if((a[i-1]>=97&&a[i+1]<=122)||(a[i-1]>=65&&a[i+1]<=90)||(a[i-1]>=48&&a[i+1]<=57))
			for(j=a[i-1]+1;j<a[i+1];j++)
			{
				printf("%c",j);
			}
			else 
			{
				printf("-");
			}
		}
	}
	return 0;
 } 

