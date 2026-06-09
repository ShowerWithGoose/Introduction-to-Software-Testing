#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define PI 3.14159265
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
char inp[1005];
int main()
{
	int len,i,j,k=0,we=0;
	gets(inp);
	len=strlen(inp);
	for(i=0;i<len;i++)
	{
		if(inp[i]=='.')
		break;
		else
		{
			k*=10;
			we++;
			k+=inp[i]-'0';
		}
	}
	if(k!=0)
	{
		printf("%c.",inp[0]);
		for(i=1;i<len;i++)
		{
			if(inp[i]!='.')
			{
				printf("%c",inp[i]);
			}
		}
		printf("e%d",we-1);
	}
	if(k==0)
	{
		we=0;
		for(i=2;i<len;i++)
		{
			if(inp[i]=='0')
			we++;
			else
			{
				printf("%c",inp[i]);
				if(i!=len-1)
				printf(".");
				j=i+1;
				break;
			}
		}
		for(i=j;i<len;i++)
		{
			printf("%c",inp[i]);
		}
		printf("e-%d",we+1);
	}
	return 0;
}

