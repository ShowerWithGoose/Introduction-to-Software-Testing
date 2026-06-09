#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char s[105];
char h[105];
char b[105];

int main()
{
    //把输入分成小数点前后
    gets(s); // @@ gets is removed in the C11 standard, causing a compilation error in modern compilers.
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
        while(b[i++]=='0');
        k = -(i--);
        if(strlen(b)==(i+1))
            printf("%ce%d",b+i,k); // @@ b+i is a char pointer, but the %c format specifier expects a char. Should be b[i].
        else
            printf("%c.%se%d",b+i,b+i+1,k); // @@ b+i is a char pointer, but the %c format specifier expects a char. Should be b[i].
    }
    else if(strlen(h)==1)
    {
        printf("%c.%se0",h,b); // @@ h is a char pointer, but the %c format specifier expects a char. Should be h[0].
    }
    else
    {
        printf("%c.%s%se%d",h,h+1,b,strlen(h)-1); // @@ h is a char pointer, but the %c format specifier expects a char. Should be h[0].
    }
    return 0;
}