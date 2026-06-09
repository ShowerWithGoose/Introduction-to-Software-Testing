#include<stdio.h>
int main()
{
    int zhan[100];
    int top=0; // @@ The initial state of the stack should be empty, so top should be initialized to -1 (or logic adjusted). With top=0 and pre-increment logic later, the first element is placed at index 0 but 'top' represents count. However, the pop logic `zhan[--top]` with top=0 initially will access zhan[-1] if not checked properly, or rather, the check `top>0` prevents popping when top is 0 (empty). But standard stack with top=-1 is safer. Let's look closer. If top=0 means empty, push does `zhan[top++]` -> zhan[0], top becomes 1. Pop checks `top>0` (1>0 true), does `zhan[--top]` -> zhan[0], top becomes 0. This logic actually works for empty/full detection IF implemented consistently. 
    // However, the problem says "initial state ... is empty". 
    // Let's look at the output format error first.
    int opr,shu;
    while(1)
    {
        scanf("%d",&opr);
        if(opr==1)
        {
            if(top<=99) // @@ If top represents the number of elements (0-based count where 0 is empty), max capacity 100 means top can go up to 100. If top is index of next free slot, 0..99 are valid indices. So if top==100, it's full. Here `top<=99` allows pushing when top is 99. After push, top becomes 100. Next push checks 100<=99 false -> error. This seems correct for capacity 100.
            {
                scanf("%d",&zhan[top++]);
            }
            else
            {
                printf("error ");
            }
        }
        else if(opr==0)
        {
            if(top>0)
            {
                printf("%d",zhan[--top]); // @@ The output format requires elements to be separated by spaces. This printf does not print a space after the number. It should be `printf("%d ", zhan[--top]);`.
            }
            else
            {
                printf("error ");
            }
        }
        else
        {
            break;
        }
    }
    return 0;
}