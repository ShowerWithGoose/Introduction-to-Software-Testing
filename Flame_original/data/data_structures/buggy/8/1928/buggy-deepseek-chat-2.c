#include<stdio.h>

int main()
{
    int x;
    while(scanf("%d",&x)!=EOF) // @@ [Missing braces for while loop; only the next line is executed, causing infinite loop and incorrect output]
    
    printf("%d\n",x);
    return 0;
}