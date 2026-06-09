#include <stdio.h>
#include <string.h>
int main()
{
	char s[100];
	int i=0,j,len;
	gets(s);
	len=strlen(s);
	while(s[len-1]=='0')
		{
			len--;
		}
	while(s[i]!='.'&&s[i]!='\0')
		{
			i++;
		}
	if((i==1&&len==1) || (i==1&&len==2) )
		{
			printf("%ce0",s[0]);
		}
	else
	{
		if(s[0]=='0')
		{
			i=2;
			while(s[i]=='0')
			{
				i++;
			}
			if(len-1-i==0)
				printf("%c",s[i]);
			else{
			printf("%c.",s[i]);
			for(j=i+1;j<len;j++)
			{
				printf("%c",s[j]);
			}}
			printf("e-%d",i-1);
		}
		else{
		printf("%c.",s[0]);
		for(j=1;j<i;j++)
		{
			printf("%c",s[j]);
		}
		for(j=i+1;j<len;j++)
		{
			printf("%c",s[j]);
		}
		printf("e%d",i-1);
	    }
	}
		return 0;
}

