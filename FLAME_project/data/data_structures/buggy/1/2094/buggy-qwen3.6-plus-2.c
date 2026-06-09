#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void permutation(int *a, int x, int y) {
    if (x == y - 1) {
        int j;
        for (j = 0; j < y; j++) {
            printf("%d ", *(a + j));
        }
        printf("\n");
        return;
    }

    int k = 0;
    for (k = x; k < y; k++) {
        swap(a + k, a + x);
        permutation(a, x + 1, y);
        swap(a + k, a + x);
    }
}
int a[11];

int main() {
    int n, i;
    scanf("%d", &n);
    if (n == 1) { // @@ The problem requires lexicographical order and specific formatting. Hardcoding outputs is incorrect and fragile. More importantly, the hardcoded output for n=1 is "1" but expected format usually implies a newline or consistent spacing. However, the critical error here is that the student hardcoded cases instead of using the algorithm. For N=2, the expected output in the prompt is just "1 2 " (with a trailing space based on the reference logic often seen in these problems, or specifically the test case says Expected Output: "1 2 "). Wait, looking at the Test Case Input: 2, Expected Output: "1 2 ". The buggy output was "1 2 \n2 1". The reference program prints all permutations. The problem description says "generate all permutations". For N=2, permutations are "1 2" and "2 1". Why is the expected output only "1 2 "? 
    // Re-reading carefully: "Expected Output: 1 2 ". There is a trailing space in the expected output string provided in the prompt description? Or is it just one line? 
    // Actually, looking at the reference program, it prints ALL permutations. 
    // The "Expected Output" provided in the prompt for the failed test case is `1 2 `. This looks like it might be truncated or the problem description in the prompt context is slightly misleading vs the reference code. 
    // HOWEVER, the core issue with this student code is that it hardcodes responses for small N. 
    // Let's look at the failure. Input 2. Buggy Output: `1 2\n2 1`. Expected: `1 2 `. 
    // This implies the judge expects ONLY the first permutation? No, that contradicts "generate all permutations". 
    // It is highly likely the "Expected Output" shown in the prompt `1 2 ` is actually `1 2 \n2 1 ` but formatted poorly in the description, OR the student's code has a formatting error.
    // But wait, if I look at the student code for n=2: `printf("1 2\n2 1");`. It lacks a trailing newline potentially, or spaces.
    // The real error is the hardcoding strategy which is fundamentally wrong for a general solution, but specifically for N=2, the output `1 2\n2 1` vs Expected `1 2 ` suggests the Expected Output might actually be multi-line and the prompt display is cut off, OR the expected output strictly follows the format of the reference code which prints a space after every number including the last one.
    // The student's hardcoded strings do not have a space after the last number in each line (e.g., "1 2" vs "1 2 "). The reference code `printf("%d ", a[k])` adds a space after every number.
    // So for N=2, Reference outputs: "1 2 \n2 1 \n".
    // Student outputs: "1 2\n2 1".
    // The mismatch is the missing trailing spaces and potentially newlines.
    // Therefore, the hardcoding lines are errors because they don't match the formatting of the general algorithm (which adds trailing spaces).
    
    printf("1");
    return 0;
    }
    if (n == 2) { // @@ Hardcoded output does not match the required format (missing trailing spaces after numbers and potentially missing final newline) produced by the general algorithm. The general algorithm prints "%d " for each number.
    printf("1 2\n2 1");
    return 0;
    }
    if (n == 3) { // @@ Hardcoded output does not match the required format (missing trailing spaces after numbers).
    printf("1 2 3\n1 3 2\n2 1 3\n2 3 1\n3 1 2\n3 2 1");
    return 0;
    }
    if (n == 4) { // @@ Hardcoded output does not match the required format (missing trailing spaces after numbers).
    printf("1 2 3 4\n1 2 4 3\n1 3 2 4\n1 3 4 2\n1 4 2 3\n1 4 3 2\n2 1 3 4\n2 1 4 3\n2 3 1 4\n2 3 4 1\n2 4 1 3\n2 4 3 1\n3 1 2 4\n3 1 4 2\n3 2 1 4\n3 2 4 1\n3 4 1 2\n3 4 2 1\n4 1 2 3\n4 1 3 2\n4 2 1 3\n4 2 3 1\n4 3 1 2\n4 3 2 1 ");
    return 0;
    }
    if (n == 5) { // @@ Hardcoded output is incomplete/incorrectly formatted and relies on magic strings instead of algorithmic generation.
    printf("1 2 3 4 5\n1 2 3 5 4\n1 2 4 3 5\n1 2 4 5 3\n1 2 5 3 4\n1 2 5 4 3\n1 3 2 4 5\n1 3 2 5 4\n1 3 4 2 5\n1 3 4 5 2\n1 3 5 2 4\n1 3 5 4 2\n1 4 2 3 5\n1 4 2 5 3\n1 4 3 2 5\n1 4 3 5 2\n1 4 5 2 3\n1 4 5 3 2\n1 5 2 3 4\n1 5 2 4 3\n1 5 3 2 4\n1 5 3 4 2\n1 5 4 2 3\n1 5 4 3 2\n2 1 3 4 5\n2 1 3 5 4\n2 1 4 3 5\n2 1 4 5 3\n2 1 5 3 4\n2 1 5 4 \n2 3 1 4 5\n2 3 1 5 4\n2 3 4 1 5\n2 3 4 5 \n2 3 5 1 4\n2 3 5 4 1\n2 4 1 3 5\n2 4 1 5 3\n2 4 3 1 5\n2 4 3 5 1\n2 4 5 1 3\n2 4 5 3 1\n" );
    printf("2 5 1 3 4\n2 5 1 4 3\n2 5 3 1 4\n2 5 3 4 1\n2 5 4 1 3\n2 5 4 3 1\n3 1 2 4 5\n3 1 2 5 4\n3 1 4 2 5\n3 1 4 5 2\n3 1 5 2 4\n3 1 5 4 2\n3 2 1 4 5\n3 2 1 5 4\n3 2 4 1 5\n3 2 4 5 1\n3 2 5 1 4\n3 2 5 4 1\n3 4 1 2 5\n3 4 1 5 2\n3 4 2 1 5\n3 4 2 5 1\n3 4 5 1 2\n3 4 5 2 1\n3 5 1 2 4\n3 5 1 4 2\n3 5 2 1 4\n3 5 2 4 1\n3 5 4 1 2\n3 5 4 2 1\n4 1 2 3 5\n4 1 2 5 3\n4 1 3 2 5\n4 1 3 5 2\n4 1 5 2 3\n4 1 5 3 2\n4 2 1 3 5\n4 2 1 5 3\n4 2 3 1 5\n4 2 3 5 1\n4 2 5 1 3\n4 2 5 3 1\n4 3 1 2 5\n4 3 1 5 2\n4 3 2 1 5\n4 3 2 5 1\n4 3 5 1 2\n4 3 5 2 1\n4 5 1 2 3\n4 5 1 3 2\n4 5 2 1 3\n4 5 2 3 1\n4 5 3 1 2\n4 5 3 2 1\n5 1 2 3 4\n5 1 2 4 3\n5 1 3 2 4\n5 1 3 4 2\n5 1 4 2 3\n5 1 4 3 2\n5 2 1 3 4\n5 2 1 4 3\n5 2 3 1 4\n5 2 3 4 1\n5 2 4 1 3\n5 2 4 3 1\n5 3 1 2 4\n5 3 1 4 2\n5 3 2 1 4\n5 3 2 4 1\n5 3 4 1 2\n5 3 4 2 1\n5 4 1 2 3\n5 4 1 3 2\n5 4 2 1 3\n5 4 2 3 1\n5 4 3 1 2\n5 4 3 2 1\n");
    return 0;
    }
    if (n > 1) {
        for (i = 0; i < n; i++) {
            a[i] = i + 1;
        }
    }
    permutation(a, 0, n);
    return 0;
}