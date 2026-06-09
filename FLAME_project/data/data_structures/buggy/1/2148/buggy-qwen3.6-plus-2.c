#include<stdio.h>
#include<string.h>
int main(){
    int n;
    scanf("%d",&n);
    if(n==1){
        printf("1");
    }
    if(n==2){
        printf("1 2");
        printf("\n");
        printf("2 1"); // @@ The problem requires generating all permutations. For N=2, the permutations are "1 2" and "2 1". However, the expected output for the test case input '2' is only "1 2 ". This suggests a misunderstanding of the problem statement or the test case expectation in the prompt description vs standard permutation problems. Wait, looking at the Expected Output: "1 2 ". It seems the expected output might be truncated or specific to a different interpretation. Let's re-read carefully. "Output N! lines...". For N=2, 2! = 2 lines. The expected output provided in the prompt is "1 2 ". This is extremely strange. Usually, permutations of 1..2 are "1 2" and "2 1". If the expected output is strictly "1 2 ", then the problem might be asking for something else, or the test case expectation is wrong. However, looking at the Buggy Output: "1 2\n2 1", and Expected: "1 2 ", it implies the second line is missing or the format is different. Actually, looking at the reference program, it prints all permutations. The "Source Code" provided in the error analysis section is different from the "Reference Program". The user wants me to debug the "Source Code" at the bottom. The Source Code for N=2 prints "1 2\n2 1". The expected output is "1 2 ". This implies that perhaps the problem description in the prompt context is misleading or the "Expected Output" shown is just the first line? No, "Expected Output: 1 2 ". If the expected output is literally just "1 2 ", then the code should not print "2 1". But standard permutation generation requires all permutations. Let's look at the constraints. 1<=N<=10. The reference program handles 1-5. The source code handles 1-4. The test case is N=2. The buggy output is "1 2\n2 1". The expected output is "1 2 ". This is a contradiction with standard permutation definitions. However, often in these automated systems, if the expected output is "1 2 ", it might mean that the judge is only checking the first line, or there is a trailing space issue, or the problem is actually "Print the first permutation" (which is unlikely given the description). OR, more likely, the "Expected Output" provided in the prompt snippet is incomplete or malformed in the description, BUT I must follow the instruction: "identify the location of the errors... based on... expected output". If the expected output is truly just "1 2 ", then printing "2 1" is an error. Why would it be just "1 2 "? Maybe the problem is "Generate the lexicographically smallest permutation"? No, "generate all permutations". 
        Let's reconsider the "Expected Output". Is it possible the newline is missing in the expected output display? "1 2 " usually implies a trailing space or newline. If the buggy output is "1 2\n2 1", and expected is "1 2 ", maybe the system expects NO second line? That contradicts "Output N! lines". 
        Let's look at the Reference Program again. It prints all permutations. 
        Let's look at the Source Code again. It hardcodes outputs. 
        There is a high probability the "Expected Output" in the prompt description is actually "1 2\n2 1\n" but displayed poorly, OR the test case is actually checking for strict formatting where the last line should not have a newline? No, that doesn't remove the second line.
        
        Actually, let's look at the very first block of code provided as "Reference Program". It is a buggy implementation itself (hardcoded for 4 and 5). The second block is "Source Code" which is also hardcoded. 
        The prompt asks to identify errors in the "program below". The "program below" refers to the "Source Code" section at the end. 
        The Test Case Input is 2. 
        Buggy Output: `1 2\n2 1` (implied by printf statements). 
        Expected Output: `1 2 ` 
        
        If the expected output is strictly `1 2 `, then the code should NOT print `2 1`. This implies the problem might be misinterpreted by the student code, OR the expected output in the prompt is wrong/truncated. However, as an AI assistant, I must assume the Expected Output is correct for the specific judging environment. If the judge expects only `1 2 `, then the code printing `2 1` is wrong. But why? 
        Wait, look at the N=1 case: `printf("1");` (no newline). 
        N=2 case: `printf("1 2"); printf("\n"); printf("2 1");` (no newline at end). 
        Output: `1 2\n2 1`. 
        Expected: `1 2 `. 
        This looks like the Expected Output is actually just the first line `1 2` followed by a space/newline? 
        Let's look at similar problems. Often, if N=1, output `1`. If N=2, output `1 2` and `2 1`. 
        Is it possible the user made a typo in the "Expected Output" field of the prompt? "1 2 " vs "1 2\n2 1". 
        However, I must annotate the code based on the discrepancy. 
        If the expected output is ONLY "1 2 ", then the lines printing "2 1" are erroneous. 
        Line 10: `printf("2 1");` -> This line produces output that is not in the expected output. 
        
        Another possibility: The problem asks for permutations in lexicographical order. 
        For N=2: 
        1 2 
        2 1 
        Both are valid. 
        If the expected output is truncated in the prompt description, I should probably fix the formatting to match standard expectations (newlines at end of lines). 
        However, the instruction says "Based on ... expected output ... identify location of errors". 
        If I assume the Expected Output `1 2 ` is complete, then `printf("2 1");` is extra. 
        But this contradicts the Problem Description "Output N! lines". N!=2. So 2 lines are expected. 
        Therefore, the Expected Output in the prompt `1 2 ` is likely a representation of `1 2\n2 1\n` or similar, but cut off. 
        OR, is it possible the "Buggy Output" has an extra newline or space? 
        Buggy: `1 2\n2 1` 
        Expected: `1 2 ` 
        If the expected output ends with a space, and the buggy output ends with `1`, they don't match. 
        But the biggest difference is the missing second line in Expected. 
        
        Let's look at the N=3 block. It prints newlines after every line. 
        The N=2 block prints `1 2`, `\n`, `2 1`. It does NOT print a final `\n`. 
        The N=1 block prints `1`. No `\n`. 
        The N=4 block prints `\n` after every line including the last. 
        
        Inconsistent formatting. 
        For N=2, if the judge expects `1 2\n2 1\n`, the code outputs `1 2\n2 1`. Missing final newline. 
        For N=1, if judge expects `1\n`, code outputs `1`. 
        
        Let's assume the standard requirement: each line separated by newline. 
        The error is likely the missing newline at the end of the last permutation for N=2 (and N=1). 
        However, the prompt shows Expected Output as `1 2 `. This might represent `1 2` followed by a newline (displayed as space?). 
        If the expected output is `1 2\n2 1\n`, then the code is missing the last `\n`. 
        Line 10: `printf("2 1");` should be `printf("2 1\n");` or similar. 
        
        Let's annotate Line 10 because it lacks the terminating newline which is present in other blocks (like N=3, N=4) and is standard for line-based output. The "Expected Output" string `1 2 ` in the prompt is ambiguous but likely implies the content of the lines. If the Buggy Output is `1 2\n2 1` and Expected is `1 2\n2 1\n` (represented poorly), then the missing newline is the error. 
        
        Also, Line 8 `printf("1 2");` and Line 9 `printf("\n");` could be combined, but that's style. 
        The critical error is the missing newline after the last element.
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