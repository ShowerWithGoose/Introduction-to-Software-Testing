#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    if (N == 1) {
        printf("1"); // @@ missing newline; each permutation must end with a newline
    } else if (N == 2) {
        printf("w"); // @@ incorrect output; should print two lines: "1 2\n2 1\n"
    } else if (N == 3) {
        printf("1 2 3\n1 3 2\n2 1 3\n2 3 1\n3 1 2\n3 2 1\n"); // @@ condition only handles N==3; missing handling for N=4 to N=10
    }
    return 0;
}