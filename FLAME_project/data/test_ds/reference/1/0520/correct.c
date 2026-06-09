#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
char s[10000];

int main()
{
	gets(s);
	
	int n=strlen(s);
	
	int i;
	
	for(i=0;i<n;i++)
	{
		if(s[i]=='-')
		{
			if((s[i-1]>='0'&&s[i+1]<='9'&&s[i+1]>s[i-1])||(s[i-1]>='a'&&s[i+1]<='z'&&s[i+1]>s[i-1])||(s[i-1]>='A'&&s[i+1]<='Z'&&s[i+1]>s[i-1]))
			{
				for(int j=s[i-1]+1;j<s[i+1];j++)
				{
					printf("%c",j);
				}
			}
			else
			printf("-");
		}
		else
		{
			printf("%c",s[i]);
		}
	}
	
	
	
	
	return 0;
 } 



