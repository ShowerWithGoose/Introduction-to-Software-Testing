#include <stdio.h>
#include <string.h>
int main()
{
	char s[100];
	int i, len, k, x;
	gets(s);
	len=strlen(s);
	for(i=0;i<len;i++)
	{
		if(s[i]=='-')
		{
			if(s[i-1]<='9'&&s[i-1]>='0')
			{
				if(s[i+1]<='9'&&s[i+1]>='0')
				{
					if(s[i-1]<s[i+1])
					{
						x=s[i+1]-s[i-1];
					
						for(k=1;k<x;k++)
						{
							printf("%c", s[i-1]+k);
						}
						i=i+1;
					}
				}
			}
				if(s[i-1]<='z'&&s[i-1]>='a')
			{
				if(s[i+1]<='z'&&s[i+1]>='a')
				{
					
					if(s[i-1]<s[i+1])
					{
						x=s[i+1]-s[i-1];
					
						for(k=1;k<x;k++)
						{
							printf("%c", s[i-1]+k);
						}
						i=i+1;
					}
				}
			}
				if(s[i-1]<='Z'&&s[i-1]>='A')
			{
				if(s[i+1]<='Z'&&s[i+1]>='A')
				{
					if(s[i-1]<s[i+1])
					{
						x=s[i+1]-s[i-1];
					
						for(k=1;k<x;k++)
						{
							printf("%c", s[i-1]+k);
						}
						i=i+1;
					}
				}
			}
		}
		printf("%c", s[i]);
	}
	
	return 0;
 } 



