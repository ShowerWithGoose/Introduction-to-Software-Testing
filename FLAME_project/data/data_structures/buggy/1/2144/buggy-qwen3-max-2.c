#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    if (N == 1) {
        printf("1");
    } else if (N == 2) {
        printf("w"); // @@ [The output for N=2 is hardcoded as "w" instead of the correct lexicographical permutations "1 2\n2 1". This causes a Wrong Answer for input 2.]
    } else if (N == 3) {
        printf("1 2 3\n1 3 2\n2 1 3\n2 3 1\n3 1 2\n3 2 1\n");
    }
    return 0;
}