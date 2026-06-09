#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int stack[105];
char print[100][10]; // @@ array size insufficient for many error operations; may cause buffer overflow.
int printnum[100]; // @@ same issue, may overflow if many operations.

int main()
{
    int top,popnum=0,i,order,buf; // @@ top not initialized; should be set to 0.
    for(;;)
    {
        scanf("%d",&order);
        if(order==-1)
        {
            for(i=0;i<popnum;i++)
            {
                if(printnum[i]==0)
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
            if(top==0) // @@ top may be garbage; leads to incorrect empty check.
            {
                strcpy(print[popnum],"error");
            }
            else if(top>0)
            {
                top--;
                printnum[popnum]=stack[top];
                stack[top]=0;
            }
            popnum++;
        }
        else if(order==1)
        {
            if(top==100) // @@ top not initialized; may cause false full condition.
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
    printf("(%d)",popnum); // @@ extra output not required by problem specification.
//    for(i=0;i<10;i++)
//    {
//        printf("[%d] ",printnum[i]);
//    }
//  printf("Fuck!");
    return 0;
}