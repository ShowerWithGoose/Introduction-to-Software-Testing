#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char s[105];
char h[105];
char b[105];

int main()
{
    //把输入分成小数点前后
    gets(s);
    int len = strlen(s);
    int i=0,j=0;
    while(s[i] != '.')
    {
        h[j++] = s[i++];
    }
    h[j] = '\0';
    i++;
    j = 0;
    while(s[i] != '\0')
    {
        b[j++] = s[i++];
    }
    b[j] = '\0';

    int k;
    //0.xxxxx
    if(h[0]=='0')
    {
        i=0;
        while(b[i++]=='0'); // @@ The post-increment causes i to be incremented even when the condition fails, leading to an off-by-one error. The loop should be `while(b[i]=='0') i++;` to correctly find the first non-zero digit.
        k = -(i--); // @@ This decrement is incorrect; after the loop, i already points one past the first non-zero digit due to the post-increment. The exponent should be -(i) (without decrement) if the loop is fixed, or -(i-1) with the current buggy loop.
        if(strlen(b)==(i+1))
            printf("%ce%d",b+i,k); // @@ Using `b+i` is incorrect; it treats the pointer as a string but only prints a single character. Should be `b[i]` to print the character at that index.
        else
            printf("%c.%se%d",b+i,b+i+1,k); // @@ Same pointer issue: `b+i` should be `b[i]` for the character, and `b+i+1` should be `&b[i+1]` to get the substring starting after the first non-zero digit.
    }
    else if(strlen(h)==1)
    {
        printf("%c.%se0",h,b); // @@ `h` is a string, not a character; should be `h[0]` to print the single digit before the decimal point.
    }
    else
    {
        printf("%c.%s%se%d",h,h+1,b,strlen(h)-1); // @@ `h` should be `h[0]` to print the first character; `h+1` is correct for the rest of the integer part; `b` is correct for the fractional part.
    }
    return 0;
}