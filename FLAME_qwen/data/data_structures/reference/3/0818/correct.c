#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h> 

int main()
{
	char putin[110]={0},putout[110]={0};
	int i,j,locdp,loc0,flag0=0,lenth,flagdp=0;
	scanf("%s",putin);
	lenth=strlen(putin);
	if(putin[0]=='0')
	{
		flag0=1;
		for(i=2;putin[i]=='0';i++);
		loc0=i-1;
	}
	for(i=0;putin[i]!='\0';i++)
	{
		if(putin[i]=='.')
		{
			locdp=i;
			flagdp=1;
		}
	}
	if(putin[0]!='0'&&flagdp==1)
	{	
		putout[0]=putin[0];
		putout[1]='.';
		for(i=2,j=1;j<lenth;j++,i++)
		{
			if(putin[j]=='.')
				j++;
			putout[i]=putin[j];
		} 
		for(i=lenth-1;(putout[i]=='0'||putout[i]==0||putout[i]=='\0')&&i>0;i--)
		{
			putout[i]='\0';
		}
	}
	if(putin[0]=='0'&&flagdp==1)
	{	
		putout[0]=putin[loc0+1];
		putout[1]='.';
		for(i=2,j=loc0+2;j<lenth;j++,i++)
		{
			putout[i]=putin[j];
		} 
		for(i=lenth;(putout[i]=='0'||putout[i]==0||putout[i]=='\0'||putout[i]=='.')&&i>0;i--)
		{
			putout[i]='\0';
		}
	}
	if(flagdp==0)
	{
		putout[0]=putin[0];
		putout[1]='.';
		for(i=2,j=1;j<lenth;j++,i++)
		{
			putout[i]=putin[j];
		} 
		for(i=lenth;(putout[i]=='0'||putout[i]==0||putout[i]=='\0')&&i>0;i--)
		{
			putout[i]='\0';
		}		
	}
	if(putin[0]=='0')
	printf("%se-%d",putout,loc0);
	else
	printf("%se%d",putout,locdp-1);
} 

