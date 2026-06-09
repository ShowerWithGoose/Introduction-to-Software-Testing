#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
int bool[20]; // @@ 'bool' is a reserved keyword in C++ and may cause compilation errors; rename to 'used' or 'vis'.
int list[20];
void prt(int n, int i) {
    if (n == i) { // @@ Missing 'return;' after printing causes fall-through to the loop, leading to incorrect recursion and out-of-bounds access.
        for (int j = 0; j < n; j++)printf("%d ",list[j]);
        printf("\n");
    }
    for (int j = 1; j <= 10; j++) { // @@ Loop bound should be 'n' instead of 10 to correctly generate permutations of 1 to N.
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