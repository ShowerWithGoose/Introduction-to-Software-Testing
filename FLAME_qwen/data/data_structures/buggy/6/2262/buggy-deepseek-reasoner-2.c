#include<stdio.h>


int main()
{
    int a;
    while(~scanf("%d",&a)) // @@ The program completely deviates from the problem description; it should handle stack operations (1 for push, 0 for pop, -1 to end) and output only popped values or "error", not simply read and print all integers.
    printf("%d ",a); // @@ This line incorrectly prints every input integer; the logic for stack operations (line, outline) and error handling is missing.
    return 0;
}