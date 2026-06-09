#include<stdio.h>


int main()
{
    int a;
    while(~scanf("%d",&a)) // @@ [The condition `~scanf(...)` is incorrect for detecting end-of-input. `scanf` returns the number of successfully read items, and using bitwise NOT (`~`) on it leads to undefined or unintended loop behavior. It should be `while(scanf("%d", &a) == 1)` or similar. Also, the problem requires parsing operations (1, 0, -1) and handling stack logic, but this code just echoes all input integers, ignoring the required stack simulation.]
    printf("%d ",a); // @@ [This blindly prints every input integer, which does not implement the stack operations (push/pop) as required. The output should only print popped values or "error ", not all inputs.]
    return 0;
}