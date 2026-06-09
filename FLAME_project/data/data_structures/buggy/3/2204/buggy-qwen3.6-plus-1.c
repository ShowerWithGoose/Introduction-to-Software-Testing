#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
char s[1009];
int main()
{
    gets(s);
    int l,wc,wd; // @@ [Variables 'wc' and 'wd' are used without being initialized. If the conditions below are not met or loops don't execute as expected, they contain garbage values.]
    l=strlen(s);
    for (int i=1;i<=l-1;i++)if(s[i]=='.')wc=i;
    if(wc>1) 
    {
        printf("%c.",s[0]);
        for (int i=1;i<=l-1;i++)if(s[i]!='.')printf("%c",s[i]);
        printf("e%d",wc-1);
        
    }
    if(wc==1&&s[0]!='0') 
    {
        printf("%c.",s[0]);
        for (int i=1;i<=l-1;i++)if(s[i]!='.')printf("%c",s[i]);
        printf("e%d",wc-1);
        
    }
    if(wc==1&&s[0]=='0') 
    {
            for (int i=2;i<=l-1;i++) if(s[i]!='0')wd=i; // @@ [The loop finds the LAST non-zero digit instead of the FIRST non-zero digit because it keeps overwriting 'wd'. It should break after finding the first one. Also, if all digits are zero, 'wd' remains uninitialized.]
            
            if(wd==l-1)    printf("%ce-%d",s[wd],wd-1); // @@ [Logic error: If the last digit is the only significant one, it prints it as an integer part but fails to handle the decimal point correctly for scientific notation format if there are no trailing digits. More importantly, the exponent calculation 'wd-1' is incorrect for numbers like 0.00...0X. The exponent should be -(number of zeros + 1). For 0.00000009..., wd is index of 9. Exponent should be -(wd-1). Wait, for 0.0009 (index 4), exp is -3. wd-1 = 3. So e-3 is correct. However, the condition 'wd==l-1' implies no digits after wd. The output format "%ce-%d" misses the decimal point if there ARE digits after, but here it assumes there aren't. The main issue is the previous line finding the wrong 'wd'.]
            else    {printf("%c.",s[wd]);for (int i=wd+1;i<=l-1;i++) printf("%c",s[i]);printf("e-%d",wd-1);} // @@ [Exponent calculation 'wd-1' is correct for the position relative to decimal point in 0.xxx format? For 0.00912, wd is index of 9 (3). Exp should be -2. wd-1 = 2. So e-2 is correct. The primary error remains the initialization and finding of 'wd'.]

    }




return 0;
}