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
                    count_true=count; // @@ [This logic incorrectly assumes the decimal point is always present in non-zero-leading numbers and uses 'count' (number of digits before '.') as exponent, but 'count' includes digits after the first, not the position of '.']
                }
            }
            printf("e%d",count_true); // @@ [If there's no decimal point in input (which shouldn't happen per problem, but code doesn't validate), count_true remains 0, leading to wrong exponent. Also, for inputs like "123.45", this prints "1.2345e2" correctly, but logic is fragile and relies on decimal point being present]
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
        printf("e-%d",sum_true); // @@ [For input "0.001", it should output "1e-3", but this outputs "1e-3" only if piece==1. However, if there are more than one non-zero digit (e.g., "0.0012"), it prints "1.2e-3", which is correct format, but the initial 'sum=1' is incorrect—it should start at 0 because leading zeros after '0.' start counting from first zero. For "0.1", sum remains 1, outputs "1e-1", which is correct, but logic is coincidental. The real issue: if input is "0.0", which violates problem constraints (no trailing zeros, and all digits significant), but program may crash or misbehave. However, main error is that when there's only one non-zero digit, it prints just the digit without decimal point, which is correct, but the counting of leading zeros (sum) starts at 1 instead of 0, causing off-by-one in exponent. Example: "0.1" → sum=1 → e-1 (correct). "0.01" → sum=2 → e-2 (correct). So maybe not off-by-one. But what if input is "0.000"? Problem says no trailing zeros and all digits significant, so this won't occur. However, another critical error: if the input has no non-zero digits after decimal (which shouldn't happen per problem), piece remains 0, and nothing is printed before 'e', causing invalid output. But per problem, all digits are significant, so there is at least one non-zero. Still, the bigger issue is in the non-zero-leading branch.]
    }
    return 0;
}