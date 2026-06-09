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
        return 0;    // @@ [Returning 0 on error is ambiguous because 0 could be a valid stack element. The problem expects "error " to be printed, but the calling code in main always prints the return value of pop(), so when an error occurs, it prints "error 0 ", which is incorrect. The function should not return a value that gets printed as if it were a popped element.]
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
            printf("%d ",pop()); // @@ [This always prints the return value of pop(). When the stack is empty, pop() prints "error " and returns 0, causing the output to be "error 0 ", which is wrong. It should only print "error " and not print any number. The logic must avoid printing a number when an error occurs.]
        }
        scanf("%d",&n);
    }
    return 0;
}