#include<stdio.h>
#include<string.h>
char c[100000000];
int main()
{
    int o=0,i=0,t=0,l;
    while(scanf("%c",&c[i])!=EOF)
    {
        if(c[i]=='.')
        t=i; // @@ Error: when a dot is read, its position is saved but the character is overwritten on the next read because i is not incremented. This loses the dot and corrupts the array.
        else
        i++;
    }
    i--; // @@ Error: decrementing i after the loop is incorrect. The variable i already counts the number of non-dot characters, and this reduction causes off-by-one errors in subsequent loops.
    if(c[0]=='0')
    {
        for(l=1;c[l]=='0';l++);
        if(i==(l+1)) // @@ Error: condition i == l+1 is flawed because i has been decremented and does not represent the true number of digits. This leads to incorrect branching for cases with more than one digit after the first non-zero digit.
        printf("%ce-%d",c[l],l); // @@ Error: prints base as a single digit without decimal point when there are more digits after the first non-zero, which is incorrect.
        else
        {
            int k=l;
            printf("%c.",c[l]);
            for(l++;l<i;l++) // @@ Error: loop bound l < i is incorrect due to the earlier i--. It may miss the last digit. Also the starting point l++ after printing the first non-zero digit is off.
            printf("%c",c[l]);
            printf("e-%d",k);
        }
    }
    else
    {
        printf("%c.",c[0]);
        for(l=1;l<i;l++) // @@ Error: loop bound l < i misses the last digit because i was decremented. Should be l <= i or use the original digit count.
        printf("%c",c[l]);
        printf("e%d",t-1); // @@ Error: exponent t-1 might be correct, but t is the index of the dot that was overwritten, which could be inconsistent with the actual number of digits before decimal.
    }
    return 0;
}