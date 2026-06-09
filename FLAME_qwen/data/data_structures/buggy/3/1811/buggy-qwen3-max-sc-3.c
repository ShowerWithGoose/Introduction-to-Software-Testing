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
                    count_true=count; // @@ [This logic is flawed: 'count' counts digits before the decimal point, but 'count_true' is only set when '.' is encountered. However, in numbers like "123.45", the loop continues after '.', so 'count' becomes total non-dot digits, not just before decimal. Also, exponent should be (position of first digit - 1), not based on counting this way.]
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
        printf("e-%d",sum_true); // @@ [If input is "0.0", this outputs nothing before 'e', violating scientific notation format. Also, 'sum' starts at 1 but should count leading zeros after decimal correctly. For "0.001", it should output "1e-3", but current logic may miscount or mishandle single significant digit case.]
    }
    return 0;
}