#include <stdio.h>
#include <string.h>
char s[100];
int main()
{
	int i=0,flag=0;
	gets(s);
	if(s[i]=='+')
	i++;
	if(s[i]=='-')
	{
		printf("-");
		i++;
	}
	if(s[i]!='0')
	{
		printf("%c.",s[i]);
		i++;
		while(s[i]!='.')
		{
			printf("%c",s[i]);
			flag++;
			i++;
		}
		i++;
		while(s[i]!='\0')
		{
			printf("%c",s[i]);
			i++;
		}
		printf("e%d",flag);
	}
	else
	{
		i+=2;
		flag++;
		while(s[i]=='0')
		{
			flag++;
			i++;
		}
		printf("%c",s[i]);
		i++;
		if(s[i]!='\0')
		printf(".");
		while(s[i]!='\0')
		{
			printf("%c",s[i]);
			i++;
		}
		printf("e-%d",flag);
	}
	
	return 0;
	
}

