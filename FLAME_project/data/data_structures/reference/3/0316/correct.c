#include <stdio.h>
#include <string.h>
int main()
{	int i=0;
	int point=0;
	int key=0;
	char s[10000];
	int count=0;
	scanf("%s",s);
	for(i=1;i<strlen(s);i++)
		{
			if(s[i]=='.')
			point=i;//小数点的位置 
					}
	if(s[0]!='0'&&point!=0)
	{	
		printf("%c.",s[0]);
		for(i=1;i<strlen(s);i++)
		{
			if(s[i]!='.')
			printf("%c",s[i]);
			else
			point=i;//小数点的位置 
			
		}
			printf("e%d",point-1);	
	}
	if(s[0]!='0'&&point==0)
	{
		for(i=0;i<strlen(s);i++)
		printf("%c",s[i]);
		printf("e0");
	}
	if(s[0]=='0')
	{
		for(i=2;i<strlen(s);i++)
		{	
			if(s[i]!='0'&&i!=strlen(s)-1&&key!=-1)
			{
				key=-1;
				printf("%c.",s[i]);
				count=1-i;
				i++;
			}
			if(s[i]!='0'&&key!=-1)
			{	
				if(i==strlen(s)-1)
				{
				count=1-i;
				printf("%ce%d",s[i],count);
				}
			}
			if(key==-1)
			{	
				printf("%c",s[i]);
				if(i==strlen(s)-1)
				{
					printf("e%d",count);
				 } 
			}			
		}
		
	 } 

	
	return 0;
 } 

