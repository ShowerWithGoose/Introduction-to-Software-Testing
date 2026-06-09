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
        return 0;    
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
            if (!isEmpty()) { // @@ The original code prints the return value of pop() regardless of whether an error occurred. When the stack is empty, pop() prints "error " and returns 0. The original code then prints this 0, resulting in "error 0 ". The expected output is just "error ". We need to check if the stack is empty before printing the result of pop, or handle the printing inside pop/main logic correctly. Since pop already prints "error ", we should only print the returned value if it was a successful pop. However, pop returns 0 on error which is ambiguous if 0 is a valid data. A better approach is to check isEmpty before calling pop or change pop to not print. Given the constraint to minimize changes, we can check isEmpty here.
                printf("%d ", pop());
            } else {
                pop(); // This will print "error "
            }
        }
        scanf("%d",&n);
    }
    return 0;
}