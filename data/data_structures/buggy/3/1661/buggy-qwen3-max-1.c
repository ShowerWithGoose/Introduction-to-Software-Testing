#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#define ll long long
char s[105];
int main()
{
    scanf("%s",s);
    int i=0,len=strlen(s),j,k=0,i1;
    if(s[0]=='0')
    {
        i++; // @@ [This skips the '0' before the decimal point, but assumes input always starts with "0."; however, it doesn't verify that the next character is '.', leading to incorrect index handling if input format deviates slightly. More critically, if the number is like "0.000...", this loop logic fails to correctly locate the first non-zero digit.]
        while(s[i+1]=='0') // @@ [If the string ends before i+1 (e.g., "0."), this accesses out-of-bounds memory. Also, it assumes there's at least one digit after the decimal point, which is given, but the indexing is off: after i++, i points to '.', so s[i+1] is first digit after decimal. However, if all digits after are zero (but problem says no trailing zeros, so maybe okay). But if input is "0.1", then i=1 ('.'), s[i+1]='1', loop doesn't run, then prints s[i+1]='1' correctly. However, if input is "0.01", i=1, s[2]=='0' → enter loop, i becomes 2, then check s[3]=='1' → break. Then print s[3], and exponent = i = 2 → e-2, which is correct. BUT: what if input is "0.0"? Problem states: "all digits are significant (i.e., there are no trailing zeros after the decimal point)", so "0.0" won't occur. However, another issue: if input is "0.10", it shouldn't happen per problem, so maybe okay. Main bug: if the first non-zero is at position i+1, then exponent should be -(number of zeros after decimal before it) = -( (i+1) - 2 ) = -(i-1). But code uses exponent = i. Let's test "0.001": i starts 0, i++ → i=1 ('.'), then while(s[2]=='0') → yes, i=2; s[3]=='0'? no, assume s[3]=='1'. Then print s[3]='1', exponent = i = 2 → e-2, but correct is e-3. So exponent is off by one. Should be e-(i) where i is count of zeros after decimal, but current i is index of last zero, so first non-zero is at i+1, and its position after decimal is (i+1 - 1) = i, so exponent = -i. Wait: in "0.001", decimal positions: pos1='0', pos2='0', pos3='1'. So exponent = -3. Index of '1' is 3 (0:'0',1:'.',2:'0',3:'0',4:'1')? Wait no: "0.001" → indices: 0:'0',1:'.',2:'0',3:'0',4:'1'. So after i=0, i++ → i=1. Then while(s[i+1]=='0'): i+1=2 → '0' → i=2; i+1=3 → '0' → i=3; i+1=4 → '1' → break. Then print s[i+1]=s[4]='1', exponent = i = 3 → e-3 → correct. So maybe exponent is right. But what if input is "0.1": indices 0:'0',1:'.',2:'1'. i=0→i=1. s[2]=='1'≠'0' → skip while. Print s[2]='1', exponent=i=1 → e-1 → correct. So exponent logic seems okay. However, if the number is "0.0...0X" with X at position p (after decimal), exponent should be -p. Here, p = (index of X) - 1. Index of X = i+1, so p = i+1 -1 = i → exponent = -i → correct. So why error? Another issue: if the number has only one non-zero digit after decimal and nothing else, e.g., "0.5", then after printing "5.", we should not print anything else. But code does: for(j=i+2;j<len;j++) → i=1, j=3, len=3 → loop doesn't run → prints "5.e-1" → but expected is "5e-1" (no decimal point if no fractional digits). Problem says: "If it’s a decimal, it must have one significant digit before and after the decimal point". So if there are no digits after the first non-zero, it should be integer form. But code always prints "%c." → so "5." instead of "5". That's a format error. So this branch always outputs a decimal point even when there are no following digits, violating output spec.]
            i++;
        printf("%c.",s[i+1]); // @@ [Always prints a decimal point, even if there are no digits after the first non-zero digit. According to the problem, if there's only one significant digit (i.e., no more digits after the first non-zero), it should be printed as an integer without a decimal point. This causes incorrect output format like "5." instead of "5".]
        for(j=i+2;j<len;j++)
            printf("%c",s[j]);
        printf("e-%d",i);
    }
    else
    {
        while(s[i+1]!='.'&&i<len-1) // @@ [This loop tries to find the decimal point by checking s[i+1], but if the number has no decimal point (e.g., "123"), then i will increment until i==len-1, and s[i+1] is out of bounds (undefined behavior). The problem states: "has digits before and after the decimal point", so input always contains a decimal point. So maybe safe. But still, condition should be i < len-1 before accessing s[i+1]. It is checked in loop condition: i<len-1, so s[i+1] is valid. Okay.]
            i++;
        if(i==len-1) // @@ [This condition means no decimal point was found (since loop ended because i reached len-1 without finding '.'). But problem states input always has digits before and after decimal point, so this case should never happen. However, the code handles it anyway. But within this block, it tries to remove trailing zeros from an integer input, which contradicts problem constraints. Since input always has a decimal point, this entire if-block is unreachable and contains logic errors for cases that shouldn't occur. However, more importantly, if input is like "123.4500", problem says no trailing zeros, so this block is unnecessary. But the real bug is elsewhere.]
        {
        while(s[len-1-k]=='0') // @@ [Accesses s[len-1-k]; when k=0, it's last char. But if input has decimal point, this block shouldn't execute. However, if somehow it does, and the string ends with non-digit (unlikely), or if len-1-k <0, it crashes. But given problem constraints, maybe not triggered. Still, dead code with potential UB.]
            k++;
        if(k==len-1)
            printf("%c",s[0]);
        else
        {
        printf("%c.",s[0]);
        for(j=1;j<i+1-k;j++)
            printf("%c",s[j]);
        }
        printf("e%d",i);
        }
        else
        {
            printf("%c.",s[0]); // @@ [Same issue as in the 'if' branch: always prints a decimal point, even if there are no digits after the first digit. For example, input "5.0" is invalid per problem (no trailing zeros), but input "5.1" is valid. However, if input is "1.0", it's invalid. But consider input "1.2": output is "1.2e0" — correct. But what if input is "1."? Problem says "has digits before and after the decimal point", so "1." won't occur. So maybe always having digits after means this is okay. However, another case: input "123.4" → output "1.234e2" — correct. But wait: the code prints s[0] followed by '.', then all other digits except '.'. So for "123.4", it prints "1." then "234" → "1.234e2" — correct. So this part seems okay. But what about single-digit before decimal? Input "5.6" → "5.6e0" — correct. So maybe no error here. However, the main error is in the 'if' branch always printing a decimal point unnecessarily.]
            for(j=1;j<len;j++)
            {
                if(s[j]!='.')
                    printf("%c",s[j]);
            }
            printf("e%d",i);
        }
    }
    return 0; 
}