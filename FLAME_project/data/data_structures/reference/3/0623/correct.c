#include<stdio.h>
char s[105];
int main()
{
	int i,ex;
	gets(s);
	if(s[0]=='-')printf("-");
	for(i=0;s[i]!='.';i++);
	if((i==1&&s[i-1]=='0')||(i==2&&s[0]=='-'&&s[1]=='0'))
	{
		for(i++;s[i]=='0';i++);
		ex=i-1;
		if(s[i+1]=='\0')
		{
			printf("%ce-%d",s[i],ex);	
		}	
		else
		{
			printf("%c.",s[i]);
			for(i++;s[i]!='\0';i++)
			{
				printf("%c",s[i]);
			}
			printf("e-%d",ex);
		}
	}
	else 
	{
		if(s[0]=='-')
		{
			ex=i-2;
			i=1;
		}
		else
		{
			ex=i-1;
			i=0;
		}
		printf("%c.",s[i]);
		for(i++;s[i]!='.';i++) printf("%c",s[i]);
		for(i++;s[i]!='\0';i++) printf("%c",s[i]);
		printf("e%d",ex);
	}
	return 0;
}

