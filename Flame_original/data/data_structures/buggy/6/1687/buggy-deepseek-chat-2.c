#include<stdio.h>
int main()
{
    int zhan[100];
    int top=0;
    int opr,shu;
    while(1)
    {
        scanf("%d",&opr);
        if(opr==1)
        {
            if(top<=99) // @@ [Error: The condition should be top < 100 to check if the stack is full. Using top <= 99 allows pushing when top is 99, which is the last valid index (0-99). However, the logic is actually correct because top starts at 0 and increments after push, so top <= 99 means top can be 0..99, allowing 100 elements. But the problem states max capacity 100, so indices 0-99 are valid. The condition is fine, but the issue is that after pushing when top is 99, top becomes 100, and the next push will incorrectly succeed because top <= 99 is false. Actually, the condition should be top < 100 to allow push when top is 0..99. Since top starts at 0, top <= 99 allows top=99 to push, making top=100, then next push fails. This is correct. However, the real error is that the program does not handle the case when a push operation is attempted on a full stack correctly because the condition should be top < 100, not top <= 99. But wait, top <= 99 is equivalent to top < 100. So this is not an error. The actual error is that the program does not output a space after each popped element, and also does not output a space after "error". The problem requires a space after each output element and after "error". In the pop section, it prints "%d" without a trailing space. Also, after "error" there is a space, but the pop output lacks a space. Additionally, the program does not handle the case where a pop is attempted on an empty stack correctly because the condition top>0 should be top>=0? Actually, top starts at 0, and after push, top increments. So top indicates the number of elements. When top is 0, stack is empty. So condition top>0 is correct for non-empty. But the problem is that the output format requires a space after each popped element, but the code prints "%d" without a space. Also, the program does not output a space after the last element. The expected output shows a space after each element. So the main error is missing spaces in the output. Also, the variable 'shu' is declared but never used, which is not an error but unnecessary.]
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
                printf("%d",zhan[--top]); // @@ [Error: Missing space after the popped element. The problem requires a space after each popped element. Should be printf("%d ", ...).]
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