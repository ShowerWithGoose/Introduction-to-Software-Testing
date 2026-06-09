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
        for(int j=2;j<n-1;j++) // @@ The loop condition j<n-1 is incorrect when the input string does not include a newline character. Since fgets may include a newline, the bound should be adjusted to include all digits. For input "0.9", the string length is 3 without newline, so the loop never executes, resulting in no digit printed and exponent 0.
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
        printf("e-%d",sum_true);
    }
    return 0;
}