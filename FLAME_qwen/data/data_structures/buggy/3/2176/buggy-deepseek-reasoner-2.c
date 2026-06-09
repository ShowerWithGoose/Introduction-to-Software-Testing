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
        if(strlen(b)==(i+1)) // @@ [Condition should be strlen(b)==i instead of i+1; otherwise it fails for numbers like 0.001 where only one non-zero digit exists after decimal.]
            printf("%ce%d",b+i,k); // @@ [b+i is a pointer, but %c expects a character. Should be b[i] or *(b+i).]
        else
            printf("%c.%se%d",b+i,b+i+1,k); // @@ [First argument b+i is a pointer, should be a character b[i].]
    }
    else if(strlen(h)==1)
    {
        printf("%c.%se0",h,b); // @@ [h is a pointer, %c expects a character. Should be h[0] or *h.]
    }
    else
    {
        printf("%c.%s%se%d",h,h+1,b,strlen(h)-1); // @@ [h is a pointer, %c expects a character. Should be h[0] or *h.]
    }
    return 0;
}