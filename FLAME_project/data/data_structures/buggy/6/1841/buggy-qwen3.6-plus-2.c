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
            if(count>=100) // @@ The check for stack full should happen before incrementing count and allocating memory. Also, the condition should be >= 100 because capacity is 100 (0 to 99). If count is already 100, it's full.
            {
                printf("error ");
                continue;
            }
            count++; // @@ Count should only be incremented after verifying the push is valid.
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
            if(count<=0) // @@ Check for empty stack should happen before decrementing count or accessing top.
            {
                printf("error ");
                continue;
            }
            count--; // @@ Decrement count only after confirming the pop is valid.
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