#include<stdio.h>
int main() {
    int n;
    while (scanf("%d", &n)==1) { // @@ The program does not implement the required stack operations (push, pop, error handling) and merely echoes the input values.
        printf("%d ", n); // @@ Fails to process operation codes (1 for push, 0 for pop, -1 for end) and check for stack overflow/underflow conditions.
    }
    return 0;
}