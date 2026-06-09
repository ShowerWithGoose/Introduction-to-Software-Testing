#include<stdio.h>
#include<string.h>
char c[1001001];
int len,i,num,st;
int main()
{
	scanf("%s",c);
	len=strlen(c);
	if(c[i]=='-')printf("-"),st++;
	if(c[st]=='0')
	{
		num=1;
		for(i=st+2;i<len;i++)
		{
			if(c[i]!='0')break;
			num++;
		}
		if(i==len-1)printf("%ce-%d",c[i],num);
		else printf("%c.%se-%d",c[i],c+i+1,num);
	}
	else
	{
		printf("%c",c[st]);
		if(st+1!=len)printf(".");
		int t=1;
		for(i=st+1;i<len;i++)
		{
			if(c[i]=='.')t=0;
			else printf("%c",c[i]);
			if(t)num++;
		}
		printf("e%d",num);
	}
}

//367298599999093453490394859509568659795603.4

