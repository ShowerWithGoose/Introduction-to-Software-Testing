#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    if (N == 1) {
        printf("1"); // @@ Missing newline character '\n' at the end, which violates the output format requirement.
    } else if (N == 2) {
        printf("w"); // @@ Incorrect output string. Should print the permutations for N=2, i.e., "1 2\n2 1\n".
    } else if (N == 3) { // @@ The code only handles N up to 3, but the problem requires handling N up to 10. Missing cases for N=4 to 10.
        printf("1 2 3\n1 3 2\n2 1 3\n2 3 1\n3 1 2\n3 2 1\n");
    }
    return 0;
}