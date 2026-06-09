//1-3 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
int main()
{
	char str[10000]={0},a[10000]={0},b[10000]={0},*p;
	int zh,i;
	gets(str);
	sscanf(str,"%[0-9].%[0-9]",a,b);
	zh=strlen(a);
	if(a[0]!='0')
	{
		if(strlen(b)==0)
			printf("%c%se%d",a[0],a+1,zh-1);
		else
			printf("%c.%s%se%d",a[0],a+1,b,zh-1);
	}
	else
	{
		for(i=0;b[i]=='0';i++);
		p=&b[i]+1;
		if(strlen(b)==0)
			printf("0e0");
		else if(strlen(p)==0)
			printf("%c%se-%d",b[i],p,i+1);
		else
			printf("%c.%se-%d",b[i],p,i+1);
	}
	return 0;
}


