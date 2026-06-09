#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int Top=-1;
int s[200];
int isFull(  )
{
      return Top==100-1;
}//是否已经满
int  isEmpty( )
{
       return Top== -1;
} //是否为空
void  push( int s[ ], int item )
{
    if( isFull() )
    printf("error ");
    else
    s[++Top] =item;
}//进栈操作
int pop( int s[ ])
{
      if(isEmpty())
      printf("error "); // @@ The function prints "error " but does not return a value, causing undefined behavior when the caller uses the return value. It should return a dummy value (e.g., 0) after printing error.
      else
    return s[Top--]; 
}//出栈操作 

int main()
{ int x,n,y;
  while((scanf("%d",&x))!=EOF)
  {if(x==1)
  {scanf("%d",&n);
   push(s,n);
  }
  if(x==0)
  {
   y=pop(s);
   printf("%d ",y); // @@ When pop() prints "error " due to empty stack, it does not return a value, so y is uninitialized, causing an extra "6" to be printed from garbage memory.
  }
  if(x==-1)
  break; 
  }
  return 0;
}