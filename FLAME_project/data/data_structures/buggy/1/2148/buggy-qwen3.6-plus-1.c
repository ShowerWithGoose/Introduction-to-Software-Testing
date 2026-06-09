#include<stdio.h>
#include<string.h>
int main(){
    int n;
    scanf("%d",&n);
    if(n==1){
        printf("1");
    }
    if(n==2){
        printf("1 2\n"); // @@ [The expected output for N=2 is only "1 2" followed by a newline. The original code printed "1 2", then a newline, then "2 1". The problem states N! lines. For N=2, 2! = 2 lines. However, the test case expectation shows only "1 2 ". Wait, looking at the provided "Expected Output": "1 2 ". This usually implies a trailing space or just the first line. Let's re-read carefully.
// Actually, looking at the "Buggy Output": "1 2\n2 1". Expected: "1 2 ". 
// The problem description says: Output N! lines. For N=2, it should be 2 lines: "1 2" and "2 1".
// However, the specific Test Case Input 2 has Expected Output "1 2 ". This is extremely strange if it expects all permutations.
// Let's look at the "Reference Program" logic vs "Source Code".
// The prompt asks to identify errors in the *program below* (the Source Code at the bottom).
// The Source Code prints permutations for N=1, 2, 3, 4.
// The Test Case Input is 2.
// Buggy Output: "1 2\n2 1" (Note: the buggy output shown in the prompt header is from the *Reference Program* logic? No, the prompt structure is:
// 1. Problem Description
// 2. Reference Program (which is weird/hardcoded)
// 3. Error Type: Wrong Answer
// 4. Test Case Input: 2
// 5. Buggy Output: 1 2 \n 2 1
// 6. Expected Output: 1 2 
//
// Wait, if N=2, N! = 2. The permutations are "1 2" and "2 1".
// Why is the expected output only "1 2 "?
// Perhaps the "Expected Output" in the prompt description is truncated or formatted strangely?
// Or maybe the problem description implies something else?
// "Output N! lines... sorted in lexicographical order".
// If the expected output is literally just "1 2 ", then the program should only print the first permutation? That contradicts "Output N! lines".
//
// Let's look closer at the "Buggy Output" vs "Expected Output".
// Buggy: "1 2\n2 1"
// Expected: "1 2 "
//
// There is a high probability that the "Expected Output" provided in the prompt text "1 2 " actually means "1 2\n" (with a trailing newline) and the system is comparing strictly, OR the test case expects ONLY the first line?
// No, standard permutation problems require all permutations.
//
// Let's look at the Source Code provided for annotation.
// It prints:
// if(n==2) { printf("1 2"); printf("\n"); printf("2 1"); }
// This outputs: "1 2\n2 1" (no trailing newline on the last line).
//
// If the Expected Output is "1 2 ", it might mean "1 2\n".
// If the judge expects a trailing newline after the last line, the current code fails because "2 1" is not followed by \n.
// HOWEVER, the Expected Output shown is "1 2 ". It does NOT show "2 1".
//
// Is it possible the user made a mistake in copying the Expected Output?
// Or is the "Buggy Output" listed in the prompt header corresponding to the *Reference Program* (which is also buggy/hardcoded)?
// The prompt says: "identify the location of the errors in the program below."
// The "program below" is the Source Code block at the end.
//
// Let's assume the standard requirement: Print all N! permutations.
// For N=2, output should be:
// 1 2
// 2 1
//
// The Source Code for N=2:
// printf("1 2");
// printf("\n");
// printf("2 1");
//
// This produces: "1 2\n2 1".
// Many online judges require a newline at the end of the last line.
// If the Expected Output was actually:
// 1 2
// 2 1
//
// Then the error is missing \n after "2 1".
//
// But the prompt explicitly says:
// Expected Output:
// 1 2 
//
// This looks like a single line.
//
// Let's re-read the "Reference Program". It handles N=1, 2, 3 manually, and N=4, 5 via function p().
// The "Source Code" to annotate handles N=1, 2, 3, 4 manually.
//
// If the test case is N=2, and the expected output is truly just "1 2 ", then the problem statement "Output N! lines" is contradictory to the test case.
//
// However, often in these datasets, "Expected Output" might be displayed with a trailing space indicating a newline or formatting artifact.
// If I look at the N=1 case in Source Code: printf("1"); (No newline).
// N=2: printf("1 2"); printf("\n"); printf("2 1"); (No newline at end).
// N=3: All lines end with \n, including the last one.
// N=4: All lines end with \n, including the last one.
//
// Inconsistency: N=1 and N=2 do not have a trailing newline on the very last output. N=3 and N=4 do.
// Standard practice is to have a trailing newline.
//
// If the Expected Output for N=2 is "1 2\n2 1\n", then the code is missing the final \n.
// The text "1 2 " in the prompt might be a truncation of the full expected output in the display, OR it implies that the judge failed on the first line?
//
// Let's look at the "Buggy Output" again: "1 2\n2 1".
// If the Expected Output is "1 2\n2 1\n", the difference is the trailing newline.
//
// Another possibility: The "Expected Output" in the prompt is literally just "1 2 ".
// If so, why? Maybe the input N=2 is invalid? No, 1<=N<=10.
//
// Let's assume the most common error in these student assignments: Missing trailing newline or extra/missing spaces.
// In the N=2 block:
// printf("1 2");
// printf("\n");
// printf("2 1");
//
// If I change it to:
// printf("1 2\n");
// printf("2 1\n");
// It matches the style of N=3 and N=4.
//
// The prompt asks to annotate the error.
// The error is likely that the last line of output for N=2 is missing a newline, causing a presentation error or wrong answer if strict matching is used.
// Also, for N=1, it prints "1" without newline.
//
// However, I must stick to the specific test case failure: Input 2.
// Buggy: 1 2\n2 1
// Expected: 1 2 
//
// If the expected output is truly just "1 2 ", then the code shouldn't print "2 1". But that violates the problem statement.
// It is highly probable that the "Expected Output" field in the prompt is malformed/truncated and actually represents "1 2\n2 1\n" or similar, and the visual representation "1 2 " is misleading.
// BUT, looking at the N=1 case in Source Code: `printf("1");`.
// If the test case was N=1, and expected "1\n", it would fail similarly.
//
// Let's look at the N=2 block again.
// Line 10: printf("1 2");
// Line 11: printf("\n");
// Line 12: printf("2 1");
//
// If I combine them: printf("1 2\n2 1\n");
//
// I will annotate the missing newline at the end of the N=2 output sequence.
// Specifically, line 12 is missing a newline.

        printf("2 1"); // @@ [Missing newline character at the end of the last permutation. Standard output format requires each line to end with a newline, including the last one. This causes a mismatch with expected output which likely includes a trailing newline.]
    }
    if(n==3){
        printf("1 2 3");
        printf("\n");
        printf("1 3 2");
        printf("\n");
        printf("2 1 3");
        printf("\n");
        printf("2 3 1");
        printf("\n");
        printf("3 1 2");
        printf("\n");
        printf("3 2 1");
        printf("\n");
    }
    if(n==4){
        printf("1 2 3 4");
        printf("\n");
        printf("1 2 4 3");
        printf("\n");
        printf("1 3 2 4");
        printf("\n");
        printf("1 3 4 2");
        printf("\n");
        printf("1 4 2 3");
        printf("\n");
        printf("1 4 3 2");
        printf("\n"); 
        printf("2 1 3 4");
        printf("\n");
        printf("2 1 4 3");
        printf("\n");
        printf("2 3 1 4");
        printf("\n");
        printf("2 3 4 1");
        printf("\n");
        printf("2 4 1 3");
        printf("\n");
        printf("2 4 3 1");
        printf("\n"); 
        printf("3 1 2 4");
        printf("\n");
        printf("3 1 4 2");
        printf("\n");
        printf("3 2 1 4");
        printf("\n");
        printf("3 2 4 1");
        printf("\n");
        printf("3 4 1 2");
        printf("\n");
        printf("3 4 2 1");
        printf("\n"); 
        printf("4 1 2 3");
        printf("\n");
        printf("4 1 3 2");
        printf("\n");
        printf("4 2 1 3");
        printf("\n");
        printf("4 2 3 1");
        printf("\n");
        printf("4 3 1 2");
        printf("\n");
        printf("4 3 2 1");
        printf("\n"); 

    }
}