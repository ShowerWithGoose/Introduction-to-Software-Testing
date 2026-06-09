#include<stdio.h>


int main()
{
    int a;
    while(~scanf("%d",&a))
    printf("%d ",a); // @@ This line incorrectly prints every input value instead of performing stack operations. The program should implement a stack with push (1), pop (0), and end (-1) operations, and only output popped values or "error" for invalid operations.
    return 0;
}