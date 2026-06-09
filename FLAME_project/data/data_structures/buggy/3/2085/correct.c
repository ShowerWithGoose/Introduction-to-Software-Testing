#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h> 
#define eps 1e-6 
char c[1000];

int main() {
	gets(c);
	int s=strlen(c);int flag;
	for(int i=0;i<s;i++)
	{
		if(c[i]=='.') 
		{
			flag=i;break;
		}
	}
	if(flag!=1) 
	{
		for(int i=0;i<s;i++)
		{
			if(i==1) printf(".%c",c[i]);
			else if (c[i]!='.')printf("%c",c[i]);
		}
		printf("e%d",flag-1);
    }	 
	else
	{
		if(c[0]!='0') 
		{
			printf("%se0",c);	
		}
		else
		{
			int count=0;
			for(int i=0;i<s;i++)
			{
				if(c[i]=='0') count++;
				else if(c[i]>='1'&&c[i]<='9')
				{
					flag=i;break;
				}
			}
			printf("%c",c[flag]);
			if(flag!=s-1)
			{
				printf(".");
				for(int i=flag+1;i<s;i++)
				{
					printf("%c",c[i]);
				}	
				printf("e-%d",count);
			}
				
			else printf("e-%d",count);
		}
	}
	
return 0;
}


