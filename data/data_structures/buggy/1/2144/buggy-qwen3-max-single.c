#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    if (N == 1) {
        printf("1"); // @@ [Missing newline character '\n' at the end of output for N=1, which violates the output format requiring each permutation on its own line]
    } else if (N == 2) {
        printf("w"); // @@ [Incorrect output: prints 'w' instead of the expected permutations "1 2\n2 1\n"; this is a logical error that causes wrong output for N=2]
    } else if (N == 3) {
        printf("1 2 3\n1 3 2\n2 1 3\n2 3 1\n3 1 2\n3 2 1\n");
    }
    return 0;
}