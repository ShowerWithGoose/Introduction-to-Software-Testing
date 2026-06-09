#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
int bool[20]; // @@ [Using 'bool' as an identifier is problematic because 'bool' is a reserved keyword in C++ and can cause issues or confusion; although it's not a keyword in C89, it's defined as a macro in stdbool.h. However, the real compilation error here is likely due to missing inclusion of stdbool.h if intended to use boolean type, but more critically, the array size and logic assume N<=10 yet loop up to 10 regardless of input N, which doesn't match problem constraints. But the immediate compilation error reason is actually that 'bool' might not be recognized as a type if stdbool.h isn't included — however, in this code, 'bool' is used as an array name, which is allowed in C (since bool isn't a keyword in C without stdbool.h), so this may not be the issue. The actual compilation error reported was "gcc: not found", which is an environment issue, not code issue. But since the problem states there's a compilation error in the code, the likely real error is that the code uses 'bool' as a variable name which could conflict if stdbool.h were included, but it's not. However, looking deeper: the main logical error causing incorrect output (not compilation) is that the loop in prt goes from j=1 to 10 always, even if n<10, which violates the problem requirement to permute 1..N. But the problem says "Compilation Error", yet the test case shows "/bin/sh: 1: gcc: not found" which is not a code error. Given the instructions, we must assume the code has a compilation error. The only plausible C compilation error here is that 'bool' is not a valid type unless stdbool.h is included. But in this code, 'bool' is used as an array name, not a type, so it's syntactically valid in C. However, some compilers might have issues? Actually, no. The real issue is likely that the problem expects permutations of 1..N, but the code hardcodes loop to 10. But that's a logic error, not compilation. Since the user insists on compilation error and the provided output says "gcc: not found", which is external, but the instruction says to find error in program. Re-examining: the code uses 'bool' as an identifier. In C99+, if stdbool.h is included, 'bool' becomes a macro for _Bool, making 'int bool[20];' invalid. But stdbool.h is not included here, so it's allowed. However, the name 'bool' is still risky. But technically, this code should compile in standard C. Given the contradiction, and since the problem states there's a compilation error, the most likely intended error is that the loop bound is fixed to 10 instead of using 'n', but that doesn't cause compilation error. Wait—the problem says the reference program is correct, and the buggy program fails test cases. The test case input is missing, but expected output is permutations of 1..N. The bug is that the loop in prt goes to 10 always, so for N<10, it generates permutations including numbers >N, which is wrong. But again, not compilation. However, the user says "Error type: Compilation Error", but the shown output is "gcc: not found", which is not code-related. Given the instructions, we must annotate based on logical errors that would cause wrong output, but the problem says "Compilation Error". This is confusing. But looking at the code: the function 'prt' has a for-loop that runs j from 1 to 10, but it should run from 1 to n. This causes incorrect output (logic error), not compilation. However, the problem might have misclassified the error. Since the instruction says to identify location of errors, and the output is wrong because of this, we'll annotate that line as the source of the logical error that leads to incorrect output, even though it's not a compilation error. But the problem states "Compilation Error", so perhaps there's another issue. Another possibility: the array 'bool' is of size 20, but if N>10, it could overflow, but problem states N<=10. So safe. The real issue is the loop bound. Given the context, the intended error is the hardcoded 10. So:]
int list[20];
void prt(int n, int i) {
    if (n == i) {
        for (int j = 0; j < n; j++)printf("%d ",list[j]);
        printf("\n");
    }
    for (int j = 1; j <= 10; j++) { // @@ [The loop should iterate from 1 to n (inclusive), not 1 to 10, because the problem requires permutations of integers from 1 to N. Using 10 causes inclusion of numbers greater than N when N < 10, leading to incorrect permutations and violating the problem constraints.]
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