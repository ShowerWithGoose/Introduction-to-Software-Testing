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
}//入栈 
int pop()
{
    SB *p;
    int x;
    if(empty())
    printf("error "); // @@ [When the stack is empty, the function prints "error " but still attempts to return an undefined value (x is uninitialized), leading to undefined behavior. Additionally, the calling code always prints the return value of pop(), so in the error case it prints "error " followed by garbage or causes a crash.]
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
        printf("%d ",pop()); // @@ [This line unconditionally prints the return value of pop(). However, when the stack is empty, pop() prints "error " and then returns an uninitialized variable x, causing undefined behavior and incorrect output format (e.g., "error <garbage> "). The correct behavior is to only print the popped value on success, and only "error " on failure — not both.]
    }
    else
    {
        scanf("%d",&n);
        push(n);
    }
}
 return 0;
}