#include<stdio.h>
#include<stdlib.h>
#include<string.h>
	int top;
	int s[100];
	void initstack()
	{top=-1;
	}
	int i,j,k,x,op;
	int isEmpty( )
	{return top==-1;
	}
	int isFull( )
	{return top==99;
	}
	
	void push(int s[],int item)
	{
		if(isFull())
		printf("error ");
	else
	s[++top]=item;	
	}
	void pop(int s[])
	{

		if(isEmpty())
		printf("error ");
		else 
		printf("%d ",s[top--]);
	}
	int main()
	{
		initstack(s);
	
		while(1)
		{scanf("%d ",&op);
		
		if(op==1)//»Î’ª
		{scanf("%d ",&x);
		 push(s,x);
		 }
		 else if(op==0)
		 {pop(s);
		 }
		 else if(op==-1)
		 break;
		}
				return 0;
		 } 
		
	
	
	

