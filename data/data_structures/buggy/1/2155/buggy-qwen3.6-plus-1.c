#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    if (n == 1)
        printf("1"); // @@ Missing newline '\n' at the end, which violates the output format requirement that each permutation should be on a separate line.
    if (n == 2) // @@ Should be 'else if' to avoid redundant condition checks and match the logical flow of mutually exclusive cases.
        printf("1 2\n2 1"); // @@ Missing trailing newline '\n' for the last permutation, causing incorrect output formatting.
    if (n == 3) // @@ Should be 'else if' to avoid redundant condition checks and match the logical flow of mutually exclusive cases.
        printf("1 2 3\n1 3 2\n2 1 3\n2 3 1\n3 1 2\n3 2 1"); // @@ Missing trailing newline '\n' for the last permutation, causing incorrect output formatting.
    if (n == 4) // @@ Should be 'else if' to avoid redundant condition checks and match the logical flow of mutually exclusive cases.
        printf("1 2 3 4\n1 2 4 3\n1 3 2 4\n1 3 4 2\n1 4 2 3\n1 4 3 2\n2 1 3 4\n2 1 4 3\n2 3 1 4\n2 3 4 1\n2 4 1 3\n2 4 3 1\n3 1 2 4\n3 1 4 2\n3 2 1 4\n3 2 4 1\n3 4 1 2\n3 4 2 1\n4 1 2 3\n4 1 3 2\n4 2 1 3\n4 2 3 1\n4 3 1 2\n4 3 2 1\n");

} // @@ Missing 'return 0;' statement and the code does not handle input values for N=5 to 10 as specified in the problem constraints.