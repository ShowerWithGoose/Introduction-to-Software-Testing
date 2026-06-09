#include <stdio.h> 
#include<string.h>
#include <stdlib.h>
struct  node { 
        int  data;
        struct  node  *link;
};
typedef  struct node  *Nodeptr;
typedef  struct node  Node;
Nodeptr Top;
int  isEmpty( )
{
       return Top==NULL;
}
void initStack(  )
{
        Top=NULL;
}
void  push( int item )
{    Nodeptr p;
    p=(Nodeptr)malloc(sizeof(Node));
      {
             p->data=item;           /*将item送新结点数据域*/
             p->link=Top;              /*将新结点插在链表最前面*/
             Top=p;                         /*修改栈顶指针的指向*/
      }
}
int  pop( )
{    
Nodeptr p;
      int item;
     if ( isEmpty() ) 
     {
         printf("error ");
        return 0;    // @@ [When the stack is empty, pop() returns 0, which is indistinguishable from a valid popped value of 0. This causes incorrect output when 0 is a legitimate stack element. The reference program uses EOF to distinguish error cases, but this implementation cannot differentiate between an actual 0 and an error.]
     }
                       /* 栈中无元素*/
     else
     {
           p=Top;                          /* 暂时保存栈顶结点的地址*/  
           item=Top->data;         /*保存被删栈顶的数据信息*/
           Top=Top->link;            /* 删除栈顶结点 */ 
           free(p);                         /* 释放被删除结点*/
        return item;                         /* 返回出栈元素*/
      }
}

int main()
{
    int n,i;
    initStack(  );        
    scanf("%d",&n);
    while(n!=-1)
    {
        if(n==1)
        {
            scanf("%d",&i);
            push(i);
        }
        else if(n==0)
        {
            printf("%d ",pop()); // @@ [Because pop() returns 0 on error instead of a special sentinel like EOF, this line will print "0 " even when the stack is empty, instead of just "error ". This leads to incorrect output format and logic.]
        }
        scanf("%d",&n); // @@ [If the first input is -1, the loop doesn't run, which is correct. However, if any operation fails (e.g., pop on empty stack), the program continues processing instead of halting or handling subsequent operations correctly. But more critically, there's no check for stack fullness during push — the problem states the stack has a maximum capacity of 100, but this linked-list-based implementation has no capacity limit, violating the problem constraints.]
    }
    return 0;
}