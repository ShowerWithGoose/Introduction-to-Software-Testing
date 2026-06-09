#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#define ll long long
char s[110];
int main()
{
	scanf("%s",s);
	int len=strlen(s),j=-1,i;
	for(i=0;i<len;i++)
	{
		if(s[i]=='.')
		{
			j=i;
			break;
		}
	}
	if(s[0]=='0')
	{
		for(i=2;i<len;i++)
		{
			if(s[i]!='0')
			{
				j=i;
				break;
			}
		}
		printf("%c",s[j]);
		if(s[j+1]=='\0') ;
		else 
		{
			printf(".");
			for(i=j+1;i<len;i++) printf("%c",s[i]);
		}
		printf("e-%d",j-1);
	}
	else
	{
		printf("%c.",s[0]);
		for(i=1;i<len;i++) 
		{
			if(s[i]!='.') printf("%c",s[i]);
			else j=i;
		}
		printf("e%d",j-1);
	} 
	return 0;	
}

