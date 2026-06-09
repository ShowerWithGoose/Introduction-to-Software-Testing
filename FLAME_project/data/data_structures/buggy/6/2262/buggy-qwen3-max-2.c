#include<stdio.h>


int main()
{
    int a;
    while(~scanf("%d",&a))
    printf("%d ",a); // @@ [The program simply prints every input integer as it reads it, without implementing any stack logic. It does not handle push (1), pop (0), or termination (-1) operations correctly. For the test case "1 567 0 -1", it outputs all inputs including operation codes, instead of only outputting popped values (567).]
    return 0;
}