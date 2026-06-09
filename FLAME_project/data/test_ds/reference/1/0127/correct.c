#include <stdio.h>
#include <string.h>
int main()
{
	char s[15226];
	gets(s);
	for(int i=0;i<strlen(s);i++)
	{
		if(s[i]=='-'&&s[i-1]<s[i+1]&&((s[i-1]>='a'&&s[i+1]<='z')||(s[i-1]>='A'&&s[i+1]<='Z')||(s[i-1]>='0'&&s[i+1]<='9')))
		{
			for(int j=1;j<=s[i+1]-s[i-1];j++)
			{
				printf("%c",s[i-1]+j);
			}
			i=i+1;
		}
		else
		{
			printf("%c",s[i]);
		}
	}
	return 0;
}

