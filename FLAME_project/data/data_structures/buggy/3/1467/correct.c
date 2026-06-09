#include<stdio.h>
#include<string.h>

int main()
{
	char str[1000];
	gets(str);
	for (int i=0;i<strlen(str);i++)
	{
		if (str[0]=='0')
		{
			if (str[i]!='0' && str[i]!='.')
			{
				str[i-1]=str[i];
				if (str[i+1]!='\0')
				{
					str[i]='.';
				}
				else
				{
					str[i]='\0';
				}
				for (int j=i-1;j<strlen(str);j++)
				{
					printf("%c",str[j]);
				}
				printf("e-%d",i-1);	
				break;		
			}
		}
		if (str[0]!='0')
		{
			if (str[i]=='.')
			{
				for (int j=i;str[1]!='.';j--)
				{
					char mid;
					mid=str[j];
					str[j]=str[j-1];
					str[j-1]=mid;
				}
				for (int j=0;j<strlen(str);j++)
				{
					printf("%c",str[j]);
				}
				printf("e%d",i-1);
			}
		}
	}
}















