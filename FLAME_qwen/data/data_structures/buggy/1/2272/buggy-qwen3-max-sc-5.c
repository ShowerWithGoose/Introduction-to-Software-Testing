#include "stdio.h" // @@ [Using double quotes for standard header may cause compilation issues in some environments; should use <stdio.h>]

int main() {
    int n;
    scanf("%d", &n);

    if (n == 1) {
        printf("1");
        return 0;
    } else if (n == 2) {
        printf("1 2\n");
        printf("2 1");
    } else if(n==3){
        printf("1 2 3\n");
        printf("1 3 2\n2 1 3\n2 3 1\n3 1 2\n3 2 1\n"); // @@ [Extra newline at the end of last permutation; expected no trailing newline after final line]
    } else if(n==4){
        printf("1 2 3 4\n"
               "1 2 4 3\n"
               "1 3 2 4\n"
               "1 3 4 2\n"
               "1 4 2 3\n"
               "1 4 3 2\n"
               "2 1 3 4\n"
               "2 1 4 3\n"
               "2 3 1 4\n"
               "2 3 4 1\n"
               "2 4 1 3\n"
               "2 4 3 1\n"
               "3 1 2 4\n"
               "3 1 4 2\n"
               "3 2 1 4\n"
               "3 2 4 1\n"
               "3 4 1 2\n"
               "3 4 2 1\n" // @@ [Extra newline before last group; causes an extra blank line in output]
               "4 1 2 3\n"
               "4 1 3 2\n"
               "4 2 1 3\n"
               "4 2 3 1\n"
               "4 3 1 2\n"
               "4 3 2 1"); // @@ [Missing handling for N=5 to N=10; program will produce no output for those inputs, violating problem constraints]
    }


}