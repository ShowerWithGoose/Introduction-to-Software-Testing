#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>


int main()
{
    char a[500];
    int i=0, j=0, len;
    
    gets(a); // @@ [Using gets() is unsafe and deprecated; it may cause buffer overflow. More critically, the logic fails to handle cases where input has more than one digit before the decimal point (e.g., "123.45"). The program assumes either "0.xxx" or "x.xxx", but not "xx.xxx" or longer integer parts.]
    len = strlen(a);
    
    if(a[i] == '0')//零点几 
    {
        i=2; // @@ [Assumes the input always starts with "0.", but if input is just "0" (though problem says there are digits before and after), this fails. Also, if there are multiple zeros like "00.123" (invalid per problem, but robustness), it breaks. However, main issue: skips first two chars blindly; if input is "0.001", i becomes 2 pointing to first '0' after '.', which is correct, but logic for exponent is off by one in some cases.]
        
        while(a[i] == '0')
        {
            i++;
        }
        j=i-2; // @@ [j counts leading zeros after decimal. For "0.001", i=4 (points to '1'), j=2, then prints e-3 → correct. But if input is "0.1", i=2 (a[2]=='1'), loop doesn't run, j=0, prints e-1 → correct. So this part may be okay. However, what if all digits after decimal are zero? Problem states no trailing zeros, so maybe safe. But bigger issue: what if input has no decimal point? Problem says it does, so maybe okay.]
        
        printf("%c.", a[i]); // @@ [Always prints a decimal point even if there are no digits after? But problem says digits after decimal exist. However, if only one non-zero digit exists (e.g., "0.1"), it prints "1." which violates output spec: if base is decimal, must have one digit before and after decimal. But here, after printing "1.", there are no more digits → outputs "1.e-1", which is invalid because there's nothing after decimal. Expected: "1e-1" (as integer base) or "1.0e-1"? But problem says: if base is decimal, must have one digit before and after. However, original number has no trailing zeros, so after removing leading zeros, remaining digits may be only one. Then should output as integer (no decimal point). This code always prints decimal point, causing invalid output like "1.e-1".]
        
        i++;
        
        while(i<len)
        {
            printf("%c", a[i]);    
            i++;
        }
        
        printf("e-%d", j+1);
    }
    else if(a[i] != '0')//几点几 
    {
        printf("%c.", a[i]); // @@ [Same issue: always prints decimal point. For input "5.0" (but problem says no trailing zeros, so maybe "5.1"), it prints "5.1e0" which is okay. But if input is "5" (no decimal?), problem states there are digits before and after decimal, so input always has decimal point. However, for input like "12.34", this branch runs (since a[0]!='0'), prints "1." then prints rest including digits before decimal: from i=1, while a[i]!='.' → prints '2', then after decimal prints '34', so output is "1.234e1" — which is correct. BUT: what if input is "1.23"? Then prints "1.23e0" — correct. However, problem says: if base is integer (only one significant digit), output without decimal. But here, even for single-digit integer part and single digit after, it prints decimal. According to problem: "If it’s a decimal, it must have one significant digit before and after the decimal point". So "1.2e0" is valid. But what if after normalization, there's only one digit total? Not possible because input has digits before and after. So maybe okay. However, the real bug is in the first branch printing decimal point even when no digits follow.]
        i=1;
         
        while(a[i] != '.')
        {
            printf("%c", a[i]);
            i++;
        }
        j=i-1; // @@ [j is number of digits before decimal minus 1 → exponent. For "12.34", j=1 → e1, correct.]
        
        i++;
        
        while(i<len)
        {
            printf("%c", a[i]);    
            i++;
        }
        printf("e%d", j);
    }
    return 0;
}