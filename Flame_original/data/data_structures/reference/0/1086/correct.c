#include<stdio.h>
#include<string.h>
int main()
{
	int i,k;
	char s[110];
	scanf("%s",&s);
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]!='-')
		{
			printf("%c",s[i]);
		} 
		else
		{
			if((s[i-1]>=48&&s[i-1]<=57)&&(s[i+1]>=48&&s[i+1]<=57)&&(s[i-1]<s[i+1]))
			{
				for(k=s[i-1]+1;k<s[i+1];k++)
				{
					printf("%c",k);
				}
			}
			else if((s[i-1]>=65&&s[i-1]<=90)&&(s[i+1]>=65&&s[i+1]<=90)&&(s[i-1]<s[i+1]))
			{
				for(k=s[i-1]+1;k<s[i+1];k++)
				{
					printf("%c",k);
				}
			}
			else if((s[i-1]>=97&&s[i-1]<=122)&&(s[i+1]>=97&&s[i+1]<=122)&&(s[i-1]<s[i+1]))
			{
				for(k=s[i-1]+1;k<s[i+1];k++)
				{
					printf("%c",k);
				}
			}
			else
			{
				printf("-");
			}
		}
	}
	return 0;
}

