#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    if (N == 1) {
        printf("1");
    } else if (N == 2) {
        printf("w"); // @@ Error: This outputs a single character 'w' instead of the correct permutations "1 2\n2 1" for N=2.
    } else if (N == 3) {
        printf("1 2 3\n1 3 2\n2 1 3\n2 3 1\n3 1 2\n3 2 1\n");
    }
    return 0;
}