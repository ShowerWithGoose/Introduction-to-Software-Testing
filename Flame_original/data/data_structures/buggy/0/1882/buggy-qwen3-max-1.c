#include <stdio.h>
#include <ctype.h>
int main() {
    char s[1145];
    scanf("%s",&s); // @@ [Passing &s (char (*)[1145]) to scanf with %s expects char*, should be s instead of &s]
    if(s[0]=='a')
    {
        if(s[1]=='-')
        printf("abcdefghijklmnopqrstuBCDEF"); // @@ [Hardcoded output does not implement general expansion logic; violates problem requirements]
        else printf("abcdefg0-A"); // @@ [Hardcoded output for non-matching pattern; does not follow expansion rules]
    }
    else  if(s[0]=='d')
        printf("dcu012345678"); // @@ [Hardcoded output without processing input string or expansion logic]
    else  if(s[0]=='B')
        printf("B-e"); // @@ [Outputs literal "B-e" instead of expanding or preserving input as per rules]
    else  if(s[0]=='t')
        printf("toooold08A-a"); // @@ [Hardcoded arbitrary output unrelated to input expansion]
    return 0;
}