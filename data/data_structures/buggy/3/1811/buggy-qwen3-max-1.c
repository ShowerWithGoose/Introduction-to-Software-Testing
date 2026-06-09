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
                    count_true=count; // @@ [This logic incorrectly assumes the decimal point appears after some digits and uses 'count' (number of non-dot digits before '.') as exponent, but 'count' includes digits before '.' only if '.' hasn't been encountered yet. Also, 'count_true' is never updated correctly if '.' appears early.]
                }
            }
            printf("e%d",count_true); // @@ [If there's no '.' in the input (which shouldn't happen per problem, but code doesn't ensure it), count_true remains 0, leading to wrong exponent. Also, for numbers like "123.45", this prints "1.2345e2" correctly, but logic is fragile and relies on '.' being present. However, main issue: when '.' is at position >1, count_true is set to number of digits before '.', which is correct, BUT if '.' never appears in the loop (shouldn't happen), it fails. More critically, the condition `shu[0]!='0'` excludes valid cases like "0.1", but also misses cases like "10.0" — however, per problem, all digits are significant and no trailing zeros, so "10.0" won't appear. Still, the bigger flaw is in the else branch handling of zero-leading numbers.]
        }
    }
    else
    {
        int sum=1,sum_true=0,piece=0;
        for(int j=2;j<n-1;j++)
        {
            if(shu[j]=='0')
            {
                sum++; // @@ [This counts consecutive zeros after "0.", but 'sum' starts at 1, so for "0.001", it becomes 3, which is correct for exponent -3, but logic breaks if non-zero digit appears later. However, the real issue is in printing format.]
            }
            else
            {
                sum_true=sum; // @@ [Records the number of leading zeros + 1, which gives correct exponent magnitude, e.g., "0.001" → sum=3 → exponent -3. This part is okay.]
                piece++; // @@ [Counts non-zero digits encountered.]
                if(piece==1||piece>2)
                {
                    printf("%c",shu[j]); // @@ [For first non-zero digit, prints without decimal point. For third+ digits, prints directly. But misses decimal point placement.]
                }
                else if(piece==2)
                {
                    printf(".%c",shu[j]); // @@ [Only on second non-zero digit does it print a decimal point before it. This leads to incorrect base format. For example, "0.00123" should become "1.23e-3", but this prints "1.23" as: first digit '1' (piece=1) → prints '1'; second digit '2' (piece=2) → prints '.2'; third digit '3' (piece=3) → prints '3' → result "1.23", which is correct. Wait, that seems okay. But what if only one non-zero digit? Like "0.001"? Then piece=1, prints '1', then exits loop, and prints "e-3" → "1e-3", which is correct per spec (integer base allowed for single digit). So this might be okay. However, consider "0.1": j starts at 2, shu[2]='1', not zero → sum_true=1, piece=1 → prints '1', then "e-1" → "1e-1", correct. Now consider "0.10": but problem says no trailing zeros, so not possible. So maybe this branch is okay? But wait: what if input is "0.0"? Problem states all digits are significant and no trailing zeros, so "0.0" won't occur. So perhaps the error is elsewhere.]

                // However, critical flaw: the code assumes that after "0.", there is at least one non-zero digit (per problem statement, yes), but what if the input is just "0."? Problem says digits before and after decimal, so "0." alone is invalid per problem, so maybe safe.

                // But here's a real bug: the variable 'sum' starts at 1, and increments for each '0' starting from index 2. For "0.1", j=2, shu[2]='1' ≠ '0', so sum remains 1 → sum_true=1 → exponent -1 → correct. For "0.01", j=2: '0' → sum=2; j=3: '1' → sum_true=2 → exponent -2 → correct. So exponent logic is okay.

                // Then why test case fails? Let's look at overall structure.

                // Major issue: the condition `if(shu[0]!='0')` handles numbers NOT starting with '0', which includes numbers like "123.45" or "1.23", but what about "10.5"? That starts with '1', so goes into first branch. If it's "10.5", then shu[1] is '0', not '.', so goes to else part of inner if. Then it prints "1.", then loops j=1 to n-2: j=1: '0' → print '0', count=1; j=2: '.' → set count_true=count=1; j=3: '5' → print '5', count=2. Then prints "e1". So output: "1.05e1" → which is 10.5, correct. So that seems okay.

                // But what about a number like "5"? Input "5\n". Then n=2, shu[0]='5', shu[1]='\n'. Then shu[0]!='0' → true. Then check shu[1]=='.'? No, it's '\n'. So go to else. Then print '5', then '.', then loop j=1 to n-2=0 → loop doesn't run. Then print "e0" → "5.e0". But expected output should be "5e0" (since integer base with one digit, no decimal point). The problem says: "If it’s an integer, it contains only one significant digit without a decimal point." So "5.e0" is invalid; should be "5e0". So this is a bug.

                // Also, for input "5.0" — but problem says no trailing zeros, so "5.0" won't appear. But "5" alone should be handled as integer.

                // Another case: input "12" (no decimal). Then n=3 ("12\n"). shu[0]='1'≠'0', shu[1]='2'≠'.', so go to else. Print '1.', then j=1: '2' → print '2', count=1; j=2: '\n' → loop ends. count_true was never set (because no '.' encountered), so count_true=0. Then print "e0" → "1.2e0", but should be "1.2e1" because 12 = 1.2 × 10^1. So exponent is wrong!

                // Why? Because in the else branch (when shu[0]!='0' and shu[1]!='.'), the code assumes there is a decimal point somewhere, and tries to record its position via count_true = count when '.' is found. But if there is NO decimal point (like "12"), then '.' is never found, so count_true remains 0, and exponent is printed as 0, which is wrong.

                // The problem states: "The input data contains no sign, has digits before and after the decimal point" — wait! Re-read problem: "has digits before and after the decimal point". So input will ALWAYS have a decimal point? Let me check.

                // Problem Description: "The input data contains no sign, has digits before and after the decimal point, and all digits are significant..."

                // So input always has a decimal point! Therefore, cases like "12" (without decimal) should NOT occur. So the program can assume '.' is present.

                // Then why does the reference program handle point==0? Maybe the problem statement in the reference allows no decimal? But the current problem says "has digits before and after the decimal point", so decimal point must be present.

                // Therefore, in the buggy code, we can assume '.' is always present.

                // Then in the first branch (shu[0]!='0'), if shu[1]=='.', it's like "5.123", output as is with e0 — correct.

                // Else, it's like "123.45", then the code prints "1.", then all digits except newline, then exponent = count_true, which is set when '.' is encountered to the number of digits printed before '.' (which is count). For "123.45", digits before '.' are '1','2','3' — but wait, in the loop j starts at 1: j=1: '2' → print, count=1; j=2: '3' → print, count=2; j=3: '.' → count_true=2. Then j=4: '4' → print, count=3; j=5: '5' → print, count=4. Then exponent=2. But 123.45 = 1.2345 × 10^2 → correct. So exponent is pl-1 where pl is position of '.', which is 3 (0-indexed), so 3-1=2. And count_true=2, which matches. So this works.

                // Now the else branch (shu[0]=='0'): input like "0.00123". The code loops from j=2 (after "0.") and counts leading zeros in 'sum' (starting at 1). When non-zero found, sets sum_true=sum, and prints digits with decimal after first non-zero if more than one digit.

                // For "0.001": piece=1 → prints '1', then "e-1"? No: sum starts at 1, j=2: '0' → sum=2; j=3: '0' → sum=3; j=4: '1' → sum_true=3, piece=1 → prints '1', then "e-3" → "1e-3", correct.

                // For "0.0012": j=2:'0'→sum=2; j=3:'0'→sum=3; j=4:'1'→sum_true=3, piece=1→print '1'; j=5:'2'→piece=2→print '.2'; then "e-3" → "1.2e-3", correct.

                // So why compilation error? The user says "Error type: Compilation Error", and test case input shows "/bin/sh: 1: gcc: not found", which means the environment lacks gcc — but that's not a code error.

                // However, the instruction says: "identify the location of the errors in the program below" based on failed test cases. But the provided "Buggy Output" is a shell error, not program output.

                // But looking back, the user says: "Test Case Input:" is empty, and "Buggy Output:" is "/bin/sh: 1: gcc: not found", which suggests the code didn't even compile because gcc isn't installed. But that's not the program's fault.

                // However, the actual task is to find logical errors in the given source code (the second code block), assuming it compiles.

                // But wait: the code uses `for(int i=0;...)` which is C99. If compiled in C89 mode, it would fail. But the reference program uses `int i=0` outside loop, so maybe the environment expects C89.

                // However, the problem says "Compilation Error", but the given code is syntactically valid C99. But let's check for other issues.

                // Actually, the real issue might be logical, and the "Compilation Error" label is misleading. Because the sample input/output suggests runtime behavior.

                // Given the confusion, but based on code analysis, the main logical errors are:

                // 1. In the non-zero-leading branch, when the number has more than one digit before the decimal (e.g., "12.3"), the exponent is computed as the number of digits before the decimal minus one, which is correct. But the code relies on encountering '.' to set count_true. Since problem guarantees '.', it's okay.

                // 2. However, there's a critical bug in the zero-leading branch: the variable 'sum' is initialized to 1, and incremented for each '0' after "0.". But for "0.1", there are no zeros after "0.", so sum remains 1, which is correct (exponent -1). But what if the input is "0.0"? Problem says all digits significant and no trailing zeros, so "0.0" is invalid. So okay.

                // But wait: what if the input has only one non-zero digit after many zeros, like "0.0005"? Then piece=1, so it prints "5e-4", which is correct.

                // However, consider input "0.100" — but problem says no trailing zeros, so last zero wouldn't be there.

                // Now, here's a real bug: in the zero-leading branch, the loop runs from j=2 to n-2 (because n = strlen(shu), and fgets includes '\n', so last char is '\n', and we go to n-2 to exclude it). But what if the input doesn't end with '\n'? fgets will still null-terminate, but if the line is exactly 104 chars, it might not have '\n'. However, problem says "ending with a newline", so safe.

                // But the major flaw is in the non-zero-leading branch when the number is of the form "d." followed by digits, but the code in the else part (when shu[1] != '.') prints a decimal point unconditionally after the first digit, even if the original number had only one digit before the decimal. Wait, no: if it's "5.123", then shu[1]=='.', so it goes to the first inner if and prints as is with e0 — correct. If it's "51.23", then shu[1]='1' != '.', so goes to else, prints "5.", then the rest including '1','2','3', and exponent=1 (since '.' is at index 2, count_true=1) → "5.123e1", but should be "5.123e1" for 51.23? No: 51.23 = 5.123 × 10^1 → correct.

                // However, the problem states: "If there’s only one digit before the decimal point, it can be 0; otherwise, the first digit before the decimal point cannot be 0." So numbers like "05.123" won't appear.

                // After careful analysis, the most likely bug is in the zero-leading branch when there is exactly one non-zero digit: it prints "Xe-N", which is correct. When two or more, it prints "X.YZe-N", correct.

                // But wait: in the zero-leading branch, the first non-zero digit is printed without any preceding characters. However, what if there are no non-zero digits? But problem states all digits significant, so there must be at least one non-zero after "0.".

                // However, there's a subtle bug in the zero-leading branch: the variable 'sum' starts at 1, and is incremented for every '0' from index 2 onward. But the number of leading zeros after "0." is (position of first non-zero - 2). For "0.001", first non-zero at index 4, so leading zeros = 2, exponent = -3. And sum starts at 1, then increments twice (for indices 2 and 3) → sum=3, which is correct. So okay.

                // Given all this, why would the program fail test cases?

                // Let's consider input "0.1": 
                // shu = "0.1\n", n=4.
                // shu[0]=='0' → enter else branch.
                // j from 2 to n-2 = 2 to 2.
                // j=2: shu[2]='1' ≠ '0' → sum_true=sum=1, piece=1 → print '1'.
                // Then printf("e-%d",1) → "1e-1", correct.

                // Input "1.0": but problem says no trailing zeros, so "1.0" is invalid. Input will be "1" with decimal? No, problem says has digits before and after decimal, so "1.2", not "1." alone.

                // Input "10.0" invalid per problem.

                // Now consider input "0.0000000000001" (13 zeros). sum starts at 1, increments 12 times (indices 2 to 13 are '0'), then at index 14: '1' → sum=13, exponent -13, prints "1e-13", correct.

                // But here's a bug: in the zero-leading branch, the code prints the first non-zero digit, then for the second, prints ".X", and for subsequent, prints "X". But what if there are exactly two non-zero digits? Like "0.0012": prints '1', then '.2' → "1.2e-3", correct.

                // However, the problem says: "the base is either a decimal or an integer. If it’s a decimal, it must have one significant digit before and after the decimal point". Wait: "one significant digit before and after" — does that mean exactly one after? No, it means at least one after, and no trailing zeros. So "1.23" is fine.

                // After re-examining, the only potential issue is in the non-zero-leading branch when the number has only one digit before the decimal point but that digit is not '0' — like "5.123", which is handled correctly by the first inner if.

                // But what about a number like "0.0"? Not allowed.

                // Given the above, the code seems logically correct. However, the initial analysis missed something.

                // Let's look at the non-zero-leading branch again for a number like "123.4":
                // shu = "123.4\n", n=6.
                // shu[0]='1'≠'0', shu[1]='2'≠'.', so enter else.
                // Print '1', then '.'.
                // j=1: '2' → print '2', count=1.
                // j=2: '3' → print '3', count=2.
                // j=3: '.' → count_true = count = 2.
                // j=4: '4' → print '4', count=3.
                // Then print "e2".
                // Output: "1.234e2", which is 123.4 = 1.234 × 10^2 → correct.

                // Now, the critical bug: in the zero-leading branch, the variable 'sum' is initialized to 1, but it should be initialized to 0. Let's see:
                // For "0.1", leading zeros count = 0, exponent = -1.
                // With sum=1 initially, and no zeros, sum_true=1 → exponent -1: correct.
                // For "0.01", leading zeros=1, exponent=-2.
                // sum starts at 1, sees one '0' → sum=2 → exponent -2: correct.
                // So sum=1 is intentional to account for the exponent being -(leading_zeros + 1).

                // Therefore, the code is logically correct.

                // But wait! The problem says: "If there’s only one digit before the decimal point, it can be 0". So "0.1" is valid, and handled.

                // However, there's a bug in the non-zero-leading branch when the input is like "1.": but problem says has digits after decimal, so "1." won't appear.

                // Given the above, the only remaining possibility is the handling of the newline. The code uses n-1 to exclude newline, but in the zero-leading branch, the loop is for(j=2; j<n-1; j++). For input "0.1\n", n=4, so j<3, j=2 only: correct.

                // But what if the input is read without newline? fgets will include the newline only if it fits. Problem says "ending with a newline", so it's there.

                // After extensive analysis, the code appears correct. However, the reference program handles the case where there's no decimal point, but the problem states there is always one.

                // But the user-provided buggy code has a compilation error? Let's check syntax.

                // The code uses // comments, which are C99. If compiled as C89, it would fail. But the reference program also uses // comments.

                // The real issue might be that the code doesn't handle the case where the input has only one digit total, like "0.1" is fine, but what about "5.0" — not allowed.

                // Given the instructions, and since the problem states there's a compilation error, but the code is syntactically valid C99, perhaps the error is elsewhere.

                // However, the user says: "Buggy Output: /bin/sh: 1: gcc: not found", which is not a code error. So maybe the actual program has logical errors that cause wrong output, and the "Compilation Error" label is a mistake.

                // Looking at the zero-leading branch again: 
                //     if(piece==1||piece>2)
                //     {
                //         printf("%c",shu[j]);
                //     }
                //     else if(piece==2)
                //     {
                //         printf(".%c",shu[j]);
                //     }
                // For piece=1: prints the digit (e.g., '1')
                // For piece=2: prints ".2"
                // For piece=3: prints "3"
                // So for "0.00123", output is "1.23", which is correct.

                // But what if there is only one non-zero digit? piece=1, prints "1", then "e-3" → "1e-3", correct.

                // However, the problem says: "If it’s an integer, it contains only one significant digit without a decimal point." So "1e-3" is correct.

                // Now, consider a number like "0.1000000000000001" — but problem says no trailing zeros, so the zeros in the middle are significant? Actually, the problem says "all digits are significant", so "0.1001" is valid, and should be converted to "1.001e-1".

                // In the code: 
                // j=2: '1' → piece=1, print '1'
                // j=3: '0' → sum not incremented (because in else branch, only non-zero triggers), but wait: in the zero-leading branch, the loop body is:
                //   if(shu[j]=='0') { sum++; }
                //   else { ... }
                // So for "0.1001", 
                // j=2: '1' → else: sum_true=1, piece=1, print '1'
                // j=3: '0' → if: sum++ (sum becomes 2) — but this is wrong! Because this '0' is after the first non-zero, so it's significant and should be printed, but the code treats it as a leading zero and increments sum, which is only for leading zeros.

                // Ah! Here's the bug.

                // In the zero-leading branch, the code does:
                //   for j from 2 to n-2:
                //      if(shu[j]=='0') { sum++; }
                //      else { ... print ... }
                // This means that ANY '0' after "0." is counted as a leading zero, even if it comes after a non-zero digit.

                // For "0.101", 
                // j=2: '1' → non-zero: sum_true=1 (sum was 1), piece=1, print '1'
                // j=3: '0' → zero: sum becomes 2
                // j=4: '1' → non-zero: sum_true=2, piece=2, print '.1'
                // Output: "1.1e-2", but should be "1.01e-1".

                // Because the first non-zero is at position 2, so exponent should be -1, and the base should be "1.01".

                // But the code sets sum_true=2 at the last non-zero, overwriting the correct sum_true=1.

                // Also, the '0' at j=3 is not a leading zero; it's a significant zero in the middle.

                // Therefore, the algorithm is fundamentally flawed: it assumes that once a non-zero digit is found, all subsequent digits are non-zero, but that's not true. Zeros can appear after the first non-zero and are significant.

                // The variable 'sum' should only count leading zeros (before the first non-zero). After the first non-zero, zeros should be printed as part of the mantissa, not counted in 'sum'.

                // In the current code, 'sum' is incremented for EVERY '0' encountered, even after non-zero digits, which corrupts sum_true.

                // Additionally, sum_true is overwritten every time a non-zero digit is found, so it ends up being the total number of zeros (leading and embedded) plus 1, which is wrong.

                // Therefore, the errors are in the zero-leading branch:

                // - 'sum' should only count leading zeros (before first non-zero)
                // - 'sum_true' should be set only once (at first non-zero)
                // - After first non-zero, all digits (including zeros) should be printed as part of the mantissa

                // So the lines in the zero-leading branch are flawed.

                // Specifically:
                //   if(shu[j]=='0')
                //   {
                //       sum++;
                //   }
                // This should only happen if no non-zero digit has been encountered yet.

                // And sum_true should be set only once.

                // Therefore, the errors are in the zero-leading branch loop.
            }
        }
        printf("e-%d",sum_true); // @@ [sum_true may be overwritten by later non-zero digits, and 'sum' includes non-leading zeros, making exponent incorrect. Also, if there are embedded zeros, they are not printed because the code only prints non-zero digits in the else branch, but zeros after the first non-zero should be printed.]
    }
    return 0;
}