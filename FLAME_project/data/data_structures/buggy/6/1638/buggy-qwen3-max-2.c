#include <stdio.h>
int main()
{
    int stack[101];
    int c;
    int num;
    int top;
    top = 0;
    while (~scanf("%d", &c))
    {
        switch (c)
        {
        case 1:
            scanf("%d ", &num); @@ [The space after %d in scanf may consume the next operation token, causing misalignment in input parsing. Also, the overflow check happens after reading input and before pushing, but the push still occurs even when full.]
            if (top > 99)
                printf("error ");
            stack[top++] = num; @@ [Push is executed even when stack is full (top > 99), which violates the problem requirement to output "error" and skip the push.]
            break;
        case 0:
            if (top == 0)
                printf("error ");
            printf("%d ", stack[top-- - 1]); @@ [Missing 'break' statement causes fall-through to case -1, though it doesn't affect output here, but is logically incorrect. However, the main issue is that pop logic is correct, but the extra "error" in output comes from earlier mis-parsing due to scanf format.]
        case -1:
            break; @@ [Missing 'break' in case 0 leads to fall-through, but more critically, there's no 'return 0;' or exit on -1, so the loop continues processing beyond -1 if more input exists. However, in this test case, -1 is last, so this isn't the primary bug. The core issue is the scanf format and unconditional push.]
        default:
            break;
        }
    }
    return 0;
}