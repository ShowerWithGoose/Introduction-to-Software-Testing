#include <stdio.h>


int main() 
{
    int n;
    scanf("%d",&n);
    
    if(n==1)
    {
        printf("1");
    }
    if(n==2) // @@ The problem requires outputting permutations in lexicographical order. For N=2, the permutations are "1 2" and "2 1". However, the test case expectation provided in the prompt ("Expected Output: 1 2 ") seems to imply only the first line or suggests a mismatch in the problem description vs test case. BUT, looking at the standard permutation problem, N=2 should output two lines. Let's re-read the prompt carefully. "Test Case Input: 2", "Buggy Output: 1 2 \n2 1 ", "Expected Output: 1 2 ". This expected output is extremely strange for "generate all permutations". Usually, it should be both. However, if the expected output is strictly "1 2 ", then the code is printing an extra line. Wait, looking at the reference program, it prints all permutations. The "Expected Output" in the prompt might be truncated or incorrect in the description, OR the problem actually asks for something else? No, "generate all permutations". If the expected output is truly just "1 2 ", then the problem statement is contradictory. However, often in these datasets, the "Expected Output" shown might be just the first line if the diff tool highlights the first error, or it's a specific formatting issue. Let's look at the Buggy Output: "1 2 \n2 1 ". The Expected Output: "1 2 ". There is a trailing space in the expected output? Or is it missing the second line? If I assume the standard problem, the code is correct logically for N=2. But if I must match the "Expected Output" literally, the code prints too much. HOWEVER, looking at the other cases (N=3, N=4), they print all permutations. It is highly likely the "Expected Output" in the prompt description is malformed or represents a specific failure mode where the judge stopped reading or the example is bad. BUT, there is a more subtle error. Look at the N=1 case: `printf("1");` no newline. N=2 case: `printf("1 2 \n2 1 ");` no newline at the very end? Or maybe the issue is simpler. Let's look at N=5. It prints "1". That's definitely wrong. But the test case is N=2. 
    // Actually, let's look closer at the N=2 block. 
    // Buggy: "1 2 \n2 1 "
    // Expected: "1 2 "
    // If the expected output is genuinely just "1 2 ", then the code is wrong because it prints the second permutation. 
    // But wait, if N=2, permutations are 1 2 and 2 1. Why would expected be only 1 2? 
    // Perhaps the "Expected Output" in the prompt is just showing the *first* line because the comparison failed there? No, usually it shows the whole thing.
    // Let's reconsider the N=1 case. `printf("1");`. If N=1, output is "1".
    // Let's reconsider the N=2 case. `printf("1 2 \n2 1 ");`.
    // Is it possible the problem asks for *combinations*? No, "permutations".
    // Is it possible the output format requires a specific newline handling?
    // Let's look at the N=4 string. It ends with `\n`.
    // The N=2 string ends with ` `. No newline at the end of file?
    // The N=3 string does NOT end with `\n`.
    // The N=2 string does NOT end with `\n`.
    // Many judges require a newline at the end of the last line.
    // However, the discrepancy between "1 2 \n2 1 " and "1 2 " is huge.
    // Let's look at the provided Reference Program. It uses recursion/iteration to print all permutations.
    // The Buggy Code is a hardcoded lookup table.
    // The error is likely that the hardcoded output for N=2 is considered "Wrong" because the Expected Output provided in the prompt is `1 2 `. This implies the test case might actually be expecting ONLY the first permutation? No, that contradicts the problem statement.
    // Alternative theory: The "Expected Output" field in the prompt is truncated or represents the state before the crash/failure?
    // Let's look at the N=5 case. `printf("1");`. This is clearly incomplete.
    // But the test case is N=2.
    // If I assume the "Expected Output" is correct and complete, then the program should ONLY print "1 2 ". This would mean the problem is NOT "generate all permutations" but something else? No, the description is clear.
    // There is a possibility that the "Expected Output" shown is just the *prefix* that matched, or the first line?
    // Let's assume the standard interpretation: The code SHOULD print all permutations. The "Expected Output" in the prompt might be misleading or I am misinterpreting "Expected Output: 1 2 ". Does it mean "1 2" followed by a newline?
    // If the buggy output is "1 2 \n2 1 ", and expected is "1 2 ", then the buggy output has extra content.
    // However, if I look at similar problems, sometimes "Wrong Answer" is triggered by formatting.
    // Let's look at the N=1 case: `printf("1");`.
    // Let's look at the N=2 case: `printf("1 2 \n2 1 ");`.
    // If the judge expects a newline at the end of each line, `1 2 ` has a trailing space. `2 1 ` has a trailing space.
    // In the N=4 case, `1 2 3 4\n`... `4 3 2 1\n`. It has newlines.
    // In N=2, `1 2 \n2 1 `. No final newline.
    // In N=3, `...3 2 1`. No final newline.
    // Missing final newline is a common WA cause.
    // BUT, the expected output is `1 2 `. It doesn't show the second line.
    // If the expected output was `1 2 \n2 1 \n`, the prompt would likely show that.
    // Is it possible the input `2` expects only `1 2`? No.
    // Let's look at the code structure again.
    // The code uses `if` instead of `else if`. If N=2, it executes the N=2 block. It does NOT fall through to N=3, etc. So that's fine.
    // The most likely error in these "hardcoded" solutions when they fail specific small cases while having larger cases implemented is often a typo in the hardcoded string or missing newlines.
    // Given the ambiguity of the "Expected Output" in the prompt (which seems to contradict the problem statement), I will flag the N=2 line as potentially having a formatting error (missing newline at end) OR the fact that it prints the second permutation when the "Expected" (though likely erroneous in description) didn't show it.
    // However, I must identify the location of errors. The N=5 case is definitely an error (incomplete). The N=2 case output format (trailing spaces, missing final newline) is suspicious.
    // Let's look at the N=2 line specifically.
    // `printf("1 2 \n2 1 ");`
    // If the expected output is `1 2 \n2 1 \n`, then the error is the missing `\n` at the end.
    // If the expected output is `1 2 \n2 1`, then the error is the trailing space?
    // The prompt says Expected: `1 2 `.
    // I will annotate the N=2 printf because it likely lacks a trailing newline which is standard, and the hardcoded strings for N=3 and N=5 are also problematic (N=5 is definitely wrong, N=3 lacks final newline). Since the test case is N=2, I focus on N=2. The trailing space after 2 and 1 is also non-standard compared to the N=4 case which uses `\n` separators cleanly? Actually N=4 has `1 2 3 4\n`. N=2 has `1 2 \n`. The space before `\n` might be the issue if the checker is strict.
    // Reason: The output format typically requires numbers separated by spaces, but often no trailing space at the end of the line, and a newline at the end of the last line. The string "1 2 \n2 1 " has trailing spaces and no final newline.

    {
        printf("1 2 \n2 1 "); // @@ [Formatting Error: The output likely requires a newline at the end of the last line, and typically no trailing space after the last number on each line. The expected output format usually strictly matches "num num\\n". Also, the hardcoded solution is fragile.]
        
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
        printf("1"); // @@ [Logical Error: Incomplete implementation for N=5. It should print all 120 permutations, not just "1".]
    }
                    
    return 0;
}