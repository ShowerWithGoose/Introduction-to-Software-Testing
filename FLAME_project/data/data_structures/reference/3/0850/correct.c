#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main()
{
	char ch[101];
	fgets(ch,101,stdin);int i,time;
	if(ch[0]=='0')
	{
		
		//printf("%d\n",strlen(ch));
		for(i=0;i<strlen(ch)-2;i++)
		{
			if(ch[1+i]!='0'&&ch[1+i]!='.')
			{
				printf("%c",ch[i+1]);break;
			}
			
		}time=i;//printf("%d\n",i);
		if(i!=strlen(ch)-3)
		{
			printf(".");
			for(i++;i<strlen(ch)-2;i++)
				{
				printf("%c",ch[1+i]);
				}
		}
		printf("e-");
		printf("%d",time);	
	}
	else
	{
		char *place=strchr(ch,'.');
		time= place-ch;
		printf("%c.",ch[0]);
		for(i=0;i<strlen(ch)-2;i++)
		{
			if(ch[1+i]!='.')
			{
				printf("%c",ch[i+1]);
		}
		
		}	
		printf("e");
		printf("%d",time-1);
	return 0;
	}
} 
//0.000000000000002
/*	int length=strlen(ch)-2;
	char *place=strchr(ch,'.');
	int i;
	for(i=0;i<strlen(ch)-1;i++)
	{
		if(ch[i]!='0'&&ch[i]!='.')
		{
		printf("%c",ch[i]);break;}
	}
	if(i!=length)
	{
	printf(".");
	for(i++;i<length+1;i++)
	{
		printf("%c",ch[i]);
	}}
	printf("e");
	if(ch[0]=='0')
	printf("-");
	printf("%",length-(int)(place-ch));*/

