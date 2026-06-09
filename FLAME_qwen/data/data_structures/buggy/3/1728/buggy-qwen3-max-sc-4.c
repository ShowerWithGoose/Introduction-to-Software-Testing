#include<stdio.h>
int main()
{
    char s[1001];
    scanf("%s",s);
    char*c=s;
    int nq=0;
    while(*c!='.')
    {
        c++;
        nq++;
    }
    if(s[0]=='0')
    {
        int x=0;
        char*d=c;
        while(*d=='.'||*d=='0')
        {
            x++;
            d++;
        }
        if(*(d+1)=='\0')
        {
            printf("%ce-%d",*d,x); // @@ [When the significant digit is the last character (e.g., "0.005"), d points to '5' and *(d+1) is '\0', so this branch prints "5e-3". However, according to the problem, if there's only one significant digit, it should be printed as an integer without a decimal point. But the real issue is that when input is like "0.0", which shouldn't happen per problem constraints, but more critically: if the number is "0.1", then d points to '1', *(d+1) is '\0', so it prints "1e-1" — which is correct. However, the actual bug is in the calculation of x: x counts from the decimal point including the '.' as one step. For "0.001", c starts at '.', then d starts at '.', so first iteration: *d=='.' → x=1, d++. Then *d=='0' → x=2, d++. Then *d=='0' → x=3, d++. Then *d=='1'. So x=3, which is correct. BUT: the condition `while(*d=='.'||*d=='0')` will skip the '.' and zeros, but x is incremented for the '.' as well, which is wrong. For "0.001", we want exponent -3, but x becomes 3 because it counted the '.' as position 1. The decimal point should not count toward the exponent offset. So x should start counting after the decimal point, not including the '.' itself.]
        }
        else
        {
            printf("%c.",*d);
            d++;
            while(*d!='\0')
            {
                printf("%c",*d);
            }
            printf("e-%d",x); // @@ [Same issue: x includes the '.' in its count, leading to incorrect exponent. For "0.0012", x becomes 4 (.,0,0,1), but should be 3 (positions after decimal: 1st=0, 2nd=0, 3rd=1). So exponent should be -3, but program outputs -4.]
        }
    }
    else
    {
        printf("%c.",s[0]);
        char*o=s+1;
        while(*o!='\0')
        {
            if(*o=='.')
            {
                o++;
                continue;
            }
            printf("%c",*o);
            o++;
        }
        printf("e%d",nq-1); // @@ [This is correct for numbers like "123.45": nq=3 (digits before '.'), exponent = 3-1 = 2 → "1.2345e2", which is right.]
    }
    return 0;
}