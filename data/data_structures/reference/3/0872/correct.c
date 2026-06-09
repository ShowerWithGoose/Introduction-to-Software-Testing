#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h> 
#include <stdlib.h> 
#define llo long long
#define pn printf("\n") 

char sign;
char a[200];
char  b[200];
char buf[200];
int main()
{
	int i=0,j=0;
	int flag=0;
	gets(a);
	int len=strlen(a);
	int I,I0;
	int cnt=1;
	if(a[0]=='0')
	{
		sign='-';
		for(i=0;i<len;i++)
		{
			if(a[i]!='0'&&a[i]!='.'&&cnt)
			{
				cnt--;
				I0=i-1;
			}
			if(cnt==0)
			{	
				b[j++]=a[i];
			} 
			
		}
		if(strlen(b)==1)
		{
			printf("%c",b[0]);
		}
		else
		{
			printf("%c.",b[0]);
			
			printf("%s",b+1);
		}
		printf("e-");
		printf("%d",I0);
		return 0;
	}
	
	
	
	for(i=0;i<len;i++)
	{
		
		if(a[i]!='.')
		{
			b[j++]=a[i];
		}
		
	}
	if(strchr(a,'.')==NULL)
	{
		I=len-1;
		
	}	
	else
	I=strchr(a,'.')-a-1;
	sprintf(buf,"%c.%s",b[0],b+1);
	int lenbuf=strlen(buf);
	
	for(i=lenbuf;i>=0;i--)
	{
		if(buf[i]!='0')
		flag=1;
		if(buf[i]=='0'&&!flag)
		{
			buf[i]='\0';
		}
		
		
	}
	if(buf[2]=='\0')
	buf[1]='\0';
	printf(buf);
	printf("e%d",I);
	return 0;
} 

