#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
int bool[20]; // @@ [Using 'bool' as an identifier is problematic because it may conflict with the built-in boolean type in C++ or when including certain headers in C (like stdbool.h). Although this code doesn't include stdbool.h, some compilers or environments might still treat 'bool' as a reserved keyword or cause unexpected behavior. More critically, in C99 and later, 'bool' is a macro defined in stdbool.h, but even without including it, using 'bool' as a variable name is poor practice and can lead to portability issues or compilation errors in stricter environments.]
int list[20];
void prt(int n, int i) {
    if (n == i) {
        for (int j = 0; j < n; j++)printf("%d ",list[j]);
        printf("\n");
    }
    for (int j = 1; j <= 10; j++) { // @@ [The loop runs from 1 to 10 regardless of the input value 'n'. According to the problem, permutations should be of integers from 1 to N (where N is the input, 1<=N<=10). So the loop should run from 1 to n, not 1 to 10. This causes incorrect output when n < 10 (e.g., includes numbers greater than n) and is logically wrong. However, note that the reported error is a "Compilation Error", and this line would not cause a compilation error—it causes a logical/runtime error. But since the actual compilation error likely stems from the use of 'bool', this line is not the cause of the compilation failure. Still, per instructions, we only annotate lines with errors. The primary compilation issue is the variable name 'bool'.]
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