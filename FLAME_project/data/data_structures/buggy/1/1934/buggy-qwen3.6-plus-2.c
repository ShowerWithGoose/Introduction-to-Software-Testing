#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
int bool[20]; // @@ The variable name 'bool' shadows the standard type or keyword in some contexts, but more importantly, it is not initialized. Global arrays are zero-initialized by default in C, so this is technically okay for logic, but bad practice. However, the main error is below.
int list[20];
void prt(int n, int i) {
    if (n == i) {
        for (int j = 0; j < n; j++)printf("%d ",list[j]);
        printf("\n");
    }
    for (int j = 1; j <= 10; j++) { // @@ The loop should iterate from 1 to n, not 1 to 10. The problem requires permutations of integers from 1 to N. Iterating up to 10 generates invalid numbers if N < 10 and misses the constraint that only numbers 1..N are used.
        if (bool[j])continue;
        else {
            bool[j] = 1;
            list[i] = j;
            prt(n, i + 1);
            bool[j] = 0;
        }
    }
}
int main() {
    int n;
    scanf("%d",&n);
    prt(n, 0);
}