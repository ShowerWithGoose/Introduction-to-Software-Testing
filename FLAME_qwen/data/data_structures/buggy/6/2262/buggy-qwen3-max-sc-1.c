#include<stdio.h>


int main()
{
    int a;
    while(~scanf("%d",&a)) // @@ [The condition `~scanf(...)` is incorrect for detecting end-of-input or failure. `scanf` returns the number of successfully read items (1 here) on success, EOF on failure. `~scanf` will be -2 on success (since ~1 = -2), which is non-zero and thus true, but when scanf fails and returns EOF (-1), ~(-1) = 0, so loop stops. However, this unconventional idiom may work in some cases, but the real issue is that the program does not implement the stack logic at all—it just echoes input integers. This code completely ignores the problem requirements: it doesn't handle operations 1, 0, -1, doesn't simulate a stack, and doesn't output popped values or "error". The compilation error mentioned in the test ("gcc: not found") is likely environmental, but the logical error is that this source code is entirely unrelated to the problem.]
    printf("%d ",a);
    return 0;
}