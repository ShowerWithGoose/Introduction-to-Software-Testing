#include <stdio.h> 
int main() 
{ 
	int zsg,xsg,i,j;
	char num[101],*p,*q;
	scanf("%s",num);
	for(i=0;num[i]!='.';i++)
	{
		;
	}
	zsg=i-1;
	p=&num[i+1];
	for(i=zsg+2;num[i]!='\0';i++)
	{
		;	
	}
	xsg=i-zsg-2;
	if(num[0]!='0')
	{
		printf("%c.",num[0]);
		for(i=1;num[i]!='.';i++)
		{
			printf("%c",num[i]);	
		}
		printf("%s",p);
		printf("e%d",zsg);	
	}	
	else
	{
		for(j=zsg+2;num[j]=='0';j++)
		{
			;
		}
		q=&num[j+1];
		if(xsg==j-zsg-1)
		{
			printf("%ce-%d",num[j],xsg);	
		}
		else
		{
			printf("%c.%se-%d",num[j],q,j-zsg-1);	
		}
	}
	return 0;
}

