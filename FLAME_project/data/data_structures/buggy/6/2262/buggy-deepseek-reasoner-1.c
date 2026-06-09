#include<stdio.h>

int main()
{
    int a;
    while(~scanf("%d",&a))
    printf("%d ",a); // @@ Error: Does not implement stack operations; simply prints all input instead of handling push/pop commands and outputting only popped values.
    return 0;
}