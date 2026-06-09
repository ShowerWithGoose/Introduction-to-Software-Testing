#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>
#include<float.h>
#include<ctype.h>


#define MAXSIZE     100
#define ElemType    int

ElemType  Stack[MAXSIZE];
int  top,op,input;
void  initStack( );
int  isEmpty( );
int isFull(  );
void  push( ElemType Stack[ ],  ElemType item );
void  Error(char Stack[]);
ElemType pop( ElemType Stack[ ]);
int main()
{
	initStack( );
	while(scanf("%d",&op)!=EOF)
	{
		switch(op)
		{
			case -1:
				return 0;
				break;
			case 1:
				scanf("%d",&input);
				push(Stack,input);
				break;
			case 0:
				input=pop(Stack);
				if(input) printf("%d ",input);
				break;
		}
	}
	return 0;
 } 
void  initStack( )
{
        top= -1;
}
int  isEmpty( )
{
       return top== -1;
} 
int isFull(  )
{
      return top==MAXSIZE-1;
}
void  push( ElemType Stack[ ],  ElemType item )
{
        if( isFull() )
               Error("error");
        else
	          Stack[++top]=item;  
        return;
}
void  Error(char Stack[])
{
        printf("%s ", Stack);
        return;
}
ElemType pop( ElemType Stack[ ])
{
      if(isEmpty())
             {
             	Error("error");
             	return 0;
		   }
      else

             return Stack[top--];
      
}


