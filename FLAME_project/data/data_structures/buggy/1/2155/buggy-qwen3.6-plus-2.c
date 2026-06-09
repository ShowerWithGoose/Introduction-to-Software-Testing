#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    if (n == 1)
        printf("1");
    if (n == 2) // @@ The output for n=2 is missing a trailing newline after the last permutation, or the problem expects strictly N! lines. However, looking at the expected output "1 2 ", it seems the test case might be malformed or the expectation is just the first line? Wait, the expected output provided in the prompt is "1 2 ". This is extremely strange for "all permutations". Let's re-read carefully.
                 // Problem: "Output N! lines... unique permutation".
                 // Test Case Input: 2
                 // Expected Output: "1 2 " (Note the trailing space and no second line?)
                 // Buggy Output: "1 2\n2 1"
                 // If the expected output is literally just "1 2 ", then the problem description contradicts the test case. 
                 // HOWEVER, usually in these tasks, if the expected output is truncated or looks wrong, it might be a display issue in the prompt description vs the actual checker.
                 // Let's look at the "Reference Program" logic. It prints all permutations.
                 // Let's look at the "Buggy Output": "1 2\n2 1".
                 // Let's look at the "Expected Output": "1 2 ".
                 // There is a high probability the "Expected Output" shown in the prompt is actually just the *first* line of the expected output, or the test case is specifically checking for n=1 but labeled n=2? No, input is 2.
                 // Actually, looking at the provided "Source Code" to annotate:
                 // It hardcodes outputs.
                 // For n=2, it prints "1 2\n2 1".
                 // If the expected output is truly just "1 2 ", then the requirement is NOT all permutations, but something else?
                 // Re-reading Problem Description: "generate all permutations".
                 // If the expected output is "1 2 ", it is missing "2 1".
                 // Is it possible the expected output in the prompt description is WRONG/TRUNCATED?
                 // Or is the "Buggy Output" considered wrong because of formatting?
                 // "1 2\n2 1" vs "1 2 ".
                 // If I assume the problem description is correct (all permutations), the code is logically correct for n=2.
                 // However, often these "find the error" tasks have a specific subtle bug.
                 // Let's look at n=1. printf("1"). No newline.
                 // Let's look at n=2. printf("1 2\n2 1"). No trailing newline.
                 // Let's look at n=3. printf("...3 2 1"). No trailing newline.
                 // Let's look at n=4. printf("...4 3 2 1\n"). Has trailing newline.
                 // Inconsistency in newlines.
                 // But the specific failure is Test Case 2.
                 // Input: 2.
                 // Buggy: "1 2\n2 1"
                 // Expected: "1 2 "
                 // This expected output is very suspicious. It ends with a space. It doesn't have the second permutation.
                 // Could the problem be "Print the FIRST permutation"? No, "generate all".
                 // Could the "Expected Output" in the prompt be a typo for "1 2\n2 1\n"?
                 // If the expected output was "1 2\n2 1\n", then the bug is the missing trailing newline.
                 // The buggy output is "1 2\n2 1".
                 // The expected output string provided is "1 2 ". This looks like a copy-paste error in the prompt generation where only the first line was captured, or it's a specific weird constraint.
                 // HOWEVER, I must follow the instruction: "identify the location of the errors... based on... expected output".
                 // If the expected output is strictly "1 2 ", then the code is wrong because it prints too much.
                 // But that contradicts the problem statement.
                 // Let's assume the standard interpretation: The code should print all permutations. The "Expected Output" field in the prompt likely contains a typo or is truncated, OR the judge expects a trailing newline which is missing in the buggy output, and the display "1 2 " is just showing the first line + space?
                 // Actually, look at the n=1 case: printf("1").
                 // Look at n=2: printf("1 2\n2 1").
                 // If the test harness compares strictly, and expects a trailing newline, the output "1 2\n2 1" might fail if "1 2\n2 1\n" is expected.
                 // But the "Expected Output" shown is "1 2 ".
                 // Let's look at the Reference Program. It uses `p()` which prints `\n` after every line.
                 // So for N=2, Ref Prog outputs:
                 // "1 2 \n" (space before newline due to loop `printf("%d ", a[i])`)
                 // "2 1 \n"
                 // So the reference output for N=2 is:
                 // "1 2 \n2 1 \n"
                 // The Buggy Code outputs:
                 // "1 2\n2 1"
                 // Differences:
                 // 1. Space after each number in Ref, not in Buggy (except maybe internal?). Ref: `printf("%d ", a[i])`. So "1 2 ". Buggy: "1 2".
                 // 2. Newline at end.
                 // The "Expected Output" in the prompt is "1 2 ". This matches the FIRST line of the Reference Program's output (without the newline visible, or maybe it includes it?).
                 // If the Expected Output is truly just "1 2 ", then the test case is broken or I am misunderstanding.
                 // However, typically, if the output format requires spaces after numbers, the Buggy Code fails because it prints "1 2" instead of "1 2 ".
                 // Let's check the Buggy Code for n=2: `printf("1 2\n2 1");`
                 // It prints "1 2", newline, "2 1".
                 // The Reference Code prints "1 2 ", newline, "2 1 ", newline.
                 // The mismatch is likely the **missing space after the last number** in each line and the **missing trailing newline**.
                 // The prompt's "Expected Output" showing "1 2 " strongly suggests that the space after the 2 is significant and expected. It likely truncated the rest of the output in the display.
                 // Therefore, the error is that the hardcoded strings do not match the format of the reference program (space after every number, newline at end).
                 // Since I need to annotate the existing code, and the code is hardcoded, the "error" is in the logic of hardcoding without matching the specific formatting (trailing spaces/newlines) implied by the reference/expected output.
                 // However, I can only add @@ to existing lines.
                 // The line `if (n == 2)` triggers the wrong output format.
    
        printf("1 2\n2 1"); // @@ The output format is incorrect. It lacks a trailing space after each number and a trailing newline at the end, unlike the reference implementation which prints "%d " for each number and "\n" at the end of each line. The expected output "1 2 " indicates a space is required after the last number.
    if (n == 3)
        printf("1 2 3\n1 3 2\n2 1 3\n2 3 1\n3 1 2\n3 2 1");
    if (n == 4)
        printf("1 2 3 4\n1 2 4 3\n1 3 2 4\n1 3 4 2\n1 4 2 3\n1 4 3 2\n2 1 3 4\n2 1 4 3\n2 3 1 4\n2 3 4 1\n2 4 1 3\n2 4 3 1\n3 1 2 4\n3 1 4 2\n3 2 1 4\n3 2 4 1\n3 4 1 2\n3 4 2 1\n4 1 2 3\n4 1 3 2\n4 2 1 3\n4 2 3 1\n4 3 1 2\n4 3 2 1\n");

}