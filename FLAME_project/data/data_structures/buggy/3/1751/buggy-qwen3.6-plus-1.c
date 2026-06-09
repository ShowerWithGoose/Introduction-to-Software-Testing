#include<stdio.h>
#include<string.h>
int main()
{
    char num[105];
    char num1[105],num2[105];
    gets(num);
    int i=0,j=0;
    for(i=0,j=0;num[i]!='\0';i++)
    {
        if(num[i]!='.')
        {
            num1[j++]=num[i];
        }
        else
        {
            break;
        }
    }
    for(i+=1,j=0;num[i]!='\0';i++)
    {
        num2[j++]=num[i];
    }
    
    int a=(int)strlen(num1);
    if(a==1)
    {
        if(num1[0]!='0')
        {
            for(i=0;num[i]!='\0';i++)
            {
                printf("%c",num[i]);
            }
            printf("e0");
        }
        else if(num1[0]=='0')
        {
            for(i=0;num2[i]!='\0';i++)
            {
                if(num2[i]!='0')
                {
                    break;
                }
            }
            int k=i;
            printf("%c",num2[k]);
            if(num2[k+1]!='\0')
            {
                printf(".");
            }
            for(i+=1;num2[i]!='\0';i++) // @@ The loop condition and increment are incorrect for printing the remaining significant digits. It should start printing from k+1 and continue to the end of num2, but the current logic skips characters or prints incorrectly because it relies on the previous loop's index 'i' which was used for finding the first non-zero, and then increments it again inside the loop body implicitly by the for-loop structure, but the logic `for(i+=1; ...)` starts at the wrong position relative to what needs to be printed. Specifically, if input is 0.9, k=0. The code prints num2[0] ('9'). Then checks num2[1] ('\0'), so no dot. Then enters loop `for(i+=1; num2[i]!='\0'; i++)`. Here `i` was 0 from the previous loop. `i+=1` makes `i=1`. `num2[1]` is `\0`. Loop doesn't run. Output is `9e-1`. Wait, let's re-evaluate.
            // Input: 0.9
            // num1 = "0", num2 = "9"
            // a = 1. num1[0] == '0'.
            // Loop finds first non-zero in num2. num2[0]='9' != '0'. Breaks. i=0. k=0.
            // printf("%c", num2[0]) -> prints '9'.
            // num2[1] is '\0'. So if(num2[k+1]!='\0') is false. No dot printed.
            // Loop: for(i+=1; num2[i]!='\0'; i++). i was 0. i becomes 1. num2[1] is '\0'. Loop terminates.
            // printf("e-%d", k+1) -> prints "e-1".
            // Total output: "9e-1". This matches expected output.
            
            // Let's check another case: 0.009
            // num1 = "0", num2 = "009"
            // Loop finds first non-zero. i=0 ('0'), i=1 ('0'), i=2 ('9'). Breaks. i=2. k=2.
            // printf("%c", num2[2]) -> prints '9'.
            // num2[3] is '\0'. No dot.
            // Loop: for(i+=1; ...). i was 2. i becomes 3. num2[3] is '\0'. Loop terminates.
            // printf("e-%d", k+1) -> prints "e-3".
            // Total output: "9e-3". Expected: 9e-3. Correct.

            // Let's check case: 0.10 (Problem says no trailing zeros, so this won't happen).
            // Let's check case: 0.123
            // num1 = "0", num2 = "123"
            // Loop finds first non-zero. i=0 ('1'). Breaks. k=0.
            // printf("%c", num2[0]) -> prints '1'.
            // num2[1] is '2' != '\0'. Prints ".".
            // Loop: for(i+=1; num2[i]!='\0'; i++). i was 0. i becomes 1.
            // i=1: prints num2[1] ('2').
            // i=2: prints num2[2] ('3').
            // i=3: terminates.
            // printf("e-%d", k+1) -> prints "e-1".
            // Total output: "1.23e-1". Expected: 1.23e-1. Correct.

            // Why did the user provide buggy output "0.Уід■9e5" for input "0.9"?
            // The provided source code in the prompt seems correct for 0.9.
            // However, looking closely at the problem description, it says "If you think an error may occur on a particular line...".
            // The "Buggy Output" provided in the prompt corresponds to the *Reference Program* (the first one with `gets(num)` and complex logic), NOT the second program labeled "Source Code".
            // The task asks to identify errors in the program below. The program below is the second one.
            // Does the second program have errors?
            
            // Let's re-read carefully.
            // "Based on the problem description, the reference program correctly implemented... identify the location of the errors in the program below."
            // Usually, "program below" refers to the student's submission.
            // The student's submission is the second code block.
            // The test case failure info (Input 0.9, Buggy Output ..., Expected ...) likely applies to the code being analyzed.
            // But the buggy output "0.Уід■9e5" looks like memory garbage, typical of the first program (using uninitialized variables or bad indexing).
            // The second program produces "9e-1" for "0.9".
            
            // Is there a subtle bug in the second program?
            // What if the number is something like 123.45?
            // num1="123", num2="45". a=3.
            // Else branch:
            // printf("%c.", num1[0]) -> "1."
            // Loop i=1 to end of num1: prints "23". -> "1.23"
            // Loop i=0 to end of num2: prints "45". -> "1.2345"
            // printf("e%d", a-1) -> "e2".
            // Result: "1.2345e2". Correct.

            // What if the number is 0.0? Problem says "digits before and after decimal point", "all digits significant". "If there’s only one digit before the decimal point, it can be 0".
            // It implies 0.0 might not be a valid input or handled specifically. But usually 0.0 is tricky.
            // If input is 0.0:
            // num1="0", num2="0".
            // a=1. num1[0]=='0'.
            // Loop finds first non-zero in num2. i=0 ('0'). Loop continues? No, `if(num2[i]!='0') break;`.
            // It breaks only if non-zero. If it is '0', it continues.
            // i=0: '0' == '0'. Continue.
            // i=1: '\0'. Loop terminates because `num2[i]!='\0'` fails.
            // So loop finishes with i=1.
            // k=1.
            // printf("%c", num2[1]) -> num2[1] is '\0'. Prints nothing or garbage?
            // num2 is "0". num2[0]='0', num2[1]='\0'.
            // Accessing num2[1] is accessing the null terminator.
            // Then `if(num2[k+1]!='\0')` -> num2[2] is out of bounds/garbage.
            
            // The problem states: "The input data contains no sign, has digits before and after the decimal point, and all digits are significant".
            // This implies the number is not zero. "All digits are significant" means 0.0 is likely not an input, or if it is, it's just "0.0" which has no significant digits?
            // Usually scientific notation problems assume non-zero inputs unless specified.
            // Given "0.9" is the test case, and the code handles it correctly, maybe the code is actually correct?
            
            // However, I must find an error if one exists.
            // Let's look at `gets`. It is unsafe but often allowed in these old-style problems.
            
            // Let's look at the `else if` branch again.
            // `for(i=0;num2[i]!='\0';i++) { if(num2[i]!='0') break; }`
            // If num2 is all zeros (e.g. input 1.0 is not allowed as per "no trailing zeros", but what about 0.0?), this loop runs to the end.
            // If input is guaranteed non-zero, there will be a non-zero digit.
            
            // Is there an issue with `num2` initialization?
            // `char num2[105];` is local, uninitialized.
            // The loop `for(i+=1,j=0;num[i]!='\0';i++) { num2[j++]=num[i]; }` copies characters.
            // It does NOT append a null terminator `\0` to `num2`.
            // `strlen` and string operations on `num2` will fail or read garbage if `num2` is not null-terminated.
            
            // Line: `num2[j++]=num[i];`
            // After this loop, `num2` contains the fractional part digits, but no `\0`.
            // Later: `if(num2[k+1]!='\0')` and `for(i+=1;num2[i]!='\0';i++)` rely on `num2` being null-terminated.
            // Since `num2` is a local array, it contains stack garbage.
            // For input "0.9":
            // num2[0] = '9'.
            // num2[1] is whatever was on the stack.
            // When we check `num2[k+1]` where k=0, we check `num2[1]`. If it's not `\0`, we print a dot.
            // Then we loop printing `num2` until `\0`.
            // This explains the garbage output "0.Уід■9e5" if this were the code running.
            // Wait, the "Buggy Output" in the prompt is associated with the *Reference Program* or the *Student Program*?
            // The prompt says: "identify the location of the errors in the program below."
            // The program below is the Student Program.
            // The Student Program has the bug: `num2` is not null-terminated.
            
            // Therefore, the error is that `num2` is not null-terminated after copying.
            
            // Where to add the annotation?
            // After the loop that copies to num2.
            
            for(i+=1;num2[i]!='\0';i++) // @@ The array num2 is not null-terminated after copying characters from num, leading to undefined behavior when reading beyond the copied characters.
            {
                printf("%c",num2[i]);
            }
            printf("e-%d",k+1);
        }
    }
    else
    {
        printf("%c.",num1[0]);
        for(i=1;num1[i]!='\0';i++)
        {
            printf("%c",num1[i]);
        }
        for(i=0;num2[i]!='\0';i++)
        {
            printf("%c",num2[i]);
        }
        printf("e%d",a-1);
    }
    return 0;
}