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
        printf("e-%d",k-1); @@ [The exponent calculation is incorrect. For input "0.00000009123456789012", the first non-zero digit '9' is at position 8 after the decimal point, so the exponent should be -8. However, k counts all '0's and the '.', which gives k=9 (positions 0 to 8: '0','.','0','0','0','0','0','0','0'), so k-1=8, leading to e-8 — this part is actually correct. The real issue is in the copying loop: it skips all zeros including those that are significant after the first non-zero digit, but more critically, the loop condition does not preserve the exact sequence of digits after the first non-zero. However, the actual bug causing the wrong output "9.12345678912e-8" instead of "9.123456789012e-8" is that the input has a '0' in the middle ("...9012"), and the copying logic is correct. Wait — looking at the buggy output: it prints "9.12345678912" instead of "9.123456789012". That means the '0' after '9' is missing. But in the copying loop, it copies every character that is not '0' or '.', which would incorrectly skip the significant zero in "9012". This is the error: the program removes ALL zeros, including significant ones that appear after the first non-zero digit. So the line that fills `copy` is wrong because it excludes any '0' anywhere, even if it's part of the significant digits after the first non-zero.]
        }
        else
        {
            printf("%c",copy[0]);
            printf(".");
            for(i=1;i<strlen(copy);i++)
            {
                printf("%c",copy[i]);
            }
            printf("e-%d",k-1); @@ [Same underlying issue: the `copy` array is missing internal zeros because the copying loop skips all '0's, not just leading zeros. For input "0.00000009123456789012", the significant digits are "9123456789012", but the code copies only non-zero digits, producing "912345678912", thus dropping the '0' before '12'.]
        }

    }
}