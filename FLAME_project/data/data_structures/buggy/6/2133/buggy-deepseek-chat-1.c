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
            if(top==0) // @@ top is uninitialized; it should be initialized to -1 to represent an empty stack. Comparing top==0 incorrectly treats a stack with one element as empty.
            {
                strcpy(print[popnum],"error");
            }
            else if(top>0) // @@ top is uninitialized; this condition may behave unpredictably. Also, the logic is wrong: after popping, top should be decremented before accessing stack[top], but here it decrements first and then accesses, which is incorrect.
            {
                top--;
                printnum[popnum]=stack[top];
                stack[top]=0;
            }
            popnum++;
        }
        else if(order==1)
        {
            if(top==100) // @@ top is uninitialized; comparing to 100 is incorrect because the stack size is 105, and top should track the next empty index, not the number of elements. Also, the condition should check if top >= 100 for a stack of size 105.
            {
                scanf("%d",&buf);
                strcpy(print[popnum],"error");
                popnum++;
            }
            else if(top<100) // @@ top is uninitialized; the push logic is wrong: it should assign to stack[top] and then increment top, but here it assigns before incrementing, and top starts uninitialized.
            {
                scanf("%d",&stack[top]);
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