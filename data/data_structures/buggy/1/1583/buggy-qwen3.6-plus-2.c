#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    switch(n)
    {
        case 1:
            printf("1"); // @@ Missing newline character '\n' at the end, which violates the output format requirement.
            break;
        case 2:
            printf("1 2\n");
            printf("2 1\n");
            break;
        case 3:
            printf("1 2 3\n");
            printf("1 3 2\n");
            printf("2 1 3\n");
            printf("2 3 1\n");
            printf("3 1 2\n");
            printf("3 2 1\n");
            break;
        case 4:
            printf("1 2 3 4\n");
            printf("1 2 4 3\n");
            printf("1 3 2 4\n");
            printf("1 3 4 2\n");
            printf("1 4 2 3\n");
            printf("1 4 3 2\n");
            printf("2 1 3 4\n");
            printf("2 1 4 3\n");
            printf("2 3 1 4\n");
            printf("2 3 4 1\n");
            printf("2 4 1 3\n");
            printf("2 4 3 1\n");
            printf("3 1 2 4\n");
            printf("3 1 4 2\n");
            printf("3 2 1 4\n");
            printf("3 2 4 1\n");
            printf("3 4 1 2\n");
            printf("3 4 2 1\n");
            printf("4 1 2 3\n");
            printf("4 1 3 2\n");
            printf("4 2 1 3\n");
            printf("4 2 3 1\n");
            printf("4 3 1 2\n");
            printf("4 3 2 1\n");
            break;
        case 5:
            printf("1 2 3 4 5\n");
            printf("1 2 3 5 4\n");
            printf("1 2 4 3 5\n");
            printf("1 2 4 5 3\n");
            printf("1 2 5 3 4\n");
            printf("1 2 5 4 3\n");
            printf("1 3 2 4 5\n");
            printf("1 3 2 5 4\n");
            printf("1 3 4 2 5\n");
            printf("1 3 4 5 2\n");
            printf("1 3 5 2 4\n");
            printf("1 3 5 4 2\n");
            printf("1 4 2 3 5\n");
            printf("1 4 2 5 3\n");
            printf("1 4 3 2 5\n");
            printf("1 4 3 5 2\n");
            printf("1 4 5 2 3\n");
            printf("1 4 5 3 2\n");
            printf("1 5 2 3 4\n");
            printf("1 5 2 4 3\n");
            printf("1 5 3 2 4\n");
            printf("1 5 3 4 2\n");
            printf("1 5 4 2 3\n");
            printf("1 5 4 3 2\n");
            
            printf("2 1 3 4 5\n");
            printf("2 1 3 5 4\n");
            printf("2 1 4 3 5\n");
            printf("2 1 4 5 3\n");
            printf("2 1 5 3 4\n");
            printf("2 1 5 4 3\n");
            printf("2 3 1 4 5\n");
            printf("2 3 1 5 4\n");
            printf("2 3 4 1 5\n");
            printf("2 3 4 5 1\n");
            printf("2 3 5 1 4\n");
            printf("2 3 5 4 1\n");
            printf("2 4 1 3 5\n");
            printf("2 4 1 5 3\n");
            printf("2 4 3 1 5\n");
            printf("2 4 3 5 1\n");
            printf("2 4 5 1 3\n");
            printf("2 4 5 3 1\n");
            printf("2 5 1 3 4\n");
            printf("2 5 1 4 3\n");
            printf("2 5 3 1 4\n");
            printf("2 5 3 4 1\n");
            printf("2 5 4 1 3\n");
            printf("2 5 4 3 1\n");
            
            printf("3 1 2 4 5\n");
            printf("3 1 2 5 4\n");
            printf("3 1 4 2 5\n");
            printf("3 1 4 5 2\n");
            printf("3 1 5 2 4\n");
            printf("3 1 5 4 2\n");
            printf("3 2 1 4 5\n");
            printf("3 2 1 5 4\n");
            printf("3 2 4 1 5\n");
            printf("3 2 4 5 1\n");
            printf("3 2 5 1 4\n");
            printf("3 2 5 4 1\n");
            printf("3 4 1 2 5\n");
            printf("3 4 1 5 2\n");
            printf("3 4 2 1 5\n");
            printf("3 4 2 5 1\n");
            printf("3 4 5 1 2\n");
            printf("3 4 5 2 1\n");
            printf("3 5 1 2 4\n");
            printf("3 5 1 4 2\n");
            printf("3 5 2 1 4\n");
            printf("3 5 2 4 1\n");
            printf("3 5 4 1 2\n");
            printf("3 5 4 2 1\n");
            
            printf("4 1 2 3 5\n");
            printf("4 1 2 5 3\n");
            printf("4 1 3 2 5\n");
            printf("4 1 3 5 2\n");
            printf("4 1 5 2 3\n");
            printf("4 1 5 3 2\n");
            printf("4 2 1 3 5\n");
            printf("4 2 1 5 3\n");
            printf("4 2 3 1 5\n");
            printf("4 2 3 5 1\n");
            printf("4 2 5 1 3\n");
            printf("4 2 5 3 1\n");
            printf("4 3 1 2 5\n");
            printf("4 3 1 5 2\n");
            printf("4 3 2 1 5\n");
            printf("4 3 2 5 1\n");
            printf("4 3 5 1 2\n");
            printf("4 3 5 2 1\n");
            printf("4 5 1 2 3\n");
            printf("4 5 1 3 2\n");
            printf("4 5 2 1 3\n");
            printf("4 5 2 3 1\n");
            printf("4 5 3 1 2\n");
            printf("4 5 3 2 1\n");
            
            printf("5 1 4 3 2\n"); // @@ Missing permutations starting with "5 1 2", "5 1 3", "5 1 4 2", etc., and the order is incorrect for lexicographical sorting.
            printf("5 2 1 3 4\n");
            printf("5 2 1 4 3\n");
            printf("5 2 3 1 4\n");
            printf("5 2 3 4 1\n");
            printf("5 2 4 1 3\n");
            printf("5 2 4 3 1\n");
            printf("5 3 1 2 4\n");
            printf("5 3 1 4 2\n");
            printf("5 3 2 1 4\n");
            printf("5 3 2 4 1\n");
            printf("5 3 4 1 2\n");
            printf("5 3 4 2 1\n");
            printf("5 4 1 2 3\n");
            printf("5 4 1 3 2\n");
            printf("5 4 2 1 3\n");
            printf("5 4 2 3 1\n");
            printf("5 4 3 1 2\n");
            printf("5 4 3 2 1\n");
            break; // @@ The code only handles N up to 5, but the problem constraints specify 1<=N<=10. Missing cases for N=6 to N=10.
    }
    
    return 0;
}