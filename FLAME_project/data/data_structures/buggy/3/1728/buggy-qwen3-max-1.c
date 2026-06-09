#include<stdio.h>
int main()
{
    char s[1001];
    scanf("%s",s);
    char*c=s;
    int nq=0;
    while(*c!='.')  // @@ [If the input has no decimal point, this loop runs indefinitely, causing Time Limit Exceeded. The problem states the input always has digits before and after the decimal point, but the code doesn't guard against missing '.' in malformed inputs or due to buffer issues. However, more critically, in valid inputs like "0.00000009123456789012", this loop correctly stops at '.', so the real issue is elsewhere.]
    {
        c++;
        nq++;
    }
    if(s[0]=='0')
    {
        int x=0;
        char*d=c;
        while(*d=='.'||*d=='0')  // @@ [This loop increments 'x' for both '.' and '0', but 'x' is intended to count leading zeros after the decimal point. Including '.' in the count makes 'x' one too large. For input "0.00000009...", d starts at '.', so first iteration: *d=='.', x becomes 1, then d++. Next iterations count zeros. So total x = 1 + number_of_leading_zeros. This leads to exponent being off by 1 (e.g., outputs e-9 instead of e-8). However, the observed symptom is Time Limit Exceeded, not wrong output. But note: if the input ends with many zeros and then non-zero, it's fine. However, if the input after decimal is all zeros (though problem says no trailing zeros), but more importantly, if there is no non-zero digit after decimal (which shouldn't happen per problem), this loop could go out of bounds. But the real TLE cause is likely the next part.]
        {
            x++;
            d++;
        }
        if(*(d+1)=='\0')  // @@ [This condition checks if only one significant digit remains. However, if 'd' points to the last character, *(d+1) is '\0', which is correct. But if the string ends right after the first non-zero, this works. Not a TLE cause.]
        {
            printf("%ce-%d",*d,x);
        }
        else
        {
            printf("%c.",*d);
            d++;
            while(*d!='\0')  // @@ [This loop prints all remaining digits. It's correct and terminates. Not a TLE cause.]
            {
                printf("%c",*d);
            }
            printf("e-%d",x);
        }
    }
    else
    {
        printf("%c.",s[0]);
        char*o=s+1;
        while(*o!='\0')  // @@ [This loop skips '.' and prints other digits. Correct for numbers like "123.456". Not a TLE cause.]
        {
            if(*o=='.')
            {
                o++;
                continue;
            }
            printf("%c",*o);
            o++;
        }
        printf("e%d",nq-1);
    }
    return 0;
}