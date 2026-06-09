#include <stdio.h>
#define maxline 100

int STACK[maxline];
int top=-1;

int isFull(int top);
int EMPTYS(int top); 
void initials(int *top);//定义函数 用int *top 

int main()
{
  int op,n;
  initials(&top);//调用函数用&top 
  
  scanf("%d",&op);
  while(op!=EOF)//EOF不会遇到-1就停止 
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
     
     
    scanf("%d",&op); 
  }
	return 0;
}


int isFull(int top)
{
  return top==maxline-1;
}

void initials(int *top)
{
  top=-1;
}

int EMPTYS(int top)
{
  return top==-1;
}

