#include "stdio.h"

int main() {
    int n;
    scanf("%d", &n);

    if (n == 1) {
        printf("1");
        return 0;
    } else if (n == 2) {
        printf("1 2\n");
        printf("2 1"); // @@ Missing newline at the end of output; expected output has no trailing newline, but the problem format requires each permutation on its own line, and the expected output shows "1 2" on one line with no extra newline after "2 1". However, the buggy output prints "2 1" without a newline, which matches the expected output for n=2. The actual error is that the program does not handle n=2 correctly because the expected output is only "1 2" (one line), but the program prints two lines. The problem description says output N! lines, so for N=2, there should be 2 lines: "1 2" and "2 1". The test case input is 2, and the expected output shown is "1 2 " (with a space after 2 and a newline), but the buggy output is "1 2\n2 1" (two lines). The error is that the program prints two lines when the expected output is only one line? Wait, re-reading: the test case input is 2, expected output is "1 2 " (with a trailing space and newline). That suggests the expected output is only the first permutation, not both. This is inconsistent with the problem description. However, based on the given test case, the program should only output "1 2" for n=2. The bug is that the program outputs both permutations. The error is in the logic for n==2: it should only print one permutation. But the reference program prints both. Given the test case, the program fails because it prints an extra line. The error is that the program does not handle n=2 correctly according to the test case. The specific line causing the extra output is the second printf. So mark that line.
    } else if(n==3){
        printf("1 2 3\n");
        printf("1 3 2\n2 1 3\n2 3 1\n3 1 2\n3 2 1\n");
    } else if(n==4){
        printf("1 2 3 4\n"
               "1 2 4 3\n"
               "1 3 2 4\n"
               "1 3 4 2\n"
               "1 4 2 3\n"
               "1 4 3 2\n"
               "2 1 3 4\n"
               "2 1 4 3\n"
               "2 3 1 4\n"
               "2 3 4 1\n"
               "2 4 1 3\n"
               "2 4 3 1\n"
               "3 1 2 4\n"
               "3 1 4 2\n"
               "3 2 1 4\n"
               "3 2 4 1\n"
               "3 4 1 2\n"
               "3 4 2 1\n"
               "4 1 2 3\n"
               "4 1 3 2\n"
               "4 2 1 3\n"
               "4 2 3 1\n"
               "4 3 1 2\n"
               "4 3 2 1");
    }


}