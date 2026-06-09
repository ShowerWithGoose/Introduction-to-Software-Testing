#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define eps 1e-8

int main() {
	char s[1000],sum0=1,p[1000],k=0,flag=0;
	int i=0;
	gets(s);
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]=='.')
		break;
	}
	if(i==strlen(s))
	printf("%se0",s);
	else
	{
		if(s[0]=='0')
		{
			for(i=2;i<strlen(s);i++)
			{
				if(s[i]=='0'&&flag==0)
				sum0++;	
				else
				{
					flag=1;
					p[k]=s[i];
					k++;
				}
			}	
			printf("%c",p[0]);
			for(i=1;i<strlen(p);i++)
			{
				if(i==1)
				printf(".%c",p[i]);
				else
				printf("%c",p[i]);
			}
			printf("e-%d",sum0);
		}	
		else
		{
			sum0=0;
			for(i=1;i<strlen(s);i++)
			{
				if(s[i]=='.')
				{
					for(i;i<strlen(s)-1;i++)
					{
						s[i]=s[i+1];
					}
					s[i]='\0';
				}
				else
				sum0++;
			}
			printf("%c.",s[0]);
			for(i=1;i<strlen(s);i++)
			{
				printf("%c",s[i]);
			}
				printf("e%d",sum0);
			
		}
	} 
	return 0;
}


