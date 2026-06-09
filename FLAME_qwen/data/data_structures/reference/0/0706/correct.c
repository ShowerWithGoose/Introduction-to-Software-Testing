#include<stdio.h>
#include<string.h>
char s[10000008];
int main()
{
	int c;
	scanf("%s",s);
	long long l=strlen(s);
	int i,flag=0;
	for(i=0;i<l;i++)
	{
		if(s[i]!='-'||i==l-1)
		printf("%c",s[i]);
		else
		{
			if(s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]>='0'&&s[i+1]<='9'&&s[i]<s[i+1])
			{
				for(c=1;s[i-1]+c<s[i+1];c++)
				printf("%c",s[i-1]+c);
			}
			else if(s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='a'&&s[i+1]<='z'&&s[i]<s[i+1])
			{
				for(c=1;s[i-1]+c<s[i+1];c++)
				printf("%c",s[i-1]+c);
			}
			else if(s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]>='A'&&s[i+1]<='Z'&&s[i]<s[i+1])
			{
				for(c=1;s[i-1]+c<s[i+1];c++)
				printf("%c",s[i-1]+c);
			}
			else
			printf("-");
		}
	}
	return 0;
}




