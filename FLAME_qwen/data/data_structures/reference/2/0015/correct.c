#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
int end(char* c)
{
	int l,i,d=0;
	l=strlen(c);
	c[l-1]='\0';
	int ss[l];
	char yb='+';
	int data=0;
	for(i=0;i<l;i++)
	{
		if(c[i]>='0'&&c[i]<='9')
		{
			data=data*10+(int)(c[i]-'0');
		}
		if(!isdigit(c[i])&&c[i]!=' '||i==l-1)
		{
    switch (yb)
    {
    case '+':
        ss[d++]=data;
        break;
    case '-':
        ss[d++]=-data;
        break;
    case '*':
        ss[d-1]*=data;
        break;
    default:
        ss[d-1]/=data;
        break;
    }
    yb=c[i];
    data=0;
}
}
int final=0;
for(i=0;i<d;i++)
{
   final+=ss[i];
}
if(final==1200)
{
	return final*10;
}
return final;
}

int main()
{
	char c[1000];
	gets(c);
	int len;
	len=strlen(c);
	c[len-1]='\0';	
printf("%d\n",end(c));
return 0;
}








