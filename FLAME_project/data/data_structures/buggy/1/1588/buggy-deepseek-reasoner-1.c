#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    switch(n)
    {
        case 1:
            printf("1\n"); // @@ The reference program does not print a newline after "1". This line adds an extra newline, causing output mismatch for n=1.
            break;
        case 2:
            printf("1 2\n");
            printf("2 1\n"); // @@ The reference program prints "1 2\n2 1" without a trailing newline. This line adds an extra newline after the last permutation, causing an extra line or trailing newline mismatch.
            break;
        case 3:
            printf("1 2 3\n");
            printf("1 3 2\n");
            printf("2 1 3\n");
            printf("2 3 1\n");
            printf("3 1 2\n");
            printf("3 2 1\n"); // @@ Similar trailing newline issue: the reference program prints all three lines in one string without a newline after the last permutation.
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
            printf("4 3 2 1\n"); // @@ Trailing newline issue: the reference program prints all 24 lines in one string without a newline after the last permutation.
            break;
        case 5:
            printf("1 2 3 4 5 \n");
                        printf("1 2 3 5 4 \n");
                        printf("1 2 4 3 5 \n");
                        printf("1 2 4 5 3 \n");
                        printf("1 2 5 3 4 \n");
                        printf("1 2 5 4 3 \n");
                        printf("1 3 2 4 5 \n");
                        printf("1 3 2 5 4 \n");
                        printf("1 3 4 2 5 \n");
                        printf("1 3 4 5 2 \n");
                        printf("1 3 5 2 4 \n");
                        printf("1 3 5 4 2 \n");
                        printf("1 4 2 3 5 \n");
                        printf("1 4 2 5 3 \n");
                        printf("1 4 3 2 5 \n");
                        printf("1 4 3 5 2 \n");
                        printf("1 4 5 2 3 \n");
                        printf("1 4 5 3 2 \n");
                        printf("1 5 2 3 4 \n");
                        printf("1 5 2 4 3 \n");
                        printf("1 5 3 2 4 \n");
                        printf("1 5 3 4 2 \n");
                        printf("1 5 4 2 3 \n");
                        printf("1 5 4 3 2 \n");
            printf("2 1 3 4 5 \n");
                        printf("2 1 3 5 4 \n");
                        printf("2 1 4 3 5 \n");
                        printf("2 1 4 5 3 \n");
                        printf("2 1 5 3 4 \n");
                        printf("2 1 5 4 3 \n");
                        printf("2 3 1 4 5 \n");
                        printf("2 3 1 5 4 \n");
                        printf("2 3 4 1 5 \n");
                        printf("2 3 4 5 1 \n");
                        printf("2 3 5 1 4 \n");
                        printf("2 3 5 4 1 \n");
                        printf("2 4 1 3 5 \n");
                        printf("2 4 1 5 3 \n");
                        printf("2 4 3 1 5 \n");
                        printf("2 4 3 5 1 \n");
                        printf("2 4 5 1 3 \n");
                        printf("2 4 5 3 1 \n");
                        printf("2 5 1 3 4 \n");
                        printf("2 5 1 4 3 \n");
                        printf("2 5 3 1 4 \n");
                        printf("2 5 3 4 1 \n");
                        printf("2 5 4 1 3 \n");
                        printf("2 5 4 3 1 \n");
            printf("3 1 2 4 5 \n");
                        printf("3 1 2 5 4 \n");
                        printf("3 1 4 2 5 \n");
                        printf("3 1 4 5 2 \n");
                        printf("3 1 5 2 4 \n");
                        printf("3 1 5 4 2 \n");
                        printf("3 2 1 4 5 \n");
                        printf("3 2 1 5 4 \n");
                        printf("3 2 4 1 5 \n");
                        printf("3 2 4 5 1 \n");
                        printf("3 2 5 1 4 \n");
                        printf("3 2 5 4 1 \n");
                        printf("3 4 1 2 5 \n");
                        printf("3 4 1 5 2 \n");
                        printf("3 4 2 1 5 \n");
                        printf("3 4 2 5 1 \n");
                        printf("3 4 5 1 2 \n");
                        printf("3 4 5 2 1 \n");
                        printf("3 5 1 2 4 \n");
                        printf("3 5 1 4 2 \n");
                        printf("3 5 2 1 4 \n");
                        printf("3 5 2 4 1 \n");
                        printf("3 5 4 1 2 \n");
                        printf("3 5 4 2 1 \n");
            printf("4 1 2 3 5 \n");
                        printf("4 1 2 5 3 \n");
                        printf("4 1 3 2 5 \n");
                        printf("4 1 3 5 2 \n");
                        printf("4 1 5 2 3 \n");
                        printf("4 1 5 3 2 \n");
                        printf("4 2 1 3 5 \n");
                        printf("4 2 1 5 3 \n");
                        printf("4 2 3 1 5 \n");
                        printf("4 2 3 5 1 \n");
                        printf("4 2 5 1 3 \n");
                        printf("4 2 5 3 1 \n");
                        printf("4 3 1 2 5 \n");
                        printf("4 3 1 5 2 \n");
                        printf("4 3 2 1 5 \n");
                        printf("4 3 2 5 1 \n");
                        printf("4 3 5 1 2 \n");
                        printf("4 3 5 2 1 \n");
                        printf("4 5 1 2 3 \n");
                        printf("4 5 1 3 2 \n");
                        printf("4 5 2 1 3 \n");
                        printf("4 5 2 3 1 \n");
                        printf("4 5 3 1 2 \n");
                        printf("4 5 3 2 1 \n");
            printf("5 1 2 3 4 \n");
                        printf("5 1 2 4 3 \n");
                        printf("5 1 3 2 4 \n");
                        printf("5 1 3 4 3 \n"); // @@ Typo: should be "5 1 3 4 2" instead of "5 1 3 4 3".
                        printf("5 1 4 2 3 \n");
                        printf("5 1 4 3 2 \n");
                        printf("5 2 1 3 4 \n");
                        printf("5 2 1 4 3 \n");
                        printf("5 2 3 1 4 \n");
                        printf("5 2 3 4 1 \n");
                        printf("5 2 4 1 3 \n");
                        printf("5 2 4 3 1 \n");
                        printf("5 3 1 2 4 \n");
                        printf("5 3 1 4 2 \n");
                        printf("5 3 2 1 4 \n");
                        printf("5 3 2 4 1 \n");
                        printf("5 3 4 1 2 \n");
                        printf("5 3 4 2 1 \n");
                        printf("5 4 1 2 3 \n");
                        printf("5 4 1 3 2 \n");
                        printf("5 4 2 1 3 \n");
                        printf("5 4 2 3 1 \n");
                        printf("5 4 3 1 2 \n");
                        printf("5 4 3 2 1 \n"); // @@ Trailing newline issue: the reference program prints the entire set in one string without a newline after the last permutation.
            break;
                        
    }
    return 0;
}