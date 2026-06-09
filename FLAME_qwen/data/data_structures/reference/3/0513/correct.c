#include<stdio.h>
#include<string.h>
int main()
{
	char s[200];
	gets(s);
	if(s[0]=='0')
	{
		int i=2,cnt=1;
		while(s[i]=='0')	
		{
		    cnt++;
		    i++;
		}
		printf("%c",s[i]);
		i++;
		if(s[i]=='\0')
		{
			printf("e-%d",cnt);
		}
		else
		{
			printf(".");
			while(s[i]!='\0')
			{
				printf("%c",s[i]);
				i++;
			}
			printf("e-%d",cnt);
		}
	}
	else if(s[0]!='0')
	{
		int cnt=0,i=0;
		i++;
		printf("%c.",s[0]);
		while(s[i]!='.')
		{
			cnt++;
			i++;
		}
		i=1;
		while(s[i]!='\0')
		{
			if(s[i]!='.')
			{
				printf("%c",s[i]);
			}
			i++;
		}
		printf("e%d",cnt);
	}
	return 0;
}


