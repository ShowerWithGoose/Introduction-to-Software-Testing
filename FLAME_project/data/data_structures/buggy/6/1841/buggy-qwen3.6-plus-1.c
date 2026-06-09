#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
}Lnode,*linklist;

int main()
{
    int command,n,count=0;
    linklist top=NULL,p,q;
    while(scanf("%d",&command))
    {
        if(command==1)
        {
            scanf("%d",&n);
            if(count>=100) // @@ The check for stack full should happen before incrementing count and allocating memory. Also, the condition should be >= 100 because count represents current size. If count is 100, it's full. The original code increments count first, then checks > 100, which allows 101 elements. More importantly, if it's full, we shouldn't push.
            {
                printf("error ");
                continue;
            }
            count++; // @@ Increment count only after verifying there is space.
            p=(linklist)malloc(sizeof(Lnode));
            p->data=n;
            p->link=NULL;
            if(top==NULL)
            {
                top=p;
            }
            else
            {
                p->link=top;
            }
            top=p;
        }
        else if(command==0)
        {
            if(count<=0) // @@ Check if stack is empty before decrementing count or accessing top. If empty, print error and continue.
            {
                printf("error ");
                continue;
            }
            count--; // @@ Decrement count only after verifying the stack is not empty.
            printf("%d ",top->data);
            linklist hold=top;
            top=top->link;
            free(hold);
        }
        
        if(command==-1)
        {
            break;
        }
    }
    return 0;
 }