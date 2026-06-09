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
            scanf("%d ", &num);
            if (top > 99)
                printf("error "); // @@ should use else to avoid pushing when full
            stack[top++] = num; // @@ should be inside else block
            break;
        case 0:
            if (top == 0)
                printf("error "); // @@ should use else to avoid pop when empty
            printf("%d ", stack[top-- - 1]); // @@ missing break after case 0 (falls through to case -1); also executes even when empty
        case -1:
            break; // @@ should be return 0; to exit program on -1
        default:
            break;
        }
    }
    return 0;
}