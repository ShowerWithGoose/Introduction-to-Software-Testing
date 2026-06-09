#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
int main()
{
	int i,j,q=0,l,f=1,s;
	char a[100],b[100];
	gets(a);
	l=strlen(a);
	if(a[0]=='0')
	{
		for(i=1;i<l;i++)
		{
			if(a[i]=='0')
				f=f+1;
			if(a[i]>'0'&&a[i]<='9')
			{
				s=a[i]-'0';
				break;
			}
	    }
		if(f+2<l)
		{
			printf("%d.",s);
			for(i=f+2;i<l;i++)
				printf("%c",a[i]);
			printf("e-%d",f);
		}
		if(f+2==l)
			printf("%de-%d",s,f);
		}
	else
	{
		if(a[1]=='.')
			printf("%se0",a);
		else
		{
			for(i=0;i<l;i++)
			{
				if(a[i]=='.')
					break;
				else
					q=q+1;
			}
			printf("%c.",a[0]);
			for(i=1;i<l;i++)
			{
				if(a[i]!='.')
					printf("%c",a[i]);
			}
			printf("e%d",q-1);
		}
		
	} 
	return 0;
}




