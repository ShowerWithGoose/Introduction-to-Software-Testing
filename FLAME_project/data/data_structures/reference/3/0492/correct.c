#include<string.h>
#include<stdio.h>
int main()
{
	char num[100000];
	int i,l,location,j,note;
	gets(num);
	l=strlen(num);
	if((num[0]!='0'&&num[1]=='.')||(num[0]>='1'&&num[0]<='9'&&num[1]=='.'))
	{
		printf("%se0",num);
		return 0;
	}
	else if(num[0]=='0')
	{
		for(i=0;i<l;i++)
		{
			if(num[i]!='0'&&num[i]!='.')
			{
				location=i;
				break;
			}
		}
		if(location==l-1)
		{
			printf("%ce-%d",num[location],location-1);
		}
		else
		{
			printf("%c.",num[location]);
			for(j=location+1;j<l;j++)
			{
				printf("%c",num[j]);
			}
			printf("e-%d",location-1);	
		}
	}
	else
	{
		for(i=0;i<l;i++)
		{
			if(num[i]=='.')
			{
				note=i;
				break;
			}
		}
		printf("%c.",num[0]);
		for(i=1;i<l&&num[i]!='.';i++)
		{
			printf("%c",num[i]);
		}
		for(i=i+1;i<l;i++)
		{
			printf("%c",num[i]); 
		}
		printf("e%d",note-1);
	}
	return 0;
 } 

