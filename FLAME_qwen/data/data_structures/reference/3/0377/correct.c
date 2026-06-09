#include<stdio.h>
#include<string.h>
char a[200]={0},b,c[200]={0};
int main()
{
	gets(a);
	int i,len,f1=0,f3=0;
	len=strlen(a);
	int j=0,e=0;
	for(i=0;i<len;i++)
	{
		if(a[i]=='.')
			f1=len-i-1;
		else if(a[i]!='0' && f3==0)
		{	b=a[i];
			f3=1;			
		}
		else if(f3==1)
		{	c[j]=a[i];j++;
		}
	}
	e=j-f1;
	if(strlen(c)!=0)
	printf("%c.%se%d",b,c,e);
	else
	printf("%ce%d",b,e);
	return 0;
}



