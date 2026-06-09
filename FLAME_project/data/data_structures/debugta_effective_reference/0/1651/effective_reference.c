#include<stdio.h>
#include<string.h>
int main()
{
	char s[110];
	scanf("%s",&s);
	int a=strlen(s);
	for(int i=0;i<a;i++)
	{
		if(s[i]>='a'&&s[i]<='z'&&s[i+1]=='-'&&s[i+2]>='a'&&s[i+2]<='z'&&s[i]<s[i+2])
		{
			for(char j=s[i];j<s[i+2];j++)
			printf("%c",j);
			i++;
		}
		else if(s[i]>='A'&&s[i]<='Z'&&s[i+1]=='-'&&s[i+2]>='A'&&s[i+2]<='Z'&&s[i]<s[i+2])
		{
			for(char j=s[i];j<s[i+2];j++)
			printf("%c",j);
			i++;
		}
		else if(s[i]>='0'&&s[i]<='9'&&s[i+1]=='-'&&s[i+2]>='0'&&s[i+2]<='9'&&s[i]<s[i+2])
		{
			for(char j=s[i];j<s[i+2];j++)
			printf("%c",j);
			i++;
		}
		else printf("%c",s[i]);
	}
	return 0;
}



