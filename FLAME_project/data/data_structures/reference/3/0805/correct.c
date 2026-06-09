#include<stdio.h>
#include<string.h>
int main()
{
	char s[100]={0};
	char *p=NULL;
	gets(s);
	p=strchr(s,'.');
	int l=strlen(s),i=0,flag=0; 
	if(p==NULL)//整数 
	{
		if(l==1)
			printf("%ce0",s[0]);
		else
		{
			printf("%c.",s[0]);
			for(i=1;i<l;i++)
				printf("%c",s[i]);
			printf("e%d",l-1);
		}
	}
	else if(p-s>1)//>10小数 
	{
		printf("%c.",s[0]);
		for(i=1;i<p-s;i++)
			printf("%c",s[i]);
		for(i=p-s+1;i<l;i++)
			printf("%c",s[i]);
		printf("e%d",p-s-1);
	}
	else if(p-s==1)//0~10小数 
	{
		if(s[0]!='0')//1~10小数 
		{
			for(i=0;i<l;i++)
				printf("%c",s[i]);
			printf("e0");
		} 
		else if(s[0]=='0')//0~1小数 
		{
			for(i=2;i<l;i++)
			{
				if(s[i]!='0')
				{
					flag=i;
					break;
				}
			}
			if(s[flag+1]=='\0') printf("%ce-%d",s[flag],flag-1);
			else
			{
				printf("%c.",s[flag]);
				for(i=flag+1;i<l;i++)
					printf("%c",s[i]);
				printf("e-%d",flag-1);
			}
		} 
	}
	return 0;
}

