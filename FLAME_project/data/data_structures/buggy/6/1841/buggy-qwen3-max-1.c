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
            printf("%d ",top->data); @@ [The pop operation prints the value even when the stack was empty before this operation. The count is decremented first, so when the stack is empty (count=0), count becomes -1 and "error" is printed, but in cases where count was 1, it becomes 0 and proceeds to access top->data. However, the real issue is that the check for empty stack should happen BEFORE decrementing count and accessing top. Also, after printing error, 'continue' skips freeing, but when not error, it frees correctly. However, the main logical flaw is that count is decremented BEFORE checking if the stack is empty, leading to incorrect state tracking.]
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