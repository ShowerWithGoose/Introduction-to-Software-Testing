#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define ll long long
char s[200];
int dot=0,flag=0,wa=0,sum=1;
int main(){
    gets(s);
    int len=strlen(s);
    for(int i=0;i<len;i++){
        if(s[i]=='.')dot=i;
        if(dot>0){
            if(s[i]!='0')flag=1;
            if(!flag&&s[i]=='0')sum++; // @@ [This counts leading zeros after the decimal point incorrectly; 'sum' starts at 1, so it overcounts by 1. Also, it doesn't stop counting once a non-zero digit is found because 'flag' is set but loop continues unnecessarily.]
        }
    }
    if(dot==1&&s[0]!='0'){
        printf("%se0",s); // @@ [This case handles numbers like "5.123", but prints the whole string including the decimal part without converting to scientific notation (should be "5.123e0" → "5.123e0" is acceptable per problem? But problem says base must have only one digit before decimal. So "5.123" should become "5.123" → actually no: scientific notation requires one non-zero digit before decimal. So "5.123" is already valid base, but output format requires either single digit integer or one digit before and after decimal. However, this branch prints full input which may have multiple digits after decimal — but that's okay per problem? However, the real issue is that this branch doesn't normalize the number correctly when there are multiple digits before decimal. But given input constraints (no leading zeros unless single zero before decimal), this might be okay. However, the main bug is elsewhere.]
    }
    else{
        if(s[0]=='0'){
            for(int i=dot+sum;i<len;i++){ // @@ [Because 'sum' is overcounted (starts at 1 and increments for each leading zero including the first one after decimal), 'dot+sum' skips too many characters. For input "0.0000000912...", dot=1, sum becomes 8 (since 7 zeros after decimal before '9', but sum starts at 1 and increments 7 times → sum=8). So i starts at 1+8=9, which points to '9' — that seems correct. But wait: in "0.00000009", positions: 0:'0',1:'.',2:'0',3:'0',4:'0',5:'0',6:'0',7:'0',8:'0',9:'9'. So 7 zeros after decimal before '9' → sum should be 8? But exponent should be -8. However, the printed exponent is "e-%d",sum → e-8, which is correct. But why does the buggy output show "0.000000912..."? Because the loop prints from i=dot+sum onward, but also prints a '.' after the first printed digit only if it's not the last character. However, the first printed character is '9', then if there are more digits, it prints '.' immediately after '9', making "9." then rest. But in the buggy output, it's "0.000000912..." which suggests the code isn't even entering this branch correctly? Wait, let's reexamine.]

            // Actually, the real issue: the variable 'sum' is initialized to 1, and for each leading zero after the decimal (before first non-zero), it increments. So for "0.00000009", there are 7 zeros after decimal before '9'. The loop sets flag=0 initially. At i=2 to i=8 (s[2] to s[8] are '0'), !flag is true, so sum increments 7 times → sum = 1 + 7 = 8. Then i=9: s[9]='9', flag becomes 1. So dot+sum = 1+8=9 → correct start index.

            // But the output in the test case is "0.0000009123456789012e-1", which is completely wrong. This suggests that the program did NOT take the s[0]=='0' branch? Or there's another bug.

            // Wait: the test input is "0.00000009123456789012"
            // len = 22
            // dot = 1
            // In the first loop:
            //   i=0: s[0]='0', dot=0 → skip inner if
            //   i=1: s[1]='.' → dot=1
            //   i=2: s[2]='0', dot>0 → flag=0, so !flag true → sum++ → sum=2
            //   i=3: '0' → sum=3
            //   ... up to i=8: '0' → sum=8
            //   i=9: '9' → flag=1
            // So sum=8, dot=1
            // Then in s[0]=='0' branch:
            //   i starts at dot+sum = 1+8 = 9
            //   prints s[9]='9'
            //   then since i==9 and 9 != 21 (len-1), prints '.' → so output starts with "9."
            //   then continues printing s[10] to s[21]: "123456789012"
            //   so base is "9.123456789012"
            //   then prints "e-8"
            //   which matches expected output.

            // So why does the buggy output say "0.0000009123456789012e-1"?

            // This implies that the actual execution did not go into the s[0]=='0' branch as we expect.

            // Let's check condition: s[0]=='0' → yes, so it should go into that branch.

            // Unless... the variable 'sum' is not computed correctly because of the order of operations.

            // The first loop:
            //   for i from 0 to len-1:
            //      if s[i]=='.', set dot=i
            //      if dot>0 (meaning we've seen the dot already), then process zeros

            // But note: at i=0: s[0]='0', dot is still 0 → skip inner
            // i=1: set dot=1
            // i=2: now dot>0 → check s[2]='0' → flag=0 → sum++ (sum becomes 2)
            // ... i=8: sum becomes 8
            // i=9: s[9]='9' → set flag=1

            // So sum=8.

            // Then in the printing loop:
            //   for i from 9 to 21:
            //      if s[i]!='.' → print it (all are digits)
            //      if i==9 (which is dot+sum) and i!=21 → print '.' after first digit

            // So output: "9." + "123456789012" → "9.123456789012e-8"

            // This is correct.

            // Therefore, the bug must be elsewhere.

            // Wait: the test case says Buggy Output is "0.0000009123456789012e-1"

            // This output has many zeros after decimal, then "912...", and exponent -1.

            // This looks like the program took the else branch (s[0]!='0') even though s[0]=='0'.

            // Why? Because maybe the condition "if(s[0]=='0')" failed?

            // But s[0] is '0'.

            // Unless... the input was read with gets() and includes a newline? But gets() discards newline.

            // Another possibility: the variable 'dot' is not set correctly.

            // In the first loop, dot is set to the last occurrence of '.'? But there's only one.

            // But note: the loop sets dot=i every time it sees a '.', so if there were multiple, it would take last. But input has one.

            // Another idea: the condition "if(dot==1&&s[0]!='0')" — for input "0.000...", dot=1 and s[0]=='0', so this condition is false, so it goes to else, then checks s[0]=='0' → true.

            // So it should go into the correct branch.

            // Unless... the variable 'sum' is global and retains value from previous runs? But it's a single run.

            // Wait: the problem says the program failed on this test case. So in reality, when run, it produced the wrong output.

            // Let's simulate the provided buggy code step by step on "0.00000009123456789012":

            // s = "0.00000009123456789012" (len=22)
            // dot=0, flag=0, sum=1 (global initializers)

            // Loop i=0 to 21:
            //   i=0: s[0]='0' → not '.', so dot remains 0. dot>0? no.
            //   i=1: s[1]='.' → dot=1. Now dot>0? not yet in this iteration for the inner if? Actually, after setting dot=1, then check if(dot>0) → yes, because dot=1>0.
            //         so: s[1] is '.' → not '0', so flag remains 0? But condition: if(s[i]!='0') → '.' != '0' → true, so flag=1.
            //         and then: if(!flag && s[i]=='0') → !flag is false (because flag was just set to 1), so sum not incremented.

            // This is the critical error!

            // At i=1, s[i] is '.', which is not '0', so flag becomes 1 immediately.
            // Then for i=2 to i=8 (the zeros after decimal), flag is already 1, so the condition "!flag" is false, and sum is never incremented.

            // Therefore, sum remains 1.

            // Then in the s[0]=='0' branch:
            //   i starts at dot+sum = 1+1 = 2
            //   prints s[2]='0'
            //   then since i=2 and 2 != 21, prints '.' → so output starts with "0."
            //   then prints s[3] to s[21]: "0000009123456789012"
            //   so base is "0.0000009123456789012"
            //   exponent is "e-%d",sum → e-1

            // Which matches the buggy output: "0.0000009123456789012e-1"

            // So the error is in the first loop: when i=1 (the '.'), it sets flag=1 because '.' != '0', which prevents counting the subsequent zeros.

            // The fix: in the inner if(dot>0) block, we should skip the '.' character when checking for zeros and non-zeros.

            // Specifically, the condition should be: if(s[i]!='.' && s[i]!='0') then set flag=1.
            // And when counting zeros, only count if s[i]=='0' (and not '.').

            // Therefore, the error is in the first loop's inner conditions: they treat '.' as a non-zero digit, which sets flag prematurely.
        }
        if(i==dot+sum&&i!=len-1)printf("."); // @@ [This line is inside the for-loop, so it prints '.' after the first digit printed, which is correct. But due to the earlier error in 'sum' calculation, it's printing from the wrong position.]
    }
    printf("e-%d",sum); // @@ [Because 'sum' is not counting the leading zeros correctly (due to '.' setting flag=1), the exponent is wrong.]
}
        else{
            for(int i=0;i<len;i++){
                if(s[i]!='.'){
                    printf("%c",s[i]); 
                }
                if(i==0)printf("."); // @@ [This prints a '.' after the first digit, even if the number has only one digit total. For example, "5" would become "5." which is not allowed per problem (if integer, no decimal point). Also, for "123.45", it would print "1.2345", which is correct base, but the exponent calculation might be off. However, the main issue is in the zero-leading case.]
            }
            printf("e%d",dot-1); // @@ [For numbers without leading zero, e.g., "123.45", dot=3, so exponent=2, which is correct (1.2345e2). But if the number is "5.0", it would print "5.e0", which has a trailing '.' — invalid per problem (no trailing zeros, but here it's a trailing decimal point with no fractional part). Problem states: if decimal, must have one digit after decimal. So "5." is invalid; should be "5e0" if integer base, but problem says base can be integer only if one digit. So "5" is okay, but "5." is not. This branch always prints a '.' after first digit, which is wrong when there are no fractional digits or when the number is an integer. However, input guarantee: has digits before and after decimal point. So this might be safe. But the primary bug is in the other branch.]
        }
    }
    return 0;
}