#include<stdio.h>
int main()
{
    int zhan[100];
    int top=0; // @@ [The initial value of 'top' should be -1 to indicate an empty stack. Using 0 means the first element is placed at index 0, but 'top' then represents count rather than index, causing off-by-one errors in full/empty checks.]
    int opr,shu;
    while(1)
    {
        scanf("%d",&opr);
        if(opr==1)
        {
            if(top<=99) // @@ [Because 'top' starts at 0 and is used as a count, this condition allows pushing up to 100 elements (indices 0-99), which is correct for capacity 100. However, due to inconsistent interpretation of 'top' (as count vs index), logic becomes fragile. The real issue is in pop printing format and empty check consistency.]
            {
                scanf("%d",&zhan[top++]); // @@ [This stores the new element at current 'top' then increments. With top starting at 0, this is okay for storage, but conflicts with pop logic that uses pre-decrement.]
            }
            else
            {
                printf("error ");
            }
        }
        else if(opr==0)
        {
            if(top>0) // @@ [This check is correct only if 'top' is a count (number of elements). But when popping, it uses '--top' which treats 'top' as an index. This inconsistency leads to correct element access but reveals another bug: missing space after printed number.]
            {
                printf("%d",zhan[--top]); // @@ [Missing space after the printed number. According to output format, each popped element must be followed by a space, including the last one. This causes concatenated output like "655901..." instead of "655 901 ... ".]
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