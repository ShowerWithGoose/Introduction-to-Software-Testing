#include <stdio.h>
int a[105];
int b[105];

void pailie(int *a, int *b, int n, int depth) {
    if (depth == n + 1) {
        for (int i = 1; i <= n; i++) {
            printf("%d", a[i]);
        }
        printf("\n");
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (b[i] == 0) {
            b[i] = 1;
            a[depth] = i;
            pailie(a, b, n, depth + 1);
            b[i] = 0;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    pailie(a, b, n, 1);
} // @@ [Missing return statement in main function may cause undefined behavior in some environments, though not always a compilation error. However, the actual compilation error indicated by "/bin/sh: 1: gcc: not found" suggests the environment lacks a compiler, but assuming that's external, the code itself has another issue: missing space between numbers in output as per problem requirement. But since the error type is "Compilation Error", and the code compiles in standard C (C99+), the real issue might be that the code uses variable-length for loop counters (int i in for loop) which requires C99 or later. However, the most likely intended error is that the output format is wrong (missing space), but that's a logical error, not compilation. Given the discrepancy, and since the problem states "Compilation Error", yet the code is syntactically valid in C99+, the only plausible compilation issue in strict C89 would be declaration of 'i' inside for loop. But the reference program also does that. Alternatively, the actual bug causing failure is output format: missing space after each number. However, the problem says error type is Compilation Error, but the provided buggy output indicates a missing compiler. Since we must assume the code itself has a compilation error, and given the constraints, there is no actual compilation error in the code under C99+. But the problem insists there is. Re-examining: the function pailie is called with global arrays a and b, but the function parameters shadow the global names. This is allowed in C and not a compilation error. Therefore, the only possible explanation consistent with the problem's claim of "Compilation Error" is that the environment uses an old C standard (like C89) where declaring variables inside for loops is invalid. However, both the reference and buggy code do that. Alternatively, the real issue is that the code doesn't include <stdlib.h> or other headers—but it doesn't need to. Given all this, the problem might have misclassified the error. But per instructions, we must mark lines with potential errors. The output format is definitely wrong (no space between numbers), but that's runtime. Since the error type is stated as Compilation Error, and the only line that could cause a compilation issue in very strict settings is the for-loop variable declaration, but that's on multiple lines. However, the problem expects us to find an error based on failed test cases. Looking at expected vs actual output: the program outputs digits without spaces, e.g., "123" instead of "1 2 3". So the error is in the printf statement missing a space. But that's not a compilation error. Given the confusion, and since the problem says "Compilation Error" but the output shows a missing compiler, perhaps the real issue is elsewhere. However, the instructions say: based on test case inputs, program output, expected output. The test case input isn't shown, but expected output should have spaces. The program outputs without spaces. So the error is in the printf line. Even though it's not a compilation error, the problem might have mislabeled. We'll treat it as the critical error.]