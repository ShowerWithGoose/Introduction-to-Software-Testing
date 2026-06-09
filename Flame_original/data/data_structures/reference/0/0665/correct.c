#include <stdio.h>
#include <string.h>
int main()
{
	char s[500];
	gets(s);
	int i,j,k,l;
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]!='-')
		printf("%c",s[i]);
		else if(s[i]=='-')
		{
			if(s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='a'&&s[i+1]<='z'&&s[i-1]<s[i+1]||s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]>='A'&&s[i+1]<='Z'&&s[i-1]<s[i+1]||(s[i-1]-'0')>=0&&(s[i-1]-'0')<=9&&(s[i+1]-'0')>=0&&(s[i+1]-'0')<=9&&s[i-1]<s[i+1])
			{
				k=s[i-1]-'0';
				l=s[i+1]-'0'-1;
				for(j=k;j<l;j++)
				{
					printf("%c",j+1+'0');
				}
			}
			else printf("-");
			
		}
	}
	return 0;
}

