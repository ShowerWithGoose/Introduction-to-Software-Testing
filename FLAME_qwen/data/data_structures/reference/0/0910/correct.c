#include<stdio.h>
#include<string.h>
int main()
{
	char s[1000];
	gets(s);
	int a;
	for(a=0;s[a+2]!='\0';a++)
	{
		printf("%c",s[a]);
		if(s[a+1]=='-')
		{
			if(s[a]>='a'&&s[a+2]<='z'&&s[a+2]>s[a])
			{char b;
				for(b=s[a]+1;b<s[a+2];b++)
				printf("%c",b);
				a=a+1;
			}
			if(s[a]>='0'&&s[a+2]<='9'&&s[a+2]>s[a])
			{char b;
				for(b=s[a]+1;b<s[a+2];b++)
				printf("%c",b);
				a=a+1;
			}
			if(s[a]>='A'&&s[a+2]<='Z'&&s[a+2]>s[a])
			{char b;
				for(b=s[a]+1;b<s[a+2];b++)
				printf("%c",b);
				a=a+1;
			}
		}
	}
	printf("%c%c",s[a],s[a+1]);
	return 0;
}




