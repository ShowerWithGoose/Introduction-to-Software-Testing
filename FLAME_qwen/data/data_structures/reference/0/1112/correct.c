#include<stdio.h>
#include<string.h>
int main()
{
	char s[1000];
	int i,j;
	gets(s);
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]!='-')
			printf("%c",s[i]);
		else
		{
			if((s[i-1]>='a'&&s[i+1]<='z')||(s[i-1]>='A'&&s[i+1]<='Z')||(s[i-1]>='0'&&s[i+1]<='9'))
			{
				for(j=1;s[i-1]+j!=s[i+1];j++)
				printf("%c",s[i-1]+j);
			}
			else printf("%c",s[i]);
		}
	}
	return 0;
}

