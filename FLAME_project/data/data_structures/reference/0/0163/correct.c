#include <stdio.h>
#include <string.h>
int main()
{
	int n,i=0,k;
	char s[1000];
	scanf("%s",&s);
	for(i=0;i<=strlen(s)-1;i++)
	{
		if(s[i]!='-') printf("%c",s[i]);
		else
		{
			if(s[i-1]>='a'&&s[i+1]<='z')
			{
				for(k=1;s[i-1]+k<s[i+1];k++)
				printf("%c",s[i-1]+k);
			}
			else if(s[i-1]>='A'&&s[i+1]<='Z')
			{
				for(k=1;s[i-1]+k<s[i+1];k++)
				printf("%c",s[i-1]+k);
			}
			else if(s[i-1]>='0'&&s[i+1]<='9')
			{
				for(k=1;s[i-1]+k<s[i+1];k++)
				printf("%c",s[i-1]+k);
			}
			else printf("-");
		}
	}
	return 0;
} 

