#include<stdio.h>
#include<string.h> 
int main()
{
	char s[1000];
	scanf("%s",&s);
	int i;
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]!=45)
		{
			printf("%c",s[i]);
		}
		else
		{
			int prime=0;
			if(s[i-1]<s[i+1])
			{
				if(s[i-1]>=97&&s[i+1]<=122) prime=1;
				else if(s[i-1]>=65&&s[i+1]<=90) prime=1;
				else if(s[i-1]>=48&&s[i+1]<=57) prime=1;
			}
			if(prime==1)
			{
				char t=s[i-1]+1;
			    while(t<s[i+1])
			    {
				    printf("%c",t);
				    t++;
			    }
			}
			else printf("-");
		}
	}
	return 0;
}

