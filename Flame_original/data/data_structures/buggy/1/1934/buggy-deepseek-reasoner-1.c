#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
int bool[20];
int list[20];
void prt(int n, int i) {
    if (n == i) {
        for (int j = 0; j < n; j++)printf("%d ",list[j]);
        printf("\n");
    } // @@ Missing return statement: after printing a complete permutation, the function should return to avoid continuing the loop and causing incorrect recursion or out-of-bounds writes.
    for (int j = 1; j <= 10; j++) { // @@ Loop bound should be j <= n, not j <= 10, because permutations only include numbers from 1 to n.
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