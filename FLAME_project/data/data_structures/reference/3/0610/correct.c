#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h> 
#define pi 3.14159265
#define eps 1e-10

int main()
{
	char s[105];
	char num[105];
	gets(s);
	int i=0,weishu=0,k=0,fuhao=1;
	int flag=0,tmp=1;
	int lenth=strlen(s);
	for( i=0;i<lenth;i++)
	{
		if(s[i]=='.')flag=1;
		if(flag==1)weishu++;
		if(s[0]=='-')fuhao=-1;
		if(s[i]!='-'&&s[i]!='0'&&s[i]!='.')
		tmp=0;
		if(tmp==0&s[i]!='.')
		num[k++]=s[i];
		//break;
	 } //weishu--;
/*	if(s[0]=='0')
	{
		for(j=2;s[j]=='0';j++)
		{
		}
		if(j=(lenth-1))
		{
			printf("%de",s[lenth]);
		}
	}*/
//	weishu--;
	if(fuhao==-1)
	printf("-");
	for(i=0;i<k;i++)
	{
		if(i==1)
		{
			printf(".");
		}
		printf("%c",num[i]);
	}
/*	if(k==weishu)
	{
		printf("e0");
		return 0;
	}*/
	printf("e%d",k-weishu);
	return 0;	
 }

