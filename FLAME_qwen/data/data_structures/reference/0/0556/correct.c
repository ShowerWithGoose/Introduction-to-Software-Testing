#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#define ll long long
#define ull unsigned long long

int main()
{
	char s[200];
	gets(s);
	char a;
	int len=strlen(s);
	for(int i=0;i<len;i++)
	{
		if(s[i]=='-')
		{
			if(s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='a'&&s[i+1]<='z'&&s[i+1]>s[i-1])
			{
				for(a=s[i-1]+1;a<s[i+1];a++)
					printf("%c",a);
			}
			
			else if(s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]>='A'&&s[i+1]<='Z'&&s[i+1]>s[i-1])
			{
				for(a=s[i-1]+1;a<s[i+1];a++)
					printf("%c",a);
			}
			
			else if(s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]>='0'&&s[i+1]<='9'&&s[i+1]>s[i-1])
			{
				for(a=s[i-1]+1;a<s[i+1];a++)
					printf("%c",a);
			}
			else
				printf("%c",s[i]);
		}
		else
			printf("%c",s[i]);
	}
	return 0;
}




