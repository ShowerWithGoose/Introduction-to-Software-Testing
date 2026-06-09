#include<stdio.h>
#include<string.h>
int main()
{
	int i,length;
	char s[300],ch;
	scanf("%s",s);
	for(i=0,length=strlen(s);i<length;i++)
	{
		if(s[i]!='-')
		printf("%c",s[i]);
		if(s[i]=='-')
		{
			if(s[i-1]>='a'&&s[i+1]<='z')
			{
				for(ch=s[i-1]+1;ch<s[i+1];ch++)
				printf("%c",ch);
			}
			
			else if(s[i-1]>='A'&&s[i+1]<='Z')
			{
				for(ch=s[i-1]+1;ch<s[i+1];ch++)
				printf("%c",ch);
			}
			else if(s[i-1]>='0'&&s[i+1]<='9')
			{
				for(ch=s[i-1]+1;ch<s[i+1];ch++)
				printf("%c",ch);
			}
			
			else
			printf("-");
		}
	}
	return 0;
}

