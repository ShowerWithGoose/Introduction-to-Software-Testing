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
    while(scanf("%d",&command)) // @@ [The loop condition should check for != EOF or != -1 to match the problem's input termination with -1; currently, it loops as long as scanf succeeds, but doesn't stop when command is -1 until after processing. Also, the reference program checks `scanf(...) != -1`, but here the loop continues even after reading -1 until the next iteration, which may cause issues. However, the more critical error is that the loop condition does not handle input failure correctly and may lead to infinite loop if input ends without -1. But the immediate bug causing incorrect behavior is that the 'break' on command==-1 happens after possibly executing push/pop logic.]
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
            count--;
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