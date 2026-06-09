#include<stdio.h>


int main()
{
    int a; // @@ [Logical Error: Only a single integer variable is declared. The problem requires an array for the stack and a variable to track the top index.]
    while(~scanf("%d",&a)) // @@ [Logical Error: The loop does not parse the operation codes (1 for push, 0 for pop, -1 for end) and lacks the termination condition for -1.]
    printf("%d ",a); // @@ [Logical Error: This merely echoes the input instead of implementing push/pop operations, checking stack boundaries, and handling "error" cases.]
    return 0;
}