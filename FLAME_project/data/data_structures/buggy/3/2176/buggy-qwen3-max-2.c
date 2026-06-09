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
        while(b[i++]=='0'); @@ // The loop increments i even when b[i] is not '0', causing i to point one past the first non-zero digit. This leads to incorrect exponent and digit selection.
        k = -(i--); @@ // The exponent calculation is off by one due to the extra increment in the while loop condition.
        if(strlen(b)==(i+1))
            printf("%ce%d",b+i,k); @@ // When there's only one significant digit after skipping zeros, it should print just that digit without decimal point, but k is incorrect.
        else
            printf("%c.%se%d",b+i,b+i+1,k); @@ // Same issue: k is wrong, and the format assumes at least two digits after the first non-zero, which may not be true.
    }
    else if(strlen(h)==1)
    {
        printf("%c.%se0",h,b); @@ // According to problem description, if there's only one digit before decimal and it's non-zero, output should be just that digit followed by "e0", not with a decimal point and fractional part.
    }
    else
    {
        printf("%c.%s%se%d",h,h+1,b,strlen(h)-1); @@ // Incorrect format: it prints all digits of h (including the first) again via h+1 and appends b, leading to duplicated digits and wrong scientific notation.
    }
    return 0;
}