#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	char a[100];
	int len,zf,i,len1;
	gets(a);
	if(a[0]=='0')
	{
		for(i=0;a[i+2]=='0';i++);
		len1=i;
		for(i+=2;a[i]!='\0';i++)
		len=i-len+2;
		printf("%c",a[len1+2]);
		if(a[len1+3]!='\0')
		printf(".");
		for(i=len1+3;a[i]!='\0';i++)
		printf("%c",a[i]);
		if(len!=0)
		printf("e-%d",len1+1);
		return 0;
	}
	else
	{
		for(i=0;a[i]!='.'&&a[i]!='\0';i++);
		len=i;
		for(i=0;a[i]!='\0';i++);
		len1=i-1;
		for(i=len1;a[i]==0;i--)
		a[i]='\0';		
		printf("%c.",a[0]);
		for(i=1;a[i]!='\0';i++)
		{
			if(a[i]=='.')
			continue;
			printf("%c",a[i]);
		}
		printf("e%d",len-1);
		return 0;
	}
}

