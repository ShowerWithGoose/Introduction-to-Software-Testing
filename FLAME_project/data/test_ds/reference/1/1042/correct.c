#include<stdio.h>
#include<string.h>
int main()
{
	int i=0,j=0;
	char s[100];
	scanf("%s",s);
	for(i=0;i<strlen(s);i++)
	{
		if((s[i]=='-')&&i!=0)
		{
			if((s[i-1]>=65&&s[i+1]<=90&&s[i-1]<s[i+1])||(s[i-1]>=97&&s[i+1]<=122&&s[i-1]<s[i+1])||(s[i-1]>=48&&s[i+1]<=57&&s[i-1]<s[i+1]))
			{
				for(j=1;j<s[i+1]-s[i-1];j++)
					printf("%c",s[i-1]+j);
			}
			else printf("-");
		}
		else printf("%c",s[i]);
	}
 	return 0;
}


