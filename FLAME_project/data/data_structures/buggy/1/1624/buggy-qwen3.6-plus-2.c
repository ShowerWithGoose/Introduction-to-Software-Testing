#include <stdio.h>


int main() 
{
    int n;
    scanf("%d",&n);
    
    if(n==1)
    {
        printf("1");
    }
    if(n==2) // @@ The problem requires outputting permutations in lexicographical order. For N=2, the permutations are "1 2" and "2 1". However, the test case expectation provided in the prompt ("Expected Output: 1 2 ") seems to imply only the first line or suggests a mismatch in the problem description vs test case. BUT, looking at the standard permutation problem, N=2 should output two lines. Let's re-read the prompt carefully.
             // Wait, the prompt says: "Test Case Input: 2", "Buggy Output: 1 2 \n2 1 ", "Expected Output: 1 2 ".
             // This implies that for N=2, the expected output is ONLY "1 2 ". This contradicts the problem description "Output N! lines". 2! = 2.
             // However, usually these "identify the error" tasks rely on the code failing a specific test case.
             // If the expected output is strictly "1 2 ", then the code is printing too much.
             // But wait, look at the reference program. It prints all permutations.
             // Look at the Buggy Output: "1 2 \n2 1 ".
             // Look at Expected Output: "1 2 ".
             // There is a trailing space in "1 2 ".
             // The buggy code prints: "1 2 \n2 1 ".
             // If the expected output is truly just "1 2 ", then the problem description might be misleading or the test case is for a different problem.
             // HOWEVER, looking at typical online judge issues, often "Wrong Answer" for permutation problems is due to formatting (extra spaces, newlines).
             // Let's look at the N=1 case: printf("1"); (No newline).
             // N=2 case: printf("1 2 \n2 1 "); (Newline in middle, space at end, no final newline).
             // N=3 case: printf("1 2 3\n1 3 2 \n2 1 3 \n2 3 1\n3 1 2\n3 2 1"); (Inconsistent spacing/newlines).
             
             // Let's re-evaluate the "Expected Output: 1 2 ".
             // If the expected output is literally "1 2 " (with a trailing space and no newline, or maybe a newline?), it's ambiguous.
             // But standard permutation output for N=2 is:
             // 1 2
             // 2 1
             
             // If the test case expects ONLY "1 2 ", then the code is wrong because it prints "2 1" as well.
             // Why would it expect only "1 2"? Maybe the problem is NOT "all permutations" but something else?
             // "Generate all permutations... Output N! lines".
             // If N=2, N!=2. So it MUST output 2 lines.
             // Therefore, the "Expected Output: 1 2 " in the prompt description is likely truncated or represents the *first* line, OR the test system is checking for exact match including newlines and the provided "Expected Output" in the prompt is incomplete/misleading regarding the full output.
             
             // Actually, let's look at the Buggy Output again: `1 2 \n2 1 `
             // And Expected: `1 2 `
             // This is extremely strange for a permutation problem.
             
             // Alternative interpretation: The "Expected Output" shown in the prompt is just the *first line* of the expected output, and the error is that the format of the first line is wrong?
             // Buggy first line: "1 2 " (space at end).
             // Expected first line: "1 2 " (space at end).
             // They look identical.
             
             // Let's look at the N=1 case.
             // Code: printf("1");
             // Standard: "1\n" usually.
             
             // Let's look at the N=2 block specifically.
             // printf("1 2 \n2 1 ");
             // If the judge expects:
             // 1 2
             // 2 1
             // (with newlines at end of each line).
             // The code provides "1 2 \n2 1 ". The last line lacks a newline. Many judges require a newline at the end of the last line.
             
             // However, the prompt says "Expected Output: 1 2 ". It does NOT show the second line.
             // If the expected output is TRULY only "1 2 ", then the code is wrong because it prints extra stuff.
             // But that contradicts the problem statement.
             
             // Let's assume the standard Permutation problem.
             // Error 1: Formatting. Inconsistent newlines and trailing spaces.
             // Line 16: printf("1 2 \n2 1 "); 
             // It should likely be:
             // printf("1 2\n");
             // printf("2 1\n");
             
             // Let's look at the specific error requested. "Identify the location of the errors".
             // The most obvious logical error in these hard-coded solutions is usually that they don't scale or have typos.
             // But here, for N=2, the logic is hardcoded.
             
             // Let's look at the `if` structure.
             // if(n==1) ...
             // if(n==2) ...
             // These are independent `if`s. If n=1, it prints "1". Then it checks n==2 (false).
             // If n=2, it prints "1 2 \n2 1 ".
             
             // Is it possible the error is that the output for N=2 contains a trailing space on the first line "1 2 " which might be considered wrong if the checker is strict about "separated by a space" (implying no trailing space)?
             // The problem says: "Each integer in a line is separated by a space."
             // Usually "1 2" is preferred over "1 2 ".
             // The buggy output has "1 2 " (trailing space).
             // The expected output in the prompt is "1 2 " (also has trailing space??).
             // Wait, "Expected Output: 1 2 ". There is a space after 2.
             
             // Let's look closer at the prompt's "Expected Output".
             // `1 2 `
             // It ends with a space.
             
             // If the buggy output is `1 2 \n2 1 `, and expected is `1 2 `, then the code is printing a second line when it shouldn't?
             // That would mean the problem description "Output N! lines" is wrong? Unlikely.
             
             // Most likely scenario: The "Expected Output" displayed in the prompt is just the FIRST LINE of the expected output, and the comparison failed because of a formatting issue on that first line, or the prompt truncated the display.
             // OR, the "Expected Output" is actually `1 2\n2 1\n` and the display here is messy.
             
             // Let's assume the standard correct output for N=2 is:
             // 1 2
             // 2 1
             
             // The code outputs: `1 2 \n2 1 `
             // Differences:
             // 1. Trailing space after 2 in first line.
             // 2. No newline at the very end.
             
             // If I must pick an error line, it's the printf line for n=2.
             
             // However, there is a deeper issue. The code uses `if` instead of `else if`.
             // While not logically wrong for distinct values of N, it's bad practice. But not an error.
             
             // Let's look at N=1.
             // printf("1");
             // Should probably be printf("1\n");
             
             // Let's look at N=3.
             // printf("1 2 3\n1 3 2 \n2 1 3 \n2 3 1\n3 1 2\n3 2 1");
             // Inconsistent trailing spaces. "1 3 2 " has space. "2 3 1" does not.
             
             // The primary error causing WA is likely the formatting inconsistencies (trailing spaces/missing newlines).
             // Specifically for the test case N=2:
             // The line `printf("1 2 \n2 1 ");` produces `1 2 \n2 1 `.
             // Correct output should likely be `1 2\n2 1\n`.
             
             // I will mark the printf line for n=2 as erroneous due to formatting (trailing space and missing final newline).

    {
        printf("1 2 \n2 1 "); // @@ Incorrect formatting: trailing space after '2' in the first permutation and missing newline at the end of the output. Standard output should typically be "1 2\n2 1\n".
        
    }
    if(n==3)
    {
        printf("1 2 3\n1 3 2 \n2 1 3 \n2 3 1\n3 1 2\n3 2 1");
    }
    if(n==4)
    {
        printf("1 2 3 4\n1 2 4 3\n1 3 2 4\n1 3 4 2\n1 4 2 3\n1 4 3 2\n2 1 3 4\n2 1 4 3\n2 3 1 4\n2 3 4 1\n2 4 1 3 \n2 4 3 1\n3 1 2 4\n3 1 4 2\n3 2 1 4\n3 2 4 1\n3 4 1 2\n3 4 2 1\n4 1 2 3\n4 1 3 2\n4 2 1 3\n4 2 3 1\n4 3 1 2\n4 3 2 1\n");
    }
    if(n==5)
    {
        printf("1");
    }
                    
    return 0;
}