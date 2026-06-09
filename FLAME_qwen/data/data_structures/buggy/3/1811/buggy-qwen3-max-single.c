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
                    count_true=count; // @@ [This logic is flawed: 'count' counts digits before the decimal point, but 'count_true' should be the position of the decimal point minus 1 (i.e., number of digits before decimal - 1). However, if there are multiple '.' or input format is not as expected, this fails. Also, if there's no '.' in the non-zero-leading case, count_true remains 0, leading to wrong exponent.]
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
            if(shu[j]=='0')
            {
                sum++;
            }
            else
            {
                sum_true=sum;
                piece++;
                if(piece==1||piece>2)
                {
                    printf("%c",shu[j]);
                }
                else if(piece==2)
                {
                    printf(".%c",shu[j]);
                }
            }
        }
        printf("e-%d",sum_true); // @@ [If the input is "0.0", this loop never enters the 'else' block, so sum_true remains 0 and piece remains 0, leading to no base printed and just "e-0", which violates output format. Also, for "0.1", it prints "1e-1" (correct), but for "0.01", it prints "1e-2" (should be "1e-2" — actually correct), but for "0.102", it prints "1.02e-1" — wait, no: piece logic is broken. For "0.102": j=2 -> '1' -> piece=1 -> print '1'; j=3 -> '0' -> skip; j=4 -> '2' -> piece=2 -> print ".2", so output "1.2e-1", but expected is "1.02e-1". So it skips zeros between first and second non-zero digit. This is wrong.]
    }
    return 0;
}