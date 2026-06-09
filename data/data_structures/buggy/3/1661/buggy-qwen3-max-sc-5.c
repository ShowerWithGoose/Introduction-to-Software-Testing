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
        i++; // @@ [This skips the '0' before the decimal point, but assumes input always starts with "0."; however, if input is like "0.001", then s[1] is '.', so s[i+1] becomes s[2], which is correct. But if input has no decimal (violating problem constraints), this fails. However, main issue is below:]
        while(s[i+1]=='0') // @@ [If the input is "0.0", this loop may go out of bounds because i+1 could exceed len-1. Also, if all digits after decimal are zero (which shouldn't happen per problem statement), it leads to undefined behavior. But more critically, if the number is "0.1", then i=1 (after i++), and s[i+1] = s[2] = '1', which is fine. However, the real bug is when the first non-zero digit is at the last position.]
            i++;
        printf("%c.",s[i+1]); // @@ [If the first non-zero digit is the last character (e.g., "0.001"), then i+1 is valid. But if the input is "0.0", which violates problem constraints (no trailing zeros, and all digits significant), but if given, s[i+1] may be '\0', causing undefined behavior. However, per problem, input has no trailing zeros, so this might be safe. The actual critical error is in exponent calculation and handling of single-digit case.]
        for(j=i+2;j<len;j++)
            printf("%c",s[j]);
        printf("e-%d",i); // @@ [Exponent should be -(number of zeros after decimal + 1). For "0.001", zeros=2, exponent=-3. Here, i starts at 1 (after i++), then increments twice (for two zeros), so i=3, and prints e-3 — which is correct. So maybe not wrong here. But what if input is "0.1"? i=1, loop doesn't run, prints e-1 — correct. So this part may be okay under problem constraints.]
    }
    else
    {
        while(s[i+1]!='.'&&i<len-1) // @@ [This loop tries to find the decimal point by checking s[i+1]. But if the number has no decimal point (e.g., "123"), which violates problem description ("has digits before and after the decimal point"), but if input lacks '.', this loop runs until i=len-1, then proceeds to the next block. However, problem states input always has decimal point, so maybe acceptable. But logic is flawed: it should scan for '.' from start, not assume it's after some digits. Also, i starts at 0, so checks s[1] != '.' — misses if '.' is at s[0], but problem says first digit can't be 0 unless only one digit before decimal, so '.' won't be at start. Still, better to search for '.' directly.]
            i++;
        if(i==len-1) // @@ [This condition means no '.' was found (since loop ended because i reached len-1 without finding '.'). But problem states input always has decimal point, so this block should never execute. However, the code handles it as if it's an integer without decimal, which contradicts problem constraints. This suggests a misunderstanding. Moreover, the following code tries to remove trailing zeros, but problem states there are no trailing zeros after decimal, so this is unnecessary and buggy.]
        {
        while(s[len-1-k]=='0') // @@ [Since problem states no trailing zeros after decimal, this loop should not run. But if input violates that, it removes trailing zeros. However, if the number is integer-like (no '.'), this may remove trailing zeros from integer part, which is wrong because all digits are significant. Also, if k becomes len-1, meaning all digits except first are zero, it prints just the first digit — but this case shouldn't occur per problem.]
            k++;
        if(k==len-1)
            printf("%c",s[0]);
        else
        {
        printf("%c.",s[0]);
        for(j=1;j<i+1-k;j++) // @@ [i is len-1 here, so i+1-k = len - k. But j goes from 1 to len-k-1. However, since there's no decimal point in this branch, the digits after s[0] are all part of integer, and removing k trailing zeros is incorrect because problem states all digits are significant. This entire branch is based on a false premise.]
            printf("%c",s[j]);
        }
        printf("e%d",i); // @@ [Exponent is set to i = len-1, which would be correct for an integer like "123" -> 1.23e2, but since input must have decimal point, this case is invalid. So this branch is erroneous.]
        }
        else
        {
            printf("%c.",s[0]);
            for(j=1;j<len;j++)
            {
                if(s[j]!='.')
                    printf("%c",s[j]);
            }
            printf("e%d",i); // @@ [Here, i is the index such that s[i+1]=='.', so the decimal point is at position i+1. The number of digits before decimal is i+1. Scientific notation exponent should be (number of digits before decimal - 1). For example, "123.45" has 3 digits before decimal, exponent=2. Since decimal is at index 3 (0-based), i+1=3 => i=2, so exponent=2 — correct. So this seems okay. But what if input is "1.23"? decimal at index 1, so i+1=1 => i=0, exponent=0 — correct. So this part is likely correct.]
        }
    }
    return 0; 
}