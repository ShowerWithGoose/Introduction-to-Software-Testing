#include<stdio.h>
#include<string.h>
int a[3]={0};
char b,c;
int cal(int a,int b,char c) 
{
	switch(c)
	{
		case '+':return a+b;
		case '-':return a-b;
		case '*':return a*b;
		case '/':return a/b;
	}
}

int main()
{
	scanf(" %d",&a[0]);
	scanf(" %c",&b);
	if(b!='=')
		scanf(" %d",&a[1]);
	while(b!='=')
	{
		if(b=='*'||b=='/')
		{
			a[0]=cal(a[0],a[1],b);
			scanf(" %c",&b);
			if(b!='=')
				scanf(" %d",&a[1]);
		}
		else
		{	scanf(" %c",&c);
			if(c=='*'||c=='/')
			{
				scanf(" %d",&a[2]);
				a[1]=cal(a[1],a[2],c); 
			}
			else if(c=='+'||c=='-'||c=='=')
			{	
				a[0]=cal(a[0],a[1],b);
				b=c;
				if(c!='=')
					scanf(" %d",&a[1]);
			}
		}
	}
	printf("%d",a[0]); 		
	return 0;
}

