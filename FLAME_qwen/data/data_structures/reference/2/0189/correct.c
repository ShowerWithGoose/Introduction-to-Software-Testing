#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int shu[1000];
char str[1000],fu[1000];
int main()
{
   int i,j=0,k=0,l;
   int shu1=0,shu2=0,temp,a;
   gets(str);
   for(i=0;i<strlen(str);i++)
   {
   	if(isdigit(str[i]))
   	{
   		shu1=shu1*10+str[i]-'0';
	   }
	else if((str[i]=='+')||(str[i]=='-')||(str[i]=='*')||(str[i]=='/')||(str[i]=='='))
	{
		fu[j]=str[i];
		shu[k]=shu1;
		shu1=0;
	    k++; 
		j++;
		l=j;
		temp=k;
	}
	else if(str[i]==' ')
	{
		continue;
	}
   }
   for(i=0;i<=l;i++)
   {
   	if(fu[i]=='*')
   	{
   		shu[i+1]=shu[i]*shu[i+1];
   		shu[i]=0;
	   }
	if(fu[i]=='/')
	{
		shu[i+1]=shu[i]/shu[i+1];
		shu[i]=0;
	}
   }
   for(i=0;i<l;i++)
   {
   	if(fu[i]=='+')
   	{
   		for(j=i+1;j<=l;j++)
   		{
   			if(fu[j]=='+'||fu[j]=='-'||fu[j]=='=')
   			{
   				shu[j]=shu[i]+shu[j];
   				break;
			   }
		   }
	   }
	if(fu[i]=='-')
   	{
   		for(j=i+1;j<l;j++)
   		{
   			if(fu[j]=='+'||fu[j]=='-'||fu[j]=='=')
   			{
   				shu[j]=shu[i]-shu[j];
   				break;
			   }
		   }
	   }
	   if(fu[i]=='=')   
	   {
	   	printf("%d",shu[i]);
	   }
   }
   return 0;
}

