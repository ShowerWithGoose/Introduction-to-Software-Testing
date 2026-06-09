#include<stdio.h>
#include<string.h>
int main()
{
	char s[1000];
	gets(s);
	int count;
	int len=strlen(s);
	int m;
	int i;
	for( i=0;i<len;i++)
	{
		if(s[i]=='.')
			m=i;
	}
	if (m!=1)
	{
		count=m-1;
		printf("%c.",s[0]);
		for(int k=1;k<len;k++)
		{
			if(k!=m)
				printf("%c",s[k]);
		}
		printf("e%d",count);
	}
	else if(s[0]!='0')
	{
		for(int k=0;k<len;k++)
		{
			printf("%c",s[k]);
		}
		printf("e0");
	}
	else
	{
		for(int k=2;k<len;k++)
		{
			if(s[k]!='0')
			{
				count=k;
				break;
			}
		}
		printf("%c",s[count]);
		if(count!=len-1)
			printf(".");
		for(int k=count+1;k<len;k++)
		{
			printf("%c",s[k]);
		}
		printf("e%d",-count+1);
	}
}

