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
int pop( )
{    
Nodeptr p;
      int item;
     if ( isEmpty() ) 
     {
         printf("error ");
        return 0;    // @@ [When pop is called on an empty stack, it prints "error " and then returns 0. In main, the returned value is printed unconditionally, causing an extra "0" in the output. The correct behavior is to not output the numeric value after "error ". Either pop should not return a value (void) and handle printing completely, or main should check the return value and skip printing when the stack is empty.]
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
            printf("%d ",pop()); // @@ [This line prints the return value of pop(). When the stack is empty, pop() returns 0 after printing "error ", so the output becomes "error 0 " instead of just "error ". The issue is that pop() both prints the error message and returns a value that is printed here. The proper fix is to either have pop() be void and handle all output, or to conditionally print only when pop() indicates a valid element.]
        }
        scanf("%d",&n);
    }
    return 0;
}