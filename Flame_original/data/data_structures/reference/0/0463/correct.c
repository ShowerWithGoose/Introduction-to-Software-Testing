#include<stdio.h>
int main()
{
	char s[1000],t;
	int i,j;
	gets(s);
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]=='-')
		{
			if(('0'<=s[i-1]&&s[i+1]<='9'&&s[i-1]<s[i+1])||('a'<=s[i-1]&&s[i+1]<='z'&&s[i-1]<s[i+1])||('A'<=s[i-1]&&s[i+1]<='Z'&&s[i-1]<s[i+1]))
			{
				for(t=s[i-1]+1;t<s[i+1];t++)
				{
					printf("%c",t);
				}
			}
			else
				printf("%c",s[i]);
		}
		else
			printf("%c",s[i]);
	}
	return 0;
}

