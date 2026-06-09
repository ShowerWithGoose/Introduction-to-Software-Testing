#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    switch(n)
    {
        case 1:
            printf("1\n");
            break;
        case 2:
            printf("1 2\n"); // @@ The expected output for N=2 is "1 2 " (with a trailing space and no newline, or potentially just "1 2" depending on strictness, but the provided expected output "1 2 " suggests a trailing space. However, looking at the reference program, it prints "1 2\n2 1". The test case expected output is "1 2 ". This implies the last line should not have a newline, or there is a specific formatting requirement. Let's look closer. The expected output is `1 2 `. The buggy output is `1 2\n2 1\n`. Wait, the test case input is 2. The expected output is `1 2 `. The buggy output shown in the prompt is `1 2\n2 1`. This means the program printed both permutations. But the expected output only shows `1 2 `. This is strange. Usually, all permutations are required. Let's re-read carefully. "Output N! lines". For N=2, 2! = 2 lines. So "1 2" and "2 1" should be printed. The expected output provided in the prompt is `1 2 `. This looks like a truncated or specific format issue. However, looking at the Buggy Output: `1 2\n2 1`. And Expected: `1 2 `. It seems the judge might be expecting a trailing space after each number or line, or perhaps the newline handling is different. 
            // Actually, let's look at the Reference Program. 
            // Case 2: printf("1 2\n2 1"); -> No trailing newline.
            // Buggy Code Case 2: 
            // printf("1 2\n"); 
            // printf("2 1\n");
            // This produces "1 2\n2 1\n". 
            // The expected output is "1 2 ". This is very likely a typo in the problem description's "Expected Output" field provided in the prompt context, OR it implies that for N=2, only the first line is checked? No, that's unlikely.
            // Let's look at the other cases. Case 5 has trailing spaces inside the printf strings: "1 2 3 4 5 \n".
            // The reference program does NOT have trailing spaces.
            // The buggy program for Case 5 HAS trailing spaces.
            // The buggy program for Case 1, 2, 3, 4 does NOT have trailing spaces.
            // If the judge expects trailing spaces (as hinted by Case 5 structure in buggy code potentially trying to match something, or the expected output `1 2 `), then Case 2 is missing the trailing space.
            // However, the most obvious error in many such problems is the trailing newline.
            // Reference: "1 2\n2 1" (No final newline).
            // Buggy: "1 2\n2 1\n" (Final newline).
            // If the expected output is strictly `1 2 `, it might mean the test case is actually checking for specific whitespace.
            // Let's assume the standard error: Extra newline at the end or missing trailing space.
            // Given the Expected Output is `1 2 `, it ends with a space.
            // The buggy output line is `printf("1 2\n");`. It ends with newline.
            // If the expected output is truly `1 2 `, then the format is wrong.
            // But wait, if N=2, there are 2 permutations. Why is expected output only one line?
            // Maybe the "Expected Output" in the prompt is just the first line? Or maybe the prompt implies the program FAILED because it produced `1 2\n2 1` but expected `1 2 `?
            // Let's look at Case 5 in the buggy code. It has `printf("1 2 3 4 5 \n");`. Note the space before \n.
            // Cases 1-4 do not have this space.
            // If the judge requires a space after the last number, then Case 2 is wrong.
            printf("2 1\n");
            break;
        case 3:
            printf("1 2 3\n");
            printf("1 3 2\n");
            printf("2 1 3\n");
            printf("2 3 1\n");
            printf("3 1 2\n");
            printf("3 2 1\n");
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
            printf("4 3 2 1\n");
            break;
        case 5:
            printf("1 2 3 4 5 \n");
                        printf("1 2 3 5 4 \n");
                        printf("1 2 4 3 5 \n");
                        printf("1 2 4 5 3 \n");
                        printf("1 2 5 3 4 \n");
                        printf("1 2 5 4 3 \n");
                        printf("1 3 2 4 5 \n");
                        printf("1 3 2 5 4 \n");
                        printf("1 3 4 2 5 \n");
                        printf("1 3 4 5 2 \n");
                        printf("1 3 5 2 4 \n");
                        printf("1 3 5 4 2 \n");
                        printf("1 4 2 3 5 \n");
                        printf("1 4 2 5 3 \n");
                        printf("1 4 3 2 5 \n");
                        printf("1 4 3 5 2 \n");
                        printf("1 4 5 2 3 \n");
                        printf("1 4 5 3 2 \n");
                        printf("1 5 2 3 4 \n");
                        printf("1 5 2 4 3 \n");
                        printf("1 5 3 2 4 \n");
                        printf("1 5 3 4 2 \n");
                        printf("1 5 4 2 3 \n");
                        printf("1 5 4 3 2 \n");
            printf("2 1 3 4 5 \n");
                        printf("2 1 3 5 4 \n");
                        printf("2 1 4 3 5 \n");
                        printf("2 1 4 5 3 \n");
                        printf("2 1 5 3 4 \n");
                        printf("2 1 5 4 3 \n");
                        printf("2 3 1 4 5 \n");
                        printf("2 3 1 5 4 \n");
                        printf("2 3 4 1 5 \n");
                        printf("2 3 4 5 1 \n");
                        printf("2 3 5 1 4 \n");
                        printf("2 3 5 4 1 \n");
                        printf("2 4 1 3 5 \n");
                        printf("2 4 1 5 3 \n");
                        printf("2 4 3 1 5 \n");
                        printf("2 4 3 5 1 \n");
                        printf("2 4 5 1 3 \n");
                        printf("2 4 5 3 1 \n");
                        printf("2 5 1 3 4 \n");
                        printf("2 5 1 4 3 \n");
                        printf("2 5 3 1 4 \n");
                        printf("2 5 3 4 1 \n");
                        printf("2 5 4 1 3 \n");
                        printf("2 5 4 3 1 \n");
            printf("3 1 2 4 5 \n");
                        printf("3 1 2 5 4 \n");
                        printf("3 1 4 2 5 \n");
                        printf("3 1 4 5 2 \n");
                        printf("3 1 5 2 4 \n");
                        printf("3 1 5 4 2 \n");
                        printf("3 2 1 4 5 \n");
                        printf("3 2 1 5 4 \n");
                        printf("3 2 4 1 5 \n");
                        printf("3 2 4 5 1 \n");
                        printf("3 2 5 1 4 \n");
                        printf("3 2 5 4 1 \n");
                        printf("3 4 1 2 5 \n");
                        printf("3 4 1 5 2 \n");
                        printf("3 4 2 1 5 \n");
                        printf("3 4 2 5 1 \n");
                        printf("3 4 5 1 2 \n");
                        printf("3 4 5 2 1 \n");
                        printf("3 5 1 2 4 \n");
                        printf("3 5 1 4 2 \n");
                        printf("3 5 2 1 4 \n");
                        printf("3 5 2 4 1 \n");
                        printf("3 5 4 1 2 \n");
                        printf("3 5 4 2 1 \n");
            printf("4 1 2 3 5 \n");
                        printf("4 1 2 5 3 \n");
                        printf("4 1 3 2 5 \n");
                        printf("4 1 3 5 2 \n");
                        printf("4 1 5 2 3 \n");
                        printf("4 1 5 3 2 \n");
                        printf("4 2 1 3 5 \n");
                        printf("4 2 1 5 3 \n");
                        printf("4 2 3 1 5 \n");
                        printf("4 2 3 5 1 \n");
                        printf("4 2 5 1 3 \n");
                        printf("4 2 5 3 1 \n");
                        printf("4 3 1 2 5 \n");
                        printf("4 3 1 5 2 \n");
                        printf("4 3 2 1 5 \n");
                        printf("4 3 2 5 1 \n");
                        printf("4 3 5 1 2 \n");
                        printf("4 3 5 2 1 \n");
                        printf("4 5 1 2 3 \n");
                        printf("4 5 1 3 2 \n");
                        printf("4 5 2 1 3 \n");
                        printf("4 5 2 3 1 \n");
                        printf("4 5 3 1 2 \n");
                        printf("4 5 3 2 1 \n");
            printf("5 1 2 3 4 \n");
                        printf("5 1 2 4 3 \n");
                        printf("5 1 3 2 4 \n");
                        printf("5 1 3 4 3 \n"); // @@ Logical Error: The permutation '5 1 3 4 3' is invalid because 3 is repeated and 5 is missing. It should be '5 1 3 4 2'.
                        printf("5 1 4 2 3 \n");
                        printf("5 1 4 3 2 \n");
                        printf("5 2 1 3 4 \n");
                        printf("5 2 1 4 3 \n");
                        printf("5 2 3 1 4 \n");
                        printf("5 2 3 4 1 \n");
                        printf("5 2 4 1 3 \n");
                        printf("5 2 4 3 1 \n");
                        printf("5 3 1 2 4 \n");
                        printf("5 3 1 4 2 \n");
                        printf("5 3 2 1 4 \n");
                        printf("5 3 2 4 1 \n");
                        printf("5 3 4 1 2 \n");
                        printf("5 3 4 2 1 \n");
                        printf("5 4 1 2 3 \n");
                        printf("5 4 1 3 2 \n");
                        printf("5 4 2 1 3 \n");
                        printf("5 4 2 3 1 \n");
                        printf("5 4 3 1 2 \n");
                        printf("5 4 3 2 1 \n");
            break;
                        
    }
    return 0;
}