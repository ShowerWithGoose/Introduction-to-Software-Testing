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
    int top,popnum=0,i,order,buf; // @@ [Variable 'top' is uninitialized. It should be initialized to 0 (if treating top as count/next index) or -1 (if treating top as current index). Given the logic below, it seems to treat top as the next available index or count, but accessing stack[top] before incrementing or checking bounds relies on a defined start state. If top is garbage, stack[top] causes Runtime Error.]
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
            if(top==0) // @@ [Logic error: If top represents the number of elements (initialized to 0), empty stack check is correct. However, if top was intended to be an index, this is wrong. Assuming top is count/index of next free slot based on push logic 'stack[top]; top++', then top==0 means empty. But wait, in push: 'scanf("%d",&stack[top]); top++;'. So stack[0] is first element. Top becomes 1. Pop: 'if(top==0)' -> error. 'else if(top>0)': 'top--; printnum[popnum]=stack[top];'. This logic actually works for 0-based count IF top is initialized to 0. The primary crash is likely uninitialized top.]
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
            if(top==100) // @@ [Boundary check: Array is size 105, but problem says capacity 100. If top is index of next free slot, valid indices are 0..99. So top==100 means full. This part is logically okay for capacity 100, assuming top starts at 0.]
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
    printf("(%d)",popnum);
//    for(i=0;i<10;i++)
//    {
//        printf("[%d] ",printnum[i]);
//    }
//  printf("Fuck!");
    return 0;
}