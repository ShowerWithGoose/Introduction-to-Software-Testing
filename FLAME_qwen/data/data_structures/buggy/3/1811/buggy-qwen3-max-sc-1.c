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
                    count_true=count; // @@ [This logic incorrectly assumes the decimal point is always present in numbers starting with non-zero. If input has no decimal point (e.g., "123"), this branch runs but '.' is never found, so count_true remains 0, leading to wrong exponent. Also, the problem states input always has digits before and after '.', so this case may not occur, but code doesn't handle missing '.' correctly.]
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
        printf("e-%d",sum_true); // @@ [If the input is "0.0" (though problem says no trailing zeros, but minimal like "0.1"), this works. However, if there's only one non-zero digit after leading zeros (e.g., "0.001"), piece=1, so it prints just "1e-3", which is correct. But if input is "0.102", piece becomes 3, so it prints "102" without a decimal point, violating the rule that base must have one digit before decimal and rest after. Should print "1.02". Logic for placing decimal point is flawed.]
    }
    return 0;
}