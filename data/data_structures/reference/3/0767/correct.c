#include<stdio.h>
#include<string.h>
int main()
{
	char s[200];
	gets(s);
	int cnt=0;
	if(s[1]=='.'&&s[0]=='0')//指数为负数 
	{
		int i;
		for(i=2;s[i]=='0';i++)
		cnt++;
		cnt+=1;
		if(i==strlen(s)-1)
		printf("%ce-%d\n",s[i],cnt);
		else
		{
			printf("%c.",s[i++]);
			for(;i<strlen(s);i++)
			{
				printf("%c",s[i]);
			}
			printf("e-%d\n",cnt);
		}
	}
	
	else//指数大于等于0 
	{
		int i;
		for(i=1;i<strlen(s);i++)
		{
			if(s[i]=='.')
			break;
		}
		cnt=i-1;
		printf("%c.",s[0]);
		for(int i=1;i<strlen(s);i++)
		{
			if(s[i]!='.')
			printf("%c",s[i]);
		}
		printf("e%d\n",cnt);
		
	}
	
	return 0;
}

