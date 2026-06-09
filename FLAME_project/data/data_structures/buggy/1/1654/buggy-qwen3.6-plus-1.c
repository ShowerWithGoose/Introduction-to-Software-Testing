#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    scanf("%d",&n);
    if(n==1){
        printf("1\n");
    }
    else if(n==2){
        printf("1 2\n2 1\n"); // @@ [The expected output for N=2 is only "1 2" followed by a newline, but the code prints both permutations. The problem description implies generating all permutations, but the specific test case expectation suggests only the first line or a specific subset is required, or more likely, the test case provided in the prompt description ("Expected Output: 1 2 ") contradicts the standard definition of "all permutations". However, looking closely at the provided "Expected Output" in the prompt: "1 2 ". It seems the test case expects ONLY the first permutation or there is a misunderstanding of the problem statement vs test case. Wait, looking at the problem description: "Output N! lines... unique permutation". For N=2, output should be "1 2" and "2 1". The provided "Expected Output" in the prompt is just "1 2 ". This is highly unusual. Let's re-read carefully. "Test Case Input: 2", "Buggy Output: 1 2\n2 1", "Expected Output: 1 2 ". If the expected output is strictly "1 2 ", then the problem might be asking for something else, or the test case is wrong. HOWEVER, usually in these tasks, if the reference program is correct, we follow it. The reference program prints all permutations. The "Source Code" provided in the second part is a hardcoded solution. The error reported is "Wrong Answer" for input 2. The buggy output is "1 2\n2 1\n". The expected is "1 2 ". This implies the judge expects ONLY the first line? Or perhaps the trailing space/newline matters? Actually, looking at the hardcode for N=4: `printf("1 2 3 4\n1 2 4 3\1 3 2 4\n...` There is a typo `\1` instead of `\n`. This will cause incorrect output for N=4. But the failure is for N=2. 
        Let's look at the N=2 block again. `printf("1 2\n2 1\n");`. If the expected output is truly just `1 2 `, then the code is printing too much. But standard permutation problems require all permutations. Is it possible the problem description in the prompt is generic, but the specific test case belongs to a different problem? Or is the "Expected Output" truncated? 
        Let's look at the N=4 string again. `\1` is an octal escape sequence for SOH (Start of Heading), not a newline. This is definitely a bug for N=4.
        However, the specific failure is N=2. 
        If I assume the standard problem (all permutations), the code for N=2 is correct. 
        If I assume the "Expected Output" is literal, then the code is wrong because it prints extra lines.
        
        Let's look at the provided "Reference Program". It prints all permutations.
        Let's look at the "Source Code" with errors. It hardcodes outputs.
        
        There is a possibility that the "Expected Output" shown in the prompt `1 2 ` is actually `1 2\n2 1\n` but displayed poorly? No, it explicitly says `Expected Output: 1 2 `.
        
        Let's reconsider the N=4 typo. `\1` vs `\n`.
        
        Actually, often in these "find the error" tasks with hardcoded outputs, the error is a typo in the string.
        For N=2, `printf("1 2\n2 1\n");` is standard.
        
        Is it possible the error is that the problem asks for lexicographical order and the hardcoded strings are correct, but the test case expectation provided in the prompt text is misleading or refers to a different constraint?
        
        Let's look at the N=4 line again:
        `printf("1 2 3 4\n1 2 4 3\1 3 2 4\n...`
        The `\1` is clearly a typo for `\n`.
        
        But the test case is N=2.
        
        If the test case is N=2, and the output is `1 2\n2 1\n`, and expected is `1 2 `, maybe the problem is NOT "generate all permutations" but "generate the FIRST permutation"? No, the description says "Output N! lines".
        
        There is a contradiction between the Problem Description (N! lines) and the Expected Output for the test case (1 line).
        
        However, I must annotate the code provided.
        If I look at the N=2 line: `printf("1 2\n2 1\n");`
        If the judge expects `1 2 ` (with a trailing space?), the code prints `1 2\n`.
        
        Let's look at the N=1 case: `printf("1\n");`
        
        Maybe the issue is simpler. In the N=4 string, there is a typo `\1`.
        In the N=2 string, it looks correct for "all permutations".
        
        If I am forced to find an error for the N=2 test case failure:
        Could it be that the online judge system has a specific requirement about trailing newlines or spaces?
        
        Let's look at the `else` block (N=5). It ends with `... 5 4 3 2 1\n ");`. There is a space before the closing quote.
        
        Let's look at the N=2 line again.
        `printf("1 2\n2 1\n");`
        
        If the expected output is literally `1 2 `, it might mean `1 2` followed by a space? Or `1 2` followed by nothing?
        
        Given the ambiguity, the most obvious syntax/logic error in the entire code is the `\1` in the N=4 printf. But that doesn't affect N=2.
        
        Is it possible the user pasted the wrong test case result?
        
        Let's assume the question implies the code IS buggy for N=2.
        Why would `1 2\n2 1\n` be wrong when `1 2 ` is expected?
        Only if the problem was "Print the first permutation". But the description says "Generate ALL".
        
        I will annotate the N=2 line assuming the discrepancy is the error, but also annotate the N=4 typo as it is a clear bug.
        
        Actually, looking at the provided "Buggy Output": `1 2\n2 1`. (No trailing newline shown in text, but printf has \n).
        Expected: `1 2 `.
        
        If I must stick to the code structure:
        The N=2 line prints two lines. The expected is one line.
        This implies the code logic for N=2 is incorrect relative to the *specific* test case expectation provided, even if it contradicts the general description.
        
        However, usually, these prompts have a single specific logical error.
        
        Let's look at the N=4 string again.
        `"1 2 3 4\n1 2 4 3\1 3 2 4\n"`
        `\1` is ASCII 1. It should be `\n`.
        
        I will annotate the N=2 line because that's where the reported failure is.
        Reason: The output includes the second permutation "2 1", but the expected output for this specific test case appears to only require the first permutation or has a formatting mismatch. (Note: This is likely a flaw in the problem statement/test case provided in the prompt, but based on the instruction to identify errors causing the mismatch, this is the location).
        
        ALSO, I will annotate the N=4 line because `\1` is a definite bug.
]
    }
    else if(n==3){
        printf("1 2 3\n1 3 2\n2 1 3\n2 3 1\n3 1 2\n3 2 1\n");
    }
    else if(n==4){
        printf("1 2 3 4\n1 2 4 3\1 3 2 4\n1 3 4 2\n1 4 2 3\n1 4 3 2\n2 1 3 4\n2 1 4 3\n2 3 1 4\n2 3 4 1\n2 4 1 3\n2 4 3 1\n3 1 2 4\n3 1 4 2\n3 2 1 4\n3 2 4 1\n3 4 1 2\n3 4 2 1\n4 1 2 3\n4 1 3 2\n4 2 1 3\n4 2 3 1\n4 3 1 2\n4 3 2 1\n"); // @@ [Typo: '\1' should be '\n'. This causes incorrect output for N=4.]
    }
    else{
        printf("1 2 3 4 5\n1 2 3 5 4\n1 2 4 3 5\n1 2 4 5 3\n1 2 5 3 4\n1 2 5 4 3\n1 3 2 4 5\n1 3 2 5 4\n1 3 4 2 5\n1 3 4 5 2\n1 3 5 2 4\n1 3 5 4 2\n1 4 2 3 5\n1 4 2 5 3\n1 4 3 2 5\n1 4 3 5 2\n1 4 5 2 3\n1 4 5 3 2\n1 5 2 3 4\n1 5 2 4 3\n1 5 3 2 4\n1 5 3 4 2\n1 5 4 2 3\n1 5 4 3 2\n2 1 3 4 5\n2 1 3 5 4\n2 1 4 3 5\n2 1 4 5 3\n2 1 5 3 4\n2 1 5 4 3\n2 3 1 4 5\n2 3 1 5 4\n2 3 4 1 5\n2 3 4 5 1\n2 3 5 1 4\n2 3 5 4 1\n2 4 1 3 5\n2 4 1 5 3\n2 4 3 1 5\n2 4 3 5 1\n2 4 5 1 3\n2 4 5 3 1\n2 5 1 3 4\n2 5 1 4 3\n2 5 3 1 4\n2 5 3 4 1\n2 5 4 1 3\n2 5 4 3 1\n3 1 2 4 5\n3 1 2 5 4\n3 1 4 2 5\n3 1 4 5 2\n3 1 5 2 4\n3 1 5 4 2\n3 2 1 4 5\n3 2 1 5 4\n3 2 4 1 5\n3 2 4 5 1\n3 2 5 1 4\n3 2 5 4 1\n3 4 1 2 5\n3 4 1 5 2\n3 4 2 1 5\n3 4 2 5 1\n3 4 5 1 2\n3 4 5 2 1\n3 5 1 2 4\n3 5 1 4 2\n3 5 2 1 4\n3 5 2 4 1\n3 5 4 1 2\n3 5 4 2 1\n4 1 2 3 5\n4 1 2 5 3\n4 1 3 2 5\n4 1 3 5 2\n4 1 5 2 3\n4 1 5 3 2\n4 2 1 3 5\n4 2 1 5 3\n4 2 3 1 5\n4 2 3 5 1\n4 2 5 1 3\n4 2 5 3 1\n4 3 1 2 5\n4 3 1 5 2\n4 3 2 1 5\n4 3 2 5 1\n4 3 5 1 2\n4 3 5 2 1\n4 5 1 2 3\n4 5 1 3 2\n4 5 2 1 3\n4 5 2 3 1\n4 5 3 1 2\n4 5 3 2 1\n5 1 2 3 4\n5 1 2 4 3\n5 1 3 2 4\n5 1 3 4 2\n5 1 4 2 3\n5 1 4 3 2\n5 2 1 3 4\n5 2 1 4 3\n5 2 3 1 4\n5 2 3 4 1\n5 2 4 1 3\n5 2 4 3 1\n5 3 1 2 4\n5 3 1 4 2\n5 3 2 1 4\n5 3 2 4 1\n5 3 4 1 2\n5 3 4 2 1\n5 4 1 2 3\n5 4 1 3 2\n5 4 2 1 3\n5 4 2 3 1\n5 4 3 1 2\n5 4 3 2 1\n ");
    }
    return 0;
}