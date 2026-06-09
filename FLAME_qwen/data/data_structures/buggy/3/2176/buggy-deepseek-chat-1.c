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
        while(b[i++]=='0'); // @@ The post-increment i++ causes i to be incremented even when the condition fails, leading to an off-by-one error in the subsequent index calculations.
        k = -(i--); // @@ The post-decrement i-- further compounds the off-by-one error, resulting in an incorrect exponent value.
        if(strlen(b)==(i+1))
            printf("%ce%d",b+i,k); // @@ b+i is a pointer to the character at index i, but due to the previous errors, i may be out of bounds or point to the wrong character.
        else
            printf("%c.%se%d",b+i,b+i+1,k); // @@ Same pointer issue as above; b+i and b+i+1 may point to incorrect positions.
    }
    else if(strlen(h)==1)
    {
        printf("%c.%se0",h,b); // @@ This format does not match the expected output for cases where the integer part has one digit; the reference program outputs the base as a single digit without a decimal point when the fractional part is empty.
    }
    else
    {
        printf("%c.%s%se%d",h,h+1,b,strlen(h)-1); // @@ Missing a dot between h+1 and b in the format string; should be "%c.%s.%se%d" to match the reference program's output pattern.
    }
    return 0;
}