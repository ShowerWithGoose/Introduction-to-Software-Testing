#include<stdio.h>
#include<string.h>
#include<ctype.h>
int j(int x,char c,int y);
int main(){
	int n[1],num;
	char z[0],zi;
	scanf("%d",&n[0]);
	scanf("%c",&z[0]);
	while(z[0]==' ')
	scanf("%c",&z[0]);
	
	if(z[0]!='=')
	{
		scanf("%d",&n[1]);
		while(n[1]==' ')
		scanf("%d",&n[1]);
	}
	else
	printf("%d",n[0]);
	
	while(z[0]!='=')
	{
		if(z[0]=='*'||z[0]=='/')
		{
			n[0]=j(n[0],z[0],n[1]);
			scanf("%c",&z[0]);
			while(z[0]==' ')
			scanf("%c",&z[0]);
			if(z[0]!='='){
				scanf("%d",&n[1]);
				while(n[1]==' ')
				scanf("%d",&n[1]);
			}
			
			else
			printf("%d",n[0]);
		}
		else
		{	
			scanf("%c",&zi);
			while(zi==' ')
			scanf("%c",&zi);
			if(zi=='*'||zi=='/')
			{
				scanf("%d",&num);
				while(num==' ')
				scanf("%d",&num);
				n[1]=j(n[1],zi,num);
			}
			else if(zi=='+'||zi=='-'||zi=='=')
			{
				n[0]=j(n[0],z[0],n[1]);
				z[0]=zi;
				if(z[0]!='=')
				{
					scanf("%d",&n[1]);
					while(n[1]==' ')
					scanf("%d",&n[1]);
				}
				
				else
				printf("%d",n[0]);
			}
			else
			z[0]=zi;
			
		}
	}


	return 0;
}

int j(int x,char c,int y)
{
	int a=0;
	if(c=='+')
	a=x+y;
	else if(c=='-')
	a=x-y;
	else if(c=='*')
	a=x*y;
	else if(c=='/')
	a=x/y;
	
	return a;
}



