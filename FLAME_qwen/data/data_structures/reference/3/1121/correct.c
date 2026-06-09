#include<stdio.h>
#include<string.h>
char s[105];
int main()
{
	int i,j,k;
	gets(s);
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]=='.')
		{
			if(s[i-1]=='0'&&i==1)
			{
				for(j=i+1;s[j]=='0';j++);
				printf("%c",s[j]);
				if(j==strlen(s)-1)
				printf("e-%d",j-i);
				else
				{
					k=j;
					printf(".");
				    for(j=j+1;j<strlen(s);j++)
				    printf("%c",s[j]);
				    printf("e-%d",k-i);
				}
			}
			else if(s[i-1]!='0'&&i==1)
			{
				printf("%se0",s);
			}
			else if(i>1)
			{
				printf("%c",s[0]);
				printf(".");
				for(j=1;j<i;j++)
				printf("%c",s[j]);
				for(j=i+1;j<strlen(s);j++)
				printf("%c",s[j]);
				printf("e%d",i-1);
			}
		}
	}
	return 0;
}

