#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int num=0,b[100],i=0,j=0,k=0,a1,res=0;
	char c;
	scanf("%d",&num);
	b[0]=num;
	while(1)
	{
		scanf(" %c",&c);
		if(c=='=')
			break;
		scanf("%d",&a1);
		if(c=='+')
		{
			j++;
			b[j]=a1;
		}
		else if(c=='-')
		{
			j++;
			b[j]=0-a1;
		}
		else if(c=='*')
		{
			b[j]*=a1;
		}
		else if(c=='/')
		{
			b[j]/=a1;
		}
	}
	for(k=0;k<=j;k++)
	{
		res+=b[k];
	}
	printf("%d",res);
}
