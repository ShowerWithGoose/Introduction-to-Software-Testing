#include<stdio.h>
#include<string.h>
int main()
{
	char ch[192608],ltr;
	int i;
	gets(ch);
	for(i=0;i<strlen(ch);i++)
	{
		if(ch[i]=='-'&&'a'<=ch[i-1]&&'z'>=ch[i+1]&&ch[i+1]>ch[i-1])
		{
			for(ltr=ch[i-1]+1;ltr<ch[i+1];ltr++)
			{
				printf("%c",ltr);
			}
			i++;
		}
		if(ch[i]=='-'&&'A'<=ch[i-1]&&'Z'>=ch[i+1]&&ch[i+1]>ch[i-1])
		{
			for(ltr=ch[i-1]+1;ltr<ch[i+1];ltr++)
			{
				printf("%c",ltr);
			}
			i++;
		}
		if(ch[i]=='-'&&'0'<=ch[i-1]&&'9'>=ch[i+1]&&ch[i+1]>ch[i-1])
		{
			for(ltr=ch[i-1]+1;ltr<ch[i+1];ltr++)
			{
				printf("%c",ltr);
			}
			i++;
		}
		printf("%c",ch[i]);
	}
	return 0;
	
}

