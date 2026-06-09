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
            count++; // @@ count is incremented before checking capacity, causing incorrect state tracking; it should be incremented only after verifying the stack is not full
            if(count>100) // @@ condition should be count >= 100 to correctly detect when the stack has reached its maximum capacity of 100 before pushing
            {
                printf("error ");
                continue;
            }
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
            count--; // @@ count is decremented before checking if the stack is empty, causing incorrect state tracking; it should be decremented only after verifying the stack is not empty
            if(count<0) // @@ condition should be count <= 0 or count == 0 to correctly detect when the stack is empty before attempting to pop
            {
                printf("error ");
                continue;
            }
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