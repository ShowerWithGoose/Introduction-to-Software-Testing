#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
int bool[20]; // @@ Variable name 'bool' shadows a standard type/keyword in C++ or common libraries, but more importantly, it is not initialized. Global arrays are zero-initialized by default in C, so this is technically okay for logic, but bad practice. However, the real error is below.
int list[20];
void prt(int n, int i) {
    if (n == i) {
        for (int j = 0; j < n; j++)printf("%d ",list[j]);
        printf("\n");
    }
    for (int j = 1; j <= 10; j++) { // @@ The loop bound is hardcoded to 10 instead of using the input parameter n. This causes the program to generate permutations involving numbers up to 10 even if N is smaller (e.g., N=1), leading to extra incorrect output lines.
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