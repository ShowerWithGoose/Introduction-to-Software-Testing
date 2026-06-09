#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <limits.h>

char s[10000000];

int main(int argc, const char * argv[])
{
	int i;
	gets(s);
	int len=strlen(s);
	
	for(i=0;i<len;i++)
	{
		if(s[i+1]=='\0'||i==0)
		{
			printf("%c", s[i]);
		}
		else
		{
			if(s[i]=='-')
			{
				if(s[i-1]>='0'&&s[i+1]>='0'&&s[i+1]<='9'&&s[i-1]<='9')
				
				{
					if(s[i-1]<s[i+1])
					{
					
						while(s[i-1]<s[i+1]-1)
						{
							s[i-1]++;
							printf("%c",s[i-1]);
						}
					}
					else if(s[i-1]==s[i+1]);
					else 
					{
						printf("%c",s[i]);
					}
				}
				else if(s[i-1]>='a'&&s[i+1]>='a'&&s[i+1]<='z'&&s[i-1]<='z')
				{
					if(s[i-1]<s[i+1])
					{
					
						while(s[i-1]<s[i+1]-1)
						{
							s[i-1]++;
							printf("%c",s[i-1]);
						}
					}
					else if(s[i-1]==s[i+1]);
					else 
					{
						printf("%c",s[i]);
					}
				}
				else if(s[i-1]>='A'&&s[i+1]>='A'&&s[i+1]<='Z'&&s[i-1]<='Z')
				{
					if(s[i-1]<s[i+1])
					{
					
						while(s[i-1]<s[i+1]-1)
						{
							s[i-1]++;
							printf("%c",s[i-1]);
						}
					}
					else if(s[i-1]==s[i+1]);
					else 
					{
						printf("%c",s[i]);
					}
				}
				else 
				{
					printf("%c",s[i]);
				}
			}
			else
			{
				printf("%c",s[i]);
			}
		}
	}
	return 0;
}



