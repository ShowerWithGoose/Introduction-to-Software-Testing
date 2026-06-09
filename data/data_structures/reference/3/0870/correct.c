#include<stdio.h>
#include<string.h>
int main()
{
	char s[150];
	int i,j,k,h=1000,flag=1,dot,start=0,num=0;
	gets(s);
	int len=strlen(s);
	for(i=0;i<len;i++)
		{
			if(s[i]=='.')dot=i;
			if(s[i]!='0'&&h==1000&&s[i]!='.')start=i;
			if(s[i]<='9'&&s[i]>='1'&&flag)k=s[i]-'0',h=i,flag=0;
			if(s[i]<='9'&&s[i]>='1')num++;
		}
	if(num==1)
	{
		printf("%de%d",k,dot-start);return 0;
	}
	printf("%c.",s[h]);
	for(i=h+1;i<len;i++)if(s[i]!='.')putchar(s[i]);
	if(start>dot)printf("e%d",dot-start);
	else printf("e%d",dot-start-1);
}

