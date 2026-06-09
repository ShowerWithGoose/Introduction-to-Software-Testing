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
            if(top<=99) // @@ Error: The condition should be top < 100 (or top <= 99) but the stack is empty when top=0, so the first push should use index 0. However, the condition allows top=99, which means the stack can hold 100 elements (indices 0-99). This is actually correct for capacity 100. The real issue is that after pushing, top is incremented, so the next push checks top<=99, which is fine. But the pop condition below has a logical error.
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
            if(top>0) // @@ Error: The condition should be top > 0, but when top=0, the stack is empty. However, after a push, top becomes 1, so the first pop should access index 0 (zhan[--top] gives zhan[0]). This is correct. But the problem is that the output format requires a space after each popped element, including the last one. The code prints "%d" without a trailing space, which does not match the expected output format.
            {
                printf("%d",zhan[--top]); // @@ Error: Missing space after the integer. The expected output requires a space after each popped element (e.g., "1 2 3 "), but this prints "123" without spaces.
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