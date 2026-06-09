#include<stdio.h>
#include<string.h>
int main()
{
	char s[100];
	gets(s);
	int i,l;
	if(s[0]=='0')
	{
		for(i=2;s[i]=='0';i++);
		if(i==strlen(s)-1)
		printf("%ce-%d",s[i],i-1);
		else
		{
			printf("%c.",s[i]);
			l=i;
			for(i++;s[i]!='\0';i++)
			printf("%c",s[i]);
			printf("e-%d",l-1) ;
		}
	}
	else
	{
		for(i=0;s[i]!='.';i++);
		l=i;
		printf("%c.",s[0]);
		for(i=1;s[i]!='\0';i++)
		if(s[i]!='.')
		printf("%c",s[i]);
		printf("e%d",l-1);
	}
	return 0;
}

