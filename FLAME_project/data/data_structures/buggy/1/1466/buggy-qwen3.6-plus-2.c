#include<stdio.h>
            
int main(){
    int n;
    scanf("%d",&n);
    switch(n){
        case 1: printf("1");break;
        case 2: printf("1 2\n2 1");break; // @@ The output for N=2 is missing a trailing newline after the last permutation, or includes an extra newline depending on strict comparison. However, looking at the expected output "1 2 \n", it seems the test case expects only the first line or has a specific formatting requirement. Actually, looking closely at the Expected Output: "1 2 ", it seems there is a trailing space or newline issue. But wait, the expected output provided in the prompt is `1 2 `. This looks like it might be truncated or expecting a newline. Let's look at the Buggy Output: `1 2\n2 1`. The expected output is just `1 2 `. This implies the test case might be checking for N=1 but input is 2? No, Input is 2. If Input is 2, Expected Output should be two lines. The provided "Expected Output" in the prompt description `1 2 ` seems malformed or truncated. However, usually these problems require a newline at the end of each line. The reference program prints `1 2\n2 1`. The buggy code prints `1 2\n2 1`. They are identical for case 2. 
        // Let's re-read carefully. 
        // Test Case Input: 2
        // Buggy Output: 1 2\n2 1
        // Expected Output: 1 2 
        // This expected output looks like it's missing the second line "2 1". Or perhaps it means "1 2" followed by a newline? 
        // If the expected output is literally "1 2 " (with a trailing space) or "1 2\n", then the buggy output "1 2\n2 1" is wrong because it has too much content? No, that's impossible for permutations of 2.
        // Let's look at Case 3 in the buggy code: `printf("1 2 3\n1 3 2\n2 1 3\n2 3 1\n3 1 2 \n3 2 1");`
        // Notice `3 1 2 \n`. There is a trailing space before the newline.
        // Let's look at Case 1: `printf("1");` - No newline.
        // Let's look at Case 2: `printf("1 2\n2 1");` - No trailing newline.
        
        // Often, online judges require a newline at the very end of the output.
        // If the expected output for N=2 is:
        // 1 2
        // 2 1
        // (with a trailing newline), then `printf("1 2\n2 1");` produces `1 2\n2 1` (no trailing newline).
        // Many judges are strict about this.
        
        // However, there is a more subtle error in the provided "Source Code" vs "Reference Program".
        // In the Source Code, Case 5 is missing the first line: `1 2 3 4 5`.
        // The Source Code Case 5 starts with: `printf("1 2 3 5 4\n");`
        // The Reference Program Case 5 starts with: `printf("1 2 3 4 5\n...`
        // So for N=5, the output is wrong.
        
        // But the test case is N=2.
        // Let's look at the Expected Output again: `1 2 `
        // Is it possible the expected output is actually `1 2\n` and the display is trimming?
        // Or is it possible the question implies that the output for N=2 should ONLY be `1 2`? No, "generate ALL permutations".
        
        // Let's look at the structure of the Buggy Code's Case 2:
        // `case 2: printf("1 2\n2 1");break;`
        
        // If the judge expects a trailing newline for the last line, it should be `1 2\n2 1\n`.
        
        // Let's check Case 3 in Buggy Code:
        // `case 3: printf("1 2 3\n1 3 2\n2 1 3\n2 3 1\n3 1 2 \n3 2 1");break;`
        // Note the space in `3 1 2 \n`. This is likely an error.
        
        // Let's check Case 5 in Buggy Code:
        // It is missing `1 2 3 4 5`.
        
        // The prompt asks to identify errors based on the failed test case N=2.
        // If N=2 fails, and the output is `1 2\n2 1` vs Expected `1 2 `, it is highly probable that the Expected Output in the prompt description is truncated or formatted poorly in the description, BUT typically "Wrong Answer" on simple permutation problems with hardcoded strings is due to:
        // 1. Missing trailing newline.
        // 2. Extra spaces.
        // 3. Wrong order.
        
        // Comparing Buggy Output `1 2\n2 1` with standard correct output `1 2\n2 1\n`.
        // If the system expects a trailing newline, line 7 is missing it.
        
        // However, there is another possibility. Look at the Expected Output: `1 2 `.
        // Could it be that the test case input was actually 1? No, it says 2.
        
        // Let's assume the standard error: Missing trailing newline in the last printf of each case.
        // For Case 2: `printf("1 2\n2 1");` should be `printf("1 2\n2 1\n");`
        
        // Let's verify this hypothesis against Case 1: `printf("1");` -> should be `printf("1\n");`
        
        // Therefore, the error is likely the missing newline at the end of the output strings.

        case 3: printf("1 2 3\n1 3 2\n2 1 3\n2 3 1\n3 1 2 \n3 2 1");break; // @@ Contains an extra space in '3 1 2 ' and missing trailing newline.
        case 4: printf("1 2 3 4\n1 2 4 3\n1 3 2 4\n1 3 4 2\n1 4 2 3\n1 4 3 2\n2 1 3 4\n2 1 4 3\n2 3 1 4\n2 3 4 1\n2 4 1 3\n2 4 3 1\n3 1 2 4\n3 1 4 2\n3 2 1 4\n3 2 4 1\n3 4 1 2\n3 4 2 1\n4 1 2 3\n4 1 3 2\n4 2 1 3\n4 2 3 1\n4 3 1 2\n4 3 2 1");break; // @@ Missing trailing newline.
        case 5: 
printf("1 2 3 5 4\n"); // @@ Missing the first permutation "1 2 3 4 5" and subsequent lines are shifted/incorrect relative to standard lex order if the first is missing. Also missing trailing newline at the very end of case 5.
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
        case 6: printf("1");break;
        case 7: printf("1");break;
        case 8: printf("1");break;
        case 9: printf("1");break;
        case 10 : printf("1");break;
        default:printf("false");break;    
    }
    return 0;
}