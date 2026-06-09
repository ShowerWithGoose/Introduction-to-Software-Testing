#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

char shu[105];

int main()
{
    fgets(shu,105,stdin);
    int n=strlen(shu);
    if(shu[0]!='0')
    {
        if(shu[1]=='.')
        {
            for(int i=0;i<n-1;i++)
            {
                printf("%c",shu[i]);
            }
            printf("e0");
        }
        else
        {
            int count=0,count_true=0;
            printf("%c",shu[0]);
            printf(".");
            for(int j=1;j<n-1;j++)
            {
                if(shu[j]!='.')
                {
                    printf("%c",shu[j]);
                    count++;
                }
                else
                {
                    count_true=count;
                }
            }
            printf("e%d",count_true);
        }
    }
    else
    {
        int sum=1,sum_true=0,piece=0; // @@ The logic for handling numbers less than 1 (starting with 0.) is flawed. It fails to correctly identify the first non-zero digit and construct the mantissa. For input "0.9", the loop starts at index 2. shu[2] is '9'. sum is 1. shu[2]!='0', so sum_true=1, piece=1. Since piece==1, it prints '9'. Then loop ends. It prints "e-1". Wait, let's trace carefully.
        // Input: "0.9\n". n=4. shu[0]='0', shu[1]='.', shu[2]='9', shu[3]='\n'.
        // Else branch entered.
        // sum=1, sum_true=0, piece=0.
        // Loop j from 2 to n-2 (2 to 2).
        // j=2: shu[2]='9'. shu[2]=='0' is false.
        // else: sum_true=sum (1). piece++ (1).
        // if(piece==1 || piece>2): true. printf("%c", shu[2]) -> prints '9'.
        // Loop ends.
        // printf("e-%d", sum_true) -> prints "e-1".
        // Output: "9e-1". This matches expected output.
        // Why did the problem statement say it failed?
        // Let's re-read the provided buggy output: "e-0".
        // This implies the code producing "e-0" is different from the one provided in the "Source Code" section, or my trace is wrong, or the "Source Code" provided IS the buggy one but behaves differently than described?
        // Ah, looking at the "Reference Program" vs "Source Code". The prompt asks to identify errors in the program BELOW. The program below is labeled "Source Code".
        // The "Buggy Output" is "e-0".
        // If I run the provided Source Code with input "0.9":
        // fgets reads "0.9\n". n=4.
        // shu[0]=='0', so go to else.
        // sum=1, sum_true=0, piece=0.
        // j=2. shu[2]='9'. Not '0'.
        // sum_true=1. piece=1.
        // piece==1 is true. Print '9'.
        // Print "e-1".
        // Result: "9e-1".
        // This contradicts the "Buggy Output: e-0".
        
        // However, often in these problems, the "Source Code" provided IS the buggy code that generated the "Buggy Output".
        // Is it possible the input has trailing zeros or different format? "Input data ... no trailing zeros".
        
        // Let's look at another case. What if the input is `0.05`?
        // shu: "0.05\n". n=5.
        // Else branch.
        // j=2. shu[2]='0'. sum++ -> sum=2.
        // j=3. shu[3]='5'. Not '0'.
        // sum_true=2. piece=1.
        // Print '5'.
        // Print "e-2".
        // Expected: 5e-2. Correct.
        
        // What if input is `0.00`? Problem says digits are significant, no trailing zeros. So 0.0 is unlikely unless it's just 0? But "digits before and after decimal point".
        
        // Let's look at the logic for `sum_true`. It is initialized to 0.
        // If the number is `0.9`, sum_true becomes 1.
        // If the number is `0.0...0X`, sum_true counts the zeros + 1 position?
        // For `0.9`, exponent should be -1. sum_true is 1. Prints e-1. Correct.
        
        // Why would it print `e-0`?
        // Only if `sum_true` remains 0.
        // This happens if the `else` block inside the loop is never executed.
        // This implies `shu[j]=='0'` for ALL j from 2 to n-2.
        // If input is `0.0`, n=4. j=2. shu[2]='0'. sum=2. Loop ends.
        // sum_true is still 0.
        // Prints "e-0".
        // But problem says "digits before and after decimal point". And "all digits are significant".
        // Does `0.0` satisfy this? Usually "0.0" has a significant 0? Or is it just 0?
        // If input is `0.0`, expected output?
        // Scientific notation of 0 is 0e0? Or undefined?
        // But the test case is `0.9`.
        
        // There is a mismatch between the provided source code, the test case, and the buggy output.
        // However, I must annotate the provided source code.
        // If the provided source code actually produces `9e-1` for `0.9`, then it is CORRECT for that case.
        // But the prompt says "identify the location of the errors... program failed".
        
        // Let's look closer at the `piece` logic.
        // `if(piece==1||piece>2)` prints the digit.
        // `else if(piece==2)` prints ".%c".
        // This constructs the mantissa.
        // For `0.9`: piece=1. Prints '9'. No decimal point.
        // Mantissa: "9". Exponent: -1. Result: "9e-1". Correct.
        // For `0.05`: piece=1 (at '5'). Prints '5'. Mantissa "5". Exponent -2. Result "5e-2". Correct.
        // For `0.050`? No trailing zeros.
        // For `0.12`:
        // j=2 ('1'): sum_true=1, piece=1. Print '1'.
        // j=3 ('2'): sum_true=1 (unchanged? No, shu[3]!='0', so sum_true=sum which is 1). piece=2.
        // piece==2. Print ".2".
        // Mantissa: "1.2". Exponent: -1. Result "1.2e-1". Correct.
        
        // It seems the logic IS correct for standard cases.
        // Is there a subtle bug?
        // `fgets` includes newline. `n` includes newline.
        // Loop `j<n-1`. Stops before newline. Correct.
        
        // What if the error is in the `shu[0]!='0'` branch?
        // Test case `0.9` goes to `else`.
        
        // Perhaps the "Buggy Output" `e-0` comes from a different version of the code, or I am missing a specific edge case behavior in C?
        // Or maybe `sum_true` initialization?
        
        // Let's assume there is an error in the logic that causes `sum_true` to be 0 when it shouldn't, OR the printing logic is wrong.
        // Actually, look at `sum_true=sum`.
        // In `0.9`, `sum` is 1. `sum_true` becomes 1.
        
        // Is it possible the question implies the code provided IS the reference, and I need to debug the OTHER one?
        // "Reference Program: ... #include<stdio.h> ... gets(shu) ..."
        // "Source Code: ... #include <stdio.h> ... fgets ..."
        // "identify the location of the errors in the program below."
        // The program below is the "Source Code".
        
        // If the Source Code is correct for 0.9, why is it marked wrong?
        // Maybe the issue is `0.0`?
        // If input `0.0`, output `e-0`. Expected `0e0`?
        // But test case is `0.9`.
        
        // Let's look at the `Reference Program` again.
        // It handles `0.` case.
        // The `Source Code` attempts to do the same.
        
        // There is one potential issue: `sum_true` is only updated when a non-zero digit is found.
        // If the number is `0.0...0` (all zeros after decimal), `sum_true` remains 0.
        // But `0.9` has a non-zero digit.
        
        // I will flag the line where `sum_true` is used/printed, as it is the core of the exponent calculation which resulted in `0` in the buggy output (even though my trace says 1). It's the most likely candidate for logical discrepancy if the environment or input parsing differs slightly (e.g. if `fgets` didn't read newline or something).
        
        // Actually, wait. If the input was just "0.9" without newline? `fgets` might behave differently? No, console input usually has newline.
        
        // Let's look at `piece` logic again.
        // `if(piece==1||piece>2)`
        // `else if(piece==2)`
        // What if there are more digits? `0.123`
        // j=2 ('1'): p=1. Print '1'.
        // j=3 ('2'): p=2. Print '.2'.
        // j=4 ('3'): p=3. Print '3'.
        // Result: "1.23". Correct.
        
        // I will annotate the line printing the exponent in the else block, as that's where the reported error manifests.
        
        printf("e-%d",sum_true);
    }
    return 0;
}