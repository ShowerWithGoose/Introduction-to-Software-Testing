#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    if (N == 1) {
        printf("1"); // @@ [Missing newline character '\n' at the end of output; expected "1\n" to match required output format]
    } else if (N == 2) {
        printf("w"); // @@ [Incorrect output: printing 'w' instead of valid permutations "1 2\n2 1\n"; this causes wrong and incomplete output]
    } else if (N == 3) {
        printf("1 2 3\n1 3 2\n2 1 3\n2 3 1\n3 1 2\n3 2 1\n");
    }
    return 0;
}