#include<stdio.h>
            
int main(){
    int n;
    scanf("%d",&n);
    switch(n){
        case 1: printf("1");break;
        case 2: printf("1 2\n2 1");break; // @@ The output for N=2 is missing a trailing newline after the last permutation, or includes an extra line depending on strict comparison. However, looking at the expected output "1 2 ", it seems the test case expects only the first permutation or has a specific formatting requirement. Actually, looking closely at the Expected Output: "1 2 ", it ends with a space and no newline? Or just "1 2". The Buggy Output is "1 2\n2 1". The Expected Output provided in the prompt is "1 2 ". This suggests the test case might be flawed or expecting only the first line? No, usually these problems expect all permutations. Let's look at the Reference Program. The reference program for case 2 prints "1 2\n2 1". It does NOT print a trailing newline. The Buggy Code also prints "1 2\n2 1". The Expected Output shown is "1 2 ". This is very strange. Wait, looking at the problem description again: "Output N! lines". For N=2, that's 2 lines. The expected output in the prompt snippet `Expected Output: 1 2 ` looks truncated or malformed. However, often online judges are sensitive to trailing newlines. The reference code `printf("1 2\n2 1");` outputs `1 2` newline `2 1`. It does NOT output a final newline. If the judge expects a final newline, this would be wrong. If the judge expects exactly what is printed, it should be correct. 
        // Let's re-read the specific error. Test Case Input: 2. Buggy Output: `1 2\n2 1`. Expected Output: `1 2 `. 
        // The expected output `1 2 ` implies that perhaps the test case is actually expecting ONLY the first permutation? No, that contradicts the problem statement. 
        // Alternatively, maybe the expected output in the prompt description is just showing the first line and cutting off? 
        // Let's look at Case 3 in the buggy code: `printf("1 2 3\n1 3 2\n2 1 3\n2 3 1\n3 1 2 \n3 2 1");`. Note the space after `3 1 2 `. This is a syntax/content error compared to the reference.
        // But the failure is on Input 2.
        // Let's look at the Reference Program vs Buggy Program for Case 2.
        // Reference: `printf("1 2\n2 1");`
        // Buggy: `printf("1 2\n2 1");`
        // They are identical. Why did it fail?
        // Maybe the issue is in Case 1? `printf("1");` vs Reference `printf("1");`. Identical.
        // Maybe the issue is that the Buggy Code for Case 5 is missing the first line `1 2 3 4 5`?
        // In the Buggy Code Case 5:
        // `printf("1 2 3 5 4\n");` is the first line printed.
        // The reference starts with `1 2 3 4 5`.
        // So Case 5 is definitely wrong. But the test case is Input 2.
        
        // Let's look closer at the Expected Output format in the prompt: `1 2 `.
        // If the expected output is literally `1 2 ` (with a trailing space), then the code printing `1 2\n2 1` is wrong because it prints too much? No.
        // Is it possible the user provided the wrong Expected Output in the prompt description?
        // "Expected Output: 1 2 "
        // If the expected output is just `1 2`, then the code is printing an extra `\n2 1`.
        // But the problem says "Generate ALL permutations".
        
        // Let's assume the standard behavior: The code should match the reference.
        // The reference code for Case 2 is `printf("1 2\n2 1");`.
        // The buggy code for Case 2 is `printf("1 2\n2 1");`.
        
        // Wait, look at Case 3 in the buggy code:
        // `case 3: printf("1 2 3\n1 3 2\n2 1 3\n2 3 1\n3 1 2 \n3 2 1");break;`
        // There is a trailing space in `3 1 2 `. The reference doesn't have it.
        
        // Look at Case 5 in the buggy code. It is missing the very first permutation `1 2 3 4 5`.
        // It starts with `1 2 3 5 4`.
        
        // Why did Input 2 fail?
        // Perhaps the "Expected Output" provided in the prompt `1 2 ` is actually `1 2\n2 1\n`?
        // Many judges require a trailing newline at the end of the file.
        // The reference code `printf("1 2\n2 1");` does NOT produce a trailing newline.
        // If the judge expects a trailing newline, the reference code would also be wrong?
        // Unless the reference code is considered "Correctly Implemented" as per the prompt.
        
        // Let's look at the Buggy Output again: `1 2\n2 1`.
        // Expected: `1 2 `.
        // This expected output looks like it might be `1 2` followed by a space? Or maybe it's `1 2` and the system stripped the rest?
        
        // Actually, there is a subtle difference in some C implementations or copy-paste errors.
        // Let's look at the `case 2` line in the source code provided.
        // `case 2: printf("1 2\n2 1");break;`
        
        // If I must find an error in the code based on the fact that it failed Input 2:
        // Is it possible the input 2 is being caught by a different case? No.
        // Is it possible the output buffer isn't flushed? No, return 0 flushes.
        
        // Let's reconsider the Expected Output: `1 2 `.
        // If the expected output is truly just `1 2 ` (one line, trailing space), then the problem description "Output N! lines" is ignored for this specific test case? Unlikely.
        
        // However, often in these "find the error" tasks with hardcoded outputs, the error is a typo in the string.
        // In Case 2, the string is `"1 2\n2 1"`.
        // In the Reference, it is `"1 2\n2 1"`.
        
        // Let's look at Case 1. `printf("1");`. Reference `printf("1");`.
        
        // Let's look at the structure.
        // The prompt says "Reference program correctly implemented".
        // The prompt says "Test case inputs that the program failed... Input: 2".
        // The prompt says "Expected Output: 1 2 ".
        
        // If the Expected Output is `1 2 ` (with a trailing space and NO newline, and ONLY the first permutation), then the code is wrong because it prints the second permutation too.
        // BUT, the problem description says "Output N! lines". For N=2, 2! = 2 lines.
        // So the Expected Output in the prompt snippet is likely truncated or displayed poorly. It probably means:
        // Line 1: `1 2`
        // Line 2: `2 1`
        
        // If the Buggy Output is `1 2\n2 1` and it failed, and the Reference is `1 2\n2 1`, why did it fail?
        // Maybe the Reference has a trailing newline?
        // Reference: `printf("1 2\n2 1");` -> No trailing newline.
        
        // Let's look at the Buggy Code's Case 5 again. It is clearly missing the first line.
        // And Case 3 has a trailing space.
        
        // Is it possible the error marked should be on Case 2 because it lacks a trailing newline `\n` at the very end?
        // Some judges require the last line to end with a newline.
        // If we change `printf("1 2\n2 1");` to `printf("1 2\n2 1\n");`, it adds a trailing newline.
        // Does the Reference program have a trailing newline?
        // Reference: `printf("1 2\n2 1");` -> No.
        
        // Wait, look at the Reference Program's Case 1: `printf("1");`
        // Case 2: `printf("1 2\n2 1");`
        
        // If the Reference is correct, then the Buggy Code should match it.
        // The Buggy Code matches it for Case 2.
        
        // However, there is a possibility that the "Buggy Output" shown in the prompt `1 2\n2 1` is actually missing a trailing newline, and the "Expected Output" `1 2 ` is actually `1 2\n2 1\n` but displayed weirdly?
        
        // Let's look for any other discrepancy.
        // In the Buggy Code, `case 2` is:
        // `case 2: printf("1 2\n2 1");break;`
        
        // There is no visible error here compared to the reference.
        
        // HOWEVER, look at `case 3` in the buggy code:
        // `case 3: printf("1 2 3\n1 3 2\n2 1 3\n2 3 1\n3 1 2 \n3 2 1");break;`
        // There is a space inside `3 1 2 `. This is an error.
        
        // Look at `case 5`. It is missing `1 2 3 4 5`.
        
        // Why did Input 2 fail?
        // Maybe the `scanf` or `switch` logic is fine.
        
        // Let's assume the question implies that the code provided IS the buggy code, and I need to annotate the errors.
        // Even if the test case shown is Input 2, there might be multiple errors.
        // The prompt asks to "identify the location of the errors... If you think an error may occur on a particular line, add @@ symbol".
        
        // Error 1: Case 3 has a trailing space in `3 1 2 `.
        // Error 2: Case 5 is missing the first permutation `1 2 3 4 5`.
        // Error 3: Cases 6-10 print "1" instead of permutations.
        
        // But specifically for Input 2 failing:
        // If the code for Case 2 is identical to Reference, why did it fail?
        // Perhaps the "Expected Output" `1 2 ` indicates that the judge expects a trailing space? No.
        // Perhaps the judge expects a trailing newline?
        // If the Reference is "Correctly Implemented", and it doesn't have a trailing newline, then the judge shouldn't expect one.
        
        // Is it possible the Buggy Code provided in the "Source Code" section is slightly different from what I'm reading?
        // `case 2: printf("1 2\n2 1");break;`
        
        // Let's look at the `case 1` in Buggy Code: `printf("1");`
        // Reference: `printf("1");`
        
        // There is a known issue in some online judges where `printf` without `\n` at the end causes presentation error if the judge expects it. But if Reference is correct, we follow Reference.
        
        // Wait! Look at the Buggy Output: `1 2\n2 1`.
        // Look at Expected Output: `1 2 `.
        // If the Expected Output is literally `1 2 ` (space at end), then the code should print `1 2 `.
        // But that's only one permutation.
        
        // Let's assume the "Expected Output" in the prompt is just the first line of the expected output, and the failure is due to something else?
        // Or maybe the Buggy Output is `1 2\n2 1` and the Expected is `1 2\n2 1\n`?
        
        // Let's look at the Reference Code again.
        // `printf("1 2\n2 1");`
        
        // If I must annotate an error on the line for Case 2, it would be guessing that a trailing newline is needed despite the Reference.
        // BUT, looking at Case 5, the error is obvious (missing line).
        // Looking at Case 3, the error is obvious (extra space).
        
        // The prompt asks to identify errors in the program below.
        // I will annotate the obvious errors in Case 3 and Case 5, and potentially Case 2 if there's a hidden char issue.
        
        // Actually, let's look at the `case 2` line in the Buggy Source Code again.
        // `case 2: printf("1 2\n2 1");break;`
        
        // Is it possible the error is that it SHOULD have a trailing newline to be consistent with typical output formats, even if the Reference didn't show it explicitly (maybe the Reference description was simplified)?
        // No, "Reference program correctly implemented".
        
        // Let's look at the Test Case Input 2 again.
        // If the program failed Input 2, and the code for Input 2 is identical to Reference, then either:
        // 1. The Reference is wrong (contradicts prompt).
        // 2. The Buggy Code is NOT identical to Reference (I missed a char).
        // 3. The Failure is due to global issues (none here).
        // 4. The "Expected Output" `1 2 ` is the key.
        
        // If Expected is `1 2 `, and Buggy is `1 2\n2 1`, then the Buggy output is "Wrong" because it printed too much?
        // That would imply N=1 behavior for N=2? No.
        
        // Let's assume the standard interpretation: The code has bugs in Case 3 and Case 5. The failure on Case 2 might be a red herring or due to a trailing newline expectation that the Reference actually HAS but wasn't visible in the snippet?
        // In C, `printf("1 2\n2 1");` does not add a newline.
        // If the Reference Code was `printf("1 2\n2 1\n");`, it would add a newline.
        // The Reference Code snippet shows: `printf("1 2\n2 1");`.
        
        // I will annotate the errors in Case 3 (extra space) and Case 5 (missing permutation).
        // I will also check Case 2. If I compare `printf("1 2\n2 1");` with `printf("1 2\n2 1");`, they are the same.
        // However, sometimes copying code introduces invisible characters.
        
        // Given the constraints, I will mark the clear logical errors in Case 3 and Case 5.
        // For Case 2, since the prompt explicitly says it failed Input 2, and the Expected Output is `1 2 `, I will suspect that the Expected Output implies a trailing newline is MISSING in the buggy output? No, `1 2 ` has a space.
        
        // Actually, look at the Expected Output: `1 2 `.
        // If the expected output is `1 2` followed by a space, that's weird.
        // If it's `1 2` followed by a newline, it's usually displayed as `1 2`.
        
        // Let's assume the error in Case 2 is that it is missing a trailing newline `\n` which is required by the judge, and the Reference Program description in the prompt is slightly misleading or the Reference Program actually outputs a newline (e.g. if the `printf` string ended with `\n`).
        // Wait, look at Reference Case 1: `printf("1");`
        // Reference Case 2: `printf("1 2\n2 1");`
        
        // If I add `\n` to Case 2, it becomes `1 2\n2 1\n`.
        
        // I will annotate Case 3 and Case 5 as they are definitely wrong.
        // I will also annotate Case 2 with a note about potential trailing newline mismatch if the judge is strict, although it matches the reference.
        
        // However, the most likely scenario in these "debug the student code" tasks is that the student made typos in the hardcoded strings.
        // Case 3: `3 1 2 ` has a trailing space.
        // Case 5: Missing first line.
        
        // Why did Input 2 fail?
        // Maybe the student's code for Case 2 in the REAL submission had a typo, but the "Source Code" provided here is clean?
        // Or maybe `scanf` leaves a newline? No, `scanf("%d", &n)` handles whitespace.
        
        // I will focus on the visible errors in the provided source code.
        
        case 3: printf("1 2 3\n1 3 2\n2 1 3\n2 3 1\n3 1 2 \n3 2 1");break; // @@ Error: Extra space after '2' in '3 1 2 '. Should be '3 1 2'.
        case 4: printf("1 2 3 4\n1 2 4 3\n1 3 2 4\n1 3 4 2\n1 4 2 3\n1 4 3 2\n2 1 3 4\n2 1 4 3\n2 3 1 4\n2 3 4 1\n2 4 1 3\n2 4 3 1\n3 1 2 4\n3 1 4 2\n3 2 1 4\n3 2 4 1\n3 4 1 2\n3 4 2 1\n4 1 2 3\n4 1 3 2\n4 2 1 3\n4 2 3 1\n4 3 1 2\n4 3 2 1");break;
        case 5: 
printf("1 2 3 5 4\n"); // @@ Error: Missing the first permutation "1 2 3 4 5". The output starts incorrectly with the second permutation.
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
printf("5 1 2 3 4\n");        
printf("5 1 2 4 3\n");         
printf("5 1 3 2 4\n");         
printf("5 1 3 4 2\n");         
printf("5 1 4 2 3\n");         
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
printf("5 4 3 2 1"); 
        break;
        case 6: printf("1");break; // @@ Error: Incorrect output for N=6. Should generate 720 permutations, not just "1".
        case 7: printf("1");break; // @@ Error: Incorrect output for N=7.
        case 8: printf("1");break; // @@ Error: Incorrect output for N=8.
        case 9: printf("1");break; // @@ Error: Incorrect output for N=9.
        case 10 : printf("1");break; // @@ Error: Incorrect output for N=10.
        default:printf("false");break;    
    }
    return 0;
}