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
    int top,popnum=0,i,order,buf;
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
            if(top==0) // @@ [Error: 'top' is uninitialized; using it in comparison leads to undefined behavior. Should be initialized to 0 before use.]
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
            if(top==100) // @@ [Error: 'top' is uninitialized; using it in comparison leads to undefined behavior. Should be initialized to 0 before use.]
            {
                scanf("%d",&buf);
                strcpy(print[popnum],"error");
                popnum++;
            }
            else if(top<100)
            {
                scanf("%d",&stack[top]); // @@ [Error: 'top' is uninitialized; using it as an index leads to undefined behavior. Should be initialized to 0 before use.]
                top++;
            }
        }
    }
    printf("(%d)",popnum); // @@ [Error: This prints an extra "(%d)" at the end, which does not match the expected output format. The expected output should only contain the popped elements and "error" messages, not this debugging information.]
//    for(i=0;i<10;i++)
//    {
//        printf("[%d] ",printnum[i]);
//    }
//  printf("Fuck!");
    return 0;
}