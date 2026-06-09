#include<stdio.h>
#include<string.h>
char s[10000000];
int main()
{
	gets(s);
	int dot=-1;
	for(int i=0;i<strlen(s);i++)
	if(s[i]=='.')
	{
		dot=i;
		break;
	}
	if(dot!=-1)
	{
		if(dot==1&&s[0]=='0')
			{
				int mark;
				for(int i=dot+1;i<strlen(s);i++)
				if(s[i]!='0')
				{
					mark=i;
					break;
				}
				printf("%c",s[mark]);
				if(mark!=strlen(s)-1)
				printf(".");
				for(int i= mark+1;i<strlen(s);i++)
				printf("%c",s[i]);
				printf("e-%d",mark-1);
				return 0;
			}
		if(dot==1)
		{
			for(int i=0;i<strlen(s);i++)
					printf("%c",s[i]);
					printf("e0");	
			return 0;
		}
			printf("%c.",s[0]);
			for(int i=1;i<strlen(s);i++)
		    if(s[i]!='.')
		    printf("%c",s[i]);
		    printf("e%d",dot-1);
		    return 0;
	}
	
	printf("%c",s[0]);
	int mark=0;
	for(int i=strlen(s)-1;i>=0;i--)
	{
		if(s[i]!='0')
		{
			mark=i;
			break;
		}
	}
	if(mark>0)
	{
	printf(".");
	for(int i=1;i<=mark;i++)
	printf("%c",s[i]);
	}
	printf("e%d",strlen(s)-1);
	return 0;
	
	
	
}

