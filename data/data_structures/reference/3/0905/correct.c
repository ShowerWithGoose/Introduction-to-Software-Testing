#include<stdio.h>
#include<string.h>
int main()
{	
	char s[101];
	gets(s);
	int i;
	int count;
	if(s[0]=='0')
	{	count=0;
		for(i=2;i<strlen(s);i++)
		{
			if(s[i]=='0')count++;
			else break;
		}
		printf("%c",s[i]);
		if(i!=strlen(s)-1)printf(".");
		for(i=i+1;i<strlen(s);i++)
		{
			printf("%c",s[i]);
			
		}
		printf("e-");
		printf("%d",count+1);
	}
	else 
	{	count=0;
		printf("%c",s[0]);
		printf(".");
		for(i=0;i<strlen(s);i++)
		{
			if(s[i]!='.')count++;
			else break;
		}
		for(i=1;i<strlen(s);i++)
		{
			if(s[i]!='.')printf("%c",s[i]);
		}
		printf("e");
		printf("%d",count-1);
	}
	return 0;
}
