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
    int top,popnum=0,i,order,buf; // @@ Variable 'top' is uninitialized, leading to undefined behavior when used in conditions like 'if(top==0)' or 'if(top==100)'. It should be initialized to 0 (if treating top as count/next index) or -1 (if treating top as current index). Given the logic below, it seems to treat top as the next available index or count, so initializing to 0 is likely intended, but the logic for push/pop is inconsistent with standard stack implementations.
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
            if(top==0) // @@ Logic error: If 'top' represents the number of elements (initialized to 0), empty stack check is correct. However, if 'top' was meant to be an index (like in reference), this is wrong. Assuming 'top' is count/next-index based on push logic 'stack[top]; top++', then top==0 means empty.
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
            if(top==100) // @@ Logic error: If capacity is 100, indices 0-99 are valid. If 'top' is the next free slot, then top==100 means full. This part is consistent with 'top' being a count/next-index.
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