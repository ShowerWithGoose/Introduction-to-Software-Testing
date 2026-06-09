#include<stdio.h>


int main()
{
    int a;
    while(~scanf("%d",&a)) // @@ [The condition `~scanf(...)` is incorrect for detecting end-of-input. `scanf` returns the number of successfully read items (1 here) or EOF (-1). `~(-1)` is 0, so loop stops at EOF, which is okay, but the problem expects operations to stop only on -1, not EOF. Also, this code does not implement stack logic at all—it just echoes input integers, which is completely wrong for the problem.]
    printf("%d ",a); // @@ [This blindly prints every input integer, including operation codes (1, 0, -1) and pushed values, without distinguishing them or simulating stack behavior. It fails to handle push/pop semantics, stack capacity, or error conditions.]
    return 0;
}