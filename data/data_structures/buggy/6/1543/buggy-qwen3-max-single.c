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
        return 0;    // @@ [When the stack is empty, pop() returns 0, which is a valid integer. The calling code cannot distinguish between an actual popped value of 0 and an error condition. This leads to incorrect output when a pop on empty stack should print "error " but instead may print "0 ".]
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
            printf("%d ",pop()); // @@ [Because pop() returns 0 on error instead of a special indicator (like EOF), this line will print "0 " even when the stack is empty, instead of just "error ". The error message is printed inside pop(), but then 0 is also printed here, causing incorrect output like "error 0 " or just "0 " if error printing is missed in logic flow.]
        }
        scanf("%d",&n);
    }
    return 0;
}