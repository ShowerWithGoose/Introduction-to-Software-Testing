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

ElemType  s[MAXSIZE];
int  top,n,x;
void  initStack( );
int  isEmpty( );
int isFull(  );
void  push( ElemType s[ ],  ElemType item );
void  Error(char s[]);
ElemType pop( ElemType s[ ]);
int main()
{
	initStack( );
	while(scanf("%d",&n)!=EOF)
	{
		switch(n)
		{
			case -1:
				return 0;
				break;
			case 1:
				scanf("%d",&x);
				push(s,x);
				break;
			case 0:
				x=pop(s);
				if(x) printf("%d ",x);
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
void  push( ElemType s[ ],  ElemType item )
{
        if( isFull() )
               Error("error");
        else
	          s[++top]=item;  
        return;
}
void  Error(char s[])
{
        printf("%s ", s);
        return;
}
ElemType pop( ElemType s[ ])
{
      if(isEmpty())
             {
             	Error("error");
             	return 0;
		   }
      else

             return s[top--];
      
}


