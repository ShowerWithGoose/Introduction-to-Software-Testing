#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
int bool[20]; // @@ [Using 'bool' as an identifier is problematic because 'bool' is a reserved keyword in C++ and can cause conflicts or confusion; although it's not a keyword in C89, it may still cause issues with certain compilers or standards. However, the actual compilation error here is likely due to missing inclusion of <stdbool.h> if using 'bool' as a type, but in this code 'bool' is used as an array name, which is allowed in C. The real issue causing the "gcc: not found" error is external to the code (compiler not installed), but since the problem states to find errors in the program and the reference uses a different approach, the deeper logical error is that the loop in prt goes up to 10 instead of n, causing incorrect permutations for n < 10. However, the immediate compilation concern is not in the code itself. But per instructions focusing on code logic matching the problem: the loop bound should be n, not 10.]
int list[20];
void prt(int n, int i) {
    if (n == i) {
        for (int j = 0; j < n; j++)printf("%d ",list[j]);
        printf("\n");
    }
    for (int j = 1; j <= 10; j++) { // @@ [This loop should iterate from 1 to n, not 1 to 10. Since the problem requires permutations of 1 to N, using 10 here causes inclusion of numbers greater than N when N < 10, leading to incorrect output.]
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