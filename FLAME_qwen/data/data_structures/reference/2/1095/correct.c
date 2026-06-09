#include<stdio.h>
int cal(int a, int b, char ch)
{
	if (ch=='+')
		return a + b;
	else if (ch=='-')
	    return  a-b;
	else if (ch=='*')
		return a*b;
	else
		return a/b;
}	
int read_Num()
{
	int num;
	scanf("%d",&num);
	return num;
}					
char read_Ch()
{
	char op;
	scanf(" %c",&op);
	return op;
}
int main()
{
	int a[3];		
	char b[2];								
	scanf("%d",&a[0]);
	scanf(" %c",&b[0]);
	if(b[0]!='=')
		scanf(" %d",&a[1]);
	while(b[0]!='=')
	{
		if(b[0]=='*'||b[0]=='/')	
		{
			a[0]=cal(a[0],a[1],b[0]);
			b[0]=read_Ch();
			if(b[0]!='=')
				scanf(" %d",&a[1]);
		}
		else 
		{
			scanf(" %c",&b[1]);
			if(b[1]=='+'||b[1]=='-'||b[1]=='=')
			{
				a[0]=cal(a[0],a[1],b[0]);
				b[0]=b[1];
				if(b[1]!='=')
					scanf(" %d",&a[1]);
			}
			else if(b[1]!='=')	
			{
				scanf(" %d",&a[2]);
				a[1]=cal(a[1],a[2],b[1]);
			}
			else
				b[0]=b[1];
		}
 
	}
	printf("%d",a[0]);
	return 0;
}

