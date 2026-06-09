#include<stdio.h>


int main()
{
    int a;
    while(~scanf("%d",&a)) // @@ [The condition `~scanf(...)` is incorrect for detecting end-of-input. `scanf` returns the number of successfully read items, and using bitwise NOT (`~`) on it leads to undefined or unintended loop behavior. It should be `while(scanf("%d", &a) == 1)` or similar. Also, this program completely ignores the stack logic required by the problem, treating all input as values to echo, which violates the problem specification.]
    printf("%d ",a);
    return 0;
}