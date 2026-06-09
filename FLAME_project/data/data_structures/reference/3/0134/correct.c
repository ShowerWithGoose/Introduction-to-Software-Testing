#include<stdio.h>

char c[100];
int i=0,ii;

int main()
{
	gets(c);
	while(c[i]!='.')
	{
		i++;
	}
	if(i==1&&c[0]=='0')
	{
		
		while(c[i+1]=='0')
		{
			i++;
		}
		ii=i;//0个数 
		putchar(c[i+1]);
		if(c[i+2]!='\0')
		printf(".");
		while(c[i+2]!='\0')
		{
			putchar(c[i+2]);
			i++;
		}
		printf("e-%d",ii);
	}
	else
	{
		ii=i;//.之前的数的个数 
		putchar(c[0]);
		printf(".");
		i=1;
		while(c[i]!='.')
		{
			putchar(c[i]);i++; 
		}
		i++;
		while(c[i]!='\0')
		{
			putchar(c[i]);i++;
		}
		printf("e%d",ii-1);
	}
 } 

