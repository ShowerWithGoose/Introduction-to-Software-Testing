#include <stdio.h>
#define maxline 100

int STACK[maxline];
int top;

int isFull(int top);
int EMPTYS(int top); 
void initials(int *top);

int main()
{
  int op,n;
  initials(&top);
  while(scanf("%d",&op)!=EOF)//EOF不会遇到-1就停止 
  {
    
    if(op==1)
    {//入栈 
      scanf("%d",&n);
      if(isFull(top))
      {
        printf("error ");
      }
      else
      {
        STACK[++top]=n; 
      }
    }
    
    if(op==0)
    {//出栈 
      if(EMPTYS(top))
      {
        printf("error ");
      }
      
      else
      {
        n=STACK[top--];
        printf("%d ",n);
       } 
    }
    
   if(op==-1)
   {
     break;
    } 
     
  }
    return 0;
}


int isFull(int top)
{
  return top==maxline-1;
}

void initials(int *top)
{
  top=-1; // @@ [The function parameter 'top' is a pointer, but it's being assigned directly instead of dereferencing it. Should be '*top = -1;' to initialize the global variable.]
}

int EMPTYS(int top)
{
  return top==-1;
}