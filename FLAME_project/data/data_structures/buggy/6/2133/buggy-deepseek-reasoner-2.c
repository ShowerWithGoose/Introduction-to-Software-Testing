#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int stack[105];
char print[100][10];
int printnum[100];

int main()
{
    int top,popnum=0,i,order,buf; @@ // top not initialized; should be int top=-1,...
    for(;;)
    {
        scanf("%d",&order);
        if(order==-1)
        {
            for(i=0;i<popnum;i++)
            {
                if(printnum[i]==0) @@ // logic error: printnum[i]==0 is not a reliable sentinel; should use -1 to indicate error
                {
                    fputs(print[i],stdout);
                    printf(" ");
                }
                else 
                {
                    printf("%d ",printnum[i]);
                }
            }
            break;
        }
        else if(order==0)
        {
            if(top==0) @@ // wrong condition for empty stack; should be top==-1
            {
                strcpy(print[popnum],"error");
            }
            else if(top>0) @@ // this condition should be just else; top==0 is a valid non-empty state
            {
                top--; @@ // top decrement should occur after storing the popped value
                printnum[popnum]=stack[top]; @@ // uses new top (decremented) instead of old top; should be stack[top+1] or reorder
                stack[top]=0;
            }
            popnum++;
        }
        else if(order==1)
        {
            if(top==100)
            {
                scanf("%d",&buf);
                strcpy(print[popnum],"error");
                popnum++;
            }
            else if(top<100)
            {
                scanf("%d",&stack[top]);
                top++;
            }
        }
    }
    printf("(%d)",popnum); @@ // extra output not in expected output
//    for(i=0;i<10;i++)
//    {
//        printf("[%d] ",printnum[i]);
//    }
//  printf("Fuck!");
    return 0;
}