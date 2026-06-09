#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#define e 2.718281
#define pi 3.14159265

char c[105];
int a[100],b[100]; 
int main()
{
	int i,j,k,flag=0,sum=0;
	gets(c);
	for(i=0,j=0,k=0;c[i]!='\0';i++)
	{
		if(c[i]=='.')flag=1;
		else 
		{
			if(flag==0)a[j++]=c[i]-'0';
			else b[k++]=c[i]-'0';
		}
	}
	if(c[0]=='0')
	{
		for(i=2;c[i]=='0';i++);
		if(c[i+1]=='\0')printf("%ce%d",c[i],-i+1);
		else
		{
			printf("%c.",c[i]);
			j=i;
			for(i++;c[i]!='\0';i++)printf("%c",c[i]);
			printf("e%d",-j+1);
		}
		
	}
	else 
	{
		printf("%c.",c[0]);
		for(i=1;c[i]!='\0';i++)
		{
			if(c[i]!='.')printf("%c",c[i]);
		}
		printf("e%d",j-1);
	}
	return 0;
}



