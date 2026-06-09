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
            printf("1 2\n"); // @@ The expected output for N=2 is "1 2 " (with a trailing space or specific formatting) or potentially just "1 2" without a newline if it's the only line, but looking at the reference, case 2 prints "1 2\n2 1". The buggy code prints "1 2\n" then "2 1\n". The test case input is 2. The expected output is "1 2 ". Wait, looking closely at the Expected Output provided in the prompt: "1 2 ". It seems there might be a trailing space or missing second line? No, usually permutations include all. Let's re-read carefully.
            // Problem says: Output N! lines. For N=2, 2! = 2 lines.
            // Reference Program for case 2: printf("1 2\n2 1"); -> This outputs "1 2\n2 1". No trailing newline.
            // Buggy Program for case 2: 
            // printf("1 2\n"); -> outputs "1 2\n"
            // printf("2 1\n"); -> outputs "2 1\n"
            // Total output: "1 2\n2 1\n"
            // Expected Output in prompt: "1 2 " -> This looks like a truncated or specific check. However, typically "Wrong Answer" on permutation problems with hardcoded outputs often fails due to extra newlines at the end or missing permutations.
            // Let's look at Case 5 in the buggy code. It is missing several permutations starting with 5 1...
            // In Case 5:
            // Reference has: 5 1 2 3 4, 5 1 2 4 3, 5 1 3 2 4, 5 1 3 4 2, 5 1 4 2 3, 5 1 4 3 2.
            // Buggy Code has: printf("5 1 4 3 2\n"); as the first line for 5. It is missing 5 1 2 3 4 through 5 1 4 2 3.
            
            // However, the specific test case failed is Input: 2.
            // Expected Output: "1 2 "
            // Buggy Output: "1 2\n2 1\n"
            
            // If the expected output is literally "1 2 ", it implies only the first permutation is printed? Or maybe the expected output in the prompt description is malformed/truncated?
            // "Expected Output: 1 2 "
            // If the system expects exactly "1 2 " (with a trailing space and no newline, or just "1 2"), then printing the second permutation is wrong? No, that contradicts "Output N! lines".
            
            // Let's look at the Reference Program again.
            // case 2: printf("1 2\n2 1");
            // This does NOT have a trailing newline.
            
            // Buggy code:
            // printf("1 2\n");
            // printf("2 1\n");
            // This HAS a trailing newline.
            
            // Many online judges are strict about trailing newlines.
            // But wait, the Expected Output shown is "1 2 ". This is very strange for N=2.
            // Is it possible the user made a typo in the "Expected Output" field of the prompt description?
            // Or is the "Expected Output" actually "1 2\n2 1" (without trailing newline)?
            
            // Let's assume the standard error here is the trailing newline on the last line.
            // Line 13: printf("2 1\n"); should likely be printf("2 1"); to match the reference style which avoids the final newline, OR the judge ignores trailing newlines.
            
            // However, there is a much bigger logical error in Case 5.
            // The prompt asks to identify errors based on the failed test case Input: 2.
            // If Input 2 failed, the error must be in Case 2.
            
            // Comparing Reference Case 2: "1 2\n2 1"
            // Buggy Case 2: "1 2\n2 1\n"
            
            // If the judge is strict, the extra \n at the end is the error.
            
            printf("2 1\n"); // @@ The last line of output should not have a trailing newline if the reference implementation doesn't, or it produces an extra empty line which causes Wrong Answer in strict comparators. Based on the reference code, the last permutation should not be followed by a newline.
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
            
            printf("5 1 4 3 2\n");
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
            printf("5 4 3 2 1\n");
            break;
    }
    
    return 0;
}