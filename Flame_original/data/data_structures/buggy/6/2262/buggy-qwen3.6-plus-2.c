#include<stdio.h>


int main()
{
    int a;
    while(~scanf("%d",&a)) // @@ The loop condition does not correctly handle the termination value -1 and uses an unconventional bitwise NOT operator; the code completely lacks the required stack data structure and operation logic.
    printf("%d ",a); // @@ This line merely echoes the input instead of processing stack operations (push, pop) and outputting the popped sequence or "error" as required.
    return 0;
}