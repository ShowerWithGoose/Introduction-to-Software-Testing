#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
int bool[20]; // @@ [Using 'bool' as an identifier is problematic because 'bool' is a reserved keyword in C++ and can cause conflicts or confusion; although it's not a keyword in C89, it's defined as a macro in <stdbool.h> if included, but more critically, some compilers or environments may treat it as reserved or cause naming conflicts. However, the actual compilation error here is likely due to missing standard library inclusion for proper setup, but the primary issue causing failure in strict C environments is that 'bool' is not a valid type unless stdbool.h is included. Since the array is used as an integer flag array, using 'bool' as a variable name is acceptable in pure C without stdbool.h, BUT the real error is that the loop in prt goes up to 10 always, not up to n, which causes incorrect output, not compilation error. However, the reported error is "gcc: not found", which is a system error, not code error. But given the context, the actual bug causing logical error (not compilation) is the loop bound. Yet the problem states "Compilation Error", which contradicts. Re-examining: the code uses 'bool' as an array name — this is allowed in C (without stdbool.h), so not a compilation error. The true issue leading to wrong output is the loop condition. But the user says "Error type: Compilation Error" and the buggy output is "/bin/sh: 1: gcc: not found", which indicates the environment lacks gcc, not a code error. However, per instructions, we must find errors in the program that would cause failure. Given the discrepancy, the only plausible code-related issue that could cause a compilation error in some contexts is using 'bool' without including <stdbool.h> if the compiler treats it strictly. But in standard C without stdbool.h, 'bool' is just an identifier. Alternatively, the real logical error is the loop runs to 10 instead of n. But the problem says "Compilation Error". This is confusing. However, looking at the reference program vs buggy code: the buggy code loops j from 1 to 10 always, but should loop to n. That causes wrong output, not compilation error. But the test case input is missing, and expected output is missing. Given the instruction to identify location of errors based on failed test cases, and the output being wrong (not compilation), but the error type says "Compilation Error", there's inconsistency. However, the only line that could potentially cause a compilation issue in some strict environments is using 'bool' as a variable name if <stdbool.h> is implicitly included or if the compiler has issues. But realistically, the main bug is the loop bound. Since the problem states the program failed test cases (implying runtime/logical error, despite saying "Compilation Error"), and the output is wrong, the error is in the loop limit. So the for loop should go to n, not 10. Thus, the line with "j <= 10" is wrong.]
void prt(int n, int i) {
    if (n == i) {
        for (int j = 0; j < n; j++)printf("%d ",list[j]);
        printf("\n");
    }
    for (int j = 1; j <= 10; j++) { // @@ [The loop should iterate from 1 to n (inclusive), not 1 to 10, because we need permutations of 1..N, not 1..10. When N < 10, this includes invalid numbers; when N > 10 (but N<=10 per problem, so only N<10 is issue), it still works for N=10 but fails for N<10 by including numbers greater than N. This causes incorrect permutations and violates the problem requirement.]
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