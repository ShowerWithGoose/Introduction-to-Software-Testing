#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    switch(n)
    {
        case 1:
            printf("1");
            break;
        case 2:
            printf("1 2\n"); // @@ The expected output for N=2 is "1 2 " (with a trailing space and no newline, or potentially just "1 2" depending on strictness, but the provided expected output "1 2 " suggests a specific format issue). However, looking at the reference program, it prints "1 2\n2 1". The buggy code prints "1 2\n" then "2 1\n". The test case input is 2. The expected output is "1 2 ". This implies the problem might expect only the first permutation or has a very specific formatting requirement not met by printing all permutations with newlines. Wait, looking closer at the Expected Output: "1 2 ". It seems truncated or specific. Let's re-read carefully.
            // Actually, usually these problems require ALL permutations. The reference program prints all.
            // The "Expected Output" shown in the prompt is "1 2 ". This looks like it might be a partial match error or a specific formatting error where the judge expects no newline at the end of the last line, or spaces instead of newlines?
            // Let's look at the Reference Program for Case 2: `printf("1 2\n2 1");`. It does NOT have a trailing newline.
            // The Buggy Code for Case 2: `printf("1 2\n"); printf("2 1\n");`. This HAS a trailing newline.
            // Many online judges are strict about trailing newlines. If the expected output is exactly "1 2\n2 1" (no final newline), then printing a final newline causes a Wrong Answer.
            // However, the "Expected Output" listed in the prompt is just "1 2 ". This is confusing. It might be that the display is cut off.
            // Let's assume the standard error here is the trailing newline on the last permutation.
            // But wait, if I look at Case 1: `printf("1");` (No newline).
            // Case 2 Reference: `printf("1 2\n2 1");` (Newline between, none at end).
            // Buggy Case 2: Prints newline after "2 1".
            // So the error is likely the extra newline at the end of the last permutation for each case.
            
            // Let's look at the specific line causing the issue for Input 2.
            // Line 13: printf("1 2\n"); -> Correctly separates first and second.
            // Line 14: printf("2 1\n"); -> Adds a newline at the very end.
            // The reference implementation does NOT add a newline at the very end.
            printf("2 1\n"); // @@ Extra trailing newline. The reference program outputs "1 2\n2 1" without a final newline. This causes a mismatch in strict output comparison.
            break;
        case 3:
            printf("1 2 3\n");
            printf("1 3 2\n");
            printf("2 1 3\n");
            printf("2 3 1\n");
            printf("3 1 2\n");
            printf("3 2 1\n"); // @@ Extra trailing newline. Similar to case 2, the last line should not have a trailing newline to match the reference behavior strictly, although often judges ignore single trailing newlines. Given the WA, this is the likely culprit across all cases.
            break;
        case 4:
            printf("1 2 3 4\n");
            printf("1 2 4 3\n");
            printf("1 3 2 4\n");
            printf("1 3 4 2\n");
            printf("1 4 2 3\n");
            printf("1 4 3 2\n");
            printf("2 1 3 4\n");
            printf("2 1 4 3\n");
            printf("2 3 1 4\n");
            printf("2 3 4 1\n");
            printf("2 4 1 3\n");
            printf("2 4 3 1\n");
            printf("3 1 2 4\n");
            printf("3 1 4 2\n");
            printf("3 2 1 4\n");
            printf("3 2 4 1\n");
            printf("3 4 1 2\n");
            printf("3 4 2 1\n");
            printf("4 1 2 3\n");
            printf("4 1 3 2\n");
            printf("4 2 1 3\n");
            printf("4 2 3 1\n");
            printf("4 3 1 2\n");
            printf("4 3 2 1\n"); // @@ Extra trailing newline.
            break;
        case 5:
            printf("1 2 3 4 5\n");
            printf("1 2 3 5 4\n");
            printf("1 2 4 3 5\n");
            printf("1 2 4 5 3\n");
            printf("1 2 5 3 4\n");
            printf("1 2 5 4 3\n");
            printf("1 3 2 4 5\n");
            printf("1 3 2 5 4\n");
            printf("1 3 4 2 5\n");
            printf("1 3 4 5 2\n");
            printf("1 3 5 2 4\n");
            printf("1 3 5 4 2\n");
            printf("1 4 2 3 5\n");
            printf("1 4 2 5 3\n");
            printf("1 4 3 2 5\n");
            printf("1 4 3 5 2\n");
            printf("1 4 5 2 3\n");
            printf("1 4 5 3 2\n");
            printf("1 5 2 3 4\n");
            printf("1 5 2 4 3\n");
            printf("1 5 3 2 4\n");
            printf("1 5 3 4 2\n");
            printf("1 5 4 2 3\n");
            printf("1 5 4 3 2\n");
            
            printf("2 1 3 4 5\n");
            printf("2 1 3 5 4\n");
            printf("2 1 4 3 5\n");
            printf("2 1 4 5 3\n");
            printf("2 1 5 3 4\n");
            printf("2 1 5 4 3\n");
            printf("2 3 1 4 5\n");
            printf("2 3 1 5 4\n");
            printf("2 3 4 1 5\n");
            printf("2 3 4 5 1\n");
            printf("2 3 5 1 4\n");
            printf("2 3 5 4 1\n");
            printf("2 4 1 3 5\n");
            printf("2 4 1 5 3\n");
            printf("2 4 3 1 5\n");
            printf("2 4 3 5 1\n");
            printf("2 4 5 1 3\n");
            printf("2 4 5 3 1\n");
            printf("2 5 1 3 4\n");
            printf("2 5 1 4 3\n");
            printf("2 5 3 1 4\n");
            printf("2 5 3 4 1\n");
            printf("2 5 4 1 3\n");
            printf("2 5 4 3 1\n");
            
            printf("3 1 2 4 5\n");
            printf("3 1 2 5 4\n");
            printf("3 1 4 2 5\n");
            printf("3 1 4 5 2\n");
            printf("3 1 5 2 4\n");
            printf("3 1 5 4 2\n");
            printf("3 2 1 4 5\n");
            printf("3 2 1 5 4\n");
            printf("3 2 4 1 5\n");
            printf("3 2 4 5 1\n");
            printf("3 2 5 1 4\n");
            printf("3 2 5 4 1\n");
            printf("3 4 1 2 5\n");
            printf("3 4 1 5 2\n");
            printf("3 4 2 1 5\n");
            printf("3 4 2 5 1\n");
            printf("3 4 5 1 2\n");
            printf("3 4 5 2 1\n");
            printf("3 5 1 2 4\n");
            printf("3 5 1 4 2\n");
            printf("3 5 2 1 4\n");
            printf("3 5 2 4 1\n");
            printf("3 5 4 1 2\n");
            printf("3 5 4 2 1\n");
            
            printf("4 1 2 3 5\n");
            printf("4 1 2 5 3\n");
            printf("4 1 3 2 5\n");
            printf("4 1 3 5 2\n");
            printf("4 1 5 2 3\n");
            printf("4 1 5 3 2\n");
            printf("4 2 1 3 5\n");
            printf("4 2 1 5 3\n");
            printf("4 2 3 1 5\n");
            printf("4 2 3 5 1\n");
            printf("4 2 5 1 3\n");
            printf("4 2 5 3 1\n");
            printf("4 3 1 2 5\n");
            printf("4 3 1 5 2\n");
            printf("4 3 2 1 5\n");
            printf("4 3 2 5 1\n");
            printf("4 3 5 1 2\n");
            printf("4 3 5 2 1\n");
            printf("4 5 1 2 3\n");
            printf("4 5 1 3 2\n");
            printf("4 5 2 1 3\n");
            printf("4 5 2 3 1\n");
            printf("4 5 3 1 2\n");
            printf("4 5 3 2 1\n");
            
            printf("5 1 4 3 2\n"); // @@ Missing permutations for 5 starting with 5. The sequence jumps from 4 5 3 2 1 to 5 1 4 3 2. It is missing "5 1 2 3 4", "5 1 2 4 3", "5 1 3 2 4", "5 1 3 4 2". Also the order is wrong. Lexicographically, 5 1 2 3 4 comes before 5 1 4 3 2.
            printf("5 2 1 3 4\n");
            printf("5 2 1 4 3\n");
            printf("5 2 3 1 4\n");
            printf("5 2 3 4 1\n");
            printf("5 2 4 1 3\n");
            printf("5 2 4 3 1\n");
            printf("5 3 1 2 4\n");
            printf("5 3 1 4 2\n");
            printf("5 3 2 1 4\n");
            printf("5 3 2 4 1\n");
            printf("5 3 4 1 2\n");
            printf("5 3 4 2 1\n");
            printf("5 4 1 2 3\n");
            printf("5 4 1 3 2\n");
            printf("5 4 2 1 3\n");
            printf("5 4 2 3 1\n");
            printf("5 4 3 1 2\n");
            printf("5 4 3 2 1\n"); // @@ Extra trailing newline.
            break;
    }
    
    return 0;
}