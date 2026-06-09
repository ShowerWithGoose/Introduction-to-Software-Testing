#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char s[105];
char h[105];
char b[105];

int main()
{
    //把输入分成小数点前后
    gets(s); @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors or warnings in modern compilers.]
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
        while(b[i++]=='0'); @@ [This loop increments 'i' even after finding a non-zero digit, leading to off-by-one error in exponent calculation and digit selection.]
        k = -(i--); @@ [Incorrect exponent calculation due to prior off-by-one; should be k = -(i - 1) or similar logic.]
        if(strlen(b)==(i+1)) @@ [Because 'i' was decremented after being too large, this condition may incorrectly trigger for cases that should print fractional part.]
            printf("%ce%d",b+i,k);
        else
            printf("%c.%se%d",b+i,b+i+1,k);
    }
    else if(strlen(h)==1)
    {
        printf("%c.%se0",h,b);
    }
    else
    {
        printf("%c.%s%se%d",h,h+1,b,strlen(h)-1);
    }
    return 0;
}