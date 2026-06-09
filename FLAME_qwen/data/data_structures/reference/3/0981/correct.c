#include<stdio.h>
#include<string.h>
int main()
{
	char s[100];
	char *p=NULL;
	int i,l;
	gets(s);
	p=strchr(s,'.');
	if(p==NULL)
	{
		if(strlen(s)==1)
			printf("%ce0",s[0]);
		else
		{
			printf("%c.",s[0]);
			for(i=1;i<(int)strlen(s);i++)
				printf("%c",s[i]);
			printf("e%d",(int)strlen(s)-1);
		}
	}
	else if(p-s==1)
	{
		if(s[0]=='0')
		{
			for(i=2;i<(int)strlen(s);i++)
				if(s[i]!='0')
				{
					l=i;
					break;
				}
			if(l==(int)strlen(s)-1)
			{
				printf("%c",s[l]);
				printf("e-%d",l-1);
			}
			else
			{
				printf("%c.",s[l]);
				for(i=l+1;s[i]!='\0';i++)
					printf("%c",s[i]);
				printf("e-%d",l-1);
			}
		}
		else
		{
			for(i=0;i<(int)strlen(s);i++)
				printf("%c",s[i]);
			printf("e0");
		}
	}
	else
	{
		l=p-s;
		printf("%c.",s[0]);
		for(i=1;i<p-s;i++)
			printf("%c",s[i]);
		for(i=p-s+1;i<(int)strlen(s);i++)
			printf("%c",s[i]);
		printf("e%d",l-1);
	}
	return 0;
}

