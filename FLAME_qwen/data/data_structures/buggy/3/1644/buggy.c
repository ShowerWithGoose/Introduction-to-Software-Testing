#include<stdio.h>
#include<string.h>

int main()
{
	char s[200];
	scanf("%s",s);
	
	int i,k,t=0,m;
	for(i=0;i<(strlen(s));i++)
	{
		if(s[i]=='.')
		{
			k=i;
		}
		if(s[i]=='0')
		{
			t++;
		}
		else 
		{
			t=0;
		}
	}
	if(k>1||(k==1&& s[0]!='0'))
	{
		printf("%c",s[0]);
		printf(".");
		
		for(i=1;i<strlen(s)-t;i++)
		{
			if(i==k)
			continue;
			else
			printf("%c",s[i]);
		}
		printf("e%d",k-1);
	}
	else if(k=1)
	{
		for(i=1;i<strlen(s);i++)
		{
			if(s[i]!='0'&&s[i]!='.')
			{
				m=i-1;
				break;
			}
		}
		printf("%c",s[m+1]);
		if(strlen(s)==t+m+2)
		{
			printf("e-%d",m);
		}
		else
		{
			printf(".");
			for(i=m+2;i<strlen(s)-t;i++)
			{
				printf("%c",s[i]);
			}
		}
	}
	return 0;
}
	


