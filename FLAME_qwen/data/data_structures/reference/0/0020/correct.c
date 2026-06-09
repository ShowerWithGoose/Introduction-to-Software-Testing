#include<stdio.h>
#include<string.h>
int main()
{
	char ch[100];
	char a;
	int i;
	scanf("%s",ch);
	for(i=0;i<strlen(ch);i++)
	{
		if(ch[i]=='-')
		{
			if(ch[i-1]>='a'&&ch[i-1]<='z'&&ch[i+1]>='a'&&ch[i+1]<='z'&&ch[i+1]>ch[i-1])
			{
				for(a=ch[i-1]+1;a<ch[i+1];a++)
				{
					printf("%c",a);
				}
			}
			else if(ch[i-1]>='A'&&ch[i-1]<='Z'&&ch[i+1]>='A'&&ch[i+1]<='Z'&&ch[i+1]>ch[i-1])
			{
				for(a=ch[i-1]+1;a<ch[i+1];a++)
				{
					printf("%c",a);
				}
			}
			else if(ch[i-1]>='0'&&ch[i-1]<='9'&&ch[i+1]>='0'&&ch[i+1]<='9'&&ch[i+1]>ch[i-1])
			{
				for(a=ch[i-1]+1;a<ch[i+1];a++)
				{
					printf("%c",a);
				}
			}
			else
			{
				printf("%c",ch[i]);
			}
		}
		else
		{
			printf("%c",ch[i]);
		}
	}
	
	return 0;
}

