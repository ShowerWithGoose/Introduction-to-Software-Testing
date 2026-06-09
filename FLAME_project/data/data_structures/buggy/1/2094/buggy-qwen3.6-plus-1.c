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
    if (n == 1) {
        printf("1"); // @@ The problem requires each integer to be followed by a space and each permutation to end with a newline. For N=1, the output should be "1 \n" or similar consistent format. More importantly, hardcoding outputs is incorrect logic, but specifically here, it misses the newline or space format consistency if strict. However, the main error is that the problem expects a general solution, not hardcoded ones. But looking at the test case N=2, the expected output is "1 2 \n" (based on typical judges) or just "1 2\n". The prompt says Expected Output: "1 2 ". Wait, the expected output in the prompt is "1 2 ". Let's look closely.
        // Actually, the primary issue is that the code hardcodes responses for small N instead of using the algorithm.
        // For N=2, it prints "1 2\n2 1". The expected output for the test case Input 2 is "1 2 ".
        // Wait, the problem description says "Output N! lines". For N=2, there are 2 permutations.
        // The "Expected Output" shown in the prompt is just "1 2 ". This looks like a truncated example or a specific single-line expectation?
        // No, "Output N! lines". For N=2, it should be 2 lines.
        // Let's re-read the "Expected Output" section carefully.
        // Test Case Input: 2
        // Buggy Output: 1 2 \n 2 1
        // Expected Output: 1 2 
        // This implies the judge might only be checking the first line? Or perhaps the "Expected Output" provided in the prompt description is incomplete/misleadingly formatted?
        // Usually, permutation problems require all permutations.
        // However, looking at the provided "Buggy Output" vs "Expected Output":
        // Buggy: "1 2\n2 1"
        // Expected: "1 2 "
        // If the expected output is truly just "1 2 ", then the problem might be asking for something else?
        // "generate all permutations... Output N! lines".
        // If N=2, N!=2. So 2 lines.
        // Why is the expected output only "1 2 "?
        // Perhaps the "Expected Output" in the prompt is actually just the *first* line, and the comparison failed because of extra newlines or spaces?
        // Or maybe the "Expected Output" listed is wrong in the prompt description provided to me?
        // Let's look at the Reference Program. It prints all permutations.
        // The Buggy Code hardcodes.
        // If I look at line 23: printf("1 2\n2 1");
        // If the judge expects "1 2 \n2 1 \n" (with trailing spaces), the hardcoded version might fail formatting.
        // But the most obvious error is the hardcoding itself which prevents generalization, but for N=2 it should work logically if formats match.
        // Let's look at the format in `permutation`: printf("%d ", ...). It adds a space after every number.
        // So for N=2, `permutation` outputs: "1 2 \n2 1 \n".
        // The hardcoded N=2 outputs: "1 2\n2 1". (No trailing spaces, no trailing newline potentially depending on interpretation).
        // The mismatch is likely due to formatting (missing trailing spaces/newlines) in the hardcoded strings compared to the general algorithm's output style or vice versa.
        // However, the instruction asks to identify errors. The hardcoding is definitely an error in implementation strategy.
        // Specifically, line 23 returns early.
        return 0;
    }
    if (n == 2) {
        printf("1 2\n2 1"); // @@ Hardcoding output is incorrect. It should use the general permutation function. Also, the format lacks trailing spaces after numbers which the general function produces ("%d "), causing a mismatch with expected output format if strict.
        return 0;
    }
    if (n == 3) {
        printf("1 2 3\n1 3 2\n2 1 3\n2 3 1\n3 1 2\n3 2 1"); // @@ Hardcoding output is incorrect. Format inconsistency (missing trailing spaces) compared to the standard output logic.
        return 0;
    }
    if (n == 4) {
        printf("1 2 3 4\n1 2 4 3\n1 3 2 4\n1 3 4 2\n1 4 2 3\n1 4 3 2\n2 1 3 4\n2 1 4 3\n2 3 1 4\n2 3 4 1\n2 4 1 3\n2 4 3 1\n3 1 2 4\n3 1 4 2\n3 2 1 4\n3 2 4 1\n3 4 1 2\n3 4 2 1\n4 1 2 3\n4 1 3 2\n4 2 1 3\n4 2 3 1\n4 3 1 2\n4 3 2 1 "); // @@ Hardcoding output is incorrect.
        return 0;
    }
    if (n == 5) {
        printf("1 2 3 4 5\n1 2 3 5 4\n1 2 4 3 5\n1 2 4 5 3\n1 2 5 3 4\n1 2 5 4 3\n1 3 2 4 5\n1 3 2 5 4\n1 3 4 2 5\n1 3 4 5 2\n1 3 5 2 4\n1 3 5 4 2\n1 4 2 3 5\n1 4 2 5 3\n1 4 3 2 5\n1 4 3 5 2\n1 4 5 2 3\n1 4 5 3 2\n1 5 2 3 4\n1 5 2 4 3\n1 5 3 2 4\n1 5 3 4 2\n1 5 4 2 3\n1 5 4 3 2\n2 1 3 4 5\n2 1 3 5 4\n2 1 4 3 5\n2 1 4 5 3\n2 1 5 3 4\n2 1 5 4 \n2 3 1 4 5\n2 3 1 5 4\n2 3 4 1 5\n2 3 4 5 \n2 3 5 1 4\n2 3 5 4 1\n2 4 1 3 5\n2 4 1 5 3\n2 4 3 1 5\n2 4 3 5 1\n2 4 5 1 3\n2 4 5 3 1\n" ); // @@ Hardcoding output is incorrect. Contains typos/incomplete permutations (e.g., "2 1 5 4 " missing last number? No, N=5. "2 1 5 4" is length 4. Missing 3?).
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