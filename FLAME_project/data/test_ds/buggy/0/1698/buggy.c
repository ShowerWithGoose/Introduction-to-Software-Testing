#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h> 

int main()
{
	char s[1000000];
	gets(s);
	int i,j,t,len;
	len=strlen(s);
	for(i=0;i<len;i++)
	{
		if(s[i]==45)
		{
			j=s[i+1]-s[i-1];
			if(s[i-1]>=48&&s[i+1]<=57&&s[i-1]<s[i+1])
			{
				for(t=1;t<j;t++)
				printf("%c",s[i-1]+t); 
			}
			else if(s[i-1]>=65&&s[i+1]<=90&&s[i-1]<s[i+1])
			{
				for(t=1;t<j;t++)
				printf("%c",s[i-1]+t);
			}
			else if(s[i-1]>=97&&s[i+1]<=122&&s[i-1]<s[i+1])
			{
				for(t=1;t<j;t++)
				printf("%c",s[i-1]+t);
			}	
		}
		else
		printf("%c",s[i]);
	}
	return 0;
}

