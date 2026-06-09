#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <tgmath.h>
#include <complex.h>
#include <assert.h>
#include <stdarg.h>
#include <stdbool.h>
char s[100000]; 
int main (void)
{
	scanf("%s",s);
	int n=strlen(s);
	int i;
	for(i=0;i<n;i++)
	{
		if(i==0||i==n-1)
			printf("%c",s[i]);
		else
		{
			if(s[i]=='-')
			{
				if(s[i-1]<s[i+1])
				{
					if(s[i-1]>='a'&&s[i+1]<='z')
					{
						char c;
						for(c=s[i-1]+1;c<s[i+1];c++)
							printf("%c",c);
					}
					else if(s[i-1]>='A'&&s[i+1]<='Z')
					{
						char c;
						for(c=s[i-1]+1;c<s[i+1];c++)
							printf("%c",c);
					}
					else if(s[i-1]>='0'&&s[i+1]<='9')
					{
						char c;
						for(c=s[i-1]+1;c<s[i+1];c++)
							printf("%c",c);
					}
					else 
						printf("%c",s[i]);
					
				}
				else
					printf("%c",s[i]);	
			}
			else 
				printf("%c",s[i]);	
		}	
	} 
    return 0;
}




