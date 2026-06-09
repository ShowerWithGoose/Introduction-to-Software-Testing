#include<stdio.h>


int main()
{
    int a;
    while(~scanf("%d",&a)) // @@ [This loop does not interpret operation codes; it just reads and prints all integers instead of implementing stack operations.]
    printf("%d ",a); // @@ [This prints every input value, whereas it should only print popped elements or "error" based on stack state.]
    return 0;
}