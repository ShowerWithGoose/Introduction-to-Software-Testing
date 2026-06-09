#include<stdio.h>
#include<string.h> 
int main()
{
	char s[1000];
	scanf("%s",&s);
	int t;
	for(t=0;t<strlen(s);t++)
	{
		if(s[t]!=45)
		{
			printf("%c",s[t]);
		}
		else
		{
			int prime=0;
			if(s[t-1]<s[t+1])
			{
				if(s[t-1]>=97&&s[t+1]<=122) prime=1;
				else if(s[t-1]>=65&&s[t+1]<=90) prime=1;
				else if(s[t-1]>=48&&s[t+1]<=57) prime=1;
			}
			if(prime==1)
			{
				char p=s[t-1]+1;
			    while(p<s[t+1])
			    {
				    printf("%c",p);
				    p++;
			    }
			}
			else printf("-");
		}
	}
	return 0;
}

