#include<stdio.h>
#define MAXSIZE     100
int  STACK[MAXSIZE];
int  top;
void  initStack( )
{
        top = -1;
}
int  isEmpty( )
{
       return top== -1;
} 
int isFull(  )
{
      return top==MAXSIZE-1;
}
void  push(int s[ ], int item ){
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
			printf("%d ",s[top--]);
}
int main()
{
	int op,x;
	initStack();
		while(1)
	{
		for(;;)
		{
			scanf("%d",&op);
			switch(op)
			{
				case 1:
					scanf("%d",&x);
					push(STACK,x);
					break;
				case 0:
					pop(STACK);
					break;
				case -1:return 0;
			}
		}
}
}

