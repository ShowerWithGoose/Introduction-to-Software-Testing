#include<stdio.h>
int main()
{
    int zhan[100];
    int top=0; // @@ The initial value of top should be -1 to represent an empty stack, or the push/pop logic needs to be adjusted accordingly. With top=0 and pre-increment/decrement logic mixed, it causes off-by-one errors or incorrect empty/full checks. Specifically, if top starts at 0, the first push goes to index 0 and increments to 1. Pop checks top>0, so if one element is present (top=1), --top makes it 0, accessing index 0. This part might work logically if consistent, but the output format is wrong.
    int opr,shu;
    while(1)
    {
        scanf("%d",&opr);
        if(opr==1)
        {
            if(top<=99) // @@ This condition allows pushing when top is 99. If top represents the count of elements, indices are 0..99. If top is the next free slot, max index is 99. If top starts at 0, pushing 100 items makes top 100. The check top<=99 allows the 100th item (index 99) to be pushed, incrementing top to 100. This seems correct for capacity 100. However, standard stack implementation often uses top as index of top element. Let's look at pop.
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
                printf("%d",zhan[--top]); // @@ Missing space after the printed number. The expected output requires elements to be separated by spaces, including a space after the last element. It should be printf("%d ", zhan[--top]);
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