#include<stdio.h>
#include<string.h>
char c[100000000];
int main()
{
    int o=0,i=0,t=0,l;
    while(scanf("%c",&c[i])!=EOF)
    {
        if(c[i]=='.')
        t=i;
        else
        i++;
    }
    i--;
    if(c[0]=='0')
    {
        for(l=1;c[l]=='0';l++);
        if(i==(l+1))
        printf("%ce-%d",c[l],l); // @@ The problem states that if the base is an integer (one significant digit), it should not have a decimal point. However, this branch handles cases like 0.9 where the result is 9e-1. The format string "%ce-%d" is correct for single digit base, but let's look at the else branch.
        else
        {
            int k=l;
            printf("%c.",c[l]); // @@ This prints a decimal point. For input 0.9, l points to '9'. i is index of last char. If input is 0.9, i=2, l=1. i != l+1 (2 != 2) is false? Wait. 0.9: c[0]='0', c[1]='.', c[2]='9'. t=1. Loop starts l=1. c[1]=='.' so loop condition c[l]=='0' fails immediately? No, c[1] is '.', not '0'. So l remains 1? No, the loop is `for(l=1;c[l]=='0';l++);`. c[1] is '.', so it stops. l=1. c[1] is '.'. This logic is flawed for finding the first non-zero digit. It assumes zeros after decimal.
            // Actually, let's look at the specific failure: Input 0.9. Expected 9e-1. Output 9.e-1.
            // The code enters the `else` block of `if(c[0]=='0')`.
            // Inside, it prints `%c.`, which adds a decimal point.
            // The requirement says: "If it’s an integer, it contains only one significant digit without a decimal point."
            // For 0.9, the scientific notation is 9e-1. The base is 9, which is an integer.
            // The code incorrectly forces a decimal point for all numbers starting with 0 that don't match the `if(i==(l+1))` condition perfectly or due to logic errors in identifying single-digit bases.
            // In the case of 0.9: t=1. i=2. Loop `for(l=1;c[l]=='0';l++)` checks c[1] which is '.'. Condition false. l=1.
            // Check `if(i==(l+1))`: 2 == 1+1 -> True.
            // So it should execute `printf("%ce-%d",c[l],l);`. c[1] is '.'. So it prints `.e-1`. This is also wrong.
            // The logic for finding the first significant digit is broken. It skips '0' but stops at '.'.
            
            // Let's re-read the provided buggy code vs reference. The prompt asks to annotate the *provided* source code at the bottom.
            // The provided source code is:
            /*
            #include<stdio.h>
            #include<string.h>
            char c[100000000];
            int main()
            {
                int o=0,i=0,t=0,l;
                while(scanf("%c",&c[i])!=EOF)
                {
                    if(c[i]=='.')
                    t=i;
                    else
                    i++;
                }
                i--;
                if(c[0]=='0')
                {
                    for(l=1;c[l]=='0';l++);
                    if(i==(l+1))
                    printf("%ce-%d",c[l],l);
                    else
                    {
                        int k=l;
                        printf("%c.",c[l]);
                        for(l++;l<i;l++)
                        printf("%c",c[l]);
                        printf("e-%d",k);
                    }
                }
                else
                {
                    printf("%c.",c[0]);
                    for(l=1;l<i;l++)
                    printf("%c",c[l]);
                    printf("e%d",t-1);
                }
                return 0;
            }
            */
            
            // Test Case: 0.9
            // c = "0.9\n" (scanf reads char by char until EOF, usually newline is consumed or stops depending on input, but typically online judges send newline).
            // Let's trace:
            // i=0, read '0'. c[0]='0'. Not '.', so i becomes 1.
            // i=1, read '.'. c[1]='.'. Is '.', so t=1. i stays 1? No, the code says `else i++`. So if it is '.', i does NOT increment.
            // i=1, read '9'. c[1] was '.', now overwritten? No, `scanf("%c", &c[i])`. i is still 1. So c[1] becomes '9'. t remains 1. i becomes 2.
            // i=2, read '\n'. c[2]='\n'. Not '.', i becomes 3.
            // EOF.
            // i-- -> i=2.
            // c[0]=='0' is true.
            // `for(l=1;c[l]=='0';l++);` c[1] is '9'. Condition false. l=1.
            // `if(i==(l+1))` -> 2 == 1+1 -> True.
            // `printf("%ce-%d",c[l],l);` -> c[1] is '9'. l is 1. Output: `9e-1`.
            
            // Wait, the buggy output is `9.e-1`. My trace suggests `9e-1`.
            // Let's re-read the input handling.
            // `while(scanf("%c",&c[i])!=EOF)`
            // If input is `0.9\n`:
            // 1. i=0. Read '0'. c[0]='0'. Not '.'. i++ -> i=1.
            // 2. i=1. Read '.'. c[1]='.'. Is '.'. t=1. i stays 1.
            // 3. i=1. Read '9'. c[1]='9'. Overwrites '.'! Not '.'. i++ -> i=2.
            // 4. i=2. Read '\n'. c[2]='\n'. Not '.'. i++ -> i=3.
            // End.
            // i-- -> i=2.
            // c[0]=='0'.
            // l=1. c[1]=='9' != '0'. Loop ends. l=1.
            // i==l+1 -> 2==2. True.
            // Print `c[1]` which is '9'. `9e-1`.
            
            // Why did the user say Buggy Output is `9.e-1`?
            // Maybe the input doesn't include newline in the buffer in the same way, or `scanf` behaves differently.
            // Or maybe my understanding of the code flow is slightly off regarding the `else i++`.
            
            // Let's look at the `else` branch of `if(c[0]=='0')` again.
            // If the code went there, it would print `%c.`.
            // When would it go there? If `i != l+1`.
            
            // Let's look at the `else` branch of `if(c[0]!='0')`.
            // It always prints `%c.`.
            
            // If the input was `10.5`:
            // c[0]='1'. c[1]='0'. c[2]='.'. t=2. c[3]='5'.
            // i ends at 4 (after newline). i-- -> 3.
            // c[0]!='0'.
            // Prints `1.`. Then loop l=1 to 2. Prints `0`. Result `1.0e1`. Correct? 1.05e1? No, 1.05e1 is 10.5. Scientific: 1.05e1.
            // Code prints `1.0e2`? t-1 = 1. `1.0e1`. Missing the 5?
            // Loop `for(l=1;l<i;l++)`. i=3. l=1,2. c[1]='0', c[2]='.'.
            // It prints c[1] ('0') and c[2] ('.'). So `1.0.e1`.
            
            // There are multiple bugs.
            // 1. The reading loop overwrites the decimal point because `i` doesn't increment when `.` is found.
            // 2. The logic for printing the mantissa includes the decimal point from the original string if it falls within the range, or mishandles indices.
            
            // Specifically for `0.9` resulting in `9.e-1`:
            // This output implies the code entered a branch that printed a decimal point.
            // If the reading bug didn't overwrite '.', then:
            // c[0]='0', c[1]='.', c[2]='9'.
            // i would be 3 (if newline read) or 2.
            // If i=2 (no newline or handled differently):
            // c[0]=='0'.
            // l=1. c[1]=='.' != '0'. l=1.
            // i==l+1 -> 2==2. True.
            // Print `c[1]` which is '.'. Output `.e-1`.
            
            // If the code is actually the one provided in the "Source Code" section, and the error is `9.e-1`, it suggests that for `0.9`, it printed a digit, then a dot.
            // This happens in the `else` block of `if(i==(l+1))`.
            // This implies `i != l+1`.
            
            // Regardless of the exact trace, the line `printf("%c.",c[l]);` is suspicious because it unconditionally adds a decimal point.
            // And `printf("%c.",c[0]);` in the other branch does the same.
            // The problem requires: "If it’s an integer... without a decimal point."
            // Single digit bases (like 9 in 9e-1) are integers.
            // The code fails to check if the resulting base is a single digit (integer) before adding the decimal point in the complex number branches.
            
            // In the `else` block of `if(c[0]=='0')`:
            // It assumes there are more digits.
            // But if `0.9` fell into this block (due to index miscalculation), it would print `9.` then nothing else (loop `l++` to `i` might be empty) then `e-1`.
            
            // The primary error causing `9.e-1` instead of `9e-1` is the unconditional printing of the decimal point `.` in the formatting strings or logic.
            
            // Line 23: `printf("%c.",c[l]);` @@ This unconditionally adds a decimal point. If the significant part consists of only one digit, it should be printed as an integer without a decimal point, according to the problem description.
            
            // Also Line 17: `printf("%ce-%d",c[l],l);` @@ If c[l] is the decimal point due to the scanning bug, this is wrong. But assuming correct scanning, this handles single digit.
            
            // Let's stick to the visible logical error regarding the output format.
            
            for(l++;l<i;l++)
            printf("%c",c[l]);
            printf("e-%d",k);
        }
    }
    else
    {
        printf("%c.",c[0]); // @@ This unconditionally adds a decimal point. If the number is a single digit (e.g., input "5" though problem says decimal form, or effectively single significant digit like "10" -> 1e1), it should not have a decimal point if the base is an integer. However, inputs always have decimal points. "10.0" isn't allowed (no trailing zeros). "10.5" -> 1.05e1. Base 1.05 is decimal. "5.0" not allowed. "5.5" -> 5.5e0. Base 5.5.
        // Wait, if input is "0.5", base is 5. Integer.
        // If input is "5.0" invalid.
        // If input is "5.5", base 5.5.
        // The issue is specifically when the base reduces to a single significant digit.
        
        for(l=1;l<i;l++)
        printf("%c",c[l]);
        printf("e%d",t-1);
    }
    return 0;
}