#include<stdio.h>


int main()
{
    int a;
    while(~scanf("%d",&a)) // @@ [The bitwise NOT operator '~' is incorrectly used for checking EOF. It should be 'while(scanf("%d",&a) != EOF)' or 'while(scanf("%d",&a) == 1)'. Using '~' causes incorrect loop behavior and may lead to infinite loops or undefined behavior.]
    printf("%d ",a);
    return 0;
}