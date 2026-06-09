#include<stdio.h>
#include<string.h>
char c[100000000];
int main()
{
    int o=0,i=0,t=0,l;
    while(scanf("%c",&c[i])!=EOF)
    {
        if(c[i]=='.')
        t=i;
        else
        i++; // @@ [The loop reads one character at a time, but increments `i` only when the character is not '.', causing '.' to be overwritten in the next iteration. This leads to incorrect storage of the input string and loss of the decimal point position.]
    }
    i--; // @@ [This decrements `i` after the loop, but due to the flawed reading logic above, `i` may not correctly represent the last valid index of the input string.]
    if(c[0]=='0')
    {
        for(l=1;c[l]=='0';l++);
        if(i==(l+1))
        printf("%ce-%d",c[l],l); // @@ [The exponent should be `l-1` (number of leading zeros after '0.') rather than `l`. For example, "0.001" should yield exponent -2, not -3.]
        else
        {
            int k=l;
            printf("%c.",c[l]);
            for(l++;l<i;l++)
            printf("%c",c[l]);
            printf("e-%d",k); // @@ [Same exponent error: should be `k-1`, not `k`.]
        }
    }
    else
    {
        printf("%c.",c[0]);
        for(l=1;l<i;l++)
        printf("%c",c[l]);
        printf("e%d",t-1);
    }
    return 0;
}