#include<stdio.h>
#include<malloc.h>¡¯
#define MAXSIZE     100
int  STACK[MAXSIZE];
int  top;
void  initStack( )
{
        top=-1;
}
int  isEmpty( )
{
       return top==-1;
} 
int isFull(  )
{
      return top==MAXSIZE-1;
}
void  push( int s[ ],  int item ){
        if( isFull() )
        	printf("error ");    
        else
			s[++top]=item;
}
void pop( int s[ ])
{
      if(isEmpty())
             printf("error "); 
      else
			{printf("%d ",s[top]);top--;}
}
int main()
{
	int a,b;
	scanf("%d",&a);
	initStack( );
	while(a!=-1)
	{
		if(a==1)
		{
			scanf("%d",&b);
			push(STACK,b);
		}else if(a==0)
		{
			pop(STACK);
		 } 
		scanf("%d",&a);
	}
	return 0;
}

