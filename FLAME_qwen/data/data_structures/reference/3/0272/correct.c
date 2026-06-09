#include <stdio.h>
#include <string.h>
int main()
{
	char s[110],*fh;
	gets(s);
	int i,t,exist=0; 
	fh=strchr(s,'.');
	if(fh-s==1&&s[0]=='0')
	{
		for(i=0;i<strlen(s);i++)
		{
			if(s[i]!='0'&&s[i]!='.')
			break;
		}
		for(t=i+1;t<strlen(s);t++)
		{
			if(s[t]!='0')
			{
				exist=1;
			}
		}
		printf("%c",s[i]);
		if(exist==0)
		{
			printf("e-%d",i-1);
		 }
		else
		{
			putchar('.');
			for(t=strlen(s)-1;t>0;t--)
			{
				if(s[t]=='0'&&s[t+1]=='\0')
				{
					s[t]='\0';
				}
			}
			printf("%s",s+i+1);
			printf("e-%d",i-1);
		}
		
	}
	else if(fh-s==1&&s[0]!='0')
	{
		for(t=strlen(s)-1;t>0;t--)
			{
				if(s[t]=='0'&&s[t+1]=='\0')
				{
					s[t]='\0';
				}
			}
			printf("%s",s);
			printf("e0");
	}
	else if(fh-s>1)
	{
	    for(t=strlen(s)-1;t>0;t--)
			{
				if(s[t]=='0'&&s[t+1]=='\0')
				{
					s[t]='\0';
				}
			}
			printf("%c",s[0]);
		for(i=1;i<strlen(s);i++)
		{
			if(s[i]!='0'&&s[i]!='.')
			{
				exist=1;
			}
		}
		if(exist==0)
		{
			printf("e%d",fh-s-1);
		 }
		else
		{
			putchar('.');
			*fh='\0';
			printf("%s",s+1);
			printf("%s",fh+1);
			printf("e%d",fh-s-1);
		}
	}
	return 0;
}



