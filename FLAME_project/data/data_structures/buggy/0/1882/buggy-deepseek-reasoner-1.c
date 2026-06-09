#include <stdio.h>
#include <ctype.h>
int main() {
    char s[1145];
    scanf("%s",&s);
    if(s[0]=='a') // @@ [Error: Only handles inputs starting with 'a', not general case]
    {
        if(s[1]=='-') // @@ [Error: Only checks second character for dash; does not process entire string]
        printf("abcdefghijklmnopqrstuBCDEF"); // @@ [Error: Hardcoded incorrect expansion; should expand "a-c-g0-A" to "abcdefg0-A"]
        else printf("abcdefg0-A"); // @@ [Error: Hardcoded output for a different case; not generic]
    }
    else  if(s[0]=='d') // @@ [Error: Only handles inputs starting with 'd']
        printf("dcu012345678"); // @@ [Error: Hardcoded output; not generic]
    else  if(s[0]=='B') // @@ [Error: Only handles inputs starting with 'B']
        printf("B-e"); // @@ [Error: Hardcoded output; not generic]
    else  if(s[0]=='t') // @@ [Error: Only handles inputs starting with 't']
        printf("toooold08A-a"); // @@ [Error: Hardcoded output; not generic]
    return 0;
}