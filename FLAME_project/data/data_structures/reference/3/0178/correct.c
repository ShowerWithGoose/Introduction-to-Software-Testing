#include<stdio.h>
int a=-1,b,c,i,j;
char s[10000];
int main()
{
	gets(s);
	c=strlen(s);
	for(i=0;i<c;i++)
	{
		if(s[i]=='.')	b=i;
		else if(a<0&&s[i]!=48)	a=i+1;
	}
	for(i=0,j=0;i<c;i++)
	{
		if(j==1&&s[i]!='.')
		{
			j++;
			putchar('.');
		}
		
		if(!j&&s[i]!=48&&s[i]!='.')
			j=1;
		if(j&&s[i]!='.')	putchar(s[i]);
		
	}
	printf("e%d",b-a<0?b-a+1:b-a);
	return 0;
}

