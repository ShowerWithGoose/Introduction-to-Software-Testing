#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
int bool[20]; // @@ [Using 'bool' as an identifier is problematic because 'bool' is a keyword in C++ and can conflict with standard headers or cause confusion; more critically, in C99 and later, including <stdbool.h> defines 'bool', but even without it, using 'bool' as a variable name is poor practice and may cause compilation issues in some environments. However, the primary error here is that the array size and loop bounds do not adapt to input N (which is <=10), but the real compilation issue is likely due to 'bool' being a reserved word in some compilers or contexts.]
int list[20];
void prt(int n, int i) {
    if (n == i) {
        for (int j = 0; j < n; j++)printf("%d ",list[j]);
        printf("\n");
    }
    for (int j = 1; j <= 10; j++) { // @@ [This loop always runs from 1 to 10 regardless of the input value of 'n'. It should run from 1 to 'n' to generate permutations of 1..n. However, this is a logical error, not a compilation error. The actual compilation error is more likely due to the use of 'bool' as a variable name which may conflict in certain compiler settings.]
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