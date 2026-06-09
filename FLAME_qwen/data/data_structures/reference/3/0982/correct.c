#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>	

int main()
{
	char s[200];
	int i,j,n,e;
	gets(s);
	n=strlen(s);
	if(n==1)
	{
		puts(s);
		return 0;
	}
	if(s[0]=='0')
	{
		for(i=0;s[i]=='0'||s[i]=='.';i++);
		e=-(i-1);
		if(i!=n-1)
		{
			s[i-1]=s[i];
			s[i]='.';
			for(j=i-1;j<n;j++)
				printf("%c",s[j]);
		}
		else
			for(j=i;j<n;j++)
				printf("%c",s[j]);
		printf("e%d",e);	
	}
	else
	{
		for(i=0;s[i]!='.';i++);
		e=i-1;
		printf("%c.",s[0]);
		for(i=1;i<n;i++)
		{
			if(s[i]!='.')
				printf("%c",s[i]);
		}
		printf("e%d",e);
	}
	return 0;
}

