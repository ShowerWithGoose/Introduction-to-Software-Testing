#include<stdio.h>
int main()
{
	char s[10000]={};
	char ch;
	gets(s);
	for(int i=0;s[i]!='\0';i++)
	{
		if(s[i]=='-')
		{
			if(s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='a'&&s[i+1]<='z'&&s[i+1]>s[i-1])
			{
				for(ch=s[i-1]+1;ch<s[i+1];ch++)
					printf("%c",ch);
			}
			else if(s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]>='A'&&s[i+1]<='Z'&&s[i+1]>s[i-1])
			{
				for(ch=s[i-1]+1;ch<s[i+1];ch++)
					printf("%c",ch);
			}
			else if(s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]>='0'&&s[i+1]<='9'&&s[i+1]>s[i-1])
			{
				for(ch=s[i-1]+1;ch<s[i+1];ch++)
					printf("%c",ch);
			}
			else
				printf("%c",s[i]);
		}
		else
			printf("%c",s[i]);
	}
	return 0;
}



