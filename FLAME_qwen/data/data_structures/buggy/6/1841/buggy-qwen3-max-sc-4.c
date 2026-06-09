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
    while(scanf("%d",&command)) // @@ [The loop condition should check for != EOF or != -1, but more critically, it does not handle the termination condition (-1) before processing. Also, scanf returns number of items read, so on failure (e.g., end of input), it returns 0 or EOF, causing infinite loop or undefined behavior. However, the immediate logical error is that when command == -1, the loop body still executes partially before breaking, but more importantly, the pop operation decrements count before checking if stack is empty.]
    {
        if(command==1)
        {
            scanf("%d",&n);
            count++;
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
            count--; // @@ [This decrements count before checking if the stack is empty. If count is 0 (empty stack), this makes count -1, then the next condition checks count<0 and prints "error", but the decrement should happen only after confirming the stack is not empty. This leads to incorrect count state and potential double error reporting or logic flaw.]
            if(count<0)
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