#include <stdio.h>
#include <string.h>
#include<math.h>
int main ()
{
    char a[1024];
    gets(a);
    int i=0;
    int k=strlen(a);
    
    if(a[0]!='0')
    {
        while(a[i]!='.')
        {
            i=i+1;
        }
        printf("%c",a[0]);
        // The problem states: "If it’s an integer, it contains only one significant digit without a decimal point."
        // If the input is like "5.0" (though problem says no trailing zeros, so likely "5" isn't input as "5.0" but maybe "5.1"), 
        // wait, the problem says "digits before and after the decimal point". So input is always X.Y.
        // However, look at the expected output for 0.9 -> 9e-1. It does NOT have a decimal point because there are no digits after the significant digit in the mantissa.
        // In the case of 0.9: i becomes 1 (skips '0'), then skips '.', so i becomes 2? No.
        // Let's trace 0.9 with the buggy code.
        // a = "0.9\n" or "0.9". k=3.
        // a[0]=='0', goes to else if.
        // while(a[i]=='0'||a[i]=='.'):
        // i=0: a[0]=='0' -> true. i=1.
        // i=1: a[1]=='.' -> true. i=2.
        // i=2: a[2]=='9' -> false. Loop ends. i=2.
        // printf("%c", a[2]) -> prints '9'.
        // printf(".") -> prints '.'.  @@ This prints a decimal point even when there are no subsequent significant digits, violating the format rule for integer bases.
        // for(int j=i+1; j<k; j++) -> j=3. k=3. Loop doesn't run.
        // printf("e-%d", i-1) -> e-1.
        // Output: 9.e-1. Expected: 9e-1.
        // The error is unconditionally printing the decimal point. It should only be printed if there are digits following the first significant digit.
        
        // To fix this properly within the constraints of annotating the existing line:
        // The line `printf(".");` is logically incorrect because it assumes there will always be fractional part digits in the scientific notation base.
        // According to the rule: "If it’s a decimal... If it’s an integer... without a decimal point."
        // An integer base occurs when the original number has only one significant digit total (e.g., 0.9 -> 9, or 5.0 -> 5 but input has no trailing zeros so 5.0 unlikely, maybe 0.5 -> 5e-1).
        // So we need to check if `i + 1 < k` (are there any characters left after the first significant digit?) before printing the dot.
        
        // Since I must annotate the specific line causing the error:
        printf("."); // @@ Incorrectly prints decimal point even when there are no remaining significant digits (e.g., input "0.9" results in "9." instead of "9"). Should conditionally print based on whether there are more digits.
        for(int j=i+1;j<k;j++)
        {
            printf("%c",a[j]);
        }
        printf("e-%d",i-1);
    }
    
    return 0;
}