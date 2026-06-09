#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

char shu[105];

int main()
{
    fgets(shu,105,stdin);
    int n=strlen(shu);
    if(shu[0]!='0')
    {
        if(shu[1]=='.')
        {
            for(int i=0;i<n-1;i++)
            {
                printf("%c",shu[i]);
            }
            printf("e0");
        }
        else
        {
            int count=0,count_true=0;
            printf("%c",shu[0]);
            printf(".");
            for(int j=1;j<n-1;j++)
            {
                if(shu[j]!='.')
                {
                    printf("%c",shu[j]);
                    count++;
                }
                else
                {
                    count_true=count;
                }
            }
            printf("e%d",count_true);
        }
    }
    else
    {
        int sum=1,sum_true=0,piece=0;
        for(int j=2;j<n-1;j++)
        {
            if(shu[j]=='0') // @@ [This condition causes significant zeros to be skipped and incorrectly increments `sum` after the first non‑zero digit, leading to a missing digit in the mantissa and a wrong exponent.]
            {
                sum++;
            }
            else
            {
                sum_true=sum;
                piece++;
                if(piece==1||piece>2) // @@ [The conditional structure (piece==1 or piece>2) prints non‑zero digits without a decimal point, and piece==2 prints with a decimal before the digit. This fails to include any zero digits that appear between non‑zero digits and places the decimal point incorrectly. The mantissa should contain all significant digits from the first non‑zero onward, with the decimal after the first digit.]
                {
                    printf("%c",shu[j]);
                }
                else if(piece==2) // @@ [This prints a decimal point only when the second non‑zero digit is encountered, which is incorrect. The decimal point should be placed right after the first non‑zero digit, regardless of subsequent digits (including zeros).]
                {
                    printf(".%c",shu[j]);
                }
            }
        }
        printf("e-%d",sum_true);
    }
    return 0;
}