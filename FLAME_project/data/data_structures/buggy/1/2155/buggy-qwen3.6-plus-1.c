#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    if (n == 1)
        printf("1");
    if (n == 2) // @@ The problem requires each permutation to be on a separate line ending with a newline. For N=2, the output "1 2\n2 1" is technically correct in content but often online judges are strict about trailing newlines or specific formatting. However, looking at the expected output "1 2 ", it seems the expected output for N=2 in the prompt description might be truncated or specific. Let's look closer. The expected output provided in the prompt is "1 2 ". This is extremely strange for N=2 as there should be 2! = 2 permutations. Wait, the prompt says "Expected Output: 1 2 ". This implies only one line? No, 2! is 2. The reference program prints two lines. The buggy output is "1 2\n2 1". The expected output shown in the prompt block is just "1 2 ". This is likely a typo in the prompt's "Expected Output" section which usually lists the *first* line or is incomplete. HOWEVER, looking at the Buggy Output vs Expected Output: Buggy: "1 2\n2 1", Expected: "1 2 ". If the expected output is literally just "1 2 ", then the code is wrong because it prints too much. But standard permutation problems require all permutations. Let's re-read carefully. "Output N! lines". For N=2, N!=2. So 2 lines are expected. The "Expected Output" field in the prompt likely got cut off or is displaying incorrectly. BUT, if I must follow the prompt's explicit "Expected Output: 1 2 ", then the code is printing an extra line. However, usually these prompts have a mismatch in the display. Let's look at the source code provided in the "Source Code" section vs the "Reference Program". The "Source Code" section contains a completely different, hardcoded solution. The "Reference Program" uses recursion/swaps. The task is to identify errors in the "program below". Which program? The prompt says "identify the location of the errors in the program below." and then provides "Source Code:". So I must annotate the "Source Code:" section. 
    // Actually, looking at the Expected Output "1 2 ", it ends with a space. The buggy output has "1 2\n2 1". 
    // If the test case is N=2, and the expected output is truly just "1 2 ", then the problem description "Output N! lines" contradicts the expected output for N=2 (which would be 2 lines). 
    // It is highly probable that the "Expected Output" in the prompt description is malformed/truncated and should be "1 2\n2 1\n". 
    // However, often in these specific debugging tasks, if the expected output is "1 2 ", it might mean the judge expects a trailing space on the last number and a newline, OR it's a specific format. 
    // Let's look at the Buggy Output: "1 2\n2 1". It lacks a trailing newline after the last line? Or maybe it has it. printf("1 2\n2 1") does not end with \n. 
    // Standard practice: each line should end with \n. 
    // If the expected output is "1 2 \n2 1 \n" (with spaces), the code doesn't do that. 
    // Let's assume the standard interpretation: The code hardcodes outputs. 
    // For N=2, it prints "1 2\n2 1". 
    // If the Expected Output is "1 2 ", this is very confusing. 
    // Let's look at the Reference Program's output format: printf("%d ", a[i]); then printf("\n"); 
    // So each number is followed by a space, including the last one. Then a newline. 
    // So for N=2, Line 1: "1 2 \n". Line 2: "2 1 \n". 
    // The Buggy Code prints: "1 2\n2 1". 
    // Differences: 
    // 1. Missing space after the last number in each line. 
    // 2. Missing newline at the very end of the output (if the last printf doesn't include it, which it doesn't). 
    // The Expected Output "1 2 " likely represents the first line "1 2 " (with space) and potentially the rest is cut off in the display, OR it strictly checks the first line? No, it checks full output. 
    // Most likely error: The format string "1 2\n2 1" does not match the reference format "%d " for each number. It should be "1 2 \n2 1 \n". 
    
    printf("1 2\n2 1"); // @@ The output format is incorrect. According to the reference program, each integer should be followed by a space (including the last one in the line), and each line should end with a newline. The correct string should be "1 2 \n2 1 \n".
    if (n == 3)
        printf("1 2 3\n1 3 2\n2 1 3\n2 3 1\n3 1 2\n3 2 1"); // @@ Similar format error: missing trailing spaces after numbers and potentially missing final newline. Should be "1 2 3 \n..." etc.
    if (n == 4)
        printf("1 2 3 4\n1 2 4 3\n1 3 2 4\n1 3 4 2\n1 4 2 3\n1 4 3 2\n2 1 3 4\n2 1 4 3\n2 3 1 4\n2 3 4 1\n2 4 1 3\n2 4 3 1\n3 1 2 4\n3 1 4 2\n3 2 1 4\n3 2 4 1\n3 4 1 2\n3 4 2 1\n4 1 2 3\n4 1 3 2\n4 2 1 3\n4 2 3 1\n4 3 1 2\n4 3 2 1\n"); // @@ Format error: missing trailing spaces after each number in every line. E.g., "1 2 3 4" should be "1 2 3 4 ".

}