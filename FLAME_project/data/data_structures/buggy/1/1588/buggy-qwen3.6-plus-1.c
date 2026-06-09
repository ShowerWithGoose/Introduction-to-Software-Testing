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
            printf("1 2\n"); @@ The expected output for N=2 is "1 2 " (with a trailing space and no newline, or potentially just "1 2" depending on strictness, but the reference shows "1 2\n2 1" without trailing newlines for the last line? No, the reference output for case 2 is "1 2\n2 1". The test case expected output is "1 2 ". Wait, looking at the Expected Output provided in the prompt: "1 2 ". It seems there is a trailing space. Let's look closer. The Buggy Output is "1 2\n2 1\n". The Expected Output is "1 2 ". This implies the test case might only be checking the first line or there is a specific format issue. However, usually permutations problems require all permutations. Let's re-read carefully.
            
            Actually, looking at the "Expected Output" in the prompt:
            Expected Output:
            1 2 
            
            There is a trailing space after 2. And only one line? No, N=2 should have 2! = 2 permutations.
            If the expected output is literally just "1 2 ", then the problem description might be misleading or the test case is partial.
            HOWEVER, looking at the Reference Program:
            case 2: printf("1 2\n2 1");
            This outputs:
            1 2
            2 1
            
            The Buggy Output for Input 2 is:
            1 2
            2 1
            
            The Expected Output shown in the prompt is:
            1 2 
            
            This is extremely confusing. Usually, "Expected Output" lists the full correct output. If it only lists "1 2 ", it might mean the judge is comparing line by line and failed on the first line due to formatting, or the expected output block was truncated in the prompt description.
            
            Let's look at the Buggy Code's Case 5.
            Line: printf("5 1 3 4 3 \n");
            This is clearly a typo. It should be 5 1 3 4 2.
            
            Let's look at the formatting of Case 5 in the buggy code.
            printf("1 2 3 4 5 \n"); -> Has a trailing space before \n.
            The reference program does NOT have trailing spaces.
            Reference: "1 2 3 4 5\n..."
            Buggy: "1 2 3 4 5 \n..."
            
            If the judge is strict about whitespace, the trailing spaces in Case 5 are errors.
            Are there trailing spaces in Case 2?
            printf("1 2\n"); -> No trailing space.
            printf("2 1\n"); -> No trailing space.
            
            Why did the test case fail for Input 2?
            Buggy Output:
            1 2
            2 1
            
            Expected Output:
            1 2 
            
            If the expected output is truly just "1 2 ", then the problem is not generating all permutations, or the prompt's "Expected Output" section is malformed/truncated.
            However, often in these datasets, if the output contains trailing spaces where none should exist, or missing newlines, it fails.
            
            Let's look at the Reference Program again.
            case 2: printf("1 2\n2 1");
            Note: No newline at the very end of the string.
            
            Buggy Code Case 2:
            printf("1 2\n");
            printf("2 1\n");
            This adds a newline after the last permutation.
            
            Many online judges ignore trailing newlines, but some are strict.
            However, the most obvious error in the provided code is in Case 5.
            
            Let's look at the specific error requested. "Identify the location of the errors... If you think an error may occur on a particular line...".
            
            The prompt provides a specific Test Case Input: 2.
            And says the program failed this test case.
            
            If the reference implementation is considered correct:
            Ref Output for 2: "1 2\n2 1"
            Buggy Output for 2: "1 2\n2 1\n"
            
            Difference: Trailing newline.
            
            However, there is a much more severe logical error in Case 5 which makes the whole program incorrect for N=5.
            Line: printf("5 1 3 4 3 \n");
            This prints '3' twice and misses '2'. It should be "5 1 3 4 2 \n" (if we keep the trailing space style) or "5 1 3 4 2\n".
            
            Also, ALL printf statements in Case 5 have a trailing space before \n.
            Example: printf("1 2 3 4 5 \n");
            The reference does not have trailing spaces.
            
            So for N=5, the output will be wrong due to:
            1. Trailing spaces on every line.
            2. Typo in "5 1 3 4 3".
            
            But the failure reported is for Input 2.
            
            Let's re-read the Expected Output for Input 2 carefully.
            "1 2 "
            
            If the expected output is "1 2 ", it implies a trailing space.
            The buggy output is "1 2\n".
            
            Is it possible the user made a mistake in pasting the expected output?
            Or is the "Expected Output" actually showing that the first line SHOULD have a trailing space?
            
            Let's look at the Buggy Code Case 1:
            printf("1\n");
            
            Case 2:
            printf("1 2\n");
            
            If the pattern in Case 5 (trailing spaces) was intended to be applied to all cases, then Case 2 is missing the trailing space?
            No, Case 1, 2, 3, 4 in the buggy code do NOT have trailing spaces inside the quotes before \n.
            Case 5 DOES have trailing spaces.
            
            This inconsistency suggests the code is just badly written/hardcoded.
            
            However, the most critical "Wrong Answer" usually stems from content errors.
            
            Let's assume the question asks to annotate the lines that are erroneous.
            
            Error 1: In Case 5, the line `printf("5 1 3 4 3 \n");` is logically incorrect because it repeats 3 and omits 2.
            
            Error 2: In Case 5, all lines have trailing spaces (e.g., `"1 2 3 4 5 \n"`). This likely causes a Wrong Answer for N=5 due to format mismatch with standard expectations (and the reference solution).
            
            Error 3: For the specific test case N=2 failing:
            The Buggy Output is `1 2\n2 1\n`.
            The Expected Output is shown as `1 2 `.
            
            If the Expected Output is truly `1 2 `, it's possible the test harness expects a trailing space on the line?
            Or, more likely, the "Expected Output" block in the prompt is truncated or represents a specific comparison error message.
            
            However, looking at the Reference Code:
            `printf("1 2\n2 1");`
            
            If I run the Reference Code for N=2, it outputs:
            `1 2`
            `2 1`
            (No trailing newline at the end of file).
            
            The Buggy Code outputs:
            `1 2`
            `2 1`
            (With trailing newline).
            
            If the judge is strict, the extra newline might be the issue.
            
            BUT, the prompt asks to identify errors in the program below. The program has a glaring typo in Case 5. Even if the test case shown is N=2, the program is fundamentally broken for N=5. I should annotate the obvious logical error in Case 5.
            
            Additionally, the trailing spaces in Case 5 are format errors.
            
            Let's look at the line:
            `printf("5 1 3 4 3 \n");`
            
            This is definitely an error.
            
            Are there errors in Case 2?
            If the reference is strict about no trailing newline, then:
            `printf("2 1\n");` should be `printf("2 1");`?
            
            However, usually, trailing newlines are acceptable. The typo in Case 5 is not.
            
            I will annotate the typo in Case 5.
            I will also annotate the trailing spaces in Case 5 as they deviate from the reference and standard formatting.
            
            Wait, if I must explain the failure for Test Case Input 2:
            If the expected output is `1 2 `, maybe the problem requires a trailing space after each number?
            Reference: `printf("1 2\n2 1");` -> No trailing space after 2.
            
            Let's look at the Buggy Output vs Expected Output again.
            Buggy: `1 2\n2 1\n`
            Expected: `1 2 `
            
            This looks like the Expected Output provided in the prompt description might be incomplete or referring to a specific diff.
            
            However, I will focus on the clear bugs in the code provided.
            
            1. Case 5 has trailing spaces in all printfs.
            2. Case 5 has a typo `5 1 3 4 3`.
            
            I will mark the typo line.
            I will also mark the trailing space lines in Case 5? That would be too many lines.
            
            Let's look at the instructions: "identify the location of the errors... add @@ symbol directly after that line".
            
            The most distinct error is the typo.
            
            Line 134: `printf("5 1 3 4 3 \n");`
            
            Reason: The permutation is invalid (duplicate 3, missing 2). Should be "5 1 3 4 2".
            
            Also, the trailing spaces in Case 5 are inconsistent with Cases 1-4 and the Reference.
            
            Line 75: `printf("1 2 3 4 5 \n");`
            Reason: Contains a trailing space before the newline, which is likely incorrect formatting compared to the reference solution.
            
            Since I need to keep the line count unchanged and just annotate, I will annotate the specific logical typo and potentially the first instance of the formatting error in Case 5 to indicate the pattern.
            
            However, the prompt specifically mentions the test case Input 2 failed.
            If Input 2 failed, and the code for Case 2 is: