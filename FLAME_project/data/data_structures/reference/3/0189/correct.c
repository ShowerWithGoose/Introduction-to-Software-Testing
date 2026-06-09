#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	char str[1000];
	scanf("%s",&str);
	int l=strlen(str);
	int i=0;
	int dian=0;
	for(i=0;i<l;i++)
	{
		if(str[i]=='.')
		{
			dian=i;
		}
	}
	if(dian==0)
	{
		printf("%c",str[0]);
		printf(".");
		for(i=1;i<l;i++)
		{
			printf("%c",str[i]);
		}
		printf("e");
		printf("%d",l-1);
	}
	if(str[0]=='0'&&str[1]=='.')
	{
	    int flag=0;
		for(i=2;i<l;i++)
		{
			if (str[i]!='0')
			{
				flag=i;
				break;	
			}
		}
		if(flag==l-1)
	    {
	    	printf("%c",str[l-1]);
	    	printf("e-%d",l-2);
		}
	    if(flag!=l-1)
	    {
		  printf("%c.",str[flag]);
		for(i=flag+1;i<l&&str[i]!='\0';i++)
		{
			printf("%c",str[i]);
		}
		printf("e-");
		printf("%d",flag-1);
	}
}
		
		
	if(str[0]!='0'&&str[1]!='.'&&dian!=0)
	{
		printf("%c",str[0]);
		printf(".");
	for(i=1;i<dian;i++)
		{
			printf("%c",str[i]);	
		}
	for(i=dian+1;i<l&&str[i]!='\0';i++)
		{
			printf("%c",str[i]);
		}
		printf("e");
		printf("%d",dian-1);
		}
	
	if(str[0]!='0'&&str[1]=='.')
	{
		printf("%s",str);
		printf("e0");
	}
	return 0;
}

