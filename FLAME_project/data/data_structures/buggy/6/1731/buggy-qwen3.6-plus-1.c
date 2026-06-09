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
      printf("error ");
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
   y=pop(s); // @@ The return value of pop() is used regardless of whether the stack was empty. If the stack is empty, pop() prints "error " but returns an undefined/garbage value (since the else branch with the return statement is skipped). This garbage value is then printed by printf("%d ", y), causing the extra number in the output.
   printf("%d ",y); // @@ This line executes even when the stack is empty, printing the uninitialized or garbage value returned by pop(). It should only print if the pop was successful.
  }
  if(x==-1)
  break; 
  }
  return 0;
}