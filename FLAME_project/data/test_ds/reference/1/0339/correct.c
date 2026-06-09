#include<stdio.h>
#include<string.h>
char s[1000];
int main()
{
	gets(s);
	int i;
	for(i=0;i<100000;i++)
	{
		if(s[i]=='\0')
		break;
		if(s[i]!='-')
		printf("%c",s[i]);
		else
		{
			if(s[i-1]<s[i+1])
			{
				if(s[i-1]<='9'&&s[i-1]>='0'&&s[i+1]<='9'&&s[i+1]>='0')
				{
					int j;
					for(j=1;j<(s[i+1]-s[i-1]);j++)
					printf("%c",s[i-1]+j);
				}
				else if(s[i-1]<='z'&&s[i-1]>='a'&&s[i+1]<='z'&&s[i+1]>='a')
				{
					int j;
					for(j=1;j<(s[i+1]-s[i-1]);j++)
					printf("%c",s[i-1]+j);
				}
				else if(s[i-1]<='Z'&&s[i-1]>='A'&&s[i+1]<='Z'&&s[i+1]>='A')
				{
					int j;
					for(j=1;j<(s[i+1]-s[i-1]);j++)
					printf("%c",s[i-1]+j);
				}
				else
				printf("%c",s[i]);
			}
			else
			printf("%c",s[i]);
		}
	}
	return 0;
}

