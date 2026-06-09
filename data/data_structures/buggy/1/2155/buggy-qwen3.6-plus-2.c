#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    if (n == 1) // @@ Should be 'else if' to match the reference program structure and avoid redundant condition checks.
        printf("1");
    if (n == 2) // @@ Should be 'else if'.
        printf("1 2\n2 1");
    if (n == 3) // @@ Should be 'else if'.
        printf("1 2 3\n1 3 2\n2 1 3\n2 3 1\n3 1 2\n3 2 1");
    if (n == 4) // @@ Should be 'else if'. Additionally, the program is incomplete as it lacks cases for N=5 to N=10 required by the problem constraints.
        printf("1 2 3 4\n1 2 4 3\n1 3 2 4\n1 3 4 2\n1 4 2 3\n1 4 3 2\n2 1 3 4\n2 1 4 3\n2 3 1 4\n2 3 4 1\n2 4 1 3\n2 4 3 1\n3 1 2 4\n3 1 4 2\n3 2 1 4\n3 2 4 1\n3 4 1 2\n3 4 2 1\n4 1 2 3\n4 1 3 2\n4 2 1 3\n4 2 3 1\n4 3 1 2\n4 3 2 1\n");

}