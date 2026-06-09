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
    while(scanf("%d",&command)) // @@ [The loop condition does not check for input failure or the termination command -1 properly. It should also break on EOF or when command is -1, but currently it only breaks after processing -1 later. More critically, scanf returns the number of successfully read items, so on EOF it returns EOF (typically -1), making the condition true and causing an infinite loop or undefined behavior.]
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