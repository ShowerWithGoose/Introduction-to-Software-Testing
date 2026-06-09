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
            if(top==0) @@ // 'top' is uninitialized, so comparing to 0 is undefined behavior; also, stack is empty when top == 0 only if top starts at 0, but initial value is indeterminate
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
            if(top==100) @@ // 'top' is uninitialized, so this condition may evaluate incorrectly; also, stack full condition should be top >= 100 or top == 100 only if top starts at 0 and counts number of elements
            {
                scanf("%d",&buf);
                strcpy(print[popnum],"error");
                popnum++;
            }
            else if(top<100)
            {
                scanf("%d",&stack[top]); @@ // If top is uninitialized, writing to stack[top] causes undefined behavior (likely segmentation fault)
                top++;
            }
        }
    }
    printf("(%d)",popnum);
//    for(i=0;i<10;i++)
//    {
//        printf("[%d] ",printnum[i]);
//    }
//  printf("Fuck!");
    return 0;
}