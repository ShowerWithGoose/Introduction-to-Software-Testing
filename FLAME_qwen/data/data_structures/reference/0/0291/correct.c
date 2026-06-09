#include<stdio.h>
#include<string.h>
int main()
{
	char str[1000];
	int i=0;
	gets(str);
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]!='-')
			printf("%c",str[i]);
		else
		{
			if(str[i-1]>='0'&&str[i-1]<='9'&&str[i+1]>='0'&&str[i+1]<='9'&&str[i-1]<str[i+1])
			{
				while(str[i-1]<str[i+1]-1)
				{
					str[i-1]++;
					printf("%c",str[i-1]);
				}
			}
			else if(str[i-1]>='a'&&str[i-1]<='z'&&str[i+1]>='a'&&str[i+1]<='z'&&str[i-1]<str[i+1])
			{
				while(str[i-1]<str[i+1]-1)
				{
					str[i-1]++;
					printf("%c",str[i-1]);
				}
			}
			else if(str[i-1]>='A'&&str[i-1]<='Z'&&str[i+1]>='A'&&str[i+1]<='Z'&&str[i-1]<str[i+1])
			{
				while(str[i-1]<str[i+1]-1)
				{
					str[i-1]++;
					printf("%c",str[i-1]);
				}
			}
			else
				printf("%c",str[i]);
		}
	}
	return 0;
 } 

