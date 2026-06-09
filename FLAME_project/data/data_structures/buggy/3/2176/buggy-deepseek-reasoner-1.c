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
        while(b[i++]=='0');
        k = -(i--);
        if(strlen(b)==(i+1))
            printf("%ce%d",b+i,k); // @@ error: b+i is a pointer, but %c expects a character; should be b[i] or *(b+i)
        else
            printf("%c.%se%d",b+i,b+i+1,k); // @@ error: first %c expects a character, b+i is a pointer; second %s expects pointer (b+i+1 is correct)
    }
    else if(strlen(h)==1)
    {
        printf("%c.%se0",h,b); // @@ error: %c expects a character, but h is a pointer; should be h[0] or *h
    }
    else
    {
        printf("%c.%s%se%d",h,h+1,b,strlen(h)-1); // @@ error: %c expects a character, but h is a pointer; should be h[0] or *h
    }
    return 0;
}