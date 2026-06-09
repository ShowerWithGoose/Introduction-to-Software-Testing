#include "stdio.h" // @@ Standard library headers should be included using angle brackets <stdio.h>; using quotes may lead to compilation errors if the compiler cannot locate the file in the current directory.

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
        printf("1 3 2\n2 1 3\n2 3 1\n3 1 2\n3 2 1\n");
    } else if(n==4){ // @@ The code only handles N up to 4, but the problem specifies 1<=N<=10. This hardcoded approach will produce no output for N=5 to 10 and should be replaced with a recursive backtracking algorithm.
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
               "3 4 2 1\n"
               "4 1 2 3\n"
               "4 1 3 2\n"
               "4 2 1 3\n"
               "4 2 3 1\n"
               "4 3 1 2\n"
               "4 3 2 1");
    }


} // @@ Missing implementation for N=5 to 10. The program fails to meet the problem constraints and requires a general permutation generation logic.