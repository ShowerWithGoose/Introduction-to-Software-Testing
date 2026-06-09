#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char ch[1000];
int main()
{
	int i = 0, j = 0;
	int cnt = -1;
	char s[100];
	gets(s);
	int len = strlen(s);
	while(i<len)
	{
		if(s[i]!='-')
			ch[++cnt]=s[i],i++;
		else
		{
			if(i==0 || i==len-1)
				ch[++cnt]=s[i],i++;
			else if(s[i-1]>='a' && s[i-1] <= 'z' && s[i+1] >= 'a' && s[i+1] <= 'z' && s[i-1]<s[i+1])
			{
				char k=s[i-1]+1;
				for(;k<=s[i+1];k++)
				{
					ch[++cnt]=k;
				}
				i=i+2;
			}
			else if(s[i-1]>='A' && s[i-1] <= 'Z' && s[i+1] >= 'A' && s[i+1] <= 'Z' && s[i-1]<s[i+1])
			{
				char k=s[i-1]+1;
				for(;k<=s[i+1];k++)
				{
					ch[++cnt]=k;
				}
				i=i+2;
			}
			else if(s[i-1]>='0' && s[i-1] <= '9' && s[i+1] >= '0' && s[i+1] <= '9' && s[i-1]<s[i+1])
			{
				char k=s[i-1]+1;
				for(;k<=s[i+1];k++)
				{
					ch[++cnt]=k;
				}
				i=i+2;
			}
			else
			{
				ch[++cnt]=s[i];
				i++;
			}
		}
	}
	ch[cnt+1]='\0';
	puts(ch);
	return 0;
 } 

