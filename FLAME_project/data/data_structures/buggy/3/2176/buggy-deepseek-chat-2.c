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
        while(b[i++]=='0'); // @@ The loop increments i even after finding the first non-zero digit, causing i to be one position too far. For input "0.9", b is "9", the loop condition b[0]=='0' is false, but i is still incremented to 1, leading to incorrect indexing later.
        k = -(i--); // @@ The post-decrement i-- is applied to the already incremented i, resulting in k being set to -1 instead of 0. For "0.9", i becomes 1 after the while loop, then i-- makes i=0, so k = -1, which is wrong (should be 0).
        if(strlen(b)==(i+1)) // @@ For "0.9", strlen(b)=1, i=0, so i+1=1, condition is true, but b+i points to b[0] which is '9', so it prints "9e-1" correctly by accident. However, the logic is flawed for other cases.
            printf("%ce%d",b+i,k); // @@ b+i is a pointer, but %c expects a char, so this is incorrect. It should be *(b+i) or b[i]. For "0.9", b+i points to "9", and %c prints the first character '9', so it works accidentally.
        else
            printf("%c.%se%d",b+i,b+i+1,k);
    }
    else if(strlen(h)==1)
    {
        printf("%c.%se0",h,b); // @@ For input like "1.23", h="1", b="23", this prints "1.23e0", which is correct. But for input "0.9", this branch is not taken.
    }
    else
    {
        printf("%c.%s%se%d",h,h+1,b,strlen(h)-1); // @@ For input like "12.34", h="12", b="34", this prints "1.234e1", which is correct. But for input "0.9", this branch is not taken.
    }
    return 0;
}