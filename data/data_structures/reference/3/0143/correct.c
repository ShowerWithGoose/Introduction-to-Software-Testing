#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <limits.h>
int main(int argc, const char * argv[])
{
	int count=0;
	int i,j;
	int len;
	int p=0,flag=0;
	char s[100000];
	char s1[100000];
	gets(s);
	len=strlen(s);
	if(s[0]!='0')
	{
		for(i=0;i<len;i++)
		{
			if(s[i]=='.')
			{
				p=i;
				break;
			}
			else count++;	
		}
		for(i=1;i<p;i++)
		{
			j=i-1;
			s1[j]=s[i];
		}
		for(i=p+1;i<len;i++)
		{
			j=i-2;
			s1[j]=s[i];
		}
		
		printf("%c.%se%d",s[0],s1,count-1);
		
	}
	else
	{
		
		for(i=2;i<len;i++)
		{
			if(s[i]!='0')
			{
				p=i;
				break;
			}
			else count++;
		}	
		len-=3;
		if(count==len)
		{
			printf("%ce-%d",s[p],count+1);
		}
		else
		{
			len+=3;
			for(i=p+1;i<len;i++)
			{
				j=i-count-3;
				s1[j]=s[i];
			}
			printf("%c.%se-%d",s[p],s1,count+1);
		}
	}
	return 0;
 } 

