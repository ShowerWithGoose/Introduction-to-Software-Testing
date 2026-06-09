#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int stack[110];
int main()
{
    int top=0; // @@ The initial state of the stack should be empty. Using top=0 implies the stack has one element or uses 1-based indexing inconsistently with the push/pop logic below. It should be -1 to match an empty stack where top points to the current top element, or 0 if top points to the next free slot (but then pop logic is wrong). Given the reference uses top=-1, let's look at the logic. If top=0 means empty, push should be stack[top++]=num. Pop should be stack[--top]. Here push is stack[top]=num; top++. This means top points to the next free slot. So empty is top==0. Full is top==100. Pop accesses stack[top-1]. The code accesses stack[top], which is out of bounds or uninitialized for the current top element.
    int op,num;
    while(1)
    {
        scanf("%d",&op);
        if(op==1)
        {
            scanf("%d",&num);
            if(top==99) // @@ If top represents the next free slot (0-indexed), capacity 100 means indices 0..99. Full when top==100. If top represents count, full when top==100. The check top==99 suggests it thinks index 99 is the last valid one, but if top is next-free, pushing to index 99 is valid, making top 100. So full check should be top==100.
            printf("error ");
            else
            {
                stack[top]=num;
                top++;
            }
        }
        else if(op==0)
        {
            if(top==0)
            printf("error ");
            else
            {
                printf("%d ",stack[top]); // @@ Since top points to the next free slot, the current top element is at stack[top-1]. Accessing stack[top] reads uninitialized memory or the wrong element.
                top--; 
            }
        }
        else if(op==-1)
        break;
    }
    return 0;
}