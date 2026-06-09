#include<stdio.h>
#include<string.h>
char s[10000];
int main()
{
	scanf("%s",&s);
	int len=strlen(s);
	int i,j,k;
	for(i=0;i<len;i++)
	{
		if(s[i]=='-')
		{
			if(s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='a'&&s[i+1]<='z'&&s[i+1]>s[i-1])
			{
				int m=s[i+1]-s[i-1];
				for(j=0;j<m-1;j++)
				{
					printf("%c",s[i-1]+j+1);
				}
			}
			else if(s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]>='A'&&s[i+1]<='Z'&&s[i+1]>s[i-1])
			{
				int m=s[i+1]-s[i-1];
				for(j=0;j<m-1;j++)
				{
					printf("%c",s[i-1]+j+1);
				}
			}
			else if(s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]>='0'&&s[i+1]<='9'&&s[i+1]>s[i-1])
			{
				int m=s[i+1]-s[i-1];
				for(j=0;j<m-1;j++)
				{
					printf("%c",s[i-1]+j+1);
				}
			}
			else
			printf("%c",s[i]);
		}
		else
		printf("%c",s[i]);
	}
}



