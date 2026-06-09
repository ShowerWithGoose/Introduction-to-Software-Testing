#include<stdio.h>

int main()
{
    int x;
    while(scanf("%d",&x)!=EOF) // @@ [Missing braces for while loop; only the first printf is executed in the loop, and the return statement is outside the loop, causing infinite loop or incorrect output]
    
    printf("%d\n",x);
    return 0;
}