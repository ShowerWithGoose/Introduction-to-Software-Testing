#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
typedef struct bond{
    int a;
    struct bond *next;
}SB;
SB *top; 
void intbond()
{
top=NULL;
}//初始化栈 
int empty()
{
    return top==NULL;
}//检验是否栈空 
void push(int x)
{
    SB *p;
    if((p=(SB*)malloc(sizeof(SB)))==NULL)
    printf("No memory!");
    else{
        p->a=x;
        p->next=top;
        top=p;
    }
}//入栈  // @@ Missing check for stack maximum capacity (100), should output "error " if full
int pop()
{
    SB *p;
    int x;
    if(empty())
    printf("error "); // @@ Missing return statement in error branch, causes undefined behavior and compilation error in strict environments
    else
    {
        p=top;
        x=top->a;
        top=top->next;
        free(p);
        return x;
    }
}//出栈 
int main()
{
intbond();
int m,n;
while(~scanf("%d",&m))
{
    if(m==-1)
    break;
    else if(m==0)
    {
        printf("%d ",pop()); // @@ Unconditionally prints pop()'s return value, but pop() returns nothing on empty stack, leading to undefined behavior and incorrect output format
    }
    else
    {
        scanf("%d",&n);
        push(n); // @@ Missing capacity check before push, should verify current size < 100 and print "error " if full
    }
}
 return 0;
}