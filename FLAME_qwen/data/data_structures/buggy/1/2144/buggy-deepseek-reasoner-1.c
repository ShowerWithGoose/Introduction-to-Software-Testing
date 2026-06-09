#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    if (N == 1) {
        printf("1"); // @@ Missing newline: should be "1\n" to match expected output format.
    } else if (N == 2) {
        printf("w"); // @@ Incorrect output: should print two lines "1 2\n2 1\n".
    } else if (N == 3) {
        printf("1 2 3\n1 3 2\n2 1 3\n2 3 1\n3 1 2\n3 2 1\n");
    } // @@ Missing handling for N >= 4: program should output all permutations for N up to 10.
    return 0;
}