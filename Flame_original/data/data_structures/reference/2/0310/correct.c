#include <stdio.h>
#include <string.h>
int main()
{
	char c[1010],sign='+';
	int a[1010],ret=0;
	gets(c);
	int i,n,j=strlen(c);
	for(i=0;i<j;i++)
	{
		if(c[i]==' ')
		{
			for(n=i;n<j;n++)
				c[n]=c[n+1];
		}
	 } 
	j=strlen(c);
	int temp=0,num=0;
	for(i=0;i<j;i++)
	{
		if(c[i]>='0'&&c[i]<='9')
			temp=temp*10+c[i]-'0';
		else
		{
			if(sign=='+') a[num++]=temp;
			else if(sign=='-') a[num++]=-temp;
			else if(sign=='*') a[num-1]*=temp;
			else if(sign=='/') a[num-1]/=temp;
			temp=0;
			sign=c[i];
		}
	}
	for(i=0;i<num;i++)
		ret+=a[i];
	printf("%d",ret);
	return 0; 
 } 

