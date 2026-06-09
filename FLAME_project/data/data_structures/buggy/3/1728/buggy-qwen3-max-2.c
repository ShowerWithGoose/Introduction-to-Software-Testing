#include<stdio.h>
int main()
{
    char s[1001];
    scanf("%s",s);
    char*c=s;
    int nq=0;
    while(*c!='.')  // @@ [This loop assumes there is always a '.' in the input, but if the input has no decimal point (though problem says it does), it could run past the end of string causing undefined behavior or infinite loop. However, per problem description input always has digits before and after '.', so this isn't the main issue.]
    {
        c++;
        nq++;
    }
    if(s[0]=='0')
    {
        int x=0;
        char*d=c;
        while(*d=='.'||*d=='0')  // @@ [This loop increments 'x' for both '.' and '0', but 'x' is meant to count leading zeros after the decimal point. Counting '.' as a zero shifts the exponent incorrectly. For input "0.00000009...", '.' is counted as one, then seven '0's, making x=8, but exponent should be -8, which accidentally matches. However, logic is flawed because '.' shouldn't count toward exponent offset. More critically, if input ends right after '.', this may read beyond string. But main error is below.]
        {
            x++;
            d++;
        }
        if(*(d+1)=='\0')  // @@ [This checks if only one significant digit remains, but if input is like "0.0001", d points to '1', *(d+1) is '\0', so it prints "1e-4" correctly. However, for "0.00010", problem states no trailing zeros, so this case won't occur. Not the core error.]
        {
            printf("%ce-%d",*d,x);
        }
        else
        {
            printf("%c.",*d);
            d++;
            while(*d!='\0')  // @@ [This loop prints all remaining digits, which is correct per problem (no trailing zeros).]
            {
                printf("%c",*d);
            }
            printf("e-%d",x);  // @@ [The value of 'x' includes the '.' character in its count, so for "0.00000009...", x becomes 8 (1 for '.' + 7 zeros), which gives e-8 — correct by accident. But logic is wrong; should not count '.'. However, this isn't causing TLE.]
        }
    }
    else
    {
        printf("%c.",s[0]);
        char*o=s+1;
        while(*o!='\0')  // @@ [This loop processes digits after first, skipping '.'. Correct for numbers like "123.45" -> "1.2345e2".]
        {
            if(*o=='.')
            {
                o++;
                continue;
            }
            printf("%c",*o);
            o++;
        }
        printf("e%d",nq-1);  // @@ [nq counts digits before '.', so for "123.45", nq=3, exponent=2 — correct.]
    }
    return 0;
}