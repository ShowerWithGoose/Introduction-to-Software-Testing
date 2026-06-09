#include<stdio.h>
int main()
{
    int zhan[100];
    int top=0; // @@ [The initial value of 'top' should be -1 to indicate an empty stack. Using 0 means the first element is placed at index 0, but 'top' then represents the count of elements rather than the index of the top element, causing off-by-one errors in boundary checks.]
    int opr,shu;
    while(1)
    {
        scanf("%d",&opr);
        if(opr==1)
        {
            if(top<=99) // @@ [Because 'top' starts at 0 and is used as a count, this condition allows pushing up to 100 elements (indices 0-99), which is correct for capacity 100. However, due to the initial 'top=0', the logic is inconsistent with standard stack indexing where 'top=-1' means empty. The real issue is in pop output formatting and missing space after numbers.]
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
                printf("%d",zhan[--top]); // @@ [Missing space after the printed number. The problem requires each popped element to be followed by a space, including the last one. This outputs numbers without spaces, causing concatenated output like "655901...".]
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