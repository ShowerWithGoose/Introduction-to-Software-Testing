#include<stdio.h>
#include<string.h>
#include<ctype.h>

int test(char a)
{
	if(isdigit(a)>0) return 1;
	if(islower(a)>0) return 2;
	if(isupper(a)>0) return 3;
	return 0;
}

int main()
{
	char s[100]={};
	gets(s);
	int i;
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]=='-')
		{
			if(test(s[i-1])==test(s[i+1]))
			{
				int m;
				for(m=s[i-1]+1;m<s[i+1];m++)
				putchar(m);
			}
			else printf("-");
		}
		else putchar(s[i]);
	}
	return 0;
 } 

