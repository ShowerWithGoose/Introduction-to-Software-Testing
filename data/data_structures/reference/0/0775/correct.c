#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
char s[1000];
int main()
{
	int i;
	char a,b;
	scanf("%s",s);
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]=='-')
		{
			if(((islower(s[i-1])&&islower(s[i+1]))||(isupper(s[i-1])&&isupper(s[i+1]))||(isdigit(s[i-1])&&isdigit(s[i+1])))&&s[i-1]<s[i+1])
			{
				for(a=s[i-1]+1,b=s[i+1];a<b;a++)
				{
					printf("%c",a);
				}
			}
			else printf("-");
		}
		else printf("%c",s[i]);
	}
	return 0;
}



