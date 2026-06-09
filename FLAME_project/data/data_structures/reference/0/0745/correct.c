#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#define M 1000005
#define ll long long
#define ull unsigned long long
char s[202];
int  main()
{
	gets(s);
//	printf("%d",strlen(s));
	for(int i=0;i<strlen(s);i++)
	{
		if(s[i]!='-') printf("%c",s[i]);
		else
		{
			if(('a'<=s[i-1])&&(s[i-1]<='z'))
		{
			if(('a'<=s[i+1])&&(s[i+1]<='z')&&(s[i+1]>s[i-1]-1))
			for(int j=1;j<=s[i+1]-s[i-1]-1;j++)
			{
				printf("%c",s[i-1]+j);
			}
			else printf("%c",s[i]);
		}
		else if(('A'<=s[i-1])&&(s[i-1]<='Z'))
		{
			if(('A'<=s[i+1])&&(s[i+1]<='Z')&&(s[i+1]>s[i-1]-1))
			for(int j=1;j<=s[i+1]-s[i-1]-1;j++)
			{
				printf("%c",s[i-1]+j);
			}
			else printf("%c",s[i]);
		}
		else if(('0'<=s[i-1])&&(s[i-1]<='9'))
		{
			if(('0'<=s[i+1])&&(s[i+1]<='9')&&(s[i+1]>s[i-1]-1))
			for(int j=1;j<=s[i+1]-s[i-1]-1;j++)
			{
				printf("%c",s[i-1]+j);
			}
			else printf("%c",s[i]);
		}
		else printf("%c",s[i]);
		}
	}
	return 0;
}





