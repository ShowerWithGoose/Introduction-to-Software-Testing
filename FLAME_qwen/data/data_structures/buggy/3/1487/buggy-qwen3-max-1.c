#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>


int main()
{
    char a[500];
    int i=0, j=0, len;
    
    gets(a); // @@ [Using gets() is unsafe and deprecated; it was removed in C11. This may cause compilation errors with modern compilers that don't support gets(). Use fgets() instead.]
    len = strlen(a);
    
    if(a[i] == '0')//零点几 
    {
        i=2; // @@ [Assumes input always has "0." prefix, but skips the '.' without checking. If input is "0" (no decimal), this leads to out-of-bounds access. Also fails if there are multiple leading zeros like "00.123", which violates problem constraints but still risks logic error.]
        
        while(a[i] == '0')
        {
            i++;
        }
        j=i-2; // @@ [Exponent calculation is incorrect. For "0.00123", i becomes 4 (points to '1'), j=2, then prints e-3 (j+1=3). But correct exponent should be -3, so this part seems okay. However, if all digits after decimal are zero (not allowed per problem), it would break. More critically, if the number is exactly "0.0", undefined behavior occurs. But main issue: doesn't handle case where after skipping zeros, we reach end of string (e.g., "0.000"), which violates problem's "no trailing zeros" but still needs robustness.]
        
        printf("%c.", a[i]); // @@ [If the input is "0.1", i=2 points to '1', prints "1." — correct. But if input has no non-zero digits after decimal (invalid per problem, but code doesn't validate), a[i] could be '\0', causing undefined behavior.]
        
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
        printf("%c.", a[i]);
        i=1;
         
        while(a[i] != '.') // @@ [Assumes there is always a decimal point. But problem states input has digits before AND after decimal point, so '.' must exist. However, if input is an integer like "123" (violates problem spec), this loops past end of string. But per problem, input always has decimal point, so maybe acceptable. Still, logic flaw: for "12.34", it prints "1.234e2"? Let's see: prints '1.', then from i=1, prints '2' (before '.'), then after '.', prints '34', so output is "1.234e1" (since j = i-1 = 2-1=1). But correct scientific notation for "12.34" is "1.234e1" — correct. However, what if input is "1.23"? Then i=1, a[1]=='.', so while loop doesn't run, j=0, prints "1.e0" → "1.e0", but expected "1.23e0". Wait: after printing "1.", i=1, then while(a[i]!='.') → a[1]=='.', so loop skipped. Then i++ makes i=2, then prints rest: "23". So output "1.23e0" — correct. So this branch seems okay structurally, but...]
        {
            printf("%c", a[i]);
            i++;
        }
        j=i-1; // @@ [j counts digits before decimal minus 1, which is correct for exponent. For "123.45", digits before = 3, exponent = 2, j = 3-1=2 — correct.]
        
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