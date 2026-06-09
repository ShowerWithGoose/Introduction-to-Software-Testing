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
        while(b[i++]=='0'); // @@ [The loop increments i after checking b[i], so when the loop exits, i is already one past the first non-zero digit. This causes incorrect indexing in subsequent printf statements.]
        k = -(i--); // @@ [The post-decrement i-- further complicates the index, making k incorrect. For input "0.9", b is "9", loop exits with i=1, then i-- makes i=0, so k = -0 = 0, but the exponent should be -1.]
        if(strlen(b)==(i+1)) // @@ [Due to incorrect i, this condition may not correctly identify when there are no digits after the first non-zero digit.]
            printf("%ce%d",b+i,k); // @@ [b+i points to the wrong character; for "0.9", b+i points to b[0]='9', but the format specifier %c expects a character, not a pointer, causing undefined behavior or printing '@'.]
        else
            printf("%c.%se%d",b+i,b+i+1,k); // @@ [Same pointer issue; b+i and b+i+1 are pointers, not characters, leading to incorrect output.]
    }
    else if(strlen(h)==1)
    {
        printf("%c.%se0",h,b); // @@ [For input like "1.23", this prints "1.23e0", but the expected output should be "1.23e0" only if there is exactly one digit before decimal. However, the problem requires the base to have one digit before decimal, which is correct, but the exponent should be 0 only if the number is already in scientific notation form. This is actually correct for this case, but the issue is in the first branch.]
    }
    else
    {
        printf("%c.%s%se%d",h,h+1,b,strlen(h)-1); // @@ [For input like "12.34", this prints "1.234e1", which is correct. However, the format string has an extra %s; it should be "%c.%s%se%d" but the first %c prints h[0], then %s prints h+1 (rest of integer part), then %s prints b (fractional part), then e and exponent. This works but is fragile.]
    }
    return 0;
}