#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define eps 1e-6
#define EMP struct employee
char buf[BUFSIZ];
 
int main()
{
	int i,m;
	char s[120];
	gets(s);
	if(s[0]=='0')
	{
		if(strlen(s)==3)
		{
			printf("%ce-1",s[2]);
			return 0;
		}
		for(i=2;s[i]!='\0';i++)
		{
			if(s[i]!='0')
			{
				m=i-1;
				break;
			}
		}
		printf("%c.",s[m+1]);
		for(i=m+2;s[i]!='\0';i++)
		{
			printf("%c",s[i]);
		}
		printf("e-%d\n",m);
	}
	else
	{
		printf("%c.",s[0]);
		for(i=1;;i++)
		{
			if(s[i]!='.')
			{
				printf("%c",s[i]);
			}
			else
			{
				m=i;
				break;
			}
			
		}
		for(i=m+1;s[i]!='\0';i++)
		{
			printf("%c",s[i]);
		}
		printf("e%d",m-1);
		
	}
	
	return 0;
}





