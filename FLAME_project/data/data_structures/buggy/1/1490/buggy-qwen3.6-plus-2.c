#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

//输入输出类型！循环后清零！输入取地址！数据范围！吃掉回车！输出换行！
//long long lld! while(){..i=0}! scanf("",&a)! getchar()! printf("..\n")!

int main() {
    int n;
    scanf("%d", &n);
    if (n == 1) {
        printf("1"); // @@ Missing newline character at the end of output. The expected output format requires each permutation to be on its own line, implying a trailing newline for the last line as well, or consistent formatting. More critically, looking at the test case for N=2, the expected output is "1 2 \n" (with a trailing space and newline? No, usually just newline). Let's look at the specific failure.
    }
    if (n == 2) {
        printf("1 2\n2 1"); // @@ Missing newline character at the end of the output. The expected output for N=2 is "1 2 \n2 1\n" or similar. The test case shows Expected Output: "1 2 \n". Wait, the prompt says Expected Output: "1 2 ". This looks like it might be truncated in the description or implies a specific formatting. However, standard permutation problems require a newline after each permutation. The buggy output is "1 2\n2 1". The expected output shown in the prompt is "1 2 ". This is strange. Let's re-read carefully.
        // Test Case Input: 2
        // Buggy Output: 1 2\n2 1
        // Expected Output: 1 2 
        // It seems the expected output provided in the prompt description might be incomplete or malformed ("1 2 "). Usually, it should be "1 2\n2 1\n". 
        // However, looking at the reference program, it prints "1 2\n2 1" for n=2 without a trailing newline.
        // If the judge expects a trailing newline, then both n=1 and n=2 cases are missing it.
        // Let's look at the n=1 case in the source code: printf("1"); -> Missing newline.
        // Let's look at the n=2 case in the source code: printf("1 2\n2 1"); -> Missing trailing newline.
        // In competitive programming, missing a trailing newline often causes WA or PE.
        // The error annotation should point to the missing newlines.
    }
    if (n == 3) {
        printf("1 2 3\n1 3 2\n2 1 3\n2 3 1\n3 1 2\n3 2 1"); // @@ Missing trailing newline character at the end of the output.
    }
    if (n == 4) {
        printf("1 2 3 4\n1 2 4 3\n1 3 2 4\n1 3 4 2\n1 4 2 3\n1 4 3 2\n");
        printf("2 1 3 4\n2 1 4 3\n2 3 1 4\n2 3 4 1\n2 4 1 3\n2 4 3 1\n");
        printf("3 1 2 4\n3 1 4 2\n3 2 1 4\n3 2 4 1\n3 4 1 2\n3 4 2 1\n");
        printf("4 1 2 3\n4 1 3 2\n4 2 1 3\n4 2 3 1\n4 3 1 2\n4 3 2 1\n");
    }

    return 0;
}