#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#define e 2.718281
#define pi 3.14159265

char s[10005];
int i,j; 
int main()
{
	gets(s);
	int len=strlen(s);
	for(i=0;i<len;i++)
	{
		if(s[i]!='-')
		{
			printf("%c",s[i]);
		}
		else 
		{
			if(s[i-1]<='9'&&s[i-1]>='0'&&s[i+1]<='9'&&s[i+1]>='0'&&s[i-1]<s[i+1])
			{
				char c=s[i-1]+1;
				while(c<s[i+1])
				{
					printf("%c",c);
					c++;
				}
			}
			else if(s[i-1]<='z'&&s[i-1]>='a'&&s[i+1]<='z'&&s[i+1]>='a'&&s[i-1]<s[i+1])
			{
				char c=s[i-1]+1;
				while(c<s[i+1])
				{
					printf("%c",c);
					c++;
				}
			}
			else if(s[i-1]<='Z'&&s[i-1]>='A'&&s[i+1]<='Z'&&s[i+1]>='A'&&s[i-1]<s[i+1])
			{
				char c=s[i-1]+1;
				while(c<s[i+1])
				{
					printf("%c",c);
					c++;
				}
			}
			else printf("%c",s[i]);
		}
	}
	return 0;
}







