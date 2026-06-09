#include <stdio.h> 
#include<string.h>
#include <stdlib.h>
struct  node { 
        int  data;
        struct  node  *link;
};
typedef struct node  *Nodeptr;
typedef struct node  Node;
Nodeptr Top;
int  isEmpty( )
{
       return Top==NULL;
}
void initStack(  )
{
        Top=NULL;
}
void  push( int item ) // @@ 未检查栈是否已满（栈最大容量为100），满栈时应输出"error "，但此处直接入栈
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
        return 0; // @@ 空栈时返回0，但主函数会无条件打印该值，导致输出错误的多余数字"0 "；应返回特殊值（如EOF）以区分
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
            printf("%d ",pop()); // @@ 未检查pop返回值是否有效，空栈时pop返回0导致此处错误地打印"0 "，应判断返回值后再打印
        }
        scanf("%d",&n);
    }
    return 0;
}