#include <stdio.h>
#include <math.h>
#include <string.h>
char s[110];
int main()
{
    scanf("%s",s);
    int len=strlen(s);
    int i=0,flag=0;
    if(strchr(s,'.')==NULL)
    {
        for(i=len-1;i>=1;i--)
        {
            if(s[i]!='0')
            {
                flag=i;
                break;
            }
        }
        if(flag==0)
        {
            printf("%c",s[0]);
        }
        else
        {
            printf("%c.",s[0]);
            for(i=1;i<=flag;i++)
            {
                printf("%c",s[i]);
            }
        }
        printf("e%d",len-1);
    }
    else
    {
        if(s[0]=='0')
        {
            for(i=0;i<len;i++)
            {
                if(s[i]!='0'&&s[i]!='.')
                {
                    flag++;
                }
                if(flag==2)
                {
                    printf(".");
                }
                if(flag!=0)
                {
                    printf("%c",s[i]);
                }
            }
            printf("e%d",2-len); // @@ The exponent calculation is incorrect. For input "0.00000009123456789012", the first significant digit '9' is at index 9. The exponent should be -(number of zeros after decimal point + 1) or simply (index of first sig digit - 1) * -1? No, standard scientific notation for 0.00...0X is X... e-N where N is the position of the decimal point relative to the first significant digit. Specifically, if the first significant digit is at index k (0-indexed), and the decimal point is at index 1 (since it starts with "0."), the exponent is -(k - 1). Here k=9, so exponent is -8. The formula `2-len` gives 2-22 = -20, which is wrong. The correct exponent for a number 0.d1d2...dk... where dk is the first non-zero digit is -k. Wait, let's trace. "0.00000009...". Index 0:'0', 1:'.', 2:'0'... 9:'9'. The value is 9.12... * 10^-8. The exponent is -8. The index of '9' is 9. The decimal point is at 1. The number of places the decimal point moves to the right to get after the 9 is 9-1 = 8 positions. So exponent is -8. The variable `flag` counts significant digits found so far? No, `flag` increments when a non-zero non-dot char is found. So when '9' is found, `flag` becomes 1. When '1' is found, `flag` becomes 2. The loop prints characters. The exponent needs to be calculated based on the position of the first significant digit. Let `pos` be the index of the first significant digit. The exponent is `-(pos - 1)`. In the current code, we don't store `pos`. We can calculate it. When `flag` goes from 0 to 1, that's the first significant digit. Its index is `i`. So exponent is `-(i-1)`.
        }
        else
        {
            for(i=0;i<len;i++)
            {
                if(s[i]=='.')
                {
                    flag=i;
                    break;
                }
            }
            printf("%c",s[0]);
            printf(".");
            for(i=1;i<len;i++)
            {
                if(s[i]!='.')
                printf("%c",s[i]);
            }
            printf("e%d",flag-1);
        }
    }
    return 0;
}