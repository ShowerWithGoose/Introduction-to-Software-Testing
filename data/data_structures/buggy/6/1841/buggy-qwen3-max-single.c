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
    while(scanf("%d",&command)) // @@ [The loop condition should check for != EOF or != -1 to match the problem's termination condition (-1). Currently, it loops as long as scanf succeeds, but doesn't break immediately when command is -1, causing potential extra reads or missed breaks. Also, the reference program uses `scanf(...) != -1`, but more correctly should check return value of scanf for input success. However, the critical flaw is that when command==-1, the loop body still executes fully before breaking, which may cause unintended behavior if -1 is read but other operations follow. But the main error causing "error" output mismatch is in pop logic.]
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
            count--; // @@ [This decrements count BEFORE checking if stack is empty. If count was 0, it becomes -1, then the next condition checks count<0 and prints "error", but the decrement itself is incorrect logic. The correct approach is to check if count==0 (or top==NULL) BEFORE decrementing. This causes count to go negative on empty pop, which may affect subsequent operations and violates proper stack semantics.]
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