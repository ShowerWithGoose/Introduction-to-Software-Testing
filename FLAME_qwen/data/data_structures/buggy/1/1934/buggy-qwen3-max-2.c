#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
int bool[20]; // @@ [Using 'bool' as an identifier is problematic because 'bool' is a reserved keyword in C++ and can cause conflicts or confusion; although it's not a keyword in C89, it may still cause issues with some compilers or standards. More critically, the array size may be insufficient if N > 10, but the main error causing compilation failure is likely the use of 'bool' without including <stdbool.h> if intended as boolean type. However, the actual compilation error in the test environment ("gcc: not found") suggests a system issue, but assuming the code itself has a semantic/compilation flaw under standard C, using 'bool' as a variable name is unsafe and may conflict if <stdbool.h> is implicitly included or in C99+ mode.]
int list[20];
void prt(int n, int i) {
    if (n == i) {
        for (int j = 0; j < n; j++)printf("%d ",list[j]);
        printf("\n");
    }
    for (int j = 1; j <= 10; j++) { // @@ [This loop always iterates from 1 to 10 regardless of input N. If N < 10, it will generate permutations with numbers beyond N, which is incorrect. If N > 10 (though problem says N<=10), it would still cap at 10. But more importantly, this causes wrong output, not compilation error. However, the primary compilation-related issue is the use of 'bool' as a variable name without proper type definition.]
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