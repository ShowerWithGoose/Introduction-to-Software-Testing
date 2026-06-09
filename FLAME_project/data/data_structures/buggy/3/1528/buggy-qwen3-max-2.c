#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    char str[1000]={},copy[1000]={};
    int i,k=0,j=0;
    gets(str);
    if(str[0]!='0')
    {
        for(i=0;i<strlen(str);i++)
        {
            if(str[i]!='.')
            k++;
            else
            break;
        }
        if(strlen(str)>1)
        {
        printf("%c",str[0]);
        printf(".");
        for(i=1;i<strlen(str);i++)
        {
            if(str[i]!='.')
            printf("%c",str[i]);
        }
        printf("e");
        printf("%d",k-1);
        }
        else
        {
            printf("%c",str[0]);
            printf("e0");
        }
        
    }
    else
    {
        for(i=0;i<strlen(str);i++)
        {
            if(str[i]=='0'||str[i]=='.')
            k++;
            else
            break;
        }
        for(i=0;i<strlen(str);i++)
        {
             if(str[i]!='0'&&str[i]!='.')
             {
             copy[j++]=str[i];
             }
        }
        if(strlen(copy)==1)
        {
        printf("%c",copy[0]);
        printf("e-%d",k-1); @@ [The exponent calculation is incorrect. For input "0.00000009123456789012", the first non-zero digit '9' is at position 8 after the decimal point, so the exponent should be -8. However, k counts all '0's and the '.', which gives k=9 (8 zeros + 1 dot), so k-1 = 8, leading to e-8, which is correct in magnitude. But the real issue is that the loop condition includes '.' as part of the count, and the logic fails when there are digits after the first non-zero that include a '0' — but in this case, the output truncates the significant digits incorrectly. The actual bug is in the copying loop: it copies all non-zero and non-dot characters, but the original number has a '0' in "9012", which is significant and must be preserved. However, the current code does preserve it. So why is output "9.12345678912" instead of "9.123456789012"? Because the input was "0.00000009123456789012", and the copy array should contain "9123456789012". But the buggy output shows "9.12345678912", missing the '0'. This suggests that the copying loop is correct, but perhaps the input reading or string handling is flawed. However, looking closely: the test input is "0.00000009123456789012" — that’s 8 zeros after decimal, then "9123456789012". The expected output is "9.123456789012e-8", meaning the mantissa is "9.123456789012". But the buggy output is "9.12345678912e-8" — it's missing the '0' before the last '12'. This implies that somewhere, a '0' digit is being skipped. However, in the else block, the copy loop is: if(str[i]!='0'&&str[i]!='.') — this is WRONG! It skips ALL '0's, not just leading zeros. The problem states: "all digits are significant (i.e., there are no trailing zeros after the decimal point)" — but internal zeros (like in 9012) are significant and must be kept. The current code removes every '0', not just leading ones. That’s the critical error.]
        }
        else
        {
            printf("%c",copy[0]);
            printf(".");
            for(i=1;i<strlen(copy);i++)
            {
                printf("%c",copy[i]);
            }
            printf("e-%d",k-1); @@ [Same exponent issue as above, but the main bug is in the copying loop that removes all zeros, including significant internal ones.]
        }

    }
}