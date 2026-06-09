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
            count++; // @@ Logical error: count incremented before checking capacity. Should move after the if condition to avoid incorrect count when stack is full.
            if(count>100)
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
            count--; // @@ Logical error: count decremented before checking emptiness. Should move after the empty check to avoid negative count.
            if(count<0)
            {
                printf("error ");
                continue;
            }
            printf("%d ",top->data);
            linklist hold=top; // @@ Compilation error in C89: declaration after statement. Move this declaration to the beginning of the block or compile with C99/C11.
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